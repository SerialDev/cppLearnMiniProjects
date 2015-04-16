#include "Sprite.h"


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
	float vertexData[12];

	// First triangle
	vertexData[0] = x + width;
	vertexData[1] = y + height; 

	vertexData[2] = x;
	vertexData[3] = y + height; 

	vertexData[4] = x;
	vertexData[5] = y;

	// Second triangle
	vertexData[6] = x;
	vertexData[7] = y;

	vertexData[8] = x + width;
	vertexData[9] = y;

	vertexData[10] = x + width;
	vertexData[11] = y + height;

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

	// Point OpenGL to the data in our VBO.
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	// Draw 6 vertices to the screen
	glDrawArrays(GL_TRIANGLES, 0, 6);

	// Disable the vertex attrib array (essential)
	glDisableVertexAttribArray(0);

	// Unbind the VBO 
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}