#pragma once
class Player
{
public:
	Player();
	void init(int level, int health, int attack, int defense, int experience);

	int attack();
	int takeDamage(int attack);

	// Setters
	void setPosition(int x, int y);

	void addExperience(int experience);

	// Getters 
	void getPosition(int &x, int &y);



private:
	// Properties 
	int pLevel;
	int pHealth;
	int pAttack;
	int pDefense;
	int pExperience;

	// Position
	int px;
	int py;

};

