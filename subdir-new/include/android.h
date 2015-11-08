//#include "RTShaderHelper.h"

#define OGRE_STATIC_GLES2
//#define OGRE_STATIC_ParticleFX
//#define OGRE_STATIC_OctreeSceneManager
#include "OgreStaticPluginLoader.h"

#include <EGL/egl.h>
#include <android/log.h>
//#include <android_native_app_glue.h>

#include "Ogre.h"
#include "OgreRenderWindow.h"
#include "OgreStringConverter.h"
#include "RTShaderHelper.h"
#include "Android/OgreAndroidEGLWindow.h"
#include "Android/OgreAPKFileSystemArchive.h"
#include "Android/OgreAPKZipArchive.h"


//static Ogre::RenderWindow* gRenderWnd = NULL;
//static Ogre::Root* gRoot = NULL;
static Ogre::StaticPluginLoader* gStaticPluginLoader = NULL;
//static AAssetManager* gAssetMgr = NULL; 
//static Ogre::SceneManager* gSceneMgr = NULL;
static Ogre::ShaderGeneratorTechniqueResolverListener* gMatListener = NULL;

//static int32_t handleInput(struct android_app* app, AInputEvent* event);

//static void handleCmd(struct android_app* app, int32_t cmd);

