#include <iostream>
#include <string>
#include "TicTacToeGame.h"

using namespace std;

int main()
{
	char input;
	bool isDone = false;
	TicTacToeGame game;
	

	while (isDone == false){
		game.playGame();
		cout << "Would you like to play again?\n (Y/N): ";
		cin >> input;
		if (input == 'N' || input == 'n'){
			isDone == true;
		}
		else{
			game.playGame();
		}
	}

	system("PAUSE");

	return 0;
}