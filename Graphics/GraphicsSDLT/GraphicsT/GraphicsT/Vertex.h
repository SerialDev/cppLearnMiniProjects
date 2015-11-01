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

struct UV
{
	float u;
	float v;
};

struct Vertex
{
	Position position;
	
	// 4 bytes for an RBG colour
	Color color;

	// UV texture coordinates
	UV uv;

	void setPosition(float x, float y)
	{
		position.x = x;
		position.y = y;
	}

	void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a)
	{
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;
	}

	void setUV(float u, float v)
	{
		uv.u = u;
		uv.v = v;
	}

};