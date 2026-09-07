/*
  =============================================================================
  Problem #33 (Level 2):
  Write a program to fill an array with keys, then print the array on screen.
  =============================================================================
*/
#include <iostream>
#include <string>
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

string RandomWord(enCarType CarType, short Length)
{
	string Word;
	for (int i = 1; i <= Length; i++)
	{
		Word = Word + RandomChar(CarType);
	}
	return Word;
}

string GenerateKey()
{
	string Key;
	Key = RandomWord(enCarType::CapitalLetter, 4) + "-"
		+ RandomWord(enCarType::CapitalLetter, 4) + "-"
		+ RandomWord(enCarType::CapitalLetter, 4) + "-"
		+ RandomWord(enCarType::CapitalLetter, 4);
	return Key;
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

void ReadArrayKey(string arr[100], int arrLength)
{
	
	for (int i = 0; i < arrLength; i++)
	{
		
		arr[i] = GenerateKey();

	}
}

void PrintStringArray(string arr[100], int arrLength)
{
	
	for (int i = 0; i < arrLength; i++)
	{
		cout << "Array[" << i << "]:" << arr[i] << endl;
	}
	
}


int main()
{
	srand((unsigned)time(NULL));
	string arr[100];
	int arrLength;
	arrLength = ReadPositiveNumber("How many keys do you want to generate?");

	ReadArrayKey(arr, arrLength);
	
	
	cout << "\nArray elements : \n\n";
	PrintStringArray(arr, arrLength);
	
	return 0;
}
