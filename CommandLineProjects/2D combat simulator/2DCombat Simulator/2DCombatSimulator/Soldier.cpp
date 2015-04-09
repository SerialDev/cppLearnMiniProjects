#include "Soldier.h"
#include <random>
#include <ctime>

using namespace std;

Soldier::Soldier(string name, char tile, int level, int attack, int defense, int health, int army)
{
	p_eName = name;
	p_eTile = tile; 
	p_eLevel = level;
	p_eAttack = attack;
	p_eDefense = defense;
	p_eHealth = health;
	p_army = army;
}

// Sets the position of the soldier
void Soldier::setPosition(int x, int y)
{
	px = x;
	py = y;
}

// Gets the position of the soldier using reference variable
void Soldier::getPosition(int &x, int &y)
{
	x = px;
	y = py;
}

int Soldier::eAttack()
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, p_eAttack);
	return attackRoll(randomEngine);
}

int Soldier::takeDamage(int attack)
{
	// check if the attack does damage
	attack -= p_eDefense;
	if (attack > 0) {
		p_eHealth -= attack;
		// check if he died
		if (p_eHealth <= 0){
			return 1;
		}
	}
	return 0;
}


// This performs the soldier's AI
char Soldier::getMove(vector <Soldier *> armies[], int numArmies)
{
	static default_random_engine randEngine(time(NULL));
	uniform_int_distribution<int> moveRoll(0, 6);
	
	Soldier * closestSoldier = getClosestEnemy(armies, numArmies);

	if (closestSoldier == nullptr) {
		return '.';
	}
	int soldierX, soldierY;
	closestSoldier->getPosition(soldierX, soldierY);

	int dx = px - soldierX;
	int dy = py - soldierY;
	int adx = abs(dx);
	int ady = abs(dy);


	if (adx > ady){
		if (dx > 0){
			return 'a';
		}else{
			return 'd';
		}

	}
	// Moving along y axis
	else {
		if (dy > 0){
			return 'w';
		}
		else{
			return 's';
		}
	}
}

Soldier *Soldier::getClosestEnemy(vector<Soldier *> armies[], int numArmies)
{
	Soldier *closestSoldier = nullptr;
	int closestDistance = INT_MAX;
	int enemyx, enemyy;
	int distance;

	for (int i = 0; i < numArmies; i++) {
		if (i != p_army) {
			for (int j = 0; j < armies[i].size; j++){
				armies[i][j]->getPosition(enemyx, enemyy);
				distance = abs(enemyx - px) + abs(enemyy - py);
				if (distance < closestDistance){
					closestSoldier = armies[i][j];
					closestDistance = distance;
				}
			}
		}
	}

	return closestSoldier;
}