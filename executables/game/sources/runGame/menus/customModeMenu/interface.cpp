#include "runGame/menus/customModeMenu/interface.h"
#include "game/structs/timeOptionsStruct.h"
#include "texturing/texturePosition.h"
#include "commonFiles/types/essentials.h"
#include "game/consts/constexpr.h"
#include "game/consts/sdlColors.h"
#include "game/consts/fontsSizes.h"
#include <cassert>

constexpr int BOX_W = SQR_SIZE * 6;
constexpr int BOX_H = SQR_SIZE * 1;
constexpr int BOX_X = SCREENW / 2;
constexpr int BUTTON_W = SQR_SIZE * 4;

customMenu::Interface::Interface(Essentials& essentials):
	pieceFallTimeMin{100},
	pieceFallTimeMax{1000},
	pieceSpeedIncr{1},
	pieceFallTotalTime{60 * 15},
	timeMinBox{essentials.logs, essentials.rndWnd, SDL_Rect{ BOX_X, SQR_SIZE * 3, BOX_W, BOX_H}, FONT_MEDIUM_SIZE, pieceFallTimeMin},
	timeMaxBox{essentials.logs, essentials.rndWnd, SDL_Rect{ BOX_X, SQR_SIZE * 5, BOX_W, BOX_H}, FONT_MEDIUM_SIZE, pieceFallTimeMax},
	speedIncrBox{essentials.logs, essentials.rndWnd, SDL_Rect{ BOX_X, SQR_SIZE * 7, BOX_W, BOX_H}, FONT_MEDIUM_SIZE, pieceSpeedIncr},
	totalTimeBox{essentials.logs, essentials.rndWnd, SDL_Rect{ BOX_X, SQR_SIZE * 9, BOX_W, BOX_H}, FONT_MEDIUM_SIZE, pieceFallTotalTime},
	arial{essentials.logs.error, ARIALFONTPATH, FONT_MEDIUM_SIZE},
	timeMinText{essentials.logs, essentials.rndWnd, arial, "End speed time: ", WHITE_COL, TexturePosition{SQR_SIZE, SQR_SIZE * 3 + SQR_SIZE / 2, false, true} },
	timeMaxText{essentials.logs, essentials.rndWnd, arial, "Start speed time: ", WHITE_COL, TexturePosition{SQR_SIZE, SQR_SIZE * 5 + SQR_SIZE / 2, false, true} },
	speedIncrText{essentials.logs, essentials.rndWnd, arial, "Speed increment: ", WHITE_COL, TexturePosition{SQR_SIZE, SQR_SIZE * 7 + SQR_SIZE / 2, false, true} },
	totalTimeText{essentials.logs, essentials.rndWnd, arial, "Total time (seconds): ", WHITE_COL, TexturePosition{SQR_SIZE, SQR_SIZE * 9 + SQR_SIZE / 2, false, true} },
	hintAboutTime{essentials.logs, essentials.rndWnd, arial, "About 'start' and 'end' speed time: the higher the value, the slower the pieces fall.", WHITE_COL, 
						TexturePosition{SQR_SIZE, SCREENH - SQR_SIZE * 4, false, true} },
	startGameButtons{
		HighLightButton{essentials.logs, essentials.rndWnd, arial, "Easy", WHITE_COL, SDL_Rect{ SQR_SIZE * 4 - BUTTON_W / 2, SCREENH - SQR_SIZE * 2, BUTTON_W, SQR_SIZE}, GREEN_COL},
		HighLightButton{essentials.logs, essentials.rndWnd, arial, "Intermediate", WHITE_COL, SDL_Rect{ SCREENW / 2 - BUTTON_W / 2, SCREENH - SQR_SIZE * 2, BUTTON_W, SQR_SIZE}, GREEN_COL},
		HighLightButton{essentials.logs, essentials.rndWnd, arial, "Hard", WHITE_COL, SDL_Rect{ SCREENW - SQR_SIZE * 4 - BUTTON_W / 2, SCREENH - SQR_SIZE * 2, BUTTON_W, SQR_SIZE}, GREEN_COL}
	},
	goBack{essentials.logs, essentials.rndWnd, arial, "Go back", WHITE_COL, SDL_Rect{ SCREENW - BUTTON_W, SQR_SIZE, BUTTON_W, SQR_SIZE}, GREEN_COL}
{
	
}

void customMenu::Interface::drawEverything(Essentials& essentials) const
{
	timeMinBox.drawBoxWithoutFocus(essentials.rndWnd);
	timeMaxBox.drawBoxWithoutFocus(essentials.rndWnd);
	speedIncrBox.drawBoxWithoutFocus(essentials.rndWnd);
	totalTimeBox.drawBoxWithoutFocus(essentials.rndWnd);
	timeMinText.draw(essentials.rndWnd);
	timeMaxText.draw(essentials.rndWnd);
	speedIncrText.draw(essentials.rndWnd);
	totalTimeText.draw(essentials.rndWnd);
	hintAboutTime.draw(essentials.rndWnd);
	drawHighlightButtons(essentials);
	goBack.drawButton(essentials.rndWnd);
}

void customMenu::Interface::drawHighlightButtons(Essentials& essentials) const
{
	for( auto const &btn : startGameButtons )
	{
		btn.drawButton(essentials.rndWnd);
	}
}

void customMenu::Interface::update(Essentials& essentials, const Offset& mousePosition, bool mouseLeftButton)
{
	timeMinBox.catchUserFocus(essentials.logs, essentials.rndWnd, mousePosition, mouseLeftButton);
	timeMaxBox.catchUserFocus(essentials.logs, essentials.rndWnd, mousePosition, mouseLeftButton);
	speedIncrBox.catchUserFocus(essentials.logs, essentials.rndWnd, mousePosition, mouseLeftButton);
	totalTimeBox.catchUserFocus(essentials.logs, essentials.rndWnd, mousePosition, mouseLeftButton);
	updateHighlightButtons(mousePosition, mouseLeftButton);
	goBack.updateButton(mousePosition, mouseLeftButton);
}

void customMenu::Interface::updateHighlightButtons(const Offset& mousePosition, bool mouseLeftButton)
{
	for( auto &btn : startGameButtons )
	{
		btn.updateButton(mousePosition, mouseLeftButton);
	}
}

void customMenu::Interface::setOptionForCustomGame(TimeOptions& timeOptions) const
{
	timeOptions.pieceFallTimeMin = pieceFallTimeMin;
	timeOptions.pieceFallTimeMax = pieceFallTimeMax;
	timeOptions.pieceSpeedIncr = pieceSpeedIncr;
	timeOptions.pieceFallTotalTime = pieceFallTotalTime * 1000;
}

bool customMenu::Interface::letsStartCustomGame(unsigned skill) const
{
	assert( skill < startGameButtons.size() );
	return startGameButtons[skill].buttonClicked();
}

bool customMenu::Interface::goBackClicked() const
{
	return goBack.buttonClicked();
}