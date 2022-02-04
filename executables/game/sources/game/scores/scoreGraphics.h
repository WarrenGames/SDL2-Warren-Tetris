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
	std::array< std::vector< TextureCombo >, GAME_MAX > scoresTexts;

public:
	ScoresGraphics(Essentials& essentials, const sdl2::Font& arial, const ScoresData& data);
	~ScoresGraphics() = default;
	ScoresGraphics& operator= ( const ScoresGraphics& ) = delete;
	ScoresGraphics ( const ScoresGraphics& ) = delete;

	void drawTexts(Essentials& essentials) const;

private:
	void drawSkillLevels(Essentials& essentials) const;
	void drawScores(Essentials& essentials) const;
	void createTexts(Essentials& essentials, const sdl2::Font& arial, const ScoresData& data);
	
	SDL_Color getColor(bool isCurrentGame) const;
	
	void addSkillText(Essentials& essentials, const sdl2::Font& arial, const std::string& text, int skillNum);
};

#endif //SCORE_GRAPHICS_H