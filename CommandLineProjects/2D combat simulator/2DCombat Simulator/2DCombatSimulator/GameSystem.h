#pragma once
#include "Level.h"
#include <string>

using namespace std;

class GameSystem
{
public:
	GameSystem(string levelFileName);

	void playGame();


private:
	Level plevel;

};

