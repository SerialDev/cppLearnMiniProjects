#pragma once
#include "GLTexture.h"

#include <string> 

class imageLoader
{
public:
	static GLTexture loadPNG(std::string filePath);
};

