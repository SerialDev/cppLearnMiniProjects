#include <iostream>

int main()
{
	int x = 50, y = 0, z = 0;

	while (x <= 100) {
		y += x;
		x++;
		z++;
	}

	std::cout << z << "The sum of the numbers from 50 to 100 is " << y << std::endl;
	std::cin.ignore();
	std::cin.get();
	
	return 0;
}