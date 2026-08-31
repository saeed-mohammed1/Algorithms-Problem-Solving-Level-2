/*
  =============================================================================
  Problem #20 (Level 2):
  Write a program to generate and print random characters of different types:
  (Small Letter, Capital Letter, Special Character, and Digit).
  =============================================================================
*/
#include <iostream>
#include <cstdlib>
using namespace std;

enum enRandom { SmallLetter = 1, CapitalLetter = 2, SpecialLetter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;  
}

char Random(enRandom Randoms)
{
	switch (Randoms)
	{
	case enRandom::SmallLetter:
	{
		return RandomNumber(97, 122);
		break;
	}
	case enRandom::CapitalLetter:
	{
		return RandomNumber(65, 90);
		break;
	}
	case enRandom::SpecialLetter:
	{
		return RandomNumber(33, 47);
		break;
	}
	case enRandom::Digit:
	{
		return RandomNumber(48, 57);
		break;
	}

	}

}


int main()
{
	srand((unsigned)time(NULL));
	
	cout << Random(enRandom::SmallLetter) << endl;
	cout << Random(enRandom::CapitalLetter) << endl;
	cout << Random(enRandom::SpecialLetter) << endl;
	cout << Random(enRandom::Digit) << endl;
	return 0;
}
