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