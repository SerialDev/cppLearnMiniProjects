#pragma once
#include <vector>
#include <string> 
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Level
{
public:
	Level();

	void load(string fileName, Player &player);
	void print();

	void movePlayer(char input, Player &player);
	void updateEnemies(Player &player);

	// Getters
	char getTile(int x, int y);
	// Setters
	void setTile(int x, int y, char tile);
	
private:
	vector <string> pLevelData;
	vector <Enemy> pEnemies;
private:
	void processPlayerMove(Player &player, int targetX, int targetY);
	void processEnemyMove(Player &player, int enemyIndex, int targetX, int targetY);
	void battleMonster(Player &player, int targetX, int targetY);
};

