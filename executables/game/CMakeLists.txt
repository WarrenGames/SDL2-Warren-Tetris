cmake_minimum_required(VERSION 3.8)

project( game LANGUAGES CXX)

if(UNIX)
	include(GNUInstallDirs)
endif(UNIX)

set(HEADERS
		sources/commonFiles/pathsLoadings/pathsLoadings.h
		sources/commonFiles/types/essentials.h
		sources/runGame/menus/customModeMenu/interface.h
		sources/runGame/menus/customModeMenu/customMenuContext.h
		sources/runGame/menus/mainMenuElements.h
		sources/runGame/menus/keycodesInfos.h
		sources/runGame/menus/mainMenu.h
		sources/runGame/menus/options/optionsMenuElements.h
		sources/runGame/menus/options/context.h
		sources/runGame/initialize/initRendWindow.h
		sources/runGame/initialize/initSDL2Comp.h
		sources/runGame/initialize/initErrorLog.h
		sources/game/drawing/drawPiece.h
		sources/game/drawing/drawMatrix.h
		sources/game/drawing/borderDrawing.h
		sources/game/drawing/playerScore.h
		sources/game/drawing/squareTexturing.h
		sources/game/gameActions/pieceRotationTest.h
		sources/game/gameActions/removeCompleteLines.h
		sources/game/gameActions/checkGameOver.h
		sources/game/gameActions/pieceCollisionTest.h
		sources/game/gameActions/moveCurrentPieceToMatrix.h
		sources/game/contexts/gameContext.h
		sources/game/input/actAccToInput.h
		sources/game/input/inputsConsts.h
		sources/game/input/userInput.h
		sources/game/consts/sdlColors.h
		sources/game/consts/fontsSizes.h
		sources/game/consts/constexpr.h
		sources/game/structs/scanLinesInfos.h
		sources/game/structs/timeOptionsStruct.h
		sources/game/objects/squareData.h
		sources/game/objects/pieceClass.h
		sources/game/objects/pieceFallSpeedInterface.h
		sources/game/objects/randomSingleton.h
		sources/game/objects/activePieceThings.h
		sources/game/objects/chronoTimer.h
		sources/game/objects/globalGameObject.h
		sources/game/objects/loadedPieces.h
		sources/game/scores/scoresInfos.h
		sources/game/scores/scoreGraphics.h
		sources/game/scores/scoreData.h
		sources/game/scores/bestScores.h
		sources/game/loadFiles/loadPieceFile.h
)

set(SOURCES 
		sources/commonFiles/pathsLoadings/pathsLoadings.cpp
		sources/commonFiles/types/essentials.cpp
		sources/runGame/menus/mainMenuElements.cpp
		sources/runGame/menus/customModeMenu/customMenuContext.cpp
		sources/runGame/menus/customModeMenu/interface.cpp
		sources/runGame/menus/mainMenu.cpp
		sources/runGame/menus/keycodesInfos.cpp
		sources/runGame/menus/options/context.cpp
		sources/runGame/menus/options/optionsMenuElements.cpp
		sources/runGame/initialize/initErrorLog.cpp
		sources/runGame/initialize/initSDL2Comp.cpp
		sources/runGame/initialize/initRendWindow.cpp
		sources/main.cpp
		sources/game/drawing/drawPiece.cpp
		sources/game/drawing/playerScore.cpp
		sources/game/drawing/borderDrawing.cpp
		sources/game/drawing/drawMatrix.cpp
		sources/game/drawing/squareTexturing.cpp
		sources/game/gameActions/pieceCollisionTest.cpp
		sources/game/gameActions/removeCompleteLines.cpp
		sources/game/gameActions/moveCurrentPieceToMatrix.cpp
		sources/game/gameActions/checkGameOver.cpp
		sources/game/gameActions/pieceRotationTest.cpp
		sources/game/contexts/gameContext.cpp
		sources/game/input/userInput.cpp
		sources/game/input/actAccToInput.cpp
		sources/game/structs/scanLinesInfos.cpp
		sources/game/structs/timeOptionsStruct.cpp
		sources/game/objects/pieceClass.cpp
		sources/game/objects/squareData.cpp
		sources/game/objects/activePieceThings.cpp
		sources/game/objects/randomSingleton.cpp
		sources/game/objects/chronoTimer.cpp
		sources/game/objects/loadedPieces.cpp
		sources/game/objects/globalGameObject.cpp
		sources/game/objects/pieceFallSpeedInterface.cpp
		sources/game/scores/scoreGraphics.cpp
		sources/game/scores/scoresInfos.cpp
		sources/game/scores/scoreData.cpp
		sources/game/scores/bestScores.cpp
		sources/game/loadFiles/loadPieceFile.cpp
)

add_executable(	
	${PROJECT_NAME} 
	WIN32
	${SOURCES} 
	${HEADERS} 
	${INC_DIRS}
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
	${SDL2_LIBRARIES} 
	${SDL2_IMAGE_LIBRARIES} 
	${SDL2_TTF_LIBRARIES} 
	${SDL2_MIXER_LIBRARIES}
	genericLib
	sdl2_wrapper
)

set_target_properties(	
	${PROJECT_NAME} 
	PROPERTIES 
	CXX_STANDARD 20 
	CXX_STANDARD_REQUIRED YES 
	CXX_EXTENSIONS ON 
	LINKER_LANGUAGE CXX
)
