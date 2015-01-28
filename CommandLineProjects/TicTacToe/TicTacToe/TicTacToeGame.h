#pragma once
class TicTacToeGame
{
public:
	TicTacToeGame();

	void playGame();

private:


	// Empties the board
	void clearBoard();
	// Prints the board
	void printBoard();
	char board[3][3];

	int getXCoord();
	int getYCoord();
	bool placeMarker(int x, int y, char currentPlayer);

	bool checkForVictory(char currentPlayer);
};

