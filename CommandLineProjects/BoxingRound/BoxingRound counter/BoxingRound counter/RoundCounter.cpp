#include "RoundCounter.h"
#include <iostream>
#include <string>

using namespace std;

RoundCounter::RoundCounter()
{
	_roundN = 1; 
	while (_roundN <= 12)
	{
		cout << "Input Round " << _roundN << " winner" << endl;
		char roundW;
    	string knockDown;

		cin >> roundW;
		switch (roundW) {
		case 'a':
		case 'A':
			_boxerA += 10;
			_boxerB += 9;
			break;
		case 'b':
		case 'B':
			_boxerB += 10;
			_boxerA += 9;
		default:

			cin >> knockDown;
			if (knockDown == "Ka"){
				_boxerA += 10;
				_boxerB += 8;

			}else if (knockDown == "KOa") {
				_boxerA += 100;
				roundW += 12;

			}
			else if (knockDown == "KOb") {
				_boxerB += 100;
				roundW += 12;

			}
			break;
		}

		cout << "Boxer A score: " << _boxerA << "\t\t" << "Boxer B score: " << _boxerB << endl;
		_roundN++;
	}
	if (_boxerA == _boxerB){
		cout << "Draw" << endl;
	}
	else if (_boxerA > _boxerB) {
		cout << "Boxer A Won " << _boxerA << " to " << _boxerB << endl;
	}
	else if (_boxerA < _boxerB) {
		cout << "Boxer B Won" << _boxerB << " to " << _boxerA << endl;
	}

}

