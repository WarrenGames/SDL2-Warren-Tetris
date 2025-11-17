#ifndef CUSTOM_MODE_MENU_INTERFACE_H
#define CUSTOM_MODE_MENU_INTERFACE_H

#include "widgets/editBoxes/uint_editBox.h"
#include "texturing/texturesCombo.h"
#include "text/sdl2ttf_font.h"
#include "widgets/buttons/highlightButtonWidget.h"
#include "game/consts/constexpr.h"
#include <array>

struct Essentials;
struct TimeOptions;

namespace customMenu{

class Interface
{
private:
	unsigned pieceFallTimeMin;
	unsigned pieceFallTimeMax;
	unsigned pieceSpeedIncr;
	unsigned pieceFallTotalTime;
	UintEditBox timeMinBox;
	UintEditBox timeMaxBox;
	UintEditBox speedIncrBox;
	UintEditBox totalTimeBox;
	sdl2::Font font;
	TextureCombo timeMinText;
	TextureCombo timeMaxText;
	TextureCombo speedIncrText;
	TextureCombo totalTimeText;
	TextureCombo hintAboutTime;
	std::array< HighLightButton, SkillGameMax > startGameButtons;
	HighLightButton goBack;

public:
	explicit Interface(Essentials& essentials);
	~Interface() = default;
	Interface( const Interface& ) = delete;
	Interface& operator= ( const Interface& ) = delete;
	Interface( Interface&& ) = default;
	Interface& operator= ( Interface&& ) = default;
	void drawEverything(Essentials& essentials) const;
	void drawHighlightButtons(Essentials& essentials) const;
	
	void update(Essentials& essentials, const Offset& mousePosition, bool mouseLeftButton);
	void updateHighlightButtons(const Offset& mousePosition, bool mouseLeftButton);
	
	void setOptionForCustomGame(TimeOptions& timeOptions) const;
	
	bool letsStartCustomGame(unsigned skill) const;
	
	bool goBackClicked() const;
};

}

#endif //CUSTOM_MODE_MENU_INTERFACE_H