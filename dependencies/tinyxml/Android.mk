LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS) 

BUILD_ROOT := ..

#LOCAL_PATH := $(call my-dir) 

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include


LOCAL_SRC_FILES := \
	$(subst $(LOCAL_PATH)/,, \
	$(wildcard $(LOCAL_PATH)/*.cpp)) 
	
#LOCAL_SHARED_LIBRARIES := libbullet
LOCAL_LDLIBS	:= -landroid -lc -lm -ldl -llog -lEGL -lGLESv2
#LOCAL_LDLIBS	+= -L../$(OGRE_PATH)/lib/armeabi-v7a -L../$(OGREDEPS_PATH)/lib/armeabi-v7a -L$(LOCAL_PATH)/../../ubc/android-project/libs/armeabi 
#LOCAL_LDLIBS	+= -lRenderSystem_GLES2Static -lOgreRTShaderSystemStatic -lOgreOverlayStatic -lOgreMainStatic
#LOCAL_LDLIBS	+= -lzzip -lz -lFreeImage -lfreetype -lOIS -lmesa -lglsl_optimizer 
#LOCAL_LDLIBS += ../$(OGREDEPS_PATH)/lib/armeabi-v7a/libsupc++.a ../$(OGREDEPS_PATH)/lib/armeabi-v7a/libstdc++.a ../$(OGRESAMPLES_PATH)/GLES2/obj/local/armeabi-v7a/libcpufeatures.a

LOCAL_STATIC_LIBRARIES := android_native_app_glue cpufeatures

LOCAL_MODULE := tinyxml 
LOCAL_CFLAGS := -frtti -fexceptions
include $(BUILD_SHARED_LIBRARY) 

include $(CLEAR_VARS) 

#include $(PREBUILD_STATIC_LIBRARY)
