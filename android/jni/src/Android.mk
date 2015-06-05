
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
 
LOCAL_MODULE := UltimateBasketballChallenge

BUILD_ROOT := ../../../..
ALMIXER_PATH = $(BUILD_ROOT)/almixer
BTOGRE_PATH := $(BUILD_ROOT)/btogre
BULLET_PATH := $(BUILD_ROOT)bullet4droid
ENET_PATH := $(BUILD_ROOT)/enet 
MYGUI_PATH := $(BUILD_ROOT)/mygui-svn
SDL_PATH := $(BUILD_ROOT)/SDL2
TINYXML_PATH := $(BUILD_ROOT)/tinyxml
OPENSTEER_PATH := ${BUILD_ROOT}/opensteer
OGRE_PATH := ../../../../OgreSDK/Ogre
OGREDEPS_PATH :=../../../../OgreSDK/Dependencies
OGGVORBIS_PATH := ${BUILD_ROOT}/libvorbislibogg
OPENAL_PATH := ${BUILD_ROOT}/openal-soft
UBC_ROOT := $(BUILD_ROOT)/ubc2
UBC_SRC_DIR := $(UBC_ROOT)/src/game

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(ENET_PATH)/include/enet
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(BUILD_ROOT)/enet/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(BTOGRE_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(BUILD_ROOT)/bullet4droid/jni/src
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(SDL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OPENSTEER_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/Build
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/Components/Overlay
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/Components/RTShaderSystem 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/OgreMain
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/PlugIns/ParticleFX 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/PlugIns/OctreeSceneManager
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/RenderSystems/GLES2
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/RenderSystems/GLES2/EGL
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGREDEPS_PATH)/include/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGGVORBIS_PATH)/jni/include/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OPENAL_PATH)/jni/OpenAL/include/AL
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(MYGUI_PATH)/MyGUIEngine/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(MYGUI_PATH)/Platforms/Ogre/OgrePlatform/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(ALMIXER_PATH)/include
LOCAL_C_INCLUDES += ../include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_ROOT)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(TINYXML_PATH)
# Add your application source files here...
#LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
#LOCAL_PATH := ../../.. 
#LOCAL_SRC_FILES := \
#	$(subst $(LOCAL_PATH) ,, \
# $(wildcard $(LOCAL_PATH)/src/game/*.cpp)) 

LOCAL_SRC_FILES := ../../../src/game/SDL_android_main.c \
LOCAL_SRC_FILES += ../../../src/game/ai/ai.cpp \
LOCAL_SRC_FILES += ../../../src/game/basketballs.cpp \
LOCAL_SRC_FILES += ../../../src/game/ai/basketballsteer.cpp \
LOCAL_SRC_FILES += ../../../src/game/courtdata.cpp \
LOCAL_SRC_FILES += ../../../src/game/courtstate.cpp \
LOCAL_SRC_FILES += ../../../src/game/defensestate.cpp \
LOCAL_SRC_FILES += ../../../src/game/gameengine.cpp \
LOCAL_SRC_FILES += ../../../src/game/gamestate.cpp \
LOCAL_SRC_FILES += ../../../src/game/gui.cpp \
LOCAL_SRC_FILES += ../../../src/game/hoop.cpp \
LOCAL_SRC_FILES += ../../../src/game/input.cpp \
LOCAL_SRC_FILES += ../../../src/game/load.cpp \
LOCAL_SRC_FILES += ../../../src/game/logging.cpp \
LOCAL_SRC_FILES += ../../../src/game/networkengine.cpp \ 
LOCAL_SRC_FILES += ../../../src/game/networkobject.cpp \
LOCAL_SRC_FILES += ../../../src/game/networkgamedataobject.cpp \
LOCAL_SRC_FILES += ../../../src/game/networkgamestateobject.cpp \
LOCAL_SRC_FILES += ../../../src/game/networkplayerdataobject.cpp \
LOCAL_SRC_FILES += ../../../src/game/networkplayerstateobject.cpp \
LOCAL_SRC_FILES += ../../../src/game/networkteamdataobject.cpp \
LOCAL_SRC_FILES += ../../../src/game/networkteamstateobject.cpp \
LOCAL_SRC_FILES += ../../../src/game/offensestate.cpp \
LOCAL_SRC_FILES += ../../../src/game/offenseplays.cpp \
LOCAL_SRC_FILES += ../../../src/game/physicsengine.cpp \
LOCAL_SRC_FILES += ../../../src/game/playerdata.cpp \
LOCAL_SRC_FILES += ../../../src/game/players.cpp \
LOCAL_SRC_FILES += ../../../src/game/playerstate.cpp \
LOCAL_SRC_FILES += ../../../src/game/ai/playersteer.cpp \
LOCAL_SRC_FILES += ../../../src/game/ai/playersteerplugin.cpp \
LOCAL_SRC_FILES += ../../../src/game/renderengine.cpp \
LOCAL_SRC_FILES += ../../../src/game/ai/steering.cpp \
LOCAL_SRC_FILES += ../../../src/game/sound/soundengine.cpp \
LOCAL_SRC_FILES += ../../../src/game/teamdata.cpp \
LOCAL_SRC_FILES += ../../../src/game/teams.cpp \
LOCAL_SRC_FILES += ../../../src/game/teamstate.cpp \
LOCAL_SRC_FILES += ../../../src/game/ubcapp.cpp \
LOCAL_SRC_FILES += ../../../src/game/userinput.cpp 

LOCAL_SHARED_LIBRARIES := SDL2 openal sdl_sound almixer ogg vorbis vorbis-jni
LOCAL_STATIC_LIBRARIES := BtOgre bullet enet MyGUIEngine MyGUIOgrePlatform tinyxml opensteer
#LOCAL_STATIC_LIBRARIES := BtOgre bullet enet MyGUIEngine MyGUIOpenGLESPlatform tinyxml 

LOCAL_LDLIBS	:= -landroid -lc -lm -ldl -llog -lEGL -lGLESv1_CM -lGLESv2
LOCAL_LDLIBS	+= -L../../OgreSDK/Ogre/lib/armeabi -L../../OgreSDK/Dependencies/lib/armeabi
LOCAL_LDLIBS	+= -lRenderSystem_GLES2Static -lOgreRTShaderSystemStatic -lOgreOverlayStatic -lOgreMainStatic -lPlugin_OctreeSceneManagerStatic
LOCAL_LDLIBS += -lPlugin_ParticleFXStatic 
LOCAL_LDLIBS	+= -lzzip -lz -lFreeImage -lfreetype -lOIS -lmesa -lglsl_optimizer 
LOCAL_LDLIBS += ../../OgreSDK/Dependencies/lib/armeabi/libsupc++.a ../../OgreSDK/Dependencies/lib/armeabi/libstdc++.a ../$(OGRESAMPLES_PATH)/GLES2/obj/local/armeabi/libcpufeatures.a 

LOCAL_CFLAGS := -w -fPIC -frtti -fexceptions -fpermissive -x c++ -D___ANDROID___ -DANDROID -DZZIP_OMIT_CONFIG_H -std=c++11

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/cpufeatures) 
$(call import-module,android/native_app_glue) 

