#ifndef WRAPPER_WAV_H
#define WRAPPER_WAV_H



//namespace MySound
//{
	struct SoundInfo;
//}


#define WAV_BUFFER_SIZE 2048

#include <vector>
//#include "../../Macros.h"
#include <cstring>

#include "isoundfilewrapper.h"

typedef struct wav_file
{
	FILE * f;
	char* curPtr;
	char* filePtr;
	size_t fileSize;
	size_t processedSize;

} wav_file;

typedef struct WAV_DESC
{
	uint8_t riff[4];
	uint64_t size;
	uint8_t wave[4];

} WAV_DESC;

typedef struct WAV_FORMAT
{
	uint8_t id[4];
	uint64_t size;
	uint16_t format;
	uint16_t channels;
	uint64_t sampleRate;
	uint64_t byteRate;
	uint16_t blockAlign;
	uint16_t bitsPerSample;

} WAV_FORMAT;

typedef struct WAV_CHUNK
{
	uint8_t id[4];
	uint64_t size;

} WAV_CHUNK;

//namespace MySound
//{

	class WrapperWav : public ISoundFileWrapper
	{
		public:
			WrapperWav(int minDecompressLengthAtOnce = -1);
			~WrapperWav();

			virtual void LoadFromMemory(char * data, int dataSize, SoundInfo * soundInfo);
			virtual void LoadFromFile(FILE * f, SoundInfo * soundInfo);
			virtual void DecompressStream(std::vector<char> & decompressBuffer, bool inLoop = false);
			virtual void DecompressAll(std::vector<char> & decompressBuffer);
			virtual void ResetStream();

			virtual void Seek(size_t pos, SEEK_POS start);
			virtual size_t GetCurrentStreamPos() const;

			virtual float GetTime() const;
			virtual float GetTotalTime() const;

		private:
			wav_file t;
			char bufArray[WAV_BUFFER_SIZE];
			

			int minProcesssLengthAtOnce;

			WAV_DESC desc;
			WAV_FORMAT format;
			
			WAV_CHUNK curChunk;
			int curBufSize;
			
			void ReadData(void * dst, size_t size);
			

	};
//}


#endif
