#pragma once
#include "TextureCache.h"
#include <string>

class ResourceManager
{
public:
	static GLTexture getTexture(std::string texturePath);

	static GLuint boundTexture;

private:
	static TextureCache textureCache;
};

