#include "Sprite.h"
#include "Vertex.h"
#include "ResourceManager.h"

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
void Sprite::init(float x, float y, float width, float height, std::string texturePath)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;

	_texture = ResourceManager::getTexture(texturePath);

	// Generate buffer if it hasn't already been generated
	if (_vboID == 0){
		glGenBuffers(1, &_vboID);
	}

	/* This array will hold vertex data
	6 vertices, each vertex has 2 floats for X and Y */
	Vertex vertexData[6];

	// First triangle
	vertexData[0].setPosition(x + width, y + height);
	vertexData[0].setUV(1.0f, 1.0f);
	
	vertexData[1].setPosition(x, y + height);
	vertexData[1].setUV(0.0f, 1.0f);

	vertexData[2].setPosition(x, y);
	vertexData[2].setUV(0.0f, 0.0f);

	// Second triangle
	vertexData[3].setPosition(x, y);
	vertexData[3].setUV(0.0f, 0.0f);

	vertexData[4].setPosition(x + width, y);
	vertexData[4].setUV(1.0f, 0.0f);

	vertexData[5].setPosition(x + width, y + height);
	vertexData[5].setUV(1.0f, 1.0f);

	for (int i = 0; i < 6; i++){
		vertexData[i].setColor(255, 0, 255, 255);
		
	}

	vertexData[1].setColor(0, 0, 255, 255);

	vertexData[4].setColor(0, 255, 0, 255);
	


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
	glBindTexture(GL_TEXTURE_2D, _texture.id);

	// Bind the buffer object
	glBindBuffer(GL_ARRAY_BUFFER, _vboID); 

	// Tell OpenGL to use first attribute array, right now only position is used
	glEnableVertexAttribArray(0);

	// This is the position attribute pointer
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

	// This is the colour attribute pointer
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));

	// This is the UV attribute pointer
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

	// Draw 6 vertices to the screen
	glDrawArrays(GL_TRIANGLES, 0, 6);

	// Disable the vertex attrib array (essential)
	glDisableVertexAttribArray(0);

	// Unbind the VBO 
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}