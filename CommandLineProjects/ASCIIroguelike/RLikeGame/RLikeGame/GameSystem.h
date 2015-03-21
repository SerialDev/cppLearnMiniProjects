#pragma once
#include "Player.h"
#include "Level.h"
#include <string>

using namespace std;

class GameSystem
{
public:
	GameSystem(string levelFileName);

	void playGame();
	void playerMove();

private:
	Level plevel;
	Player pPlayer;
};

