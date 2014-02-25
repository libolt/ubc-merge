#include "android.h"

static Ogre::DataStreamPtr openAPKFile(const Ogre::String& fileName)
{
	Ogre::DataStreamPtr stream;
    AAsset* asset = AAssetManager_open(gAssetMgr, fileName.c_str(), AASSET_MODE_BUFFER);
    if(asset)
    {
		off_t length = AAsset_getLength(asset);
        void* membuf = OGRE_MALLOC(length, Ogre::MEMCATEGORY_GENERAL);
        memcpy(membuf, AAsset_getBuffer(asset), length);
        AAsset_close(asset);
                
        stream = Ogre::DataStreamPtr(new Ogre::MemoryDataStream(membuf, length, true, true));
    }
    return stream;
}
		
static void setupScene()
{
	Ogre::ConfigFile cf;
    cf.load(openAPKFile("resources.cfg"));
	
	Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
	while (seci.hasMoreElements())
	{
		Ogre::String sec, type, arch;
		sec = seci.peekNextKey();
		Ogre::ConfigFile::SettingsMultiMap* settings = seci.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator i;

		for (i = settings->begin(); i != settings->end(); i++)
		{
			type = i->first;
			arch = i->second;
			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch, type, sec);
		}
	}

	Ogre::ResourceGroupManager::getSingletonPtr()->initialiseResourceGroup(Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

	Ogre::RTShader::ShaderGenerator::initialize();
	Ogre::RTShader::ShaderGenerator::getSingletonPtr()->setTargetLanguage("glsles");
	gMatListener = new Ogre::ShaderGeneratorTechniqueResolverListener();
	Ogre::MaterialManager::getSingleton().addListener(gMatListener);
	
	gSceneMgr = gRoot->createSceneManager(Ogre::ST_GENERIC);
	Ogre::RTShader::ShaderGenerator::getSingletonPtr()->addSceneManager(gSceneMgr);
		
	Ogre::Camera* camera = gSceneMgr->createCamera("MyCam");
	
	Ogre::Entity* pEntity = gSceneMgr->createEntity("SinbadInstance", "Sinbad.mesh");
	Ogre::SceneNode* pNode = gSceneMgr->getRootSceneNode()->createChildSceneNode();
	pNode->attachObject(pEntity);

	Ogre::Light* pDirLight = gSceneMgr->createLight();
	pDirLight->setDirection(Ogre::Vector3(0,-1,0));
	pDirLight->setType(Ogre::Light::LT_DIRECTIONAL);
	pNode->attachObject(pDirLight);

	camera->setNearClipDistance(1.0f);
	camera->setFarClipDistance(100000.0f);
	camera->setPosition(0,0,20.0f);
	camera->lookAt(0,0,0);
	camera->setAutoAspectRatio(true);

	Ogre::Viewport* vp = gRenderWnd->addViewport(camera);
	vp->setBackgroundColour(Ogre::ColourValue(1,0,0));	
	vp->setMaterialScheme(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);	

	Ogre::RTShader::ShaderGenerator::getSingletonPtr()->invalidateScheme(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);
}

static int32_t handleInput(struct android_app* app, AInputEvent* event) 
{
}

static void handleCmd(struct android_app* app, int32_t cmd)
{
    switch (cmd) 
    {
        case APP_CMD_SAVE_STATE:
            break;
        case APP_CMD_INIT_WINDOW:
            if(app->window && gRoot)
            {
                AConfiguration* config = AConfiguration_new();
                AConfiguration_fromAssetManager(config, app->activity->assetManager);
                gAssetMgr = app->activity->assetManager;
				
                if(!gRenderWnd)
                {
				    Ogre::ArchiveManager::getSingleton().addArchiveFactory( new Ogre::APKFileSystemArchiveFactory(app->activity->assetManager) );
					Ogre::ArchiveManager::getSingleton().addArchiveFactory( new Ogre::APKZipArchiveFactory(app->activity->assetManager) );
				
                    Ogre::NameValuePairList opt;
                    opt["externalWindowHandle"] = Ogre::StringConverter::toString((int)app->window);
                    opt["androidConfig"] = Ogre::StringConverter::toString((int)config);
                           
					gRenderWnd = gRoot->createRenderWindow("OgreWindow", 0, 0, false, &opt); 
		
					setupScene();
                }
                else
                {
					static_cast<Ogre::AndroidEGLWindow*>(gRenderWnd)->_createInternalResources(app->window, config);
                }
                AConfiguration_delete(config);
            }
            break;
        case APP_CMD_TERM_WINDOW:
            if(gRoot && gRenderWnd)
				static_cast<Ogre::AndroidEGLWindow*>(gRenderWnd)->_destroyInternalResources();
            break;
        case APP_CMD_GAINED_FOCUS:
            break;
        case APP_CMD_LOST_FOCUS:
            break;
    }
}


