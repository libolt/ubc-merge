cmake_minimum_required(VERSION 2.6)
PROJECT (UBC)
#INCLUDE(${CMAKE_MODULE_PATH}/FindBoost.cmake)
SET(CMAKE_MODULE_PATH "${UBC_SOURCE_DIR}/cmake")
#SET(BOOST_ROOT "c:\users\libolt\builds\boost-mingw\boost")
set(Boost_USE_MULTITHREADED OFF)

IF (WIN32)
if( MSVC )
 # Deactivate warning C4251
 set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4251 /wd4275" )

endif()
ENDIF (WIN32)
    INCLUDE (FindBoost)
    INCLUDE (FindENet)
    INCLUDE (FindOGRE)
    INCLUDE (FindOIS)
    INCLUDE (FindMyGUI)
    find_package(Boost COMPONENTS date_time program_options filesystem system REQUIRED)
    find_package(Threads REQUIRED)
#    MESSAGE("ENET_INCLUDE_DIR = ${ENET_INCLUDE_DIR}")
#    MESSAGE ("ENET_LIBRARIES = ${ENET_LIBRARIES}")

    SET (UBC_DEPENDENCIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependencies)
    SET (UBC_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
    SET (UBC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
    SET (UBC_SRCS ${UBC_SRC_DIR}/basketballs.cpp ${UBC_SRC_DIR}/courtdata.cpp ${UBC_SRC_DIR}/courtstate.cpp ${UBC_SRC_DIR}/defense.cpp ${UBC_SRC_DIR}/games.cpp ${UBC_SRC_DIR}/gamestate.cpp ${UBC_SRC_DIR}/gui.cpp ${UBC_SRC_DIR}/input.cpp ${UBC_SRC_DIR}/load.cpp ${UBC_SRC_DIR}/network.cpp ${UBC_SRC_DIR}/offense.cpp ${UBC_SRC_DIR}/physics.cpp ${UBC_SRC_DIR}/playerdata.cpp ${UBC_SRC_DIR}/players.cpp ${UBC_SRC_DIR}/playerstate.cpp ${UBC_SRC_DIR}/rendersystems.cpp ${UBC_SRC_DIR}/sound.cpp ${UBC_SRC_DIR}/teamdata.cpp ${UBC_SRC_DIR}/teams.cpp ${UBC_SRC_DIR}/teamstate.cpp ${UBC_SRC_DIR}/ubcapp.cpp)
    
    SET (CLIENT_SRCS ${UBC_SRC_DIR}/client.cpp)
    SET (SERVER_SRCS ${UBC_SRC_DIR}/server.cpp)
    SET (UBC_DATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/data)

    file(GLOB_RECURSE UBC_HEADERS include/*.h)
#    file(GLOB_RECURSE UBC_SRCS src/*.cpp)

    ADD_SUBDIRECtory (dependencies)
    ADD_SUBDIRECTORY (include)
#    ADD_SUBDIRECTORY (src)

IF (CMAKE_BUILD_TYPE MATCHES "Debug")
    ADD_SUBDIRECTORY (debug)
ELSEIF (CMAKE_BUILD_TYPE MATCHES "Release")
    ADD_SUBDIRECTORY (release)
ENDIF (CMAKE_BUILD_TYPE MATCHES "Debug")


