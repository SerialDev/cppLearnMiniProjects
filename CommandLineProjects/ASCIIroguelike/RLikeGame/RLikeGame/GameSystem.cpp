#include "GameSystem.h"
#include <iostream>
#include <conio.h>

// Constructor sets up the game
GameSystem::GameSystem(string levelFileName)
{
	pPlayer.init(1, 100, 10, 10, 0);
	plevel.load(levelFileName, pPlayer);
	

	system("PAUSE"); // system ("Pause");
}


void GameSystem::playGame()
{
	bool isDone = false;

	while (isDone == false) {
		plevel.print();
		playerMove();
		plevel.updateEnemies(pPlayer);

	}
} 

void GameSystem::playerMove()
{
	char input;
	printf("Enter a move command (w/a/s/d): ");
	input = _getch();

	plevel.movePlayer(input, pPlayer);
}