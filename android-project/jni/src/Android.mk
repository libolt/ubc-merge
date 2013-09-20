
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../../../../SDL
OGRE_PATH :=../../../../OgreSDK/Ogre
UBC_ROOT := ../../..
UBC_SRC_DIR := $(UBC_ROOT)/src/game

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/Build
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/OgreMain
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_ROOT)/include 

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
	$(UBC_SRC_DIR)/basketballs.cpp

LOCAL_SHARED_LIBRARIES := SDL2

LOCAL_LDLIBS := -lGLESv1_CM -llog

include $(BUILD_SHARED_LIBRARY)
