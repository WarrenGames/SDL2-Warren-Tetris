#include "advancedDrawing/texturesLoading/animFileTextures.h"
#include "logging/logsStruct.h"
#include "texturing/rendererWindow.h"
#include <sstream>
#include <cassert>

AnimLoadData::AnimLoadData(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const std::string& texturePath, unsigned frameDur):
	tload{logs, rndWnd, texturePath},
	frameDuration{frameDur}
{
	
}

AnimLoadData::operator bool() const
{
	return tload;
}

AnimTextureElement::AnimTextureElement():
	isLoadingPerfect{true}
{
	
}

AnimTextureElement::AnimTextureElement(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const std::string& listFile):
	isLoadingPerfect{true}
{
	lookUpListFile(logs, rndWnd, listFile);
}

bool AnimTextureElement::wasLoadingPerfect() const
{
	return isLoadingPerfect;
}

size_t AnimTextureElement::size() const
{
	return loadedTextures.size();
}

std::vector< AnimLoadData >::const_iterator AnimTextureElement::begin() const
{
	return loadedTextures.begin();
}

std::vector< AnimLoadData >::const_iterator AnimTextureElement::end() const
{
	return loadedTextures.end();
}

void AnimTextureElement::addTexture(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const std::string& textureFilePath, unsigned frameDuration)
{
	if( AnimLoadData anim{logs, rndWnd, textureFilePath, frameDuration} )
	{
		loadedTextures.emplace_back( std::move( anim ) );
	}
	else{
		logs.error.wrRessourceCreationError("AnimLoadData (texture and its frame duration)", textureFilePath + "couldn't be loaded.");
	}
}

void AnimTextureElement::readLine(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, std::istringstream& lineStream)
{
	unsigned frameDuration{0};
	std::string texturePath;
	if( lineStream >> texturePath >> frameDuration )
	{
		addTexture(logs, rndWnd, texturePath, frameDuration);
	}
}

void AnimTextureElement::lookUpListFile(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const std::string& listFilePath)
{
	if( std::ifstream file{ listFilePath } )
	{
		std::string fileLine;
		while( std::getline( file, fileLine ) )
		{
			std::istringstream lineStream{ fileLine };
			readLine(logs, rndWnd, lineStream);
		}
	}
	else{
		isLoadingPerfect = false;
		logs.error.wrFileOpeningError(listFilePath, "AnimTextureElement data");
	}
}

LoadedAnimTexturesList::LoadedAnimTexturesList():
	isLoadingPerfect{true}
{
	
}

bool LoadedAnimTexturesList::wasLoadingPerfect() const
{
	return isLoadingPerfect;
}

void LoadedAnimTexturesList::lookUpListFile(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const std::string& listFilePath, const std::string& refListDirectory)
{
	if( std::ifstream referenceFilesList{ listFilePath } )
	{
		std::string fileLine;
		while( std::getline( referenceFilesList, fileLine ) )
		{
			animations.emplace_back( AnimTextureElement{logs, rndWnd, refListDirectory + fileLine} );
		}
	}
	else{
		logs.error.wrFileOpeningError(listFilePath, "load animation textures from '" + listFilePath + "' file with this directory: " + refListDirectory);
		isLoadingPerfect = false;
	}
}

size_t LoadedAnimTexturesList::size() const
{
	return animations.size();
}

const AnimTextureElement& LoadedAnimTexturesList::operator[](size_t index) const
{
	assert( index < animations.size() );
	return animations[index];
}

std::vector< AnimTextureElement >::const_iterator LoadedAnimTexturesList::begin() const
{
	return animations.begin();
}

std::vector< AnimTextureElement >::const_iterator LoadedAnimTexturesList::end() const
{
	return animations.end();
}
