#include "ResourceManager.h"


TextureCache ResourceManager::textureCache;

GLTexture ResourceManager::getTexture(std::string texturePath)
{
	return textureCache.getTexture(texturePath);
}
