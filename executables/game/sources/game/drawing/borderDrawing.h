#ifndef BORDER_DRAWING_H
#define BORDER_DRAWING_H

#include "texturing/texturesCombo.h"

struct AppLogFiles;
namespace sdl2{ class RendererWindow; }

class BorderDrawing
{
private:
	TextureCombo graySquare;
	TextureCombo redSquare;

public:
	explicit BorderDrawing(AppLogFiles& logs, sdl2::RendererWindow& rndWnd);
	~BorderDrawing() = default;
	BorderDrawing( const BorderDrawing& Copy ) = delete;
	BorderDrawing& operator= ( const BorderDrawing& Copy ) = delete;
	
	void drawAllBorders(sdl2::RendererWindow& rndWnd);
	void drawWall(sdl2::RendererWindow& rndWnd, int wall_x_pos);
	void drawBottomWall(sdl2::RendererWindow& rndWnd);
};

#endif //BORDER_DRAWING_H