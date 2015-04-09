#include "Level.h"
#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>


Level::Level()
{
}

void Level::load(string fileName)
{
	// Loads the level
	ifstream file;

	file.open(fileName);
	if (file.fail()) {
		perror(fileName.c_str());
		system("PAUSE"); // System("PAUSE")
		exit(1);
	}
	string line;
	while (getline(file, line)){
		pLevelData.push_back(line);
	}
	file.close();

	// Process the level

	char tile;

	for (int i = 0; i < pLevelData.size(); i++) {
		for (int j = 0; j < pLevelData[i].size(); j++){
			tile = pLevelData[i][j];

			switch (tile) {
			case '1': // Team 1
				_armies[0].push_back(new Soldier("C", tile, 1, 10, 5, 20, 0));
				_armies[0].back()->setPosition(j, i);
				break;
			case '2': //  Team 2
				_armies[1].push_back(new Soldier("2", tile, 2, 10, 5, 35, 1));
				_armies[1].back()->setPosition(j, i);
				break;
			case '#': // All the tiles that don't require extra processing. eg. walls/floor
			case '.':
				break;
			default: // If we get here that means we haven't registered the tile so print out a warning
				printf("Warning: Uknown tile %c at %d, %d", tile, j, i);
				system("Pause");
				break;

			}
		}
	}
}

	void Level::print()
{
	cout << string(100, '\n');
	for (int i = 0; i < pLevelData.size(); i++) {
		printf("%s\n", pLevelData[i].c_str());
	}
	printf("\n");
}

void Level::update()
{
	char move;
	int i = 0;
	bool isDone = false;
	// Loops until done 
	while (isDone == false){
		isDone = true;	
		// Loops through all armies
		for (int j = 0; j < NUM_ARMIES; j++) {
			if (i < _armies[j].size()) {
				move = _armies[j][i]->getMove(_armies, NUM_ARMIES);
				processSoldierMove(move, _armies[j][i]);
				isDone = false;
			}
		}
		i++;
	}
}

char Level::getTile(int x, int y)
{
	return  pLevelData[y][x];
	
}

void Level::setTile(int x, int y, char tile)
{
	pLevelData[y][x] = tile;
}

void Level::processSoldierMove(char direction, Soldier * soldier)
{
	int x, y; 
	int targetX, targetY;

	
	soldier->getPosition(x, y);

	switch (direction){
	case 'w': // Up
		targetX = x; 
		targetY = y - 1;
		break;
	case 'a': // Left
		targetX = x - 1;
		targetY = y;
		break;
	case 's': // Down
		targetX = x;
		targetY = y + 1;
		break;
	case 'd': // Right
		targetX = x + 1;
		targetY = y;
		break;

	}
	char targetTile = getTile(targetX, targetY);
	
	switch (targetTile) {
	case '#':
		break;
	case '.':
		moveSoldier(soldier, targetX, targetY);
		break;

	}


}

void Level::moveSoldier(Soldier *soldier, int targetX, int targetY)
{
	int x, y;
	soldier->getPosition(x, y); 

	setTile(x, y, '.');
	setTile(targetX, targetY, soldier->getTile());

	soldier->setPosition(targetX, targetY);
}