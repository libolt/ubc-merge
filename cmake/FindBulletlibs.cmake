# - Try to find enet
# Once done this will define
#
# BULLLET_FOUND - system has enet
# BULLET_INCLUDE_DIRS - the enet include directory
# BULLET_LIBRARIES - the libraries needed to use enet
#
# $BULLET_HOME is an environment variable used for finding enet.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <

FIND_PATH(BULLET_INCLUDE_DIRS Bullet-C-Api.h
    PATHS
    $ENV{BULLET_HOME}/include
    /usr/local
    /usr
    PATH_SUFFIXES bullet
    )

FIND_LIBRARY(BULLETDYNAMICS_LIBRARY
    NAMES libBulletDynamics.a
    PATHS
    $ENV{BULLET_HOME}
    /usr/local
    /usr
    PATH_SUFFIXES lib
    )

FIND_LIBRARY(BULLETCOLLISION_LIBRARY
    NAMES libBulletCollision.a
    PATHS
    $ENV{BULLET_HOME}
    /usr/local
    /usr
    PATH_SUFFIXES lib
    )

FIND_LIBRARY(BULLETLINEARMATH_LIBRARY
    NAMES libLinearMath.a
    PATHS
    $ENV{BULLET_HOME}
    /usr/local
    /usr
    PATH_SUFFIXES lib
    )


# handle the QUIETLY and REQUIRED arguments and set ENET_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BulletDynamics DEFAULT_MSG BULLETDYNAMICS_LIBRARY BULLET_INCLUDE_DIRS)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BulletCollision DEFAULT_MSG BULLETCOLLISION_LIBRARY BULLET_INCLUDE_DIRS)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LinearMath DEFAULT_MSG BULLETLINEARMATH_LIBRARY BULLET_INCLUDE_DIRS)

IF (BULLETDYNAMICS_FOUND)
    IF (BULLETCOLLISION_FOUND)
        IF (LINEARMATH_FOUND) 
            SET(BULLET_LIBRARIES ${BULLETDYNAMICS_LIBRARY} ${BULLETCOLLISION_LIBRARY} ${BULLETLINEARMATH_LIBRARY})
        ENDIF (LINEARMATH_FOUND)
    ENDIF (BULLETCOLLISION_FOUND)
ENDIF (BULLETDYNAMICS_FOUND)

MARK_AS_ADVANCED(BULLETDYNAMICS_LIBRARY BULLETCOLLISION_LIBRARY BULLETLINEARMATH_LIBRARY BULLET_LIBRARIES BULLET_INCLUDE_DIRS)

