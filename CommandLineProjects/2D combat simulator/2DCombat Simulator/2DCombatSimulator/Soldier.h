#pragma once
#include <string>
#include <vector>

using namespace std;

class Soldier
{
public:
	Soldier(string name, char tile, int level, int attack, int defense, int health, int army);

	// Setters
	void setPosition(int x, int y);

	// Getters 
	void getPosition(int &x, int &y);
	string getName() { return p_eName; }
	char getTile() { return p_eTile; }

	int eAttack();
	int takeDamage(int attack);

	// Gets AI move command
	char getMove(vector<Soldier *> armies[], int numArmies);

private:

	Soldier *getClosestEnemy(vector<Soldier *> armies[], int numArmies);

	// Properties
	string p_eName;
	char p_eTile;

	int p_eLevel;
	int p_eAttack;
	int p_eDefense;
	int p_eHealth;
	int p_army;

	// Position
	int px;
	int py;

};

