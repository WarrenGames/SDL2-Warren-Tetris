#include "runGame/menus/mainMenuElements.h"
#include "commonFiles/types/essentials.h"
#include "texturing/texturePosition.h"
#include "runGame/menus/keycodesInfos.h"
#include "commonFiles/pathsLoadings/pathsLoadings.h"
#include "game/consts/constexpr.h"
#include "game/consts/sdlColors.h"
#include <cassert>

constexpr int HighlightBtnW = 8 * SQR_SIZE;
constexpr int HighlightBtnH = SQR_SIZE * 2;
constexpr int HighlightBtnX = GameWindowWidth / 2 - HighlightBtnW / 2;

constexpr char MoveLeftStr[] = "Move piece to left: ";
constexpr char MoveRightStr[] = "Move piece to right: ";
constexpr char MoveDownerStr[] = "Move piece to downer: ";
constexpr char ClockwiseRotStr[] = "Clockwise piece rotation: ";
constexpr char AntiClockwiseRotStr[] = "Anticlockwise piece rotation: ";

mainMenu::Elements::Elements(Essentials& essentials):
	font{essentials.logs.error, GameFontPath, 20},
	title{essentials.logs, essentials.rndWnd, font, "Tetris of the warren", WhiteColor, TexturePosition{GameWindowWidth/2, SQR_SIZE, true, true} },
	skillButtons{
		HighLightButton{essentials.logs, essentials.rndWnd, font, "Easy", WhiteColor, SDL_Rect{ HighlightBtnX, SQR_SIZE * 4, HighlightBtnW, HighlightBtnH}, OrangeColor},
		HighLightButton{essentials.logs, essentials.rndWnd, font, "Intermediate", WhiteColor, SDL_Rect{ HighlightBtnX, SQR_SIZE * 7, HighlightBtnW, HighlightBtnH}, OrangeColor},
		HighLightButton{essentials.logs, essentials.rndWnd, font, "Hard", WhiteColor, SDL_Rect{ HighlightBtnX, SQR_SIZE * 10, HighlightBtnW, HighlightBtnH}, OrangeColor}
	},
	customGame{essentials.logs, essentials.rndWnd, font, "Custom game", WhiteColor, SDL_Rect{HighlightBtnX, SQR_SIZE * 13, HighlightBtnW, HighlightBtnH}, OrangeColor},
	optionsButton{essentials.logs, essentials.rndWnd, font, "Options", WhiteColor, SDL_Rect{ HighlightBtnX, SQR_SIZE * 16, HighlightBtnW, HighlightBtnH}, OrangeColor},
	keycodesStrings{ MoveLeftStr, MoveRightStr, MoveDownerStr, ClockwiseRotStr, AntiClockwiseRotStr },
	backgroundWallpaper{ essentials.logs, essentials.rndWnd, MainMenuWallpaperPath }
{
	resetKeycodesInfos(essentials);
}

void mainMenu::Elements::drawEverything(Essentials& essentials) const
{
	backgroundWallpaper.draw(essentials.rndWnd);
	title.draw(essentials.rndWnd);
	drawButtons(essentials);
	drawInputsTexts(essentials);
	customGame.drawButton(essentials.rndWnd);
	optionsButton.drawButton(essentials.rndWnd);
}

void mainMenu::Elements::updateButtons(const Offset& mousePosition, bool mouseLeftButton)
{
	for( auto &btn : skillButtons )
	{
		btn.updateButton(mousePosition, mouseLeftButton);
	}
}

bool mainMenu::Elements::isButtonClicked(std::size_t buttonIndex) const
{
	assert( buttonIndex < skillButtons.size() );
	return skillButtons[buttonIndex].buttonClicked();
}

void mainMenu::Elements::drawButtons(Essentials& essentials) const
{
	for( auto const &btn : skillButtons )
	{
		btn.drawButton(essentials.rndWnd);
	}
}

void mainMenu::Elements::drawInputsTexts(Essentials& essentials) const
{
	for( auto const &text : inputsTexts )
	{
		text.draw(essentials.rndWnd);
	}
}

void mainMenu::Elements::resetKeycodesInfos(Essentials& essentials)
{
	KeycodesInfos keycodesInfos{essentials.logs, essentials.prefPath};
	for( std::size_t keycode{0} ; keycode < Key::InputMax ; ++keycode )
	{
		if( SDLK_UNKNOWN == keycodesInfos.keycodes[keycode] )
		{
			inputsTexts[keycode].texture.loadBlendedText(essentials.logs, essentials.rndWnd, font, keycodesStrings[keycode] + "not assigned", WhiteColor);
		}
		else{
			inputsTexts[keycode].texture.loadBlendedText(essentials.logs, essentials.rndWnd, font, keycodesStrings[keycode] + SDL_GetKeyName(keycodesInfos.keycodes[keycode]), WhiteColor);
		}
		inputsTexts[keycode].resetSpritePosition( TexturePosition{SQR_SIZE, GameWindowHeight - SQR_SIZE * 5 + SQR_SIZE * static_cast<int>(keycode), false, true} );
	}
}
