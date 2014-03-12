
LOCAL_PATH := $(call my-dir)
UBC_ROOT := $(LOCAL_PATH)/../.. 
include $(CLEAR_VARS) 
include $(call all-subdir-makefiles)

include $(LOCAL_PATH)/bullet4droid/jni/Android.mk
include $(LOCAL_PATH)/../../btogre/Android.mk 
include $(LOCAL_PATH)/../enet/Android.mk 
include $(LOCAL_PATH)/../mygui-svn/Android.mk
include $(LOCAL_PATH)/../SDL2/Android.mk
include $(LOCAL_PATH)/../tinyxml/Android.mk 
include $(LOCAL_PATH)/../src/Android.mk
