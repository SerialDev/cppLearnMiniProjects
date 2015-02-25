#include <iostream>

int main()
{
	int x, y, z = 0;
	std::cout << "Type two integers to get range (x,y): " << std::endl;
	std::cin >> x >> y;

	while (x <= y) {
		std::cout << x << " " << std::endl;
		x++;
		z++;
	}

	std::cout << "/n/n/n The number of iterations was " << z << std::endl;
	std::cin.ignore();
	std::cin.get();

	return 0;
}