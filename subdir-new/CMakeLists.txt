cmake_minimum_required(VERSION 2.6)
PROJECT (UBC)
#INCLUDE(${CMAKE_MODULE_PATH}/FindBoost.cmake)
SET(CMAKE_MODULE_PATH "${UBC_SOURCE_DIR}/cmake")
set(Boost_USE_MULTITHREADED ON)

IF (WIN32)
    IF(MSVC)
        # Deactivate warning C4251
        SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4251 /wd4275" )
    ENDIF()
ENDIF (WIN32)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Debug' as none was specified.")
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()

INCLUDE (FindENet)
INCLUDE (FindFreeImage)
INCLUDE (FindOGRE)
INCLUDE (FindSDL2)
INCLUDE (FindMyGUI)
INCLUDE (FindBulletlibs)
INCLUDE (FindBtOgre)
INCLUDE (FindTinyXML2)
INCLUDE (FindOpenSteer)
INCLUDE (FindOpenAL)
#INCLUDE (FindOggVorbis)
Include (FindALMixer)
find_package(Boost COMPONENTS chrono date_time program_options filesystem system thread REQUIRED)
find_package(Threads REQUIRED)

SET (UBC_DEPENDENCIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependencies)
SET (UBC_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET (UBC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
SET (UBC_DATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/data)


FILE(GLOB_RECURSE UBC_HEADERS include/*.h)
FILE(GLOB_RECURSE UBC_SRCS src/game/*.cpp)

ADD_SUBDIRECTORY (include)

INCLUDE_DIRECTORIES(${UBC_INCLUDE_DIR} ${ENet_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS} ${FreeImage_INCLUDE_DIR} ${OGRE_INCLUDE_DIRS} ${SDL2_INCLUDE_DIR} ${MYGUI_INCLUDE_DIRS} ${MYGUI_PLATFORM_INCLUDE_DIRS} ${BULLET_INCLUDE_DIRS} ${BtOgre_INCLUDE_DIRS} ${TinyXML2_INCLUDE_DIRS} ${OpenSteer_INCLUDE_DIRS} ${OPENAL_INCLUDE_DIR} ${ALMIXER_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})


LINK_DIRECTORIES(${ENET_LIBDIR} ${Boost_LIBRARY_DIRS} ${OGRE_LIBRARY_DIRS} ${OGRE_DEPENDLIBDIR} ${MYGUI_LIB_DIR} ${BULLET_LIBRARY_DIRS} ${BtOgre_LIBRARY_DIRS} ${TinyXML2_LIB_DIRS} ${OpenSteer_LIBRARY_DIRS} ${Boost_LIBRARY_DIRS})

IF (CMAKE_BUILD_TYPE MATCHES "Debug")
    SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/debug")
ELSEIF (CMAKE_BUILD_TYPE MATCHES "Release")
    SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/release")
ELSEIF (CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
    SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/relwithdebinfo")
ENDIF (CMAKE_BUILD_TYPE MATCHES "Debug")


IF (WIN32)
    ADD_EXECUTABLE(ubc WIN32 ${UBC_SRCS} ${UBC_HEADERS})
    TARGET_LINK_LIBRARIES(ubc ${Boost_LIBRARIES} ${ENet_LIBRARIES} ${TinyXML2_LIBRARIES} ${OpenSteer_LIBRARY} ${BtOgre_LIBRARIES} ${BULLET_LIBRARIES} ${SDL2_LIBRARY} ${MYGUI_PLATFORM_LIBRARIES} ${MYGUI_LIBRARIES} ${FreeImage_LIBRARY} ${OGRE_LIBRARIES} ${OPENAL_LIBRARY} ${ALMIXER_LIBRARY} ${Boost_LIBRARIES} version.lib imm32.lib)

ELSEIF (APPLE)
    INCLUDE_DIRECTORIES (../include ../src/tinyxml ../Dependencies/include)
    LINK_DIRECTORIES(../src/tinyxml ../Dependencies/lib/Debug)
    FIND_LIBRARY(OGRE_LIB Ogre)
    MARK_AS_ADVANCED(OGRE_LIB)
    FIND_LIBRARY(CG_LIB Cg)
    MARK_AS_ADVANCED(CG_LIB)
    FIND_LIBRARY(CARBON_LIB Carbon)
    MARK_AS_ADVANCED(CARBON_LIB)
    ADD_EXECUTABLE (ubc ${UBC_SRCS})
    TARGET_LINK_LIBRARIES( ubc tinyxml ${OGRE_LIB} ${CG_LIB} ${CARBON_LIB})
ELSE (APPLE)
    ADD_CUSTOM_COMMAND(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/config.h
        COMMAND ${CMAKE_COMMAND} -E  echo ${OGRE_PLUGINDIR} >>  ${CMAKE_CURRENT_SOURCE_DIR}/src/config.h
    )

    ADD_EXECUTABLE(ubc ${UBC_SRCS} ${UBC_HEADERS})
    TARGET_LINK_LIBRARIES(ubc ${Boost_LIBRARIES} ${ENet_LIBRARIES} ${TinyXML2_LIBRARIES} ${OpenSteer_LIBRARY} ${BtOgre_LIBRARIES} ${BULLET_LIBRARIES} ${SDL2_LIBRARY} ${MYGUI_PLATFORM_LIBRARIES} ${MYGUI_LIBRARIES} ${FreeImage_LIBRARY} ${OGRE_LIBRARIES} ${OPENAL_LIBRARY} ${ALMIXER_LIBRARY})
ENDIF (WIN32)
