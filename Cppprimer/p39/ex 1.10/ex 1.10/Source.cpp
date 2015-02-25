#include <iostream>

int main()
{
	int x = 10, y = 0;

	while (x >= 0) {
		std::cout << x << " " << std::endl;
		x--;
		y++;
	}

	std::cout << "/n/n The number of iterations was " << y << std::endl;
	std::cin.ignore();
	std::cin.get();
	
	return 0;
}