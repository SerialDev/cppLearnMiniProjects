#include "MainGame.h"
#include "Errors.h"


#include <iostream>
#include <string>




// Constructor, just initializes private member variables
MainGame::MainGame() :
	_screenWitdh(1024),
	_screenHeight(768),
	_time(0.0f),
	_window(nullptr),
	_gameState(GameState::PLAY),
	_maxFPS(60.0f)
{


}

// Destructor
MainGame::~MainGame()
{
}


// This runs the game
void MainGame::run()
{
	initSystems();

	// Initialize the sprite (temp)
	_sprites.push_back(new Sprite());
	_sprites.back()->init(-1.0f, -1.0f, 2.0f, 2.0f, "Textures/jimmyJump_pack/PNG/CharacterRight_Standing.png");

	_sprites.push_back(new Sprite());
	_sprites.back()->init(0.0f, -1.0f, 2.0f, 2.0f, "Textures/jimmyJump_pack/PNG/CharacterRight_Standing.png");

	// This only returns when the game ends
	gameLoop();
}

// Initialize SDL and OpenGL
void MainGame::initSystems()
{
	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// Open an SDL window
	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWitdh, _screenHeight, SDL_WINDOW_OPENGL);
	if (_window == nullptr) {
		fatalError("SDL Window could not be created!");
	}

	// Set up OpenGL context
	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr) {
		fatalError("SDL_GL context could not be created!");
	}

	// Set up glew
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Could not initialize glew!");
	}
	
	/* Set a double buffered window
	using SDL to prevent flickering*/
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	initShaders();
}

void MainGame::initShaders()
{
	_colorProgram.compileShaders("Shaders/colorshading.vert", "Shaders/colorshading.frag");
	_colorProgram.addAttribute("vertexPosition");
	_colorProgram.addAttribute("vertexColor");
	_colorProgram.addAttribute("vertexUV");
	_colorProgram.linkShaders();
}

// Main game loop
void MainGame::gameLoop()
{
	// Will loop until GameState is set to EXIT
	while (_gameState != GameState::EXIT){
		// Used for frame time measuring
		float startTicks = SDL_GetTicks();
		processInput();
		_time += 0.01;
		drawGame();
		calculateFPS();

		// Print only once every 10 frames
		static int frameCounter = 0;
		frameCounter++;
		if (frameCounter = 10) {
			std::cout << _fps << std::endl;
			frameCounter = 0;
		}

		float frameTicks = SDL_GetTicks() - startTicks;

		// Limit FPS to the max FPS
		if (1000.0f / _maxFPS > frameTicks) {
			SDL_Delay(1000.0f / _maxFPS - frameTicks);
		}
	}
}

// Process Input using SDL
void MainGame::processInput()
{
	SDL_Event evnt;

	// Will keep looping until there are no more events to process
	while (SDL_PollEvent(&evnt)){
		switch (evnt.type){
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			//std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
			break;
		}

	}
}

// Draws the game using OpenGL
void MainGame::drawGame()
{


	// Set base depth to 1.0
	glClearDepth(1.0);
	// Clear colour and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_colorProgram.use();
	glActiveTexture(GL_TEXTURE0);
	GLint textureLocation = _colorProgram.getUniformLocation("mySampler");
	glUniform1i(textureLocation, 0);

	GLint timeLocation = _colorProgram.getUniformLocation("time");
	glUniform1f(timeLocation, _time);

	// Draw the sprite
	for (int i = 0; i < _sprites.size(); i++){
		_sprites[i]->draw();
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	_colorProgram.unuse();

	// Swap out our buffer and draw everything to the screen
	SDL_GL_SwapWindow(_window);
}

void MainGame::calculateFPS(){
	static const int NUM_SAMPLES = 10;
	static float frameTimes[NUM_SAMPLES];
	static int currentFrame = 0;

	static float prevTicks = SDL_GetTicks();
	float currentTicks = SDL_GetTicks();

	_frameTime = currentTicks - prevTicks;
	frameTimes[currentFrame % NUM_SAMPLES] = _frameTime;

	prevTicks = currentTicks; 

	int count;

	currentFrame++;

	if (currentFrame < NUM_SAMPLES) {
		count = currentFrame;
	}
	else {
		count = NUM_SAMPLES;
	}

	float frameTimeAverage = 0;
	for (int i = 0; i < count; i++) {
		frameTimeAverage += frameTimes[i];
	}
	frameTimeAverage /= count;

	if (frameTimeAverage > 0) {
		_fps = 1000.0f / frameTimeAverage;
	}
	else {
		_fps = 60.0f;
	}


}