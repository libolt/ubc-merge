
LOCAL_PATH := $(call my-dir)
UBC_ROOT := $(LOCAL_PATH)/../.. 
include $(CLEAR_VARS) 
include $(call all-subdir-makefiles)

include $(LOCAL_PATH)/../../../bullet4droid/jni/Android.mk
include ../../btogre/Android.mk 
include ../../enet/Android.mk 
include ../../mygui/Android.mk
include ../../SDL2-2.0.0/Android.mk
include ../../ubc/android-project/jni/src/Android.mk