#include "game/scores/bestScores.h"
#include "game/drawing/playerScore.h"
#include "game/scores/scoreGraphics.h"
#include "game/scores/scoreData.h"
#include "commonFiles/types/essentials.h"
#include "game/consts/constexpr.h"
#include "game/consts/sdlColors.h"
#include "game/consts/fontsSizes.h"
#include "fileSystem/fileSystem.h"
#include "SDL.h"
#include <fstream>

void bestScores::bestScoresContext(Essentials& essentials, const PlayerScore& playerScore, unsigned skill)
{
	bestScores::createScoresFilesIfMissing(essentials);
	bool quitScoreContext{false};
	const sdl2::Font arial{essentials.logs.error, ARIALFONTPATH, FONT_BIG_SIZE};
	ScoresData scoresData{essentials, playerScore.getScore(), skill};
	ScoresGraphics graphics{essentials, arial, scoresData};
	
	bestScores::mainLoop(essentials, graphics, quitScoreContext);
	
	scoresData.outputScoresToFile(essentials);
}

void bestScores::mainLoop(Essentials& essentials, const ScoresGraphics& scores, bool& quitContext)
{
	while( false == quitContext )
	{
		essentials.inp.updateMouse();
		bestScores::quitWInp(essentials, quitContext);
		bestScores::drawAll(essentials, scores);
	}
}

void bestScores::quitWInp(Essentials& essentials, bool& quitContext)
{
	if( essentials.inp.getWindowClose() || essentials.inp.getEscapeState() )
		quitContext = true;
}

void bestScores::drawAll(Essentials& essentials, const ScoresGraphics& scores)
{
	if( essentials.drawFrequency.hasTimeElapsed(16) )
	{
		essentials.rndWnd.clearScreen(BLACK_COL);
		scores.drawTexts(essentials);
		essentials.rndWnd.displayRenderer();
		essentials.drawFrequency.joinTimePoints();
	}
}

void bestScores::createScoresFilesIfMissing(Essentials& essentials)
{
	bestScores::createSingleScoreFile(essentials, essentials.prefPath.getPath() + EASY_FILE_NAME);
	bestScores::createSingleScoreFile(essentials, essentials.prefPath.getPath() + INTERM_FILE_NAME);
	bestScores::createSingleScoreFile(essentials, essentials.prefPath.getPath() + HARD_FILE_NAME);
}

void bestScores::createSingleScoreFile(Essentials& essentials, const std::string& fileFullPath)
{
	if( ! fs::exists(fileFullPath) )
	{
		if( std::ofstream scoreFile{fileFullPath} )
		{
			essentials.logs.error << "Create new file: " << fileFullPath << "  for the player score of tetris.\n";
			scoreFile << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << "\n"; 
		}
		else
		{
			essentials.logs.error << "Error: couldn't create '" << fileFullPath << "' file for SDL 2 tetris scores.\n";
		}
	}
}