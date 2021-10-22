#ifndef MATRIX_3_DIMENSIONS_TEXTURES_LOADING_H
#define MATRIX_3_DIMENSIONS_TEXTURES_LOADING_H

#include "texturing/textureLoader.h"
#include "matrices/matrix3D.h"

struct AppLogFiles;
namespace sdl2{ class RendererWindow; }
struct Coord3D;

class Matrix3DTexturesLoading
{
private:
	MatrixTemp3D< sdl2::TextureLoader > textures;
	bool isLoadingPerfect;

public:
	explicit Matrix3DTexturesLoading();
	explicit Matrix3DTexturesLoading(const Coord3D& matSize);
	explicit Matrix3DTexturesLoading(const Coord3D& matSize, AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const std::string& filePath);
	~Matrix3DTexturesLoading() = default;
	Matrix3DTexturesLoading( const Matrix3DTexturesLoading& ) = delete;
	Matrix3DTexturesLoading& operator= ( const Matrix3DTexturesLoading& ) = delete;
	Matrix3DTexturesLoading( Matrix3DTexturesLoading&& ) = default;
	Matrix3DTexturesLoading& operator= ( Matrix3DTexturesLoading&& ) = default;
	
	bool wasLoadingPerfect() const;
	size_t width() const;
	size_t height() const;
	size_t depth() const;
	size_t size() const;
	const sdl2::TextureLoader& getLoadedTexture(const Coord3D& coords) const;
	
	void checkTexturePresenceBeforeLoading(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const Coord3D& coord, const std::string& texturePath);
	
private:
	void openFileForLoading(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const std::string& filePath);
	void readLineAndLoadTexture(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, std::istringstream& lineStream, const std::string& filePath);
};

#endif //MATRIX_3_DIMENSIONS_TEXTURES_LOADING_H