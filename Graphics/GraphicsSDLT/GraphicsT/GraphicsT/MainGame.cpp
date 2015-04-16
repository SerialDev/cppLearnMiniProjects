#include "MainGame.h"


#include <iostream>
#include <string>


// Prints out an error and exits the game
void fatalError(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit...";
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
	exit(1);
	
}

// Constructor, just initializes private member variables
MainGame::MainGame()
{
	_window = nullptr;
	_screenWitdh = 1024;
	_screenHeight = 768;
	_gameState = GameState::PLAY;
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
	_sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);

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
}

// Main game loop
void MainGame::gameLoop()
{
	// Will loop until GameState is set to EXIT
	while (_gameState != GameState::EXIT){
		processInput();
		drawGame();
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
			std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
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

	// Draw the sprite
	_sprite.draw();

	// Swap out our buffer and draw everything to the screen
	SDL_GL_SwapWindow(_window);
}