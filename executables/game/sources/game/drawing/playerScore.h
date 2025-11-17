#ifndef SCORE_DRAWING_H
#define SCORE_DRAWING_H

#include "texturing/texturesCombo.h"
#include "text/sdl2ttf_font.h"

struct AppLogFiles;
namespace sdl2{ class RendererWindow; }

class PlayerScore
{
private:
	bool canUpdateScore;
	unsigned score;
	sdl2::Font font;
	TextureCombo scoreTexture;
	
public:
	PlayerScore(AppLogFiles& logs, sdl2::RendererWindow& rndWnd);
	~PlayerScore() = default;
	PlayerScore( const PlayerScore& ) = delete;
	PlayerScore& operator= ( const PlayerScore& ) = delete;
	PlayerScore( PlayerScore&& ) = default;
	PlayerScore& operator= ( PlayerScore&& ) = default;
	
	void updateScoreText(AppLogFiles& logs, sdl2::RendererWindow& rndWnd);
	void addToScore(unsigned toAdd);
	void drawScore(sdl2::RendererWindow& rndWnd) const;
	unsigned getScore() const;
};

#endif //SCORE_DRAWING_H