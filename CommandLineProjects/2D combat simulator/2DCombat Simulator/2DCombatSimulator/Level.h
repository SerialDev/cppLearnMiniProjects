#pragma once
#include <vector>
#include <string>
#include <string>
#include "Soldier.h"

using namespace std;

const int NUM_ARMIES = 2;

//The level stores the data for the level and the soldier list, and does a lot
//of the core game logic
class Level
{
public:
	Level();
	~Level();

	void load(string fileName);
	void print();

	void update();

	//Getters
	char getTile(int x, int y);
	Soldier *getSoldier(int x, int y);
	//Setters
	void setTile(int x, int y, char tile, Soldier *soldier);

private:
	void processSoldierMove(char direction, Soldier *soldier);
	void battle(Soldier *soldier, int targetX, int targetY);
	void moveSoldier(Soldier *soldier, int targetX, int targetY);

	// I added this variable to keep track of how many lines we printed, so that we can pad
	// the bottom of the screen with newlines to keep the game board from jumping around!
	// Stores the level information
	vector <string> _levelData;
	vector <vector <Soldier *> > _soldierGrid;
	vector <Soldier *> _armies[NUM_ARMIES];
};


