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
	const sdl2::Font font{essentials.logs.error, GameFontPath, FontBigSize};
	ScoresData scoresData{essentials, playerScore.getScore(), skill};
	ScoresGraphics graphics{essentials, font, scoresData};
	
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
	if( essentials.drawFrequency.hasTimeElapsed( std::chrono::milliseconds{16} ) )
	{
		essentials.rndWnd.clearScreen(BlackColor);
		scores.drawTexts(essentials);
		essentials.rndWnd.displayRenderer();
		essentials.drawFrequency.joinTimePoints();
	}
}

void bestScores::createScoresFilesIfMissing(Essentials& essentials)
{
	bestScores::createSingleScoreFile(essentials, essentials.prefPath.getPath() + ScoreEasyFileName);
	bestScores::createSingleScoreFile(essentials, essentials.prefPath.getPath() + ScoreIntermediateFileName);
	bestScores::createSingleScoreFile(essentials, essentials.prefPath.getPath() + ScoreHardFileName);
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