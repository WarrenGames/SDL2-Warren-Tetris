cmake_minimum_required( VERSION 3.13 )

project( warrenTetris LANGUAGES CXX )

set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmakeModules )

if(WIN32)
	#Set the SDL2 main directory if you're compiling with Windows
	set( SDL2_DIR "" )
endif(WIN32)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

add_subdirectory(executables/game)
add_subdirectory(libraries/genericLib)
add_subdirectory(libraries/sdl2_wrapper)

set_target_properties(	
	game genericLib
	PROPERTIES 
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED YES 
	CXX_EXTENSIONS ON 
	LINKER_LANGUAGE CXX
)

if(UNIX)
	include(GNUInstallDirs)
	install( 
		TARGETS game 
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT Runtime
	)

else()
	install( 
		TARGETS game
		RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX} COMPONENT Runtime
	)
endif(UNIX)
