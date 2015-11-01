#pragma once
#include <string>
#include <vector>

using namespace std;

class Soldier
{
public:
	//Constructor
	Soldier(string name, char tile, int level, int attack, int defense, int health, int army);

	//Setters
	void setPosition(int x, int y);

	//Getters
	void getPosition(int &x, int &y);
	string getName() { return _name; }
	char getTile() { return _tile; }
	int getArmy() { return _army; }

	int attack();
	int takeDamage(int attack);

	//Gets AI move command
	char getMove(vector <Soldier *> armies[], int numArmies);

private:
	//Returns a pointer to the closest enemy soldier, or nullptr if there is none!
	Soldier *getClosestEnemy(vector <Soldier *> armies[], int numArmies);

	string _name;
	char _tile;

	//Properties
	int _level;
	int _attack;
	int _defense;
	int _health;
	int _army;

	//Position
	int _x;
	int _y;
};

