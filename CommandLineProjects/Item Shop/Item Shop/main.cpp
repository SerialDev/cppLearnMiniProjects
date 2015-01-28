#include <iostream> 
#include <string>

using namespace std;

const int numItems = 6;
const string shopItemNames[numItems] {"Boots", "Swords", "Helmets", "Kitten", "Poleaxes", "Leggings"};

void printInventory(const int playerInventory[numItems]);
void printShop(); 
bool buyItems(int playerInventory[numItems]);


int main()
{
	bool isDone = false; 
	
	int playerinventory[numItems] = { 0, 0, 0, 1, 0, 0 };

	while (isDone == false){
		
		printShop();
		printInventory(playerinventory);


		cout << "\n\n\n";
		cout << "*** What would you like to buy ***" << endl;
		isDone = buyItems(playerinventory);
	}

	system ("PAUSE");
	return 0;

}

void printInventory(const int playerInventory[numItems])
{
	cout << "Your inventory is: " << endl;
	for (int i = 0; i < numItems; i++){
		if (playerInventory[i] > 0) {
			cout << playerInventory[i] << "x " << shopItemNames[i] << endl;
		}
	}
	cout << endl;
}

void printShop()
{
	cout << "Welcome to the item shop!\n";

	for (int i = 0; i < numItems; i++) {
		cout << i+1 << ". " <<  shopItemNames[i] << endl;
	}

	cout << "****************" << endl;

}

bool buyItems(int playerInventory[numItems])
{
	int input;
	cout << "What would you like to buy? Enter -1 to quit. Enter (" << 1 << "-" << numItems << "):";
	cin >> input;
	
	if (input == -1) {
		return true; //the program is over
	}

	if (input - 1 < 0 || input -1 > numItems) {
		cout << "That was a bad input\n"; 
		return false;//keep going
	}

	playerInventory[input - 1]++;
	return false;

}