#pragma once
#include <string>

using namespace std;

class Enemy
{
public:
	Enemy(string name, char tile, int level, int attack, int defense, int health, int xp);

	// Setters
	void setPosition(int x, int y);

	// Getters 
	void getPosition(int &x, int &y);
	string getName() { return p_eName; }
	char getTile() { return p_eTile; }

	int eAttack();
	int takeDamage(int attack);

	// Gets AI move command
	char getMove(int playerX, int playerY);

private:
	// Properties
	string p_eName;
	char p_eTile;

	int p_eLevel;
	int p_eAttack;
	int p_eDefense;
	int p_eHealth;
	int p_eExperienceValue;

	// Position
	int px;
	int py;

};

