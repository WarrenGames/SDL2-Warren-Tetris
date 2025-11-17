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
	sdl2::Font font;
	TextureCombo title;
	std::array< HighLightButton, SkillGameMax > skillButtons;
	std::array< TextureCombo, Key::InputMax > inputsTexts;
	HighLightButton customGame;
	HighLightButton optionsButton;
	std::array< std::string, Key::InputMax > keycodesStrings;
	TextureCombo backgroundWallpaper;

	explicit Elements(Essentials& essentials);
	~Elements() = default;
	Elements( const Elements& ) = delete;
	Elements& operator= ( const Elements& ) = delete;
	Elements( Elements&& ) = default;
	Elements& operator= ( Elements&& ) = default;
	
	void drawEverything(Essentials& essentials) const;
	void updateButtons(const Offset& mousePosition, bool mouseLeftButton);
	bool isButtonClicked(std::size_t buttonIndex) const;

	void drawButtons(Essentials& essentials) const;
	void drawInputsTexts(Essentials& essentials) const;
	
	void resetKeycodesInfos(Essentials& essentials);
};

}

#endif //MAIN_MENU_ELEMENTS_H