#ifndef __ANDROID__ 

//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID

#include "SDL_main.h"
#include "android.h"
#include "gameengine.h"
#include "gamestate.h"
#include "gui.h"
#include "renderengine.h"


static Ogre::DataStreamPtr openAPKFile(const Ogre::String& fileName)
{
	renderEngine *renderE = renderEngine::Instance();
	Ogre::DataStreamPtr stream;
    AAsset* asset = AAssetManager_open(renderE->getMAssetMgr(), fileName.c_str(), AASSET_MODE_BUFFER);
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
//	exit(0);
    renderEngine *renderE = renderEngine::Instance();
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
//    Ogre::ResourceGroupManager::getSingletonPtr()->initialiseResourceGroup(Ogre::ResourceGroupManager::UBCData);
	Ogre::RTShader::ShaderGenerator::initialize();
	Ogre::RTShader::ShaderGenerator::getSingletonPtr()->setTargetLanguage("glsles");
	gMatListener = new Ogre::ShaderGeneratorTechniqueResolverListener();
	Ogre::MaterialManager::getSingleton().addListener(gMatListener);
	
//	gSceneMgr = gRoot->createSceneManager(Ogre::ST_GENERIC);
    renderE->setMSceneMgr(renderE->getMRoot()->createSceneManager(Ogre::ST_GENERIC));
//	Ogre::RTShader::ShaderGenerator::getSingletonPtr()->addSceneManager(gSceneMgr);
    Ogre::RTShader::ShaderGenerator::getSingletonPtr()->addSceneManager(renderE->getMSceneMgr());
//	Ogre::Camera* camera = gSceneMgr->createCamera("MyCam");
    Ogre::Camera* camera = renderE->getMSceneMgr()->createCamera("MyCam");
/*	
//	Ogre::Entity* pEntity = gSceneMgr->createEntity("SinbadInstance", "data/Media/models/court.mesh");
    Ogre::Entity* pEntity = renderE->getMSceneMgr()->createEntity("SinbadInstance", "Court.mesh");
//	Ogre::SceneNode* pNode = gSceneMgr->getRootSceneNode()->createChildSceneNode();
    Ogre::SceneNode* pNode = renderE->getMSceneMgr()->getRootSceneNode()->createChildSceneNode();
	pNode->attachObject(pEntity);

//	Ogre::Light* pDirLight = gSceneMgr->createLight();
    Ogre::Light* pDirLight = renderE->getMSceneMgr()->createLight();
	pDirLight->setDirection(Ogre::Vector3(0,-1,0));
	pDirLight->setType(Ogre::Light::LT_DIRECTIONAL);
	pNode->attachObject(pDirLight);
*/
	camera->setNearClipDistance(1.0f);
	camera->setFarClipDistance(100000.0f);
	camera->setPosition(0,0,20.0f);
	camera->lookAt(0,0,0);
	camera->setAutoAspectRatio(true);

//	Ogre::Viewport* vp = gRenderWnd->addViewport(camera);
    Ogre::Viewport* vp = renderE->getMWindow()->addViewport(camera);
	vp->setBackgroundColour(Ogre::ColourValue(1,0,0));	
	vp->setMaterialScheme(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);	

	Ogre::RTShader::ShaderGenerator::getSingletonPtr()->invalidateScheme(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);

}


static int32_t handleInput(struct android_app* app, AInputEvent* event) 
{
}


static void handleCmd(struct android_app* app, int32_t cmd)
{
	gameEngine *gameE = gameEngine::Instance();
    gameState *gameS = gameState::Instance();
    GUISystem *gui = GUISystem::Instance();
	renderEngine *renderE = renderEngine::Instance();
	Ogre::LogManager::getSingletonPtr()->logMessage("Handling command");
    switch (cmd) 
    {
        case APP_CMD_SAVE_STATE:
            break;
        case APP_CMD_INIT_WINDOW:
			Ogre::LogManager::getSingletonPtr()->logMessage("Initializing window");
            if(app->window && renderE->getMRoot())
            {
                AConfiguration* config = AConfiguration_new();
                AConfiguration_fromAssetManager(config, app->activity->assetManager);
                renderE->setMAssetMgr(app->activity->assetManager);
				
				if(!renderE->getMWindow()) 
//                if(!gRenderWnd)
                {
				    Ogre::ArchiveManager::getSingleton().addArchiveFactory( new Ogre::APKFileSystemArchiveFactory(app->activity->assetManager) );
					Ogre::ArchiveManager::getSingleton().addArchiveFactory( new Ogre::APKZipArchiveFactory(app->activity->assetManager) );
				
                    Ogre::NameValuePairList opt;
                    opt["externalWindowHandle"] = Ogre::StringConverter::toString((int)app->window);
                    opt["androidConfig"] = Ogre::StringConverter::toString((int)config);
                           
	//				gRenderWnd = gRoot->createRenderWindow("OgreWindow", 0, 0, false, &opt); 
	            	renderE->setMWindow(renderE->getMRoot()->createRenderWindow("OgreWindow", 0, 0, false, &opt));
//					setupScene();
					renderE->createScene();
//					gui->initMyGUI(); // Initializes MyGUI
//                    gui->createMainMenuButtons(); // creates a MyGUI button.
                    gameS->setGameType(SINGLE);
					inputSystem *input = inputSystem::Instance();
					gameE->gameLoop();
                }
                else
                {
					static_cast<Ogre::AndroidEGLWindow*>(renderE->getMWindow())->_createInternalResources(app->window, config);
                }
                AConfiguration_delete(config);
            }
            break;
        case APP_CMD_TERM_WINDOW:
            if(renderE->getMRoot() && renderE->getMWindow())
				static_cast<Ogre::AndroidEGLWindow*>(renderE->getMWindow())->_destroyInternalResources();
            break;
        case APP_CMD_GAINED_FOCUS:
            break;
        case APP_CMD_LOST_FOCUS:
            break;
    }
}


