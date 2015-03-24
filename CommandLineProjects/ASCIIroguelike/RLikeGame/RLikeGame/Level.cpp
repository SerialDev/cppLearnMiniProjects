#include "Level.h"
#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>


Level::Level()
{
}

void Level::load(string fileName, Player &player)
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
			case '@': // Player
				player.setPosition(j, i);
				break;
			case 'S': // Snake
				pEnemies.push_back(Enemy("Snake", tile, 1, 3, 1, 10, 50));
				pEnemies.back().setPosition(j, i);
				break;
			case 'g':
				pEnemies.push_back(Enemy("Goblin", tile, 2, 10, 5, 35, 150));
				pEnemies.back().setPosition(j, i);
				break;
			case 'O':
				pEnemies.push_back(Enemy("Ogre", tile, 4, 20, 40, 200, 500));
				pEnemies.back().setPosition(j, i);
				break;
			case 'B':
				pEnemies.push_back(Enemy("Bandit", tile, 3, 15, 10, 100, 300));
				pEnemies.back().setPosition(j, i);
				break;
			case 'D':
				pEnemies.push_back(Enemy("Dragon", tile, 100, 2000, 2000, 2000, 5000000));
				pEnemies.back().setPosition(j, i);
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

void Level::movePlayer(char input, Player &player)
{
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	switch (input)
	{
	case 'W': // Up
	case 'w':
		processPlayerMove(player, playerX, playerY - 1);
		break;
	case 'S': // Down
	case 's':
		processPlayerMove(player, playerX, playerY + 1);
		break;
	case 'A': // Left
	case 'a':
		processPlayerMove(player, playerX - 1, playerY);
		break;
	case 'D': // Right
	case 'd':
		processPlayerMove(player, playerX + 1, playerY);
		break;
	default:
		printf("INVALID INPUT!\n");
		system("PAUSE"); // System ("PAUSE");
		break;
	}
}

void Level::updateEnemies(Player &player)
{
	char aiMove;
	int playerX;
	int playerY;
	int enemyX;
	int enemyY;

	player.getPosition(playerX, playerY);

	for (int i = 0; i < pEnemies.size(); i++){
		aiMove = pEnemies[i].getMove(playerX, playerY);
		pEnemies[i].getPosition(enemyX, enemyY);

		switch (aiMove)
		{
			// Up
		case 'w':
			processEnemyMove(player, i, enemyX, enemyY - 1);
			break;
			// Down
		case 's':
			processEnemyMove(player, i, enemyX, enemyY + 1);
			break;
			// Left
		case 'a':
			processEnemyMove(player, i, enemyX - 1, enemyY);
			break;
			// Right
		case 'd':
			processEnemyMove(player, i, enemyX + 1, enemyY);
			break;
		}
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

void Level::processPlayerMove(Player &player, int targetX, int targetY)
{
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);
	char moveTile = getTile(targetX, targetY);

	switch (moveTile)
	{
	case '.':
		player.setPosition(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');
		break;
	case '#':
		break;
	default:
		battleMonster(player, targetX, targetY);
		break;
	}
}

void Level::processEnemyMove(Player &player, int enemyIndex, int targetX, int targetY)
{
	int playerX;
	int playerY;
	int enemyX;
	int enemyY; 

	pEnemies[enemyIndex].getPosition(enemyX, enemyY);
	player.getPosition(playerX, playerY);
	char moveTile = getTile(targetX, targetY);

	switch (moveTile)
	{
	case '.':
		pEnemies[enemyIndex].setPosition(targetX, targetY);
		setTile(enemyX, enemyY, '.');
		setTile(targetX, targetY, pEnemies[enemyIndex].getTile());
		break;
	case '@':
		battleMonster(player, enemyX, enemyY);
		break;
	default:
		break;
	}
}

void Level::battleMonster(Player &player, int targetX, int targetY)
{
	int enemyX;
	int enemyY;
	int playerX;
	int playerY;
	int attackRoll;
	int attackResult;
	string enemyName;

	player.getPosition(playerX, playerY);

	for (int i = 0; i < pEnemies.size(); i++){
		pEnemies[i].getPosition(enemyX, enemyY);
		enemyName = pEnemies[i].getName();
		if (targetX == enemyX && targetY == enemyY) {

			// Battle!
			attackRoll = player.attack();
			printf("Player attacks %s with a roll of %d\n",enemyName.c_str(), attackRoll);
			system("PAUSE");
			attackResult = pEnemies[i].takeDamage(attackRoll);
			if (attackResult != 0) {
				setTile(targetX, targetY, 'X');
				print();
				printf("%s has been vanquished!\n",enemyName.c_str());

				// Remove the enemy
				pEnemies[i] = pEnemies.back(); 
				pEnemies.pop_back();
				i--;

				system("PAUSE");
				player.addExperience(attackResult);
				return;
			}
			// Monster turn
			attackRoll = pEnemies[i].eAttack();
			printf("%s attacks Player with a roll of %d\n",enemyName.c_str(), attackRoll);
			system("PAUSE");
			attackResult = player.takeDamage(attackRoll);
			if (attackResult != 0) {
				setTile(playerX, playerY, '8');
				print();
				printf("You have been vanquished!\n");
				system("PAUSE");

				exit(0);
			}
			system("PAUSE");
			return;
		}
	}
}