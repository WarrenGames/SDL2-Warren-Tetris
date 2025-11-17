cmake_minimum_required( VERSION 3.13 )

project( game LANGUAGES CXX)

file( GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "sources/*.h" )

file( GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "sources/*.cpp" )

add_executable(	
	${PROJECT_NAME} 
	WIN32
	${SOURCES} 
	${HEADERS} 
	${INC_DIRS}
)

source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR}
	FILES ${HEADERS} ${SOURCES}
)

target_include_directories(
	${PROJECT_NAME}
	PRIVATE ${SDL2_INCLUDE_DIRS}
	PRIVATE ${SDL2_IMAGE_INCLUDE_DIRS}
	PRIVATE ${SDL2_TTF_INCLUDE_DIRS}
	PRIVATE ${SDL2_MIXER_INCLUDE_DIRS}
	PRIVATE sources
	PRIVATE ../../libraries/genericLib/sources
	PRIVATE ../../libraries/sdl2_wrapper/sources
)

target_link_libraries(	
	${PROJECT_NAME} 
	PRIVATE sdl2_wrapper
	PRIVATE genericLib
	PRIVATE ${SDL2_LIBRARIES} 
	PRIVATE ${SDL2_IMAGE_LIBRARIES} 
	PRIVATE ${SDL2_TTF_LIBRARIES} 
	PRIVATE ${SDL2_MIXER_LIBRARIES}
)

