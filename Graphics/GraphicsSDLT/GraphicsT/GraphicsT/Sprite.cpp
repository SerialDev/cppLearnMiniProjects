#include "Sprite.h"
#include "Vertex.h"
#include <cstddef>

Sprite::Sprite()
{
	// Initialize bufferID to 0
	_vboID = 0;
}


Sprite::~Sprite()
{
	// Delete Buffer when done
	if (_vboID != 0) {
		glDeleteBuffers(1, &_vboID);
	}
}

/* Initialize the Sprite's VBO. x, y, width and heigh. 
It is in the normalized coordinate space, therefore [-1, 1]*/
void Sprite::init(float x, float y, float width, float height)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;

	// Generate buffer if it hasn't already been generated
	if (_vboID == 0){
		glGenBuffers(1, &_vboID);
	}

	/* This array will hold vertex data
	6 vertices, each vertex has 2 floats for X and Y */
	Vertex vertexData[6];

	// First triangle
	vertexData[0].position.x = x + width;
	vertexData[0].position.y = y + height; 

	vertexData[1].position.x = x;
	vertexData[1].position.y = y + height;

	vertexData[2].position.x = x;
	vertexData[2].position.y = y;

	// Second triangle
	vertexData[3].position.x = x;
	vertexData[3].position.y = y;

	vertexData[4].position.x = x + width;
	vertexData[4].position.y = y;

	vertexData[5].position.x = x + width;
	vertexData[5].position.y = y + height;

	for (int i = 0; i < 6; i++){
		vertexData[i].color.r = 255;
		vertexData[i].color.g = 0;
		vertexData[i].color.b = 255;
		vertexData[i].color.a = 255;
	}

	vertexData[1].color.r = 0;
	vertexData[1].color.g = 0;
	vertexData[1].color.b = 255;
	vertexData[1].color.a = 255;

	vertexData[4].color.r = 0;
	vertexData[4].color.g = 255;
	vertexData[4].color.b = 0;
	vertexData[4].color.a = 255;
	// Tell OpenGL to bind our vertex buffer object 
	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
	// Upload the data to the GPU
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	// Unbind the buffer (opt)
	glBindBuffer(GL_ARRAY_BUFFER, 0);


}

// Draw the sprite on the screen 
void Sprite::draw()
{
	// Bind the buffer object
	glBindBuffer(GL_ARRAY_BUFFER, _vboID); 

	// Tell OpenGL to use first attribute array, right now only position is used
	glEnableVertexAttribArray(0);

	// This is the position attribute pointer
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

	// This is the colour attribute pointer
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));

	// Draw 6 vertices to the screen
	glDrawArrays(GL_TRIANGLES, 0, 6);

	// Disable the vertex attrib array (essential)
	glDisableVertexAttribArray(0);

	// Unbind the VBO 
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}