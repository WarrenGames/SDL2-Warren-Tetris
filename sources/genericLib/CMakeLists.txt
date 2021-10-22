cmake_minimum_required(VERSION 3.8)

project("genericLib" LANGUAGES CXX)

if(UNIX)
	include(GNUInstallDirs)
endif(UNIX)

set(HEADERS
		sources/random/randomGenerator.h
		sources/fileSystem/createNewElementFs.h
		sources/fileSystem/copyFilesAndDirectories.h
		sources/fileSystem/fileSystem.h
		sources/matrices/matrix2D.h
		sources/matrices/matrixStructs.h
		sources/matrices/matrix3D.h
		sources/customTypes/positionTypes.h
		sources/customTypes/caseAnim.h
		sources/time/dateAndTime.h
		sources/time/accurateTime.h
		sources/texts/textLoader.h
		sources/logging/logFile.h
		sources/logging/logsStruct.h
)

set(SOURCES
		sources/random/randomGenerator.cpp
		sources/fileSystem/createNewElementFs.cpp
		sources/fileSystem/copyFilesAndDirectories.cpp
		sources/matrices/matrixStructs.cpp
		sources/customTypes/caseAnim.cpp
		sources/customTypes/positionTypes.cpp
		sources/time/dateAndTime.cpp
		sources/time/accurateTime.cpp
		sources/texts/textLoader.cpp
		sources/logging/logFile.cpp
		sources/logging/logsStruct.cpp
)

add_library(	
	${PROJECT_NAME} 
	STATIC
	${SOURCES} 
	${HEADERS} 
	${INC_DIRS}
)

target_include_directories(
	${PROJECT_NAME}
	PUBLIC ${SDL2_INCLUDE_DIRS}
	PUBLIC ${SDL2IMAGE_INCLUDE_DIRS}
	PUBLIC ${SDL2TTF_INCLUDE_DIRS}
	PUBLIC ${SDL2MIXER_INCLUDE_DIRS}
	PUBLIC sources
)

target_link_libraries(${PROJECT_NAME} )

set_target_properties(	
	${PROJECT_NAME} 
	PROPERTIES 
	CXX_STANDARD 20 
	CXX_STANDARD_REQUIRED YES 
	CXX_EXTENSIONS ON
	LINKER_LANGUAGE CXX
)

if( UNIX )
	install(TARGETS ${PROJECT_NAME}
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
	)
endif( UNIX )