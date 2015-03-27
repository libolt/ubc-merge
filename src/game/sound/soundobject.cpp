#include "soundobject.h"
#include "isoundfilewrapper.h"

#include "wrapper_ogg.h"
#include "wrapper_wav.h"
#include "wrapper_raw.h"

#include "soundengine.h"
#include "load.h"
#include "openal.h"

//#include "../../Utils/header/Logger.h"
//#include "../../Utils/header/VFS/VFS.h"


//using namespace MySound;

SoundObject::SoundObject(const std::string & fileName, const std::string & name)
{
	this->SINGLE_BUFFER_SIZE = 64 * 1024;

	this->settings.fileName = fileName;
	this->settings.name = name;

	this->settings.pitch = 1.0f;
	this->settings.gain = 1.0f;
	this->settings.loop = false;
	this->settings.pos = Ogre::Vector3(0, 0, 0);
	this->settings.velocity = Ogre::Vector3(0, 0, 0);

	this->file = NULL;
	this->soundFileWrapper = NULL;
	this->soundData = NULL;
	this->dataSize = 0;

	this->playedCount = 0;

	this->state = STOPPED;

	this->LoadData();
}

SoundObject::SoundObject(const SoundSettings & settings)
{
	this->SINGLE_BUFFER_SIZE = 64 * 1024;

	this->settings = settings;

	this->file = NULL;
	this->soundFileWrapper = NULL;
	this->soundData = NULL;
	this->dataSize = 0;

	this->playedCount = 0;

	this->state = STOPPED;

	this->LoadData();
}

SoundObject::SoundObject(char * rawData, uint32_t dataSize, SoundInfo soundInfo, const std::string & name)
{
	this->SINGLE_BUFFER_SIZE = 64 * 1024;

	this->soundInfo = soundInfo;

	this->settings.fileName = "<memory raw data>";
	this->settings.name = name;

	this->settings.pitch = 1.0f;
	this->settings.gain = 1.0f;
	this->settings.loop = false;
	this->settings.pos = Ogre::Vector3(0, 0, 0);
	this->settings.velocity = Ogre::Vector3(0, 0, 0);

	this->file = NULL;
	this->soundFileWrapper = NULL;
	this->soundData = NULL;
	this->dataSize = 0;

	this->playedCount = 0;

	this->state = STOPPED;

	this->LoadRawData(rawData, dataSize);
}


SoundObject::~SoundObject()
{
	this->Release();
}

void SoundObject::Release()
{
	if (this->state != STOPPED)
	{
		this->Stop();
	}

	SDL_RWclose(this->file);
	this->file = NULL;
//	SAFE_DELETE(this->soundData);
//	SAFE_DELETE(this->soundFileWrapper);

	for (int i = 0; i < PRELOAD_BUFFERS_COUNT; i++)
	{
		SoundEngine::Instance()->FreeBuffer(this->buffers[i]);
	}
}

const SoundSettings & SoundObject::GetSettings() const
{
	return this->settings;
}

const SoundInfo & SoundObject::GetInfo() const
{
	return this->soundInfo;
}

void SoundObject::PlayInLoop(bool val)
{
	this->settings.loop = val;
}

float SoundObject::GetMaxBufferedTime() const
{
	return this->GetBufferedTime(PRELOAD_BUFFERS_COUNT);
}

float SoundObject::GetBufferedTime(int buffersCount) const
{
	float preBufferTime = this->SINGLE_BUFFER_SIZE / static_cast<float>(this->soundInfo.freqency * this->soundInfo.channels * this->soundInfo.bitsPerChannel / 8);
	preBufferTime *= buffersCount;
	//preBufferTime *= (PRELOAD_BUFFERS_COUNT - 1);

	return preBufferTime;
}

float SoundObject::GetTime() const
{
	//Get duration of remaining buffer
	float preBufferTime = this->GetBufferedTime(this->remainBuffers);

	//get current time of file stream
	//this stream is "in future" because of buffered data
	//duration of buffer MUST be removed from time
	float time = this->soundFileWrapper->GetTime() - preBufferTime;


	if (this->remainBuffers < PRELOAD_BUFFERS_COUNT)
	{
		//file has already been read all
		//we are currently "playing" sound from cache only
		//and there is no loop active
		time = this->soundFileWrapper->GetTotalTime() - preBufferTime;
	}

	if (time < 0)
	{
		//file has already been read all
		//we are currently "playing" sound from last loop cycle
		//but file stream is already in next loop
		//because of the cache delay

		//Signe of "+" => "- abs(time)" rewritten to "+ time"
		time = this->soundFileWrapper->GetTotalTime() + time;
	}


	//add current buffer play time to time from file stream
	float result;
	AL_CHECK(alGetSourcef(this->source->refID, AL_SEC_OFFSET, &result));

	time += result;

	//time in seconds
	return time;
}

