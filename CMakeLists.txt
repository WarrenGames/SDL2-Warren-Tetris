cmake_minimum_required(VERSION 3.0.0)

project(sdl2-warren-tetris LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmakeModules)

if(WIN32)
	#Set the SDL2 main directory if you're compiling with Windows
	set(SDL2_DIR "")
endif(WIN32)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

add_subdirectory(sources/game)
add_subdirectory(sources/genericLib)
add_subdirectory(sources/sdl2_wrapper)
