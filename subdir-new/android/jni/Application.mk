
# Uncomment this if you're using STL in your project
# See CPLUSPLUS-SUPPORT.html in the NDK documentation for more information
APP_STL := gnustl_static
APP_ABI := armeabi-v7a 
APP_CFLAGS := -fno-lto
APP_CPPFLAGS := -fno-lto
APP_LDFLAGS := -fno-lto

APP_PLATFORM := android-14
NDK_TOOLCHAIN_VERSION := 4.9
LIBCXX_USE_GABIXX:=true
