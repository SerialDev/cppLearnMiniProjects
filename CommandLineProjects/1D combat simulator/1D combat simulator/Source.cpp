#include <iostream>
#include <string>
#include <random>
#include <ctime>


using namespace std;




int main()
{
	default_random_engine randomGenerator(time(NULL));

	int whiteWalkers;
	cout << "How many white walkers are invading the wall!\n ";
	cin >> whiteWalkers;
	uniform_real_distribution<float> walkersAttack(0.0f, 10.0f);
	float healthWalkers = 1000.0f;
	float whiteAttack = walkersAttack(randomGenerator);

	int crowFighter;
	cout << "How many crows are left in castle black!\n ";
	cin >> crowFighter;
	uniform_real_distribution<float> crowAttack(5.0f, 10.0f);
	float healthCrow = 200.0f;
	float humanAttack = crowAttack(randomGenerator);


	cout << "Look over at castle black lord of light\n " << crowFighter << endl;
	cout << "At the wall they meet... Look over \n" << whiteWalkers << endl;

	while (whiteWalkers > 0 && crowFighter > 0){
		healthWalkers -= humanAttack;
		if (healthWalkers <= 0){
			whiteWalkers--;
			healthWalkers = 1000.0f;
		}

		healthCrow -= whiteAttack;
		if (healthCrow <= 0){
			crowFighter--;
			healthCrow = 200.0f;
		}
		cout << healthCrow << ": Crow health left " << crowFighter << " : fighters left\n" << endl;
		cout << healthWalkers << ": White walker health left " << whiteWalkers << " : fighters left\n4" << endl;
	}
	cout << whiteWalkers << ": white walkers left\n " << crowFighter << ": crows left\n" << endl;
	if (crowFighter > whiteWalkers) {
		cout << "crows win" << endl;
	}
	else {
		cout << "White walkers march towards the throne... CASTLE BLACK IS IN RUINS" << endl;
	}



	system("PAUSE");

	return 0;
}