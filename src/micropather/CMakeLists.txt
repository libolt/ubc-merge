
#set(LIBRARY_OUTPUT_PATH lib/${CMAKE_BUILD_TYPE})

include_directories(./)

file(
	GLOB_RECURSE
	source_files
	*.h
	*.cpp
)

add_library(
	micropather
	STATIC
	${source_files}
)

#SET_TARGET_PROPERTIES (tinyxml PROPERTIES DEFINE_SYMBOL  "EXPORT" )

#INSTALL( FILES tinyxml.h tinystr.h DESTINATION include/ )
#INSTALL( FILES lib/libtinyxml.so DESTINATION lib/ )
