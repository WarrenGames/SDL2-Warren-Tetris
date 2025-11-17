#ifndef SCORE_GRAPHICS_H
#define SCORE_GRAPHICS_H

#include "texturing/texturesCombo.h"
#include "game/consts/constexpr.h"
#include <vector>
#include <array>
#include <string>

struct Essentials;
namespace sdl2{ class Font; }
class ScoresData;

class ScoresGraphics
{
private:
	TextureCombo title;
	std::vector< TextureCombo > skillText;
	std::array< std::vector< TextureCombo >, SkillGameMax > scoresTexts;

public:
	explicit ScoresGraphics(Essentials& essentials, const sdl2::Font& font, const ScoresData& data);
	~ScoresGraphics() = default;
	ScoresGraphics( const ScoresGraphics& ) = delete;
	ScoresGraphics& operator= ( const ScoresGraphics& ) = delete;
	ScoresGraphics( ScoresGraphics&& ) = default;
	ScoresGraphics& operator= ( ScoresGraphics&& ) = default;

	void drawTexts(Essentials& essentials) const;

private:
	void drawSkillLevels(Essentials& essentials) const;
	void drawScores(Essentials& essentials) const;
	void createTexts(Essentials& essentials, const sdl2::Font& font, const ScoresData& data);
	
	SDL_Color getColor(bool isCurrentGame) const;
	
	void addSkillText(Essentials& essentials, const sdl2::Font& font, const std::string& text, int skillNum);
};

#endif //SCORE_GRAPHICS_H