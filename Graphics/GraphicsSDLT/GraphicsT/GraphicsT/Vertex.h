# pragma once

#include <GL\glew.h>

struct Position
{
	float x;
	float y;
};

struct Color
{
	// unsigned char 1 byte guaranteed, may need padding for alignment issues, in order for it to be a multiple of 4 bytes
	// RGB and alpha channel
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;
};

struct Vertex
{
	Position position;
	
	// 4 bytes for an RBG colour
	Color color;

};