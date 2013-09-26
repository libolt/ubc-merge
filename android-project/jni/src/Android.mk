
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
BUILD_ROOT := ../../../.. 
LOCAL_MODULE := main
 
BTOGRE_PATH := $(BUILD_ROOT)/btogre
BULLET_PATH := $(BUILD_ROOT)bullet4droid
ENET_PATH := $(BUILD_ROOT)/enet 
MYGUI_PATH := $(BUILD_ROOT)/mygui
SDL_PATH := $(BUILD_ROOT)/SDL2-2.0.0 
OGRE_PATH := ../../OgreSDK/Ogre
OGREDEPS_PATH := ../../OgreSDK/Dependencies
OGRESAMPLES_PATH := ../../OgreSDK/Samples
UBC_ROOT := $(BUILD_ROOT)/ubc
UBC_SRC_DIR := $(UBC_ROOT)/src/game

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(ENET_PATH)/include/enet
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(BUILD_ROOT)/enet/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(BTOGRE_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(BUILD_ROOT)/bullet4droid/jni/src
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(SDL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/Build
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/OgreMain
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGREDEPS_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(MYGUI_PATH)/MyGUIEngine/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(MYGUI_PATH)/Platforms/Ogre/OgrePlatform/include

LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_ROOT)/include 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_ROOT)/dependencies/tinyxml
# Add your application source files here...
#LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \

LOCAL_SRC_FILES := \
	$(subst $(LOCAL_PATH)/,, \
	$(wildcard $(LOCAL_PATH)/src/game/*.cpp)) 

LOCAL_SHARED_LIBRARIES := BtOgre bullet enet MyGUIEngine MyGUI.OgrePlatform SDL2 

LOCAL_LDLIBS	:= -landroid -lc -lm -ldl -llog -lEGL -lGLESv2
LOCAL_LDLIBS	+= -L$(OGRE_PATH)/lib/armeabi-v7a -L$(OGREDEPS_PATH)/lib/armeabi-v7a 
LOCAL_LDLIBS	+= -lRenderSystem_GLES2Static -lOgreRTShaderSystemStatic -lOgreOverlayStatic -lOgreMainStatic
LOCAL_LDLIBS	+= -lzzip -lz -lFreeImage -lfreetype -lOIS -lmesa -lglsl_optimizer 
LOCAL_LDLIBS += $(OGREDEPS_PATH)/lib/armeabi-v7a/libsupc++.a $(OGREDEPS_PATH)/lib/armeabi-v7a/libstdc++.a $(OGRESAMPLES_PATH)/GLES2/obj/local/armeabi-v7a/libcpufeatures.a 

LOCAL_CFLAGS := -frtti -fexceptions

include $(BUILD_SHARED_LIBRARY)