//# if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//void android_main(struct android_app* state)
int main(int argc, char *argv[])
{
	gameEngine *gameE = gameEngine::Instance();
	gameState *gameS = gameState::Instance();
	renderEngine *renderE = renderEngine::Instance();
//    renderE->getApp()->onAppCmd = &handleCmd;
/*        if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_EVENTS) != 0) {
        fprintf(stderr,
                "\nUnable to initialize SDL:  %s\n",
                SDL_GetError()
               );
        __android_log_print(ANDROID_LOG_DEBUG, "com.libolt.ubc", "SDL Error = %s", SDL_GetError());
        return 1;
    }
*/

/*
renderE->initSDL();
renderE->initOgre();
renderE->createScene();
gameE->gameLoop();
*/


//    app_dummy();

	if(renderE->getMRoot() == NULL)
	{
/*
//		gRoot = new Ogre::Root();

		renderE->setMRoot(new Ogre::Root());
#ifdef OGRE_STATIC_LIB
        gStaticPluginLoader = new Ogre::StaticPluginLoader();
        gStaticPluginLoader->load();
#endif
        renderE->getMRoot()->setRenderSystem( renderE->getMRoot()->getAvailableRenderers().at(0));
        renderE->getMRoot()->initialise(false);	
*/
//        renderE->initSDL();
		renderE->initOgre();
	}	
	
    renderE->createScene();
	
	//FIXME hardcoded while working on other bugs
	gameS->setGameType(SINGLE);
	
	inputSystem *input = inputSystem::Instance();

	gameE->gameLoop();
	
	/*
//    renderE->initOgre();
	struct android_app *state;		
    state->onAppCmd = &handleCmd;
//    state->onInputEvent = &handleInput;
 
    int ident, events;
    struct android_poll_source* source;

    while (true)
    {
//		Ogre::LogManager::getSingletonPtr()->logMessage("Looping!");


//      while ((ident = ALooper_pollAll(0, NULL, &events, (void**)&source)) >= 0)
        {
            if (source != NULL)
                source->process(state, source);
            
            if (state->destroyRequested != 0)
                return(0);
        }

		if(renderE->getApp()->window && renderE->getMRoot())
		{
			Ogre::LogManager::getSingletonPtr()->logMessage("Initing window");
            AConfiguration* config = AConfiguration_new();
			Ogre::LogManager::getSingletonPtr()->logMessage("Die?");
//            AConfiguration_fromAssetManager(config, renderE->getApp()->activity->assetManager);
            Ogre::LogManager::getSingletonPtr()->logMessage("Die??");
			renderE->setMAssetMgr(renderE->getApp()->activity->assetManager);
			Ogre::LogManager::getSingletonPtr()->logMessage("Die???");
            
			if(!renderE->getMWindow()) 
//                if(!gRenderWnd)
                {
//				    Ogre::ArchiveManager::getSingleton().addArchiveFactory( new Ogre::APKFileSystemArchiveFactory(app->activity->assetManager) );
//					Ogre::ArchiveManager::getSingleton().addArchiveFactory( new Ogre::APKZipArchiveFactory(app->activity->assetManager) );
				
                    Ogre::NameValuePairList opt;
                    opt["externalWindowHandle"] = Ogre::StringConverter::toString((int)renderE->getApp()->window);
//                    opt["androidConfig"] = Ogre::StringConverter::toString((int)config);
                           
	//				gRenderWnd = gRoot->createRenderWindow("OgreWindow", 0, 0, false, &opt); 
	            	renderE->setMWindow(renderE->getMRoot()->createRenderWindow("OgreWindow", 0, 0, false, &opt));
                    Ogre::LogManager::getSingletonPtr()->logMessage("Alive");


///					setupScene();
//					renderE->createScene();
///					gui->initMyGUI(); // Initializes MyGUI
///                    gui->createMainMenuButtons(); // creates a MyGUI button.
//                    gameS->setGameType(SINGLE);
//					inputSystem *input = inputSystem::Instance();
//					gameE->gameLoop();

                }				
		}


		if(renderE->getMWindow() != NULL && renderE->getMWindow()->isActive())
//		if(gRenderWnd != NULL && gRenderWnd->isActive())
		{
//		    exit(0);
			renderE->getMWindow()->windowMovedOrResized();
			renderE->getMRoot()->renderOneFrame();
		}

    }
//	return (0);
*/
	return (0);
}

#endif