int SoundObject::GetPlayedCount() const
{
	return this->playedCount;
}

bool SoundObject::IsPlaying() const
{
	return (this->state == PLAYING);
}

void SoundObject::Rewind()
{
	this->soundFileWrapper->ResetStream();
    
    AL_CHECK( alSourceRewind(this->source->refID) );
}

void SoundObject::GetRawData(std::vector<char> * rawData)
{
	if (this->state == PLAYING)
	{
		logMsg("Can not get raw data for sound (%s), that is in PLAY state." +this->settings.name);
		return;
	}


	this->soundFileWrapper->DecompressAll(*rawData);

	
}

template <typename T>
void SoundObject::GetRawDataNormalized(std::vector<T> * rawData)
{

	std::vector<char> raw;
	this->GetRawData(&raw);

	if (raw.size() == 0)
	{
		return;
	}

	auto bytesToT = [](short a, short b) { return ((b << 8) | a) / static_cast<T>(32768.0); };
	
	// convert to range from -1 to (just below) 1
	
	if (this->soundInfo.bitsPerChannel == 16)
	{
		int pos = 0;
		while (pos < raw.size())
		{
			T v = bytesToT(raw[pos], raw[pos + 1]);
			pos += 2;
			rawData->push_back(v);
		}
	}
	else if (this->soundInfo.bitsPerChannel == 8)
	{
		int pos = 0;
		while (pos < raw.size())
		{
			T v = raw[pos] / static_cast<T>(32768.0);
			pos += 1;
			rawData->push_back(v);
		}
	}

}




void SoundObject::LoadData()
{
    loader *load = loader::Instance();
	for (int i = 0; i < PRELOAD_BUFFERS_COUNT; i++)
	{
		this->buffers[i] = NULL;
	}


	this->spinLock = false;

	SDL_RWops * file = load->readBinaryFile(this->settings.fileName.c_str());

    if (file == NULL)
    {
        logMsg("File %s not found" + this->settings.fileName);
        return;
    }


/* FIXME!	
	if (strcmp(vfsFile->ext, "ogg") == 0)
	{
		this->soundFileWrapper = new WrapperOgg(this->SINGLE_BUFFER_SIZE);
	}
	else if (strcmp(vfsFile->ext, "wav") == 0)
	{
		this->soundFileWrapper = new WrapperWav(this->SINGLE_BUFFER_SIZE);
	}
	else 
	{
		logMsg("File extension %s not supported.", vfsFile->ext);
	}


	if (vfsFile->archiveInfo == NULL)
	{
		this->soundFileWrapper->LoadFromFile((FILE *)vfsFile->filePtr, &this->soundInfo);
	}
	else 
	{
		VFS::GetInstance()->CloseFile(this->vfsFile);
		this->vfsFile = NULL;

		this->soundData = VFS::GetInstance()->GetFileContent(this->settings.fileName, &this->dataSize);
		this->soundFileWrapper->LoadFromMemory(this->soundData, this->dataSize, &this->soundInfo);
	}

*/	
	
	//AL_CHECK( alGenSources((ALuint)1, &this->source)) ;
		
	//AL_CHECK( alGenBuffers((ALuint)1, &this->buffer) );

	
	

	
	if (this->soundInfo.bitsPerChannel == 16)
	{

		if (this->soundInfo.channels == 1)
		{
			this->soundInfo.format = AL_FORMAT_MONO16;
		}
		else
		{
			this->soundInfo.format = AL_FORMAT_STEREO16;
		}
	}
	else if (this->soundInfo.bitsPerChannel == 8)
	{

		if (this->soundInfo.channels == 1)
		{
			this->soundInfo.format = AL_FORMAT_MONO8;
		}
		else
		{
			this->soundInfo.format = AL_FORMAT_STEREO8;
		}
	}

	for (uint32_t i = 0; i < PRELOAD_BUFFERS_COUNT; i++)
	{
		SoundBuffer * buf = SoundEngine::Instance()->GetFreeBuffer();
		if (buf == NULL)
		{
			logMsg("Not enought free sound-buffers");
			continue;
		}
		this->buffers[i] = buf;
	}

	this->Preload();

}


