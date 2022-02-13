#ifndef GAME_TEXTURING_H
#define GAME_TEXTURING_H

#include "texturing/texturesCombo.h"
#include <vector>

struct AppLogFiles;
namespace sdl2{ class RendererWindow; }

class SquaresDrawing
{
private:
	std::vector< TextureCombo > squaresTextures;
	
public:
	explicit SquaresDrawing(AppLogFiles& logs, sdl2::RendererWindow& rndWnd);
	~SquaresDrawing() = default;
	SquaresDrawing( const SquaresDrawing& Copy ) = delete;
	SquaresDrawing& operator= ( const SquaresDrawing& Copy ) = delete;
	
	void drawSquare(unsigned colorIndex, int posx, int posy, sdl2::RendererWindow& render);
};

#endif //GAME_TEXTURING_H