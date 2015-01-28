#include <iostream>

using namespace std;


class CheckerBoard{
public:
	void initBoard(){
		for (int y = 0; y < 8; y++){
			for (int x = 0; x < 8; x++){
				if (((x +y) % 2) == 0) {
					board[y][x] = '.';
				}
				else {
					board[y][x] = '*';
				}
			}
		}
	}

	void printBoard(){
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++){
				cout << board[y][x];
			}
			cout << endl;
		}
	}

private: 
	char board[8][8];

};

int main()
{
	CheckerBoard checkerBoard;
	checkerBoard.initBoard();
	checkerBoard.printBoard();

	
	system("PAUSE");

	return 0;
}