# - Try to find enet
# Once done this will define
#
# BTOGRE_FOUND - system has enet
# BtOgre_INCLUDE_DIRS - the BtOgre include directory
# BtOgre_LIBRARIES - the libraries needed to use enet
#
# $BTOGRE_HOME is an environment variable used for finding enet.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <

FIND_PATH(BtOgre_INCLUDE_DIRS BtOgreGP.h
    PATHS
    $ENV{BTOGRE_HOME}/include
    /usr/local
    /usr
    PATH_SUFFIXES include
    )

FIND_LIBRARY(BtOgre_LIBRARIES_REL
    NAMES BtOgre libBtOgre.a
    PATHS
    $ENV{BTOGRE_HOME}
    /usr/local
    /usr
    )

FIND_LIBRARY(BtOgre_LIBRARIES_DBG
    NAMES BtOgre_Debug libBtOgre_d.a
    PATHS
    $ENV{BTOGRE_HOME}
    /usr/local
    /usr
    )

# handle the QUIETLY and REQUIRED arguments and set ENET_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BtOgre DEFAULT_MSG BtOgre_LIBRARIES_REL BtOgre_LIBRARIES_DBG BtOgre_INCLUDE_DIRS)

IF (BTOGRE_FOUND)
    SET(BtOgre_LIBRARIES optimized ${BtOgre_LIBRARIES_REL} debug ${BtOgre_LIBRARIES_DBG})
ELSE (BTOGRE_FOUND)
    MESSAGE("BtOgre Not Found!")
ENDIF (BTOGRE_FOUND)

MARK_AS_ADVANCED(BtOgre_LIBRARY BtOgre_LIBRARIES BtOgre_INCLUDE_DIRS)

