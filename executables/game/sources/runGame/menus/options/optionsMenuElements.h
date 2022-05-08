#ifndef OPTIONS_MENU_ELEMENTS_H
#define OPTIONS_MENU_ELEMENTS_H

#include "widgets/buttons/highlightButtonWidget.h"
#include "texturing/texturesCombo.h"
#include "text/sdl2ttf_font.h"
#include "runGame/menus/keycodesInfos.h"
#include "game/input/inputsConsts.h"

struct Essentials;

struct OptionsMenuElements
{
	KeycodesInfos keycodesData;
	const sdl2::Font arial;
	const std::array< const TextureCombo, KEY::INP_MAX > functionsNames;
	std::array< HighLightButton, KEY::INP_MAX > keycodesBtn;
	const TextureCombo pressANewKey;

	explicit OptionsMenuElements(Essentials& essentials);
	~OptionsMenuElements() = default;
	OptionsMenuElements( const OptionsMenuElements& ) = delete;
	OptionsMenuElements& operator= ( const OptionsMenuElements& ) = delete;
	OptionsMenuElements( OptionsMenuElements&& ) = default;
	OptionsMenuElements& operator= ( OptionsMenuElements&& ) = default;
	
	void updateButtons(Essentials& essentials);
	
	void drawInfoTexts(Essentials& essentials) const;
	void drawButtons(Essentials& essentials) const;
	
	void changeGameInput(Essentials& essentials);
	
	void pollEvents(Essentials& essentials, bool& canWaitInput, std::size_t keycodeNum);
	
	void updateModifications(Essentials& essentials, bool& canWaitInput, std::size_t keycodeNum, SDL_Keycode& keycode);
};

#endif //OPTIONS_MENU_ELEMENTS_H