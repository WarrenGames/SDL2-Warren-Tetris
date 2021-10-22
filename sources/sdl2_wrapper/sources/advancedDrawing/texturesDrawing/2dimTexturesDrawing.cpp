#include "advancedDrawing/texturesDrawing/2dimTexturesDrawing.h"
#include "advancedDrawing/texturesLoading/2dimTexturesLoading.h"
#include "texturing/rendererWindow.h"

Matrix2DTexturesDrawing::Matrix2DTexturesDrawing(const Coord2D& size):
	sprites{size}
{
	
}

Matrix2DTexturesDrawing::Matrix2DTexturesDrawing( const Matrix2DTexturesLoading& loadedTextures ):
	sprites{ loadedTextures.width(), loadedTextures.height() }
{
	resetTextures(loadedTextures);
}

void Matrix2DTexturesDrawing::resetTextures(const Matrix2DTexturesLoading& loadedTextures)
{
	if( loadedTextures.wasLoadingPerfect() && loadedTextures.size() > 0 )
	{
		for( size_t height{0} ; height < loadedTextures.height() ; ++height )
		{
			for( size_t width{0} ; width < loadedTextures.width() ; ++width )
			{
				sprites(width, height) = loadedTextures(width, height);
			}
		}
	}
}

void Matrix2DTexturesDrawing::draw(sdl2::RendererWindow& rndWnd, const Coord2D& coords) const
{
	sprites(coords).draw(rndWnd);
}

void Matrix2DTexturesDrawing::draw(sdl2::RendererWindow& rndWnd, const Coord2D& coords, int xpos, int ypos)
{
	sprites(coords).draw(rndWnd, xpos, ypos);
}

void Matrix2DTexturesDrawing::draw(sdl2::RendererWindow& rndWnd, const Coord2D& coords, const Offset& position)
{
	sprites(coords).draw(rndWnd, position);
}

void Matrix2DTexturesDrawing::drawToCenter(sdl2::RendererWindow& rndWnd, const Coord2D& coords, int xpos, int ypos)
{
	sprites(coords).drawToCenter(rndWnd, xpos, ypos);
}

void Matrix2DTexturesDrawing::drawToCenter(sdl2::RendererWindow& rndWnd, const Coord2D& coords, const Offset& position)
{
	sprites(coords).drawToCenter(rndWnd, position);
}

void Matrix2DTexturesDrawing::drawToCenter(sdl2::RendererWindow& rndWnd, unsigned width, unsigned height, int xpos, int ypos)
{
	sprites(width, height).drawToCenter(rndWnd, xpos, ypos);
}

std::vector< sdl2::Sprite >::const_iterator Matrix2DTexturesDrawing::begin() const
{
	return sprites.begin();
}

std::vector< sdl2::Sprite >::const_iterator Matrix2DTexturesDrawing::end() const
{
	return sprites.end();
}

std::vector< sdl2::Sprite >::iterator Matrix2DTexturesDrawing::begin()
{
	return sprites.begin();
}

std::vector< sdl2::Sprite >::iterator Matrix2DTexturesDrawing::end()
{
	return sprites.end();
}
	

sdl2::Sprite& Matrix2DTexturesDrawing::operator() ( const Coord2D& coords)
{
	return sprites(coords);
}

const sdl2::Sprite& Matrix2DTexturesDrawing::operator() ( const Coord2D& coords) const
{
	return sprites(coords);
}

sdl2::Sprite& Matrix2DTexturesDrawing::operator() (size_t width, size_t height)
{
	return sprites(width, height);
}

const sdl2::Sprite& Matrix2DTexturesDrawing::operator() (size_t width, size_t height) const
{
	return sprites(width, height);
}

size_t Matrix2DTexturesDrawing::width() const
{
	return sprites.width();
}

size_t Matrix2DTexturesDrawing::height() const
{
	return sprites.height();
}