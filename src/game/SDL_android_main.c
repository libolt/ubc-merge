
#include "SDL_config.h"
#include "Ogre.h"

#ifdef __ANDROID__

/* Include the SDL main definition header */
#include "SDL_main.h"

/*******************************************************************************
                 Functions called by JNI
*******************************************************************************/
#include <jni.h>

// Called before SDL_main() to initialize JNI bindings in SDL library
extern "C" { void SDL_Android_Init(JNIEnv* env, jclass cls); }

// Start up the SDL app
extern "C"
{
void Java_org_libsdl_app_SDLActivity_nativeInit(JNIEnv* env, jclass cls, jobject obj)
{
    /* This interface could expand with ABI negotiation, calbacks, etc. */
    SDL_Android_Init(env, cls);

    SDL_SetMainReady();

    /* Run the application code! */
    int status;
    char *argv[2];
    argv[0] = SDL_strdup("SDL_app");
    argv[1] = NULL;
    status = SDL_main(1, argv);

    /* Do not issue an exit or the whole application will terminate instead of just the SDL thread */
    //exit(status);
}
}

extern "C"
{
	
JNIEXPORT void JNICALL Java_org_libsdl_app_SDLActivityJNI_initWindow(JNIEnv * env, jobject obj,  jobject surface)
{
	Ogre::LogManager::getSingletonPtr()->logMessage("OgreJNI");
	/*
    if(surface)
    {
        ANativeWindow* nativeWnd = ANativeWindow_fromSurface(env, surface);
        if (nativeWnd && gRoot)
        {
            if (!gRenderWnd) 
            {
               Ogre::NameValuePairList opt;
               opt["externalWindowHandle"] = Ogre::StringConverter::toString((int)nativeWnd);
               gRenderWnd = Ogre::Root::getSingleton().createRenderWindow("OgreWindow", 0, 0, false, &opt);
               
               
               if(pSceneMgr == NULL)
               {
                  // open config file to load resource groups
                  Ogre::ConfigFile cf;
                  cf.load(openAPKFile("resources.cfg"));

                  Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
                  Ogre::String sec, type, arch;

                  // go through all specified resource groups
                  while (seci.hasMoreElements())
                  {
                     sec = seci.peekNextKey();
                     Ogre::ConfigFile::SettingsMultiMap* settings = seci.getNext();
                     Ogre::ConfigFile::SettingsMultiMap::iterator i;

                     // go through all resource paths
                     for (i = settings->begin(); i != settings->end(); i++)
                     {
                        type = i->first;
                        arch = i->second;
                        Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch, type, sec);
                     }
                  }
                  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
                  
                  Ogre::RTShader::ShaderGenerator::initialize();
                  Ogre::RTShader::ShaderGenerator::getSingletonPtr()->setTargetLanguage("glsles");
                  gMatListener = new ShaderGeneratorTechniqueResolverListener();
                  Ogre::MaterialManager::getSingleton().addListener(gMatListener);
   
                  pSceneMgr = gRoot->createSceneManager(Ogre::ST_GENERIC);
                  Ogre::RTShader::ShaderGenerator::getSingletonPtr()->addSceneManager(pSceneMgr);
                  Ogre::Entity* pEntity = pSceneMgr->createEntity("OgreHead", "ogrehead.mesh");
                  Ogre::SceneNode* pNode = pSceneMgr->getRootSceneNode()->createChildSceneNode();
                  pNode->attachObject(pEntity);

                  Ogre::Light* pDirLight = pSceneMgr->createLight();
                  pDirLight->setDirection(Ogre::Vector3(0,-1,0));
                  pDirLight->setType(Ogre::Light::LT_DIRECTIONAL);
                  pNode->attachObject(pDirLight);
                  
                  pCamera = pSceneMgr->createCamera("MyCam");
                  pCamera->setNearClipDistance(1.0f);
                  pCamera->setFarClipDistance(100000.0f);
                  pCamera->setPosition(0,0,100.0f);
                  pCamera->lookAt(0,0,0);
                  pCamera->setAutoAspectRatio(true);
      
                  Ogre::Viewport* vp = gRenderWnd->addViewport(pCamera);
                  vp->setBackgroundColour(Ogre::ColourValue(0,0,0));
                  vp->setMaterialScheme(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);   
                  
                  Ogre::RTShader::ShaderGenerator::getSingletonPtr()->invalidateScheme(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);
               }                  
            }
            else
            {
               static_cast<Ogre::AndroidEGLWindow*>(gRenderWnd)->_createInternalResources(nativeWnd, NULL);
            }                        
         }
    }*/
}	
}
#endif /* __ANDROID__ */

/* vi: set ts=4 sw=4 expandtab: */
