#include "Player.h"
#include <random>
#include <ctime>

using namespace std;

// Constructor, just initializes position to zero
Player::Player()
{
	px = 0;
	py = 0;
}

// Initializes the player with properties
void Player::init(int level, int health, int attack, int defense, int experience) 
{
	pLevel = level; 
	pHealth = health;
	pAttack = attack;
	pDefense = defense;
	pExperience = experience;
}

int Player::attack()
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, pAttack);
	return attackRoll(randomEngine);
}

// Sets the position of the player
void Player::setPosition(int x, int y)
{
	px = x;
	py = y;
}

void Player::addExperience(int experience)
{
	pExperience += experience;
	// Level up!
	while (pExperience > 50)
	{
		printf("Leveled up!\n"); 
		pExperience -= 50; 
		pAttack += 10;
		pDefense += 5; 
		pHealth += 10;
		pLevel++;
		system("PAUSE");
	}
}

// Gets the position of the player using reference variable
void Player::getPosition(int &x, int &y)
{
	x = px;
	y = py;
}

int Player::takeDamage(int attack)
{
	// check if the attack does damage
	attack -= pDefense;
	if (attack > 0) {
		pHealth -= attack;
		// check if he died
		if (pHealth <= 0){
			return 1;
		}
	}
	return 0;
}