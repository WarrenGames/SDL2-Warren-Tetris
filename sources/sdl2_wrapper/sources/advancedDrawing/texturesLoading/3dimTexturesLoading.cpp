#include "advancedDrawing/texturesLoading/3dimTexturesLoading.h"
#include "logging/logsStruct.h"
#include "texturing/rendererWindow.h"
#include <sstream>

Matrix3DTexturesLoading::Matrix3DTexturesLoading():
	isLoadingPerfect{true}
{
	
}

Matrix3DTexturesLoading::Matrix3DTexturesLoading(const Coord3D& matSize):
	textures{matSize},
	isLoadingPerfect{true}
{
	
}

Matrix3DTexturesLoading::Matrix3DTexturesLoading(const Coord3D& matSize, AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const std::string& filePath):
	textures{matSize},
	isLoadingPerfect{true}
{
	openFileForLoading(logs, rndWnd, filePath);
}

bool Matrix3DTexturesLoading::wasLoadingPerfect() const
{
	return isLoadingPerfect;
}

size_t Matrix3DTexturesLoading::width() const
{
	return textures.width();
}

size_t Matrix3DTexturesLoading::height() const
{
	return textures.height();
}

size_t Matrix3DTexturesLoading::depth() const
{
	return textures.depth();
}

size_t Matrix3DTexturesLoading::size() const
{
	return textures.size();
}

const sdl2::TextureLoader& Matrix3DTexturesLoading::getLoadedTexture(const Coord3D& coords) const
{
	return textures(coords);
}

void Matrix3DTexturesLoading::openFileForLoading(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const std::string& filePath)
{
	if( std::ifstream texturesListFile{ filePath } )
	{
		std::string fileLine;
		while( std::getline( texturesListFile, fileLine ) )
		{
			std::istringstream lineStream{ fileLine };
			readLineAndLoadTexture(logs, rndWnd, lineStream, filePath);
		}
	}
	else{
		logs.error.wrFileOpeningError(filePath, "load 3dim textures matrix");
	}
}

void Matrix3DTexturesLoading::readLineAndLoadTexture(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, std::istringstream& lineStream, const std::string& filePath)
{
	Coord3D coord;
	std::string texturePath;
	if( lineStream >> coord.depth >> coord.height >> coord.width >> texturePath )
	{
		checkTexturePresenceBeforeLoading(logs, rndWnd, coord, texturePath);
	}
	else{
		logs.error.wrReadErrorMessage(filePath, "3d coords and texture path");
	}
}

void Matrix3DTexturesLoading::checkTexturePresenceBeforeLoading(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const Coord3D& coord, const std::string& texturePath)
{
	if( false == textures(coord) )
	{
		if( sdl2::TextureLoader tload{logs, rndWnd, texturePath} )
		{
			textures(coord) = std::move( tload );
		}
	}
	else{
		logs.error.wrRessourceCreationError("sdl2::TextureLoader " + texturePath, "the ressource is present already");
		logs.error << "  ressource coordinates: width( " << coord.width << " ), height( " << coord.height << " ), depth( " << coord.depth << " ).\n";
	}
}