/*-----------------------------------------------------------
Function:	LoadRawData
Parametrs:
	[in] rawData - 
	[in] dataSize - 

Use raw data for this sound object�s sound
Raw data are copied into sound wrapper and later read from it
-------------------------------------------------------------*/
void SoundObject::LoadRawData(char * rawData, uint32_t dataSize)
{
	for (int i = 0; i < PRELOAD_BUFFERS_COUNT; i++)
	{
		this->buffers[i] = NULL;
	}


	this->spinLock = false;

	this->soundFileWrapper = new WrapperRaw(this->soundInfo, this->SINGLE_BUFFER_SIZE);
	
	this->soundFileWrapper->LoadFromMemory(rawData, dataSize, &this->soundInfo);





	if (this->soundInfo.bitsPerChannel == 16)
	{

		if (this->soundInfo.channels == 1)
		{
			this->soundInfo.format = AL_FORMAT_MONO16;
		}
		else
		{
			this->soundInfo.format = AL_FORMAT_STEREO16;
		}
	}
	else if (this->soundInfo.bitsPerChannel == 8)
	{

		if (this->soundInfo.channels == 1)
		{
			this->soundInfo.format = AL_FORMAT_MONO8;
		}
		else
		{
			this->soundInfo.format = AL_FORMAT_STEREO8;
		}
	}

	for (uint32_t i = 0; i < PRELOAD_BUFFERS_COUNT; i++)
	{
		SoundBuffer * buf = SoundEngine::Instance()->GetFreeBuffer();
		if (buf == NULL)
		{
		    logMsg("Not enought free sound-buffers");
			continue;
		}
		this->buffers[i] = buf;
	}

	this->Preload();

}


bool SoundObject::Preload()
{
	for (int i = 0; i < PRELOAD_BUFFERS_COUNT; i++)
	{		
		if (this->buffers[i] == NULL)
		{
			continue;
		}
		if (this->PreloadBuffer(this->buffers[i]->refID) == false)
		{
			//preload raw data - all buffers were not used, free them
			for (int j = i; j < PRELOAD_BUFFERS_COUNT; j++)
			{
				SoundEngine::Instance()->FreeBuffer(this->buffers[j]);
				this->buffers[j] = NULL;
			}

			return false;
		}
	}

	return true;
}

bool SoundObject::PreloadBuffer(int bufferID)
{
	

	std::vector<char> decompressBuffer;
	this->soundFileWrapper->DecompressStream(decompressBuffer, this->settings.loop);

	if (decompressBuffer.size() == 0)
	{
        //nothing more to read
		return false;
	}
	


	AL_CHECK( alBufferData(bufferID, this->soundInfo.format, &decompressBuffer[0], static_cast<ALsizei>(decompressBuffer.size()), this->soundInfo.freqency) );
		
	//printf("Reload...");

	return true;
}

void SoundObject::Play()
{
	
	if (this->state == PLAYING)
	{
		//can not start play same sound twice
		return;
	}

    
	if (this->state == PAUSED)
	{
		this->state = PLAYING;

		AL_CHECK(alSourcef(this->source->refID, AL_PITCH, this->settings.pitch));
		AL_CHECK(alSourcef(this->source->refID, AL_GAIN, this->settings.gain));
		AL_CHECK(alSource3f(this->source->refID, AL_POSITION, this->settings.pos[0], this->settings.pos[0], this->settings.pos[0]));
		AL_CHECK(alSource3f(this->source->refID, AL_VELOCITY, this->settings.velocity[0], this->settings.velocity[1], this->settings.velocity[2]));
		AL_CHECK(alSourcei(this->source->refID, AL_LOOPING, false));

		AL_CHECK( alSourcePlay(this->source->refID) );

		return;
	}

	
	this->source = SoundEngine::Instance()->GetFreeSource();

	if (this->source == NULL)
	{
		return;
	}

	
	AL_CHECK( alSourcef(this->source->refID, AL_PITCH, this->settings.pitch)) ;	
	AL_CHECK( alSourcef(this->source->refID, AL_GAIN, this->settings.gain) );	
	AL_CHECK( alSource3f(this->source->refID, AL_POSITION, this->settings.pos[0], this->settings.pos[0], this->settings.pos[0]) );	
	AL_CHECK( alSource3f(this->source->refID, AL_VELOCITY, this->settings.velocity[0], this->settings.velocity[1], this->settings.velocity[2]) );	
	AL_CHECK( alSourcei(this->source->refID, AL_LOOPING, false) );
	
	int usedBuffersCount = 0;
	for (int i = 0; i < PRELOAD_BUFFERS_COUNT; i++)
	{		
		if (this->buffers[i] == NULL)
		{
			continue;
		}
		AL_CHECK( alSourceQueueBuffers(this->source->refID, 1, &this->buffers[i]->refID) );
		usedBuffersCount++;
	}
	
	


	this->playedCount++;	
	AL_CHECK( alSourcePlay(this->source->refID) );
	this->state = PLAYING;
	this->activeBufferID = 0;
	this->remainBuffers = usedBuffersCount;
}

