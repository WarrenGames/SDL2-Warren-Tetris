#include "game/drawing/squareTexturing.h"
#include "logging/logsStruct.h"
#include "game/consts/constexpr.h"
#include <cassert>

SquaresDrawing::SquaresDrawing(AppLogFiles& logs, sdl2::RendererWindow& rndWnd)
{
	for( size_t i{0} ; i < SQR_COLOR_NUM ; ++i )
	{
		squaresTextures.emplace_back(TextureCombo{logs, rndWnd, "textures/elements/square" + std::to_string(i) + ".png" } );
	
		if( false == squaresTextures.back() )
		{
			logs.error << "Error at loading texture file 'square" << i << ".png in directory 'textures/elements'.\n"; 
		}
	}
}

void SquaresDrawing::drawSquare(size_t colorIndex, int posx, int posy, sdl2::RendererWindow& rndWnd)
{
	assert( colorIndex < squaresTextures.size() );
	squaresTextures[colorIndex].draw(rndWnd, posx, posy);
}