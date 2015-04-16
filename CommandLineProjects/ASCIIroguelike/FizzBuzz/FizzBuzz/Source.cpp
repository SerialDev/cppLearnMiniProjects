#include <iostream>
#include <stdio.h>
#include <string>

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
//
//main()
//{
//	int c, state;
//
//	state = OUT;
//
//	while ((c = getchar()) != EOF)
//	{
//		if (c != ' ' && c != '\n' && c != '\t')
//		{
//			state = IN;
//			putchar('*');
//		}
//		else
//		{
//			if (state == IN)
//			{
//				state = OUT;
//				putchar('\n');
//			}
//		}
//	}
////}
//
//int main()
//{
//	// round off 256 days to the next largest number of days evenly divisible by a week
//	int days = 256;
//	bool a = true;
//	while (a == true){
//		days++;
//		if (days % 7 == 0) {
//			cout << days << endl;
//			
//		}
//	}
//	cout << days << endl;
//	system("PAUSE");
//
//
//}


// Write a program that takes an integer and displays integer in English. 
//I.E. user types 932, the program displays, Nine Three Two. Remember typing just a 0 should display Zero

//#include <stdio.h>
// 
//int main (void)
//{
//        const char baseDigits[16] = {
//        '0', '1', '2', '3', '4', '5', '6', '7',
//        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
//       
//        int                     convertedNumber[64];
//        long int        numberToConvert;
//        int             nextDigit, base, index = 0;
//       
//        // Get the number and the base
//       
//        printf("Number to be converted? ");
//        scanf ("%ld", &numberToConvert);
//        printf("Base? ");
//        scanf ("%i", &base);
//       
//        // Convert to the indicated base
//       
//        do
//        {
//                convertedNumber[index] = numberToConvert % base;
//                ++index;
//                numberToConvert = numberToConvert / base;
//        } while (numberToConvert != 0);
//       
//        // Display the results in reverse order
//       
//        printf ("Converted number = ");
//       
//        for (--index; index >= 0; --index )
//        {
//                nextDigit = convertedNumber[index];
//                printf ("%c", baseDigits[nextDigit]);
//        }
//       
//        printf("\n");
//       
//        return 0;
//       
//       
//}

		
		


	/*	cout << "TEST" << endl;
		int myarray[5] = { 1, 2, 3, 4, 5 };
		for (int i = 0; i <= 5; i++)
		{
			cout << myArray[digits] << "\n";
		}

*/





struct Player()
{
	string name;
	int hp;
	int exp;
	int lvl;
	Vector position;
};

int main()
{
	Player me;
	me.hp = 100;
	me.exp = 10;
	me.lvl;
	me.position.x = me.position.y = me.position.z = 0;





		


			system("PAUSE");
			return 0;
}

//int main()
//{
//	int number;
//	cout << "Enter a number: " << endl;
//	cin >> number;
//	switch (number){
//	case 0:
//		cout << "Zero" << endl;
//	case 1:
//		cout << "One" << endl;
//	case 2:
//		cout << "Two" << endl;
//	case 3:
//		cout << "Three" << endl;
//	case 4:
//		cout << "Four" << endl;
//	case 5:
//		cout << "Five" << endl;
//	case 6:
//		cout << "Six" << endl;
//	case 7:
//		cout << "Seven" << endl;
//	case 8:
//		cout << "Eight" << endl;
//	case 9:
//		cout << "Nine" << endl;
//		break;
//	}
//
//
//
//
//	system("PAUSE");
//	return 0;
//}