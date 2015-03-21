#include <iostream>
#include <stdio.h>
#define IN 1
#define OUT 0
using namespace std;

//int main()
//{
//	int x = 0;
//	while (x < 100)
//	{
//		x++;
//		if (x % 3 == 0 && x % 5 == 0)
//		{
//			cout << "FizzBuzz" << endl;
//		}
//		else if (x % 3 == 0)
//		{
//			cout << "Fizz" << endl;
//		}
//		else if (x % 5 == 0)
//		{
//			cout << "Buzz" << endl;
//		}
//		else{
//			cout << x << endl;
//		}
//		
//
//	}
//	std::cout << "Press ENTER to continue..." << std::flush;
//  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//	return 0;
//}

main()
{
	int c, state;

	state = OUT;

	while ((c = getchar()) != EOF)
	{
		if (c != ' ' && c != '\n' && c != '\t')
		{
			state = IN;
			putchar('*');
		}
		else
		{
			if (state == IN)
			{
				state = OUT;
				putchar('\n');
			}
		}
	}
}