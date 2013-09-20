
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

MYGUI_PATH := ../../../../MyGUI_3.2.0
SDL_PATH := ../../../../SDL
OGRE_PATH := ../../../../OgreSDK/Ogre
OGREDEPS_PATH := ../../../../OgreSDK/Dependencies
UBC_ROOT := ../../..
UBC_SRC_DIR := $(UBC_ROOT)/src/game

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/Build
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGRE_PATH)/include/OgreMain
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGREDEPS_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(MYGUI_PATH)/MyGUIEngine/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(MYGUI_PATH)/Platforms/Ogre/OgrePlatform/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_ROOT)/include 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(UBC_ROOT)/dependencies/tinyxml
# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
	$(UBC_SRC_DIR)/basketballs.cpp \
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
	$(UBC_SRC_DIR)/so undergone.cpp \
	$(UBC_SRC_DIR)/teamdata.cpp \
	$(UBC_SRC_DIR)/teams.cpp \
	$(UBC_SRC_DIR)/teamstate.cpp \
	$(UBC_SRC_DIR)/ubcapp.cpp 

LOCAL_SHARED_LIBRARIES := SDL2

LOCAL_LDLIBS := -lGLESv1_CM -llog

include $(BUILD_SHARED_LIBRARY)
