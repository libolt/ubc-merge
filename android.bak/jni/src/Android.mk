
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
 
LOCAL_MODULE := UltimateBasketballChallenge

BUILD_ROOT := ../../../..
BTOGRE_PATH := $(BUILD_ROOT)/btogre
BULLET_PATH := $(BUILD_ROOT)bullet4droid
ENET_PATH := $(BUILD_ROOT)/enet 
MYGUI_PATH := $(BUILD_ROOT)/mygui-svn
SDL_PATH := $(BUILD_ROOT)/SDL-2.0.2-8296 
TINYXML_PATH := $(BUILD_ROOT)/tinyxml
OGRE_PATH := ../../../../OgreSDK/Ogre
OGREDEPS_PATH :=../../../../OgreSDK/Dependencies
UBC_ROOT := $(BUILD_ROOT)/ubc2
UBC_SRC_DIR := $(UBC_ROOT)/src/game

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(ENET_PATH)/include/enet
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(BUILD_ROOT)/enet/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(BTOGRE_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(BUILD_ROOT)/bullet4droid/jni/src
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(SDL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/Build
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/Components/RTShaderSystem 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/OgreMain
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/PlugIns/ParticleFX 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/RenderSystems/GLES2
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/RenderSystems/GLES2/EGL
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGREDEPS_PATH)/include/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(MYGUI_PATH)/MyGUIEngine/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(MYGUI_PATH)/Platforms/Ogre/OgrePlatform/include
LOCAL_C_INCLUDES += ../include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_ROOT)/include 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(TINYXML_PATH)
# Add your application source files here...
#LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
#LOCAL_PATH := ../../.. 
#LOCAL_SRC_FILES := \
#	$(subst $(LOCAL_PATH) ,, \
# $(wildcard $(LOCAL_PATH)/src/game/*.cpp)) 

LOCAL_SRC_FILES := ../../../src/game/android.cpp \
#LOCAL_SRC_FILES += ../../../../SDL-2.0.2-8296/src/main/android/SDL_android_main.c \
LOCAL_SRC_FILES += ../../../src/game/basketballs.cpp \
LOCAL_SRC_FILES += ../../../src/game/courtdata.cpp \
LOCAL_SRC_FILES += ../../../src/game/courtstate.cpp \
LOCAL_SRC_FILES += ../../../src/game/defense.cpp \
LOCAL_SRC_FILES += ../../../src/game/defensestate.cpp \
LOCAL_SRC_FILES += ../../../src/game/gameengine.cpp \
LOCAL_SRC_FILES += ../../../src/game/gamestate.cpp \
LOCAL_SRC_FILES += ../../../src/game/gui.cpp \
LOCAL_SRC_FILES += ../../../src/game/input.cpp \
LOCAL_SRC_FILES += ../../../src/game/load.cpp \
LOCAL_SRC_FILES += ../../../src/game/networkengine.cpp \ 
LOCAL_SRC_FILES += ../../../src/game/offense.cpp \
LOCAL_SRC_FILES += ../../../src/game/offensestate.cpp \
LOCAL_SRC_FILES += ../../../src/game/physicsengine.cpp \
LOCAL_SRC_FILES += ../../../src/game/playerdata.cpp \
LOCAL_SRC_FILES += ../../../src/game/players.cpp \
LOCAL_SRC_FILES += ../../../src/game/playerstate.cpp \
LOCAL_SRC_FILES += ../../../src/game/renderengine.cpp \
LOCAL_SRC_FILES += ../../../src/game/soundengine.cpp \
LOCAL_SRC_FILES += ../../../src/game/teamdata.cpp \
LOCAL_SRC_FILES += ../../../src/game/teams.cpp \
LOCAL_SRC_FILES += ../../../src/game/teamstate.cpp \
LOCAL_SRC_FILES += ../../../src/game/ubcapp.cpp 

LOCAL_SHARED_LIBRARIES := 
LOCAL_STATIC_LIBRARIES := BtOgre bullet enet MyGUIEngine MyGUIOgrePlatform tinyxml SDL2_static
LOCAL_LDLIBS	:= -landroid -lc -lm -ldl -llog -lEGL -lGLESv1_CM -lGLESv2
LOCAL_LDLIBS	+= -L../../OgreSDK/Ogre/lib/armeabi -L../../OgreSDK/Dependencies/lib/armeabi
LOCAL_LDLIBS	+= -lRenderSystem_GLES2Static -lOgreRTShaderSystemStatic -lOgreOverlayStatic -lOgreMainStatic 
LOCAL_LDLIBS += -lPlugin_ParticleFXStatic 
LOCAL_LDLIBS	+= -lzzip -lz -lFreeImage -lfreetype -lOIS -lmesa -lglsl_optimizer 
LOCAL_LDLIBS += ../../OgreSDK/Dependencies/lib/armeabi/libsupc++.a ../../OgreSDK/Dependencies/lib/armeabi/libstdc++.a ../$(OGRESAMPLES_PATH)/GLES2/obj/local/armeabi/libcpufeatures.a 

LOCAL_CFLAGS := -fPIC -frtti -fexceptions -x c++ -D___ANDROID___ -DANDROID -DZZIP_OMIT_CONFIG_H

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/cpufeatures) 
$(call import-module,android/native_app_glue) 

