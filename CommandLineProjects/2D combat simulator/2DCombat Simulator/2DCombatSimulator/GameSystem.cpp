#include "GameSystem.h"
#include <iostream>
#include <conio.h>

// Constructor sets up the game
GameSystem::GameSystem(string levelFileName)
{
	
	plevel.load(levelFileName);
	

	system("PAUSE"); // system ("Pause");
}


void GameSystem::playGame()
{
	bool isDone = false;

	while (isDone == false) {
		plevel.print();
		
		plevel.update();
		_getch();
	}
} 
