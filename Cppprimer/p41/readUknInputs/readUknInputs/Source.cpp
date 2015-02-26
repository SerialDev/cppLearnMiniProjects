#include <iostream>

int main()
{
	int sum = 0, value = 0;
	// read until the end-of-file, calculating a running total of all values read
	while (std::cin >> value){
		sum += value; // equivalent to sum = sum + value
		std::cout << "Sum is: " << sum << std::endl;
	}
	
	std::cin.ignore();
	std::cout << "Press any key..." << std::endl;
	std::cin.get();
	return 0;
	
}