#version 130
// The vertex shader opperates on each vertex

// Input data from the VBO. Each vertex is 2 floats
in vec2 vertexPosition;
in vec4 vertexColor;
in vec2 vertexUV;

out vec2 fragmentPosition;
out vec4 fragmentColor;
out vec2 fragmentUV;

void main() 
{
    // Set the x, y position on the screen
    gl_Position.xy = vertexPosition;
	
	// The z position is zero, 2D
	gl_Position.z = 0.0;
	
	// Indicates the coordinates are normalized
	gl_Position.w = 1.0;
	
	fragmentPosition = vertexPosition;
	
	fragmentColor = vertexColor;
	
	fragmentUV = vec2(vertexUV.x, 1.0f - vertexUV.y);

}