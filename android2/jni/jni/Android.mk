
LOCAL_PATH := $(call my-dir)
UBC_ROOT := $(LOCAL_PATH)/../.. 
include $(CLEAR_VARS) 
include $(call all-subdir-makefiles)

include $(LOCAL_PATH)/../../../bullet4droid/jni/Android.mk
include ../../btogre/Android.mk 
include ../../enet/Android.mk 
include ../../mygui-svn/Android.mk
include ../../SDL-2.0.2-8296/Android.mk
include ../../tinyxml/Android.mk 
include $(LOCAL_PATH)/../ubc/android/jni/src/Android.mk
