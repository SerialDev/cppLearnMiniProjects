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

	int eAttack();
	int takeDamage(int attack);

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

