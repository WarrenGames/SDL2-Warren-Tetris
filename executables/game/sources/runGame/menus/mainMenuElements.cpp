#include "runGame/menus/mainMenuElements.h"
#include "commonFiles/types/essentials.h"
#include "texturing/texturePosition.h"
#include "runGame/menus/keycodesInfos.h"
#include "commonFiles/pathsLoadings/pathsLoadings.h"
#include "game/consts/constexpr.h"
#include "game/consts/sdlColors.h"
#include <cassert>

constexpr int HL_BTN_W = 8 * SQR_SIZE;
constexpr int HL_BTN_H = SQR_SIZE*2;
constexpr int HL_BTN_X = SCREENW / 2 - HL_BTN_W / 2;

constexpr char MOVE_LEFT_STR[] = "Move piece to left: ";
constexpr char MOVE_RIGHT_STR[] = "Move piece to right: ";
constexpr char MOVE_DOWNER_STR[] = "Move piece to downer: ";
constexpr char CLOCKWISE_ROT[] = "Clockwise piece rotation: ";
constexpr char ANTI_CLOCKWISE_ROT[] = "Anticlockwise piece rotation: ";

mainMenu::Elements::Elements(Essentials& essentials):
	arial{essentials.logs.error, ARIALFONTPATH, 20},
	title{essentials.logs, essentials.rndWnd, arial, "Tetris of the warren", WHITE_COL, TexturePosition{SCREENW/2, SQR_SIZE, true, true} },
	skillButtons{
		HighLightButton{essentials.logs, essentials.rndWnd, arial, "Easy", WHITE_COL, 		SDL_Rect{ HL_BTN_X, SQR_SIZE * 4, HL_BTN_W, HL_BTN_H}, ORANGE_COL},
		HighLightButton{essentials.logs, essentials.rndWnd, arial, "Intermediate", WHITE_COL, SDL_Rect{ HL_BTN_X, SQR_SIZE * 7, HL_BTN_W, HL_BTN_H}, ORANGE_COL},
		HighLightButton{essentials.logs, essentials.rndWnd, arial, "Hard", WHITE_COL, 		SDL_Rect{ HL_BTN_X, SQR_SIZE * 10, HL_BTN_W, HL_BTN_H}, ORANGE_COL}
	},
	customGame{essentials.logs, essentials.rndWnd, arial, "Custom game", WHITE_COL, SDL_Rect{HL_BTN_X, SQR_SIZE * 13, HL_BTN_W, HL_BTN_H}, ORANGE_COL},
	optionsButton{essentials.logs, essentials.rndWnd, arial, "Options", WHITE_COL, SDL_Rect{ HL_BTN_X, SQR_SIZE * 16, HL_BTN_W, HL_BTN_H}, ORANGE_COL},
	keycodesStrings{
		std::string{MOVE_LEFT_STR},
		std::string{MOVE_RIGHT_STR},
		std::string{MOVE_DOWNER_STR},
		std::string{CLOCKWISE_ROT},
		std::string{ANTI_CLOCKWISE_ROT}
	}
{
	resetKeycodesInfos(essentials);
}

void mainMenu::Elements::drawEverything(Essentials& essentials) const
{
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
	for( std::size_t keycode{0} ; keycode < KEY::INP_MAX ; ++keycode )
	{
		if( SDLK_UNKNOWN == keycodesInfos.keycodes[keycode] )
		{
			inputsTexts[keycode].texture.loadBlendedText(essentials.logs, essentials.rndWnd, arial, keycodesStrings[keycode] + "not assigned", WHITE_COL);
		}
		else{
			inputsTexts[keycode].texture.loadBlendedText(essentials.logs, essentials.rndWnd, arial, keycodesStrings[keycode] + SDL_GetKeyName(keycodesInfos.keycodes[keycode]), WHITE_COL);
		}
		inputsTexts[keycode].resetSpritePosition( TexturePosition{SQR_SIZE, SCREENH - SQR_SIZE * 5 + SQR_SIZE * static_cast<int>(keycode), false, true} );
	}
}
