#include "TextureCache.h"
#include "imageLoader.h"
#include <iostream>


TextureCache::TextureCache()
{
}


TextureCache::~TextureCache()
{
}

GLTexture TextureCache::getTexture(std::string texturePath)
{
	// std::map<std::string, GLTexture>::iterator declared through auto
	// Look up the texture to see if it is in the map
	auto mit = _textureMap.find(texturePath);

	// Check if it is not in the map
	if (mit == _textureMap.end())
	{
		// Load the texture
		GLTexture newTexture = imageLoader::loadPNG(texturePath);

		// Insert it into the map
		_textureMap.insert(make_pair(texturePath, newTexture));

		std::cout << "Loaded Texture\n";
		return newTexture;
	}
	std::cout << "Used Cache Texture!\n";
	
	return mit->second;
}