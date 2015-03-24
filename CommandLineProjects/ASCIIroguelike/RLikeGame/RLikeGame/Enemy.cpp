#include "Enemy.h"
#include <random>
#include <ctime>

using namespace std;

Enemy::Enemy(string name, char tile, int level, int attack, int defense, int health, int xp)
{
	p_eName = name;
	p_eTile = tile; 
	p_eLevel = level;
	p_eAttack = attack;
	p_eDefense = defense;
	p_eHealth = health;
	p_eExperienceValue = xp;
}

// Sets the position of the enemy
void Enemy::setPosition(int x, int y)
{
	px = x;
	py = y;
}

// Gets the position of the enemy using reference variable
void Enemy::getPosition(int &x, int &y)
{
	x = px;
	y = py;
}

int Enemy::eAttack()
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, p_eAttack);
	return attackRoll(randomEngine);
}

int Enemy::takeDamage(int attack)
{
	// check if the attack does damage
	attack -= p_eDefense;
	if (attack > 0) {
		p_eHealth -= attack;
		// check if he died
		if (p_eHealth <= 0){
			return p_eExperienceValue;
		}
	}
	return 0;
}

char Enemy::getMove(int playerX, int playerY)
{
	static default_random_engine randEngine(time(NULL));
	uniform_int_distribution<int> moveRoll(0, 6);

	int distance;
	int dx = px - playerX;
	int dy = py - playerY;
	int adx = abs(dx);
	int ady = abs(dy);

	distance = adx + ady;

	if (distance <= 5) {                                // Need to implement range variable
		// Moving along x axis
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

	int randomMove = moveRoll(randEngine);
	switch (randomMove) {
	case 0:
		return 'a';
	case 1:
		return 'w';
	case 2:
		return 's';
	case 3:
		return 'd';
	default:
		return '.';
	}
}