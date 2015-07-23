LOCAL_PATH := $(call my-dir)
BUILD_ROOT := ../../..
UBC_DEPENDS_PATH := $(BUILD_ROOT)/ubc-depends
UBC_DEPENDS_LIB_PATH := $(UBC_DEPENDS_PATH)/lib
UBC_DEPENDS_INC_PATH := $(UBC_DEPENDS_PATH)/include

   include $(CLEAR_VARS)
   LOCAL_MODULE := ALMixer-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libalmixer.so
   include $(PREBUILT_SHARED_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := OpenAL-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libopenal.so
   include $(PREBUILT_SHARED_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := OGG-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libogg.so
   include $(PREBUILT_SHARED_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := Vorbis-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libvorbis.so
   include $(PREBUILT_SHARED_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := Vorbis-JNI-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libvorbis-jni.so
   include $(PREBUILT_SHARED_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := SDL2-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libSDL2.so
   include $(PREBUILT_SHARED_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := Boost-Atomic-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libboost_atomic-gcc-mt-s-1_58.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := Boost-Chrono-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libboost_chrono-gcc-mt-s-1_58.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := Boost-System-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libboost_system-gcc-mt-s-1_58.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := Boost-Thread-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libboost_thread_pthread-gcc-mt-s-1_58.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := OgreMain-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libOgreMainStatic.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := OgreOverlay-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libOgreOverlayStatic.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := OgreProperty-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libOgrePropertyStatic.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := OgreRTShaderSystem-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libOgreRTShaderSystemStatic.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := OgreParticleFXplugin-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/OGRE/libPlugin_ParticleFXStatic.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := OgreRenderSystem_GLES2-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/OGRE/libRenderSystem_GLES2Static.a
   include $(PREBUILT_STATIC_LIBRARY)
   
   include $(CLEAR_VARS)
   LOCAL_MODULE := BtOgre-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libBtOgre.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletCollision-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libBulletCollision.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletDynamics-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libBulletDynamics.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletFileLoader-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libBulletFileLoader.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletSoftbody-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libBulletSoftBody.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletWorldImporter-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libBulletWorldImporter.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletXmlWorldImporter-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libBulletXmlWorldImporter.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletConvexDecomposition-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libConvexDecomposition.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletGIMPACTUtils-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libGIMPACTUtils.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletHACD-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libHACD.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := BulletLinearMath-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libLinearMath.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := ENet-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libenet.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := FreeImage-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libFreeImage.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := FreeType-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libfreetype.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := MyGUIEngine-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libMyGUIEngine.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := MyGUIOgrePlatform-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libMyGUIOgrePlatform.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := MyGUIOpenGLESPlatform-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libMyGUIOpenGLESPlatform.a
   include $(PREBUILT_STATIC_LIBRARY)
   
   include $(CLEAR_VARS)
   LOCAL_MODULE := OpenSteer-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libopensteer.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := SDL_Sound-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libsdl_sound.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := TinyXML-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libtinyxml.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := ZLib-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libzlib.a
   include $(PREBUILT_STATIC_LIBRARY)

   include $(CLEAR_VARS)
   LOCAL_MODULE := ZZipLib-Prebuilt
   LOCAL_SRC_FILES := $(UBC_DEPENDS_LIB_PATH)/libzziplib.a
   include $(PREBUILT_STATIC_LIBRARY)

#LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES  := ALMixer-Prebuilt OpeanAL-Prebuilt OGG-Prebuilt Vorbis-Prebuilt  SDL2-Prebuilt 
LOCAL_STATIC_LIBRARIES  := Boost-System-Prebuilt MyGUIOgrePlatform-Prebuilt MyGUIEngine-Prebuilt TinyXML-Prebuilt  BtOgre-Prebuilt BulletDynamics-Prebuilt BulletCollision-Prebuilt BulletSoftbody-Prebuilt BulletLinearMath-Prebuilt OgreRTShaderSystem-Prebuilt OgreRenderSystem_GLES2-Prebuilt OgreMain-Prebuilt OgreParticleFXPlugin-Prebuilt OpenSteer-Prebuilt Boost-Thread-Prebuilt FreeImage-Prebuilt ZZipLib-Prebuilt FreeType-Prebuilt ENet-Prebuilt
 # BtOgre-Prebuilt  BulletCollision-Prebuilt BulletDynamics-Prebuilt BulletSoftbody-Prebuilt BulletLinearMath-Prebuilt Boost-Atomic-Prebuilt Boost-Chrono-Prebuilt Boost-System-Prebuilt Boost-Thread-Prebuilt
#LOCAL_SHARED_LIBRARIES  += OgreMain-Prebuilt OgreOverlay-Prebuilt OgreProperty-Prebuilt OgreRTShaderSystem-Prebuilt OgreRenderSystem_GLES2-Prebuilt
#LOCAl_STATIC_LIBRARIES  += 
#LOCAL_SHARED_LIBRARIES  += FreeImage-Prebuilt FreeType-Prebuilt 
#LOCAL_SHARED_LIBRARIES  += MyGUIEngine-Prebuilt MyGUIOgrePlatform-Prebuilt
#LOCAL_SHARED_LIBRARIES  += OpenSteer-Prebuilt SDL_Sound-Prebuilt TinyXML-Prebuilt ZLib-Prebuilt ZZipLib-Prebuilt
LOCAL_STATIC_LIBRARIES  +=  android_native_app_glue cpufeatures  gnustl_static supc++
 
LOCAL_MODULE := UltimateBasketballChallenge

#ALMIXER_PATH = $(BUILD_ROOT)/almixer
#BTOGRE_PATH := $(BUILD_ROOT)/btogre
#BULLET_PATH := $(BUILD_ROOT)bullet4droid
#ENET_PATH := $(BUILD_ROOT)/enet 
#MYGUI_PATH := $(BUILD_ROOT)/mygui-svn
#SDL_PATH := $(BUILD_ROOT)/SDL2
#TINYXML_PATH := $(BUILD_ROOT)/tinyxml
#OPENSTEER_PATH := ${BUILD_ROOT}/opensteer
#OGRE_PATH := ../../../../OgreSDK/Ogre
#OGREDEPS_PATH :=../../../../OgreSDK/Dependencies
#OGGVORBIS_PATH := ${BUILD_ROOT}/libvorbislibogg
#OPENAL_PATH := ${BUILD_ROOT}/openal-soft

UBC_ROOT := $(BUILD_ROOT)/ubc2
UBC_SRC_DIR := $(UBC_ROOT)/src/game

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/bullet
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/enet
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/SDL2
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/boost-1_58
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/OGRE
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/OGRE/Overlay
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/OGRE/RTShaderSystem 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/OGRE/PlugIns/ParticleFX 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/OGRE/PlugIns/OctreeSceneManager
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/OGRE/RenderSystems/GLES2
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/OGRE/RenderSystems/GLES2/EGL
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/AL
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_DEPENDS_PATH)/include/MYGUI
#LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(MYGUI_PATH)/Platforms/Ogre/OgrePlatform/include
#LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(ALMIXER_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../include
#LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_ROOT)/include
#LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(TINYXML_PATH)
# Add your application source files here...
#LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
#LOCAL_PATH := ../../.. 
LOCAL_SRC_FILES := \
                   $(subst $(LOCAL_PATH)/,, \
                       $(wildcard $(LOCAL_PATH)/../../src/game/*.cpp)) \
                   $(subst $(LOCAL_PATH)/,, \
                       $(wildcard $(LOCAL_PATH)/../../src/game/*.c)) \
                   $(subst $(LOCAL_PATH)/,, \
                       $(wildcard $(LOCAL_PATH)/../../src/game/ai/*.cpp)) \
                   $(subst $(LOCAL_PATH)/,, \
                       $(wildcard $(LOCAL_PATH)/../../src/game/gui/*.cpp)) \
                   $(subst $(LOCAL_PATH)/,, \
                       $(wildcard $(LOCAL_PATH)/../../src/game/network/*.cpp)) \
                   $(subst $(LOCAL_PATH)/,, \
                       $(wildcard $(LOCAL_PATH)/../../src/game/sound/*.cpp)) \


#LOCAL_SRC_FILES := ../../src/game/SDL_android_main.c \
#LOCAL_SRC_FILES += ../../src/game/ai/basketballsteer.cpp \
#LOCAL_SRC_FILES += ../../src/game/courtdata.cpp \
#LOCAL_SRC_FILES += ../../src/game/courtstate.cpp \
#LOCAL_SRC_FILES += ../../src/game/defensestate.cpp \
#LOCAL_SRC_FILES += ../../src/game/gameengine.cpp \
#LOCAL_SRC_FILES += ../../src/game/gamestate.cpp \
#LOCAL_SRC_FILES += ../../src/game/gui.cpp \
#LOCAL_SRC_FILES += ../../src/game/hoop.cpp \
#LOCAL_SRC_FILES += ../../src/game/input.cpp \
#LOCAL_SRC_FILES += ../../src/game/load.cpp \
#LOCAL_SRC_FILES += ../../src/game/logging.cpp \
#LOCAL_SRC_FILES += ../../src/game/networkengine.cpp \ 
#LOCAL_SRC_FILES += ../../src/game/networkobject.cpp \
#LOCAL_SRC_FILES += ../../src/game/networkgamedataobject.cpp \
#LOCAL_SRC_FILES += ../../src/game/networkgamestateobject.cpp \
#LOCAL_SRC_FILES += ../../src/game/networkplayerdataobject.cpp \
#LOCAL_SRC_FILES += ../../src/game/networkplayerstateobject.cpp \
#LOCAL_SRC_FILES += ../../src/game/networkteamdataobject.cpp \
#LOCAL_SRC_FILES += ../../src/game/networkteamstateobject.cpp \
#LOCAL_SRC_FILES += ../../src/game/offensestate.cpp \
#LOCAL_SRC_FILES += ../../src/game/offenseplays.cpp \
#LOCAL_SRC_FILES += ../../src/game/physicsengine.cpp \
#LOCAL_SRC_FILES += ../../src/game/playerdata.cpp \
#LOCAL_SRC_FILES += ../../src/game/players.cpp \
#LOCAL_SRC_FILES += ../../src/game/playerstate.cpp \
#LOCAL_SRC_FILES += ../../src/game/ai/playersteer.cpp \
#LOCAL_SRC_FILES += ../../src/game/ai/playersteerplugin.cpp \
#LOCAL_SRC_FILES += ../../src/game/renderengine.cpp \
#LOCAL_SRC_FILES += ../../src/game/ai/steering.cpp \
#LOCAL_SRC_FILES += ../../src/game/sound/soundengine.cpp \
#LOCAL_SRC_FILES += ../../src/game/teamdata.cpp \
#LOCAL_SRC_FILES += ../../src/game/teams.cpp \
#LOCAL_SRC_FILES += ../../src/game/teamstate.cpp \
#LOCAL_SRC_FILES += ../../src/game/ubcapp.cpp \
#LOCAL_SRC_FILES += ../../src/game/userinput.cpp 


LOCAL_LDLIBS	:= -landroid -lc -lm -ldl -llog -lEGL -lGLESv1_CM -lGLESv2

LOCAL_CFLAGS := -w -fPIC -frtti -fexceptions -fpermissive -x c++ -D___ANDROID___ -DANDROID -DZZIP_OMIT_CONFIG_H -std=c++11  $(COMMON_FLAGS_LIST) 
#LOCAL_CPPFLAGS :=  $(COMMON_FLAGS_LIST) -DOGRE_NO_GLES3_SUPPORT=1
include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/cpufeatures) 
$(call import-module,android/native_app_glue) 
$(CALL IMPORT-MODULE,ENet-Prebuilt)
