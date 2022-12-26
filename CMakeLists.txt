cmake_minimum_required(VERSION 3.0.0)

project( sdl2-warren-tetris LANGUAGES CXX )

set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmakeModules)

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

if(UNIX)
	include(GNUInstallDirs)
	install( DIRECTORY data fonts icons licenses textures DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME} )
	install( 
		TARGETS game genericLib sdl2_wrapper
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT Runtime
	)
	set( DESKTOP_DEST_PATH "/usr/share/applications/" )
	set( DESKTOP_FILE "sdl2-warren-tetris.desktop" )
	
	file(WRITE ${DESKTOP_FILE} "[Desktop Entry]\n")
	file(APPEND ${DESKTOP_FILE} "Version=1.0\n")
	file(APPEND ${DESKTOP_FILE} "Type=Application\n")
	file(APPEND ${DESKTOP_FILE} "Name=SDL2 Warren Tetris\n")
	file(APPEND ${DESKTOP_FILE} "Comment=The tetris of the warren with SDL2\n")
	file(APPEND ${DESKTOP_FILE} "Icon=${CMAKE_INSTALL_FULL_DATADIR}/${PROJECT_NAME}/icons/warren-tetris.ico\n")
	file(APPEND ${DESKTOP_FILE} "Exec=${CMAKE_INSTALL_FULL_BINDIR}/${PROJECT_NAME}\n")
	file(APPEND ${DESKTOP_FILE} "Path=${CMAKE_INSTALL_FULL_DATADIR}/${PROJECT_NAME}\n")
	file(APPEND ${DESKTOP_FILE} "Actions=\n")
	file(APPEND ${DESKTOP_FILE} "Categories=Game;The games of the warren;")
	
	install( FILES ${DESKTOP_FILE} DESTINATION "${DESKTOP_DEST_PATH}" )
else()
	install( 
		TARGETS game genericLib sdl2_wrapper 
		RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX} COMPONENT Runtime
	)
endif(UNIX)
