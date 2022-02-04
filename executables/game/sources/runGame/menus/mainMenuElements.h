#ifndef MAIN_MENU_ELEMENTS_H
#define MAIN_MENU_ELEMENTS_H

#include "texturing/texturesCombo.h"
#include "widgets/buttons/highlightButtonWidget.h"
#include "text/sdl2ttf_font.h"
#include "game/consts/constexpr.h"
#include "game/input/inputsConsts.h"
#include <array>
#include <string>

struct Essentials;
struct Offset;

namespace mainMenu{

struct Elements
{
	const sdl2::Font arial;
	TextureCombo title;
	std::array< HighLightButton, GAME_MAX > skillButtons;
	std::array< TextureCombo, INP_MAX > inputsTexts;
	HighLightButton customGame;
	HighLightButton optionsButton;
	std::array< std::string, KEY::INP_MAX > keycodesStrings;

	explicit Elements(Essentials& essentials);
	~Elements() = default;
	Elements( const Elements& ) = delete;
	Elements& operator= ( const Elements& ) = delete;
	
	void drawEverything(Essentials& essentials) const;
	void updateButtons(const Offset& mousePosition, bool mouseLeftButton);
	bool isButtonClicked(size_t buttonIndex) const;

	void drawButtons(Essentials& essentials) const;
	void drawInputsTexts(Essentials& essentials) const;
	
	void resetKeycodesInfos(Essentials& essentials);
};

}

#endif //MAIN_MENU_ELEMENTS_H