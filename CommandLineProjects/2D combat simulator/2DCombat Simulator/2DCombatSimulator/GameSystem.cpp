#include "GameSystem.h"
#include <iostream>
#include <conio.h>


//Constructor sets up the game
GameSystem::GameSystem(string levelFileName) {

	//Load the level from file
	_level.load(levelFileName);

	printf("%s was loaded!\n", levelFileName.c_str());
	printf("\n*Be sure to make your console window bigger for the best experience.\n\n");
	system("PAUSE");
}

void GameSystem::playGame() {

	bool isDone = false;

	while (isDone != true) {
		//print the board
		_level.print();
		//get player input
		//update level AI
		_level.update();

		_getch();
	}
}