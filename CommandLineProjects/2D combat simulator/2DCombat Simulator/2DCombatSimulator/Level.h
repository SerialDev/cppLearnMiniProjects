#pragma once
#include <vector>
#include <string> 
#include "Soldier.h"

using namespace std;

const int NUM_ARMIES = 2;


class Level
{
public:
	Level();

	void load(string fileName);
	void print();

	void update();

	// Getters
	char getTile(int x, int y);
	// Setters
	void setTile(int x, int y, char tile);
	
private:
	vector <string> pLevelData;
	vector <Soldier *> _armies[NUM_ARMIES];

	void processSoldierMove(char direction, Soldier * soldier);
	void moveSoldier(Soldier *soldier, int targetX, int targetY);
};

