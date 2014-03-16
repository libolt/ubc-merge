
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



#include <jni.h>
#include <EGL/egl.h>
#include <android/api-level.h>
#include <android/native_window_jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include "OgrePlatform.h"
#include "OgreRoot.h"
#include "OgreRenderWindow.h"
#include "OgreArchiveManager.h"
#include "Android/OgreAndroidEGLWindow.h"
#include "Android/OgreAPKFileSystemArchive.h"
#include "Android/OgreAPKZipArchive.h"

#undef OGRE_BUILD_PLUGIN_OCTREE
#undef OGRE_BUILD_COMPONENT_OVERLAY
/*
#ifdef OGRE_BUILD_PLUGIN_OCTREE
#   include "OgreOctreePlugin.h"
#endif
*/
#ifdef OGRE_BUILD_PLUGIN_PFX
#   include "OgreParticleFXPlugin.h"
#endif

/*
#ifdef OGRE_BUILD_COMPONENT_OVERLAY
#   include "OgreOverlaySystem.h"
#endif
*/
#include "OgreConfigFile.h"

#ifdef OGRE_BUILD_RENDERSYSTEM_GLES2
#   include "OgreGLES2Plugin.h"
#   define GLESRS GLES2Plugin
#else
#   include "OgreGLESPlugin.h"
#   define GLESRS GLESPlugin
#endif

#include "OgreRTShaderSystem.h"
#include "OgreEntity.h"

using namespace Ogre;

class ShaderGeneratorTechniqueResolverListener : public Ogre::MaterialManager::Listener
{
public:
   Ogre::Technique* handleSchemeNotFound( unsigned short schemeIndex, const Ogre::String& schemeName, Ogre::Material* originalMaterial, unsigned short lodIndex, const Ogre::Renderable* rend )
   {
      Ogre::Technique* generatedTech = NULL;

      // Case this is the default shader generator scheme.
      if (schemeName == Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME)
      {
         bool techniqueCreated;

         // Create shader generated technique for this material.
         techniqueCreated = Ogre::RTShader::ShaderGenerator::getSingletonPtr()->createShaderBasedTechnique(
            originalMaterial->getName(), 
            Ogre::MaterialManager::DEFAULT_SCHEME_NAME, 
            schemeName);   

         // Case technique registration succeeded.
         if (techniqueCreated)
         {
            // Force creating the shaders for the generated technique.
            Ogre::RTShader::ShaderGenerator::getSingletonPtr()->validateMaterial(schemeName, originalMaterial->getName());

            // Grab the generated technique.
            Ogre::Material::TechniqueIterator itTech = originalMaterial->getTechniqueIterator();

            while (itTech.hasMoreElements())
            {
               Ogre::Technique* curTech = itTech.getNext();

               if (curTech->getSchemeName() == schemeName)
               {
                  generatedTech = curTech;
                  break;
               }
            }            
         }
      }

      return generatedTech;
   }
};

static ShaderGeneratorTechniqueResolverListener* gMatListener = NULL;

static bool gInit = false;
static Ogre::Root* gRoot = NULL;
static Ogre::RenderWindow* gRenderWnd = NULL;

#ifdef OGRE_BUILD_PLUGIN_OCTREE
static Ogre::OctreePlugin* gOctreePlugin = NULL;
#endif

#ifdef OGRE_BUILD_PLUGIN_PFX
static Ogre::ParticleFXPlugin* gParticleFXPlugin = NULL;
#endif

#ifdef OGRE_BUILD_COMPONENT_OVERLAY
static Ogre::OverlaySystem* gOverlaySystem = NULL; 
#endif

static Ogre::GLESRS* gGLESPlugin = NULL;

static Ogre::SceneManager* pSceneMgr = NULL;
static Ogre::Camera* pCamera = NULL;
static JavaVM* gVM = NULL;

AAssetManager* gAssetMgr = NULL;

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

