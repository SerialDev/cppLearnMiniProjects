#include "TicTacToeGame.h"
#include <iostream>

using namespace std;

TicTacToeGame::TicTacToeGame()
{
	


}

void TicTacToeGame::playGame()
{
	clearBoard();

	char player1 = '+';
	char player2 = 'O';
	char currentPlayer = player1;

	int x, y;

	int turn = 0;
	bool isDone = false;
	while (isDone == false) {
		printBoard();
		x = getXCoord();
		y = getYCoord();

		if ((placeMarker(x, y, currentPlayer)) == false){
			cout << "That spot is occupied!\n";
		}
		else{
			turn++;
			 
			if (checkForVictory(currentPlayer) == true){
				cout << "The game is over! " << currentPlayer << " has won! \n";
				isDone = true;
			}
			else if (turn == 9){
				cout << "its a tied game!\n";
			}
			//Switch player turn
			if (currentPlayer == player1){
				currentPlayer = player2;
			}
			else {
				currentPlayer = player1;
			}
		}
	}

		
}



void TicTacToeGame::clearBoard()
{
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			board[i][j] = ' ';
		}
	}
}

void TicTacToeGame::printBoard()
{
	cout << endl;
	cout << "| 1  2  3 |\n";
	for (int i = 0; i < 3; i++) {
		cout << "-----------\n";
		cout << i+1 << "| " << board[i][0] << "|" << board[i][1] << " | " << board[i][2] << "|\n";
	}
	cout << "-----------\n";
}

int TicTacToeGame::getXCoord()
{
	bool isInputBad = true;

	int x;

	while (isInputBad == true) {
		cout << "Enter the X coordinate: ";
		cin >> x;

		if (x < 1 || x > 3) {
			cout << "Invalid Coordinate!\n";
		}
		else {
			isInputBad = false;
		}
	}
	return x - 1;
}

int TicTacToeGame::getYCoord()
{
	bool isInputBad = true;

	int y;

	while (isInputBad == true) {
		cout << "Enter the Y coordinate: ";
		cin >> y;

		if (y < 1 || y > 3) {
			cout << "Invalid Coordinate!\n";
		}
		else {
			isInputBad = false;
		}
	}
	return y - 1;
}

bool TicTacToeGame::placeMarker(int x, int y, char currentPlayer)
{
	if (board[y][x] != ' ') {
		return false;
	}

	board[y][x] = currentPlayer;
	return true;
}

bool TicTacToeGame::checkForVictory(char currentPlayer)
{
	for (int i = 0; i < 3; i++){
		//Check the rows
		if ((board[i][0] == currentPlayer) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])){
			return true; //we won
		}
	}

	//check the columns 
	for (int i = 0; i < 3; i++){
		//Check the rows
		if ((board[0][i] == currentPlayer) && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
			return true; //we won
		}
	}

	//Check top left diagonal
	if ((board[0][0] == currentPlayer) && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
		return true; //we won
	}


	//Check top right diagonal
	if ((board[2][0] == currentPlayer) && board[2][0] == board[1][1] && board[1][1] == board[0][2]){
		return true; //we won
	}
	return false;
}