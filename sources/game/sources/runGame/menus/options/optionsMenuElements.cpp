#include "runGame/menus/options/optionsMenuElements.h"
#include "commonFiles/types/essentials.h"
#include "texturing/texturePosition.h"
#include "game/consts/constexpr.h"
#include "game/consts/sdlColors.h"
#include "game/consts/fontsSizes.h"

constexpr int BTN_X_POS = SCREENW / 2 + SQR_SIZE * 2;
constexpr int BTN_W = SQR_SIZE * 3;
constexpr int BTN_H = SQR_SIZE; 

constexpr int TXT_X_POS = SCREENW / 2 - SQR_SIZE * 6;

OptionsMenuElements::OptionsMenuElements(Essentials& essentials):
	keycodesData{essentials.logs, essentials.prefPath},
	arial{essentials.logs.error, ARIALFONTPATH, FONT_MEDIUM_SIZE},
	functionsNames{
		TextureCombo{essentials.logs, essentials.rndWnd, arial, "Move to left:", WHITE_COL, TexturePosition{TXT_X_POS, SQR_SIZE*4+SQR_SIZE/2, false, true} },
		TextureCombo{essentials.logs, essentials.rndWnd, arial, "Move to right:", WHITE_COL, TexturePosition{TXT_X_POS, SQR_SIZE*6+SQR_SIZE/2, false, true} },
		TextureCombo{essentials.logs, essentials.rndWnd, arial, "Move downer:", WHITE_COL, TexturePosition{TXT_X_POS, SQR_SIZE*8+SQR_SIZE/2, false, true} },
		TextureCombo{essentials.logs, essentials.rndWnd, arial, "Clockwise rotation:", WHITE_COL, TexturePosition{TXT_X_POS, SQR_SIZE*10+SQR_SIZE/2, false, true} },
		TextureCombo{essentials.logs, essentials.rndWnd, arial, "Anti-clockwise rotation:", WHITE_COL, TexturePosition{TXT_X_POS, SQR_SIZE*12+SQR_SIZE/2, false, true} }
	},
	keycodesBtn{
		HighLightButton{essentials.logs, essentials.rndWnd, arial, keycodesData.getStr(KEY::MV_PIECE_LEFT), WHITE_COL, SDL_Rect{BTN_X_POS, SQR_SIZE*4, BTN_W, BTN_H}, GREEN_COL},
		HighLightButton{essentials.logs, essentials.rndWnd, arial, keycodesData.getStr(KEY::MV_PIECE_RIGHT), WHITE_COL, SDL_Rect{BTN_X_POS, SQR_SIZE*6, BTN_W, BTN_H}, GREEN_COL},
		HighLightButton{essentials.logs, essentials.rndWnd, arial, keycodesData.getStr(KEY::DOWN_FASTER), WHITE_COL, SDL_Rect{BTN_X_POS, SQR_SIZE*8, BTN_W, BTN_H}, GREEN_COL},
		HighLightButton{essentials.logs, essentials.rndWnd, arial, keycodesData.getStr(KEY::ROT_PIECE_CWISE), WHITE_COL, SDL_Rect{BTN_X_POS, SQR_SIZE*10, BTN_W, BTN_H}, GREEN_COL},
		HighLightButton{essentials.logs, essentials.rndWnd, arial, keycodesData.getStr(KEY::ROT_PIECE_ANTICWISE), WHITE_COL, SDL_Rect{BTN_X_POS, SQR_SIZE*12, BTN_W, BTN_H}, GREEN_COL}
	},
	pressANewKey{essentials.logs, essentials.rndWnd, arial, "Press a new key.", WHITE_COL, TexturePosition{SCREENW/2, SCREENH - SQR_SIZE * 2, true, true} }
{
	
}

void OptionsMenuElements::updateButtons(Essentials& essentials)
{
	for( auto &btn : keycodesBtn )
	{
		btn.updateButton(essentials.inp.getMousePosition(), essentials.inp.getMouseLeftButton());
	}
}

void OptionsMenuElements::drawInfoTexts(Essentials& essentials) const
{
	for( auto const &txt : functionsNames )
	{
		txt.draw(essentials.rndWnd);
	}
}

void OptionsMenuElements::drawButtons(Essentials& essentials) const
{
	for( auto const &btn : keycodesBtn )
	{
		btn.drawButton(essentials.rndWnd);
	}
}

void OptionsMenuElements::changeGameInput(Essentials& essentials)
{
	for( size_t keycode{0} ; keycode < KEY::INP_MAX ; ++keycode )
	{
		if( keycodesBtn[keycode].buttonClicked() )
		{
			pressANewKey.draw(essentials.rndWnd);
			essentials.rndWnd.displayRenderer();
			bool canWaitInput{true};
			pollEvents(essentials, canWaitInput, keycode);
			essentials.inp.setMouseLeftButtonFalse();
		}
	}
}

void OptionsMenuElements::pollEvents(Essentials& essentials, bool& canWaitInput, size_t keycodeNum)
{
	while( canWaitInput )
	{
		SDL_Event event;
		SDL_WaitEvent(&event);
		switch( event.type )
		{
			case SDL_KEYDOWN:
				updateModifications(essentials, canWaitInput, keycodeNum, event.key.keysym.sym);
				break;
		}
	}
}

void OptionsMenuElements::updateModifications(Essentials& essentials, bool& canWaitInput, size_t keycodeNum, SDL_Keycode& keycode)
{
	if( keycode != SDLK_ESCAPE )
	{
		keycodesData.keycodes[keycodeNum] = keycode;
		keycodesBtn[keycodeNum].changeText(essentials.logs, essentials.rndWnd, arial, keycodesData.getStr(keycodeNum), WHITE_COL);
		canWaitInput = false;
	}
}