#include "Level.h"
#include <fstream>
#include <iostream>
#include <cstdio>
#include <random>

//Constructor
Level::Level() {
}

//The destructor makes sure to free all of the memory we allocated with new
Level::~Level() {
	for (int i = 0; i < NUM_ARMIES; i++) {
		for (int j = 0; j < _armies[i].size(); j++) {
			delete _armies[i][j];
		}
	}
}

//This loads a level from the file fileName
void Level::load(string fileName) {

	//Loads the level
	ifstream file;

	//Open the file and quit if it fails to open
	file.open(fileName);
	if (file.fail()) {
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	string line;

	//Loop through the entire file, getting each row and
	//putting it in the line string.
	while (getline(file, line)) {
		//Push the current line onto the _levelData array
		_levelData.push_back(line);
		_soldierGrid.push_back(vector <Soldier *>());
		_soldierGrid.back().resize(line.size(), nullptr);
	}

	//Close the file so we arent keeping open for longer than we need to
	file.close();


	char tile;

	//Loop through the game board and process the level
	for (int i = 0; i < _levelData.size(); i++) {
		//Loop through each letter in row i
		for (int j = 0; j < _levelData[i].size(); j++) {
			//This is the current tile we are looking at
			tile = _levelData[i][j];

			//Check the tile to see what we should do
			switch (tile) {
			case '1': //Team 1
				_armies[0].push_back(new Soldier("1", tile, 1, 10, 5, 10, 0));
				_armies[0].back()->setPosition(j, i);
				_soldierGrid[i][j] = _armies[0].back();
				break;
			case '2': //Team 2
				_armies[1].push_back(new Soldier("2", tile, 1, 10, 5, 10, 1));
				_armies[1].back()->setPosition(j, i);
				_soldierGrid[i][j] = _armies[1].back();
				break;
			case '#': //All the tiles that dont need extra processing, in this case, walls and air
			case '.':
				//Doesnt need to do anthing, just break.
				break;
			default: //If we get here, that means we haven't registered the tile, so print out a warning
				printf("WARNING: Unknown tile %c at %d,%d", tile, j, i);
				system("Pause");
				break;
			}
		}
	}

	random_device::result_type seed = std::random_device()();
	mt19937 randomEngine(seed);
	Soldier *tmp;

	//Shuffle armies
	for (int i = 0; i < NUM_ARMIES; i++) {
		//Iterate backwards through vector
		for (int j = _armies[i].size() - 1; j > 1; j--) {
			uniform_int_distribution<int> randomSwap(0, j - 1);
			int swap = randomSwap(randomEngine);
			tmp = _armies[i][j];
			_armies[i][j] = _armies[i][swap];
			_armies[i][swap] = tmp;
		}
	}

}

//Prints out the level. TODO: print out the player stats to the right
void Level::print() {

	//Trick for clearing the screen (kinda)
	printf("%s", string(100, '\n').c_str());

	//could have also used
	//cout << string(100, '\n');
	//but printf is typically faster

	for (int i = 0; i < _levelData.size(); i++) {
		printf("%s\n", _levelData[i].c_str());
	}
}

//Updates all the soldier AI
void Level::update() {
	char move;
	int i = 0;
	bool isDone = false;
	//loops until done
	while (isDone == false) {
		isDone = true;
		//loops through all armies
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




//Gets a tile from the board
char Level::getTile(int x, int y) {
	return _levelData[y][x];
}

//Gets a soldier from the board
Soldier *Level::getSoldier(int x, int y) {
	return _soldierGrid[y][x];
}

//sets a tile on the board
void Level::setTile(int x, int y, char tile, Soldier *soldier) {
	_levelData[y][x] = tile;
	_soldierGrid[y][x] = soldier;
}

//Process an soldier movement
void Level::processSoldierMove(char direction, Soldier *soldier) {

	int x, y;
	int targetX, targetY;

	soldier->getPosition(x, y);

	switch (direction) {
	case 'w': //up
		targetX = x;
		targetY = y - 1;
		break;
	case 'a': //left
		targetX = x - 1;
		targetY = y;
		break;
	case 's': //down
		targetX = x;
		targetY = y + 1;
		break;
	case 'd': //right
		targetX = x + 1;
		targetY = y;
		break;
	case '.':
		return;
	}

	char targetTile = getTile(targetX, targetY);

	switch (targetTile) {
	case '#':
		break;
	case '.':
		moveSoldier(soldier, targetX, targetY);
		break;
	default:
		battle(soldier, targetX, targetY);
		break;
	}

}

//Simulate a battle between soldier and the soldier at targetX, targetY
void Level::battle(Soldier *soldier, int targetX, int targetY) {
	int x, y;
	int enemyArmy;
	soldier->getPosition(x, y);

	Soldier *targetSoldier = getSoldier(targetX, targetY);
	if (targetSoldier == nullptr) {
		return;
	}
	enemyArmy = targetSoldier->getArmy();
	if (enemyArmy == soldier->getArmy()) {
		return;
	}

	int result = targetSoldier->takeDamage(soldier->attack());
	if (result == 1) {
		for (int i = 0; i < _armies[enemyArmy].size(); i++) {
			if (_armies[enemyArmy][i] == targetSoldier) {
				_armies[enemyArmy][i] = _armies[enemyArmy].back();
				_armies[enemyArmy].pop_back();

				delete targetSoldier;

				setTile(targetX, targetY, '.', nullptr);
				break;
			}
		}
	}

}

//Moves a soldier towards the target
void Level::moveSoldier(Soldier *soldier, int targetX, int targetY) {
	int x, y;
	soldier->getPosition(x, y);

	setTile(x, y, '.', nullptr);
	setTile(targetX, targetY, soldier->getTile(), soldier);

	soldier->setPosition(targetX, targetY);
}