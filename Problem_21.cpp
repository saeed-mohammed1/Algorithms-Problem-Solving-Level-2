/*
  =============================================================================
  Problem #21 (Level 2):
  Write a program to read how many keys to generate, then generate and print
  random serial keys in the format (XXXX-XXXX-XXXX-XXXX) using uppercase letters.
  =============================================================================
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum enCarType { SmallLetter = 1, CapitalLetter = 2, SpecialLetter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

char RandomChar(enCarType Randoms)
{
	switch (Randoms)
	{
	case enCarType::SmallLetter:
	{
		return RandomNumber(97, 122);
		break;
	}
	case enCarType::CapitalLetter:
	{
		return RandomNumber(65, 90);
		break;
	}
	case enCarType::SpecialLetter:
	{
		return RandomNumber(33, 47);
		break;
	}
	case enCarType::Digit:
	{
		return RandomNumber(48, 57);
		break;
	}

	}

}

int ReadPositiveNumber(string message)
{
	int Number;
	do
	{
		cout << message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

string RandomWord(enCarType CarType, short Length)
{
	string Word;
	for (int i = 1; i <= Length; i++)
	{
		Word = Word + RandomChar(CarType);
	}
	return Word;
}

string RandomKey()
{
	string Key;
	Key = RandomWord(enCarType::CapitalLetter, 4) + "-"
		+ RandomWord(enCarType::CapitalLetter, 4) + "-"
		+ RandomWord(enCarType::CapitalLetter, 4) + "-"
		+ RandomWord(enCarType::CapitalLetter, 4);
	return Key;
}

void RandomKeys(int Number)
{
	for (int K = 1; K <= Number; K++)
	{
		cout << "Key[" << K << "]: ";
		cout << RandomKey() << endl;
	}
}


int main()
{
	srand((unsigned)time(NULL));
	RandomKeys(ReadPositiveNumber("Please enter number genrate key?"));
	
	return 0;
}
