#include "game/drawing/borderDrawing.h"
#include "game/consts/constexpr.h"

BorderDrawing::BorderDrawing(AppLogFiles& logs, sdl2::RendererWindow& rndWnd):
	graySquare{logs, rndWnd, "textures/elements/borderSquare.png"},
	redSquare{logs, rndWnd, "textures/elements/gameOverBorderSquare.png"}
{
	
}

void BorderDrawing::drawAllBorders(sdl2::RendererWindow& rndWnd)
{
	drawWall(rndWnd, 0);
	drawWall(rndWnd, (BIGMAT_WIDTH + 1) * SQR_SIZE);
	drawBottomWall(rndWnd);
}

void BorderDrawing::drawWall(sdl2::RendererWindow& rndWnd, int wall_x_pos)
{
	int sprite_y_pos{0};
	for( unsigned y_pos{0} ; y_pos < BIGMAT_HEIGHT ; ++y_pos )
	{
		if( y_pos <= 2 )
		{
			redSquare.draw(rndWnd, wall_x_pos, sprite_y_pos);
		}
		else{
			graySquare.draw(rndWnd, wall_x_pos,sprite_y_pos);
		}
		sprite_y_pos += SQR_SIZE;
	}
}

void BorderDrawing::drawBottomWall(sdl2::RendererWindow& rndWnd)
{
	for(unsigned x_pos{0} ; x_pos < BIGMAT_WIDTH + 2 ; ++x_pos )
	{
		graySquare.draw(rndWnd, x_pos * SQR_SIZE, SCREENH - SQR_SIZE);
	}
}