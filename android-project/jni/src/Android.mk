
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
BUILD_ROOT := ../../../..
LOCAL_MODULE := main
 
BTOGRE_PATH := $(BUILD_ROOT)/btogre
BULLET_PATH := $(BUILD_ROOT)bullet4droid
ENET_PATH := $(BUILD_ROOT)/enet 
MYGUI_PATH := $(BUILD_ROOT)/MyGUI_3.2.0
SDL_PATH := $(BUILD_ROOT)/SDL
OGRE_PATH := $(BUILD_ROOT)/OgreSDK/Ogre
OGREDEPS_PATH := $(BUILD_ROOT)/OgreSDK/Dependencies
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

LOCAL_SRC_FILES :=	$(UBC_SRC_DIR)/basketballs.cpp \
 $(UBC_SRC_DIR)/courtdata.cpp \
	$(UBC_SRC_DIR)/courtstate.cpp \
	$(UBC_SRC_DIR)/defense.cpp \
	$(UBC_SRC_DIR)/gameengine.cpp \
	$(UBC_SRC_DIR)/games.cpp \
	$(UBC_SRC_DIR)/gamestate.cpp \
	$(UBC_SRC_DIR)/gui.cpp \
	$(UBC_SRC_DIR)/input.cpp \
	$(UBC_SRC_DIR)/networkengine.cpp \
	$(UBC_SRC_DIR)/offense.cpp \
	$(UBC_SRC_DIR)/physicsengine.cpp \
	$(UBC_SRC_DIR)/playerdata.cpp \
	$(UBC_SRC_DIR)/players.cpp \
	$(UBC_SRC_DIR)/playerstate.cpp \
	$(UBC_SRC_DIR)/renderengine.cpp \
	$(UBC_SRC_DIR)/soundengine.cpp \
	$(UBC_SRC_DIR)/teamdata.cpp \
	$(UBC_SRC_DIR)/teams.cpp \
	$(UBC_SRC_DIR)/teamstate.cpp \
	$(UBC_SRC_DIR)/ubcapp.cpp 

LOCAL_SHARED_LIBRARIES := SDL2 BtOgre 

LOCAL_LDLIBS := -L/extSdCard/AppProjects/OgreSDK/Ogre/lib/armeabi-v7a -L/extSdCard/AppProjects/OgreSDK/Dependencies/lib/armeabi-v7a
LOCAL_LDLIBS += -lRenderSystem_GLES2Static -lOgreMainStatic -lGLESv1_CM -llog
LOCAL_LDLIBS += -lzzip -lz -lFreeImage -lfreetype -lOIS -lmesa
LOCAL_CFLAGS := -frtti -fexceptions

include $(BUILD_SHARED_LIBRARY)