extern "C" 
{
   JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) 
   {
      gVM = vm;
      return JNI_VERSION_1_4;
   }

//   JNIEXPORT void JNICALL    Java_org_ogre3d_android_OgreActivityJNI_create(JNIEnv * env, jobject obj, jobject assetManager)
   JNIEXPORT void JNICALL    Java_com_libolt_ubc_UBCActivity_create(JNIEnv * env, jobject obj, jobject assetManager)
   {
        if(gInit)
         return;
         
        gRoot = new Ogre::Root();

      gGLESPlugin = OGRE_NEW GLESRS();
      gRoot->installPlugin(gGLESPlugin);
         
#ifdef OGRE_BUILD_PLUGIN_OCTREE
      gOctreePlugin = OGRE_NEW OctreePlugin();
      gRoot->installPlugin(gOctreePlugin);
#endif
         
#ifdef OGRE_BUILD_PLUGIN_PFX
      gParticleFXPlugin = OGRE_NEW ParticleFXPlugin();
      gRoot->installPlugin(gParticleFXPlugin);
#endif

#ifdef OGRE_BUILD_COMPONENT_OVERLAY
      gOverlaySystem = OGRE_NEW OverlaySystem(); 
#endif
      
      gRoot->setRenderSystem(gRoot->getAvailableRenderers().at(0));
        gRoot->initialise(false);
        gInit = true;
      
      gAssetMgr = AAssetManager_fromJava(env, assetManager);
      if (gAssetMgr) 
      {
         ArchiveManager::getSingleton().addArchiveFactory( new APKFileSystemArchiveFactory(gAssetMgr) );
         ArchiveManager::getSingleton().addArchiveFactory( new APKZipArchiveFactory(gAssetMgr) );
      }
   }
   
   JNIEXPORT void JNICALL Java_com_libolt_ubc_UBCActivity_destroy(JNIEnv * env, jobject obj)
   {
      if(!gInit)
         return;
                
        gInit = false;
                
#ifdef OGRE_BUILD_COMPONENT_OVERLAY
      OGRE_DELETE gOverlaySystem; 
      gOverlaySystem = NULL;
#endif

        OGRE_DELETE gRoot;
        gRoot = NULL;
        gRenderWnd = NULL;

#ifdef OGRE_BUILD_PLUGIN_PFX
      OGRE_DELETE gParticleFXPlugin;
      gParticleFXPlugin = NULL;
#endif

#ifdef OGRE_BUILD_PLUGIN_OCTREE
      OGRE_DELETE gOctreePlugin;
      gOctreePlugin = NULL;
#endif

      OGRE_DELETE gGLESPlugin;
      gGLESPlugin = NULL;
   }
   

    JNIEXPORT void JNICALL Java_com_libolt_ubc_UBCActivity_initWindow(JNIEnv * env, jobject obj,  jobject surface)
   {
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
                  Ogre::Entity* pEntity = pSceneMgr->createEntity("OgreHead", "Court.mesh");
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
      }
   }
   
    JNIEXPORT void JNICALL Java_com_libolt_ubc_UBCActivity_termWindow(JNIEnv * env, jobject obj)
   {
      if(gRoot && gRenderWnd)
      {
         static_cast<Ogre::AndroidEGLWindow*>(gRenderWnd)->_destroyInternalResources();
      }
   }
   
   JNIEXPORT void JNICALL Java_com_libolt_ubc_UBCActivity_renderOneFrame(JNIEnv * env, jobject obj)
   {
      if(gRenderWnd != NULL && gRenderWnd->isActive())
      {
         try
         {
            if(gVM->AttachCurrentThread(&env, NULL) < 0)                
               return;
            
            gRenderWnd->windowMovedOrResized();
            gRoot->renderOneFrame();
            
            //gVM->DetachCurrentThread();            
         }catch(Ogre::RenderingAPIException ex) {}
      }
   }
};

#endif /* __ANDROID__ */

/* vi: set ts=4 sw=4 expandtab: */
