#pragma once

#include <SDL\SDL.h>
#include <GL\glew.h>

#include "Sprite.h"

enum class GameState {PLAY, EXIT};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

	

private:
	void initSystems();
	void gameLoop();
	void processInput();
	void drawGame();

	SDL_Window* _window;
	int _screenWitdh;
	int _screenHeight;
	GameState _gameState;

	Sprite _sprite;

};