void SoundObject::Pause()
{
	if (this->state != PLAYING)
	{
		return;
	}
	
	this->state = PAUSED;
	
	AL_CHECK( alSourcePause(this->source->refID) );
}

void SoundObject::Stop()
{
	if (this->state == STOPPED)
	{
		return;
	}

	//while(this->spinLock){}
	
	//this->spinLock = true;
	this->state = STOPPED;

    //alSourceRewind(this->source->refID);

	AL_CHECK( alSourceStop(this->source->refID) );
	
	
	for (int i = 0; i < PRELOAD_BUFFERS_COUNT; i++)
	{		
		if (this->buffers[i] == NULL)
		{
			continue;
		}
		AL_CHECK( alSourceUnqueueBuffers(this->source->refID, 1, &this->buffers[i]->refID) );
	}

	
  	SoundEngine::Instance()->FreeSource(this->source);

	this->soundFileWrapper->ResetStream();
	
    

   
    
    for (uint32_t i = 0; i < PRELOAD_BUFFERS_COUNT; i++)
	{
        SoundEngine::Instance()->FreeBuffer(this->buffers[i]);
     
		SoundBuffer * buf = SoundEngine::Instance()->GetFreeBuffer();
		if (buf == NULL)
		{
			logMsg("Not enought free sound-buffers");
			continue;
		}
		this->buffers[i] = buf;
	}
    
	this->Preload();
	this->spinLock = false;
    
}

float lastTimeTmp = 0;
void SoundObject::Update()
{
	//while(this->spinLock){}
	
	if (this->state != PLAYING)
	{
		return;
	}
	this->spinLock = true;
	
	
	float result = this->GetTime();
	if (lastTimeTmp != result)
	{
		//printf("Time: %f\n", result);
		lastTimeTmp = result;
	}
	


	// get the processed buffer count
	int buffersProcessed = 0;
	AL_CHECK( alGetSourcei(this->source->refID, AL_BUFFERS_PROCESSED, &buffersProcessed) );
	
	// check to see if we have a buffer to deQ
	if (buffersProcessed > 0) 
	{
		if (buffersProcessed > 1)
		{
			//we have processed more than 1 buffer since last call of Update method
			//we should probably reload more buffers than just the one
			logMsg("Processed more than 1 buffer since last Update");
		}

		this->activeBufferID += buffersProcessed;
		this->activeBufferID %= PRELOAD_BUFFERS_COUNT;

		// great! deQ a buffer and re-fill it
		uint32_t bufferID;
		
		// remove the buffer form the source
		AL_CHECK(alSourceUnqueueBuffers(this->source->refID, 1, &bufferID) );
		
		// fill the buffer up and reQ! 
		// if we cant fill it up then we are finished
		// in which case we dont need to re-Q
		// return NO if we dont have more buffers to Q
		
		if (this->state == STOPPED)
		{
			//put it back
			AL_CHECK( alSourceQueueBuffers(this->source->refID, 1, &bufferID) );
			this->spinLock = false;					
			return;
		}

		if (this->PreloadBuffer(bufferID) == false)
		{
			//put it back
			//AL_CHECK( alSourceQueueBuffers(this->source->refID, 1, &bufferID) );
			//this->spinLock = false;
			//this->Stop();
			//return;

			this->remainBuffers--;
		}

		//put it back
		AL_CHECK( alSourceQueueBuffers(this->source->refID, 1, &bufferID) );
	}

	this->spinLock = false;
	if (this->remainBuffers <= 0)
	{
		this->Stop();
	}

}


template void SoundObject::GetRawDataNormalized(std::vector<float> * rawData);

template void SoundObject::GetRawDataNormalized(std::vector<double> * rawData);
