#include <string>

using namespace std;
struct Vector
{
	float x, y, z;
};

struct Player
{
	string name;
	int hp;
	int position;
}; // Don't forget this semicolon at the end!
int main()
{
	// create an object of type Player,
	Player me; // instance named 'me'
	me.name = "William";
	me.hp = 100.0f;
	me.position.x = me.position.y = me.position.z = 0;
}