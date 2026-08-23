/*
  =============================================================================
  Problem #2 (Level 2):
  Write a program to ask the user to enter a positive number N, then print
  all Prime numbers from 1 to N.
  =============================================================================
*/
#include <iostream>
#include <cmath>
using namespace std;

enum enCheckPrime { Prime = 1, NotPrime = 2 };

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

enCheckPrime CheckPrimeNumber(int Number)
{
	int M = round((float)Number / 2);
	for (int i = 2; i <= M; i++)
	{
		if (Number % i == 0)
		{
			return enCheckPrime::NotPrime;
		}
	}
	return enCheckPrime::Prime;
}

void PrintPrimeNumber(int Number)
{
	 
	cout << "the prime number from " << 1 << " to " << Number << " are : " << endl;
	for (int i = 1; i <= Number; i++)
	{
		if (CheckPrimeNumber(i) == enCheckPrime::Prime)
		{
			cout << i << endl;
		}
	}
}

int main()
{
	PrintPrimeNumber(ReadPositiveNumber("Please enter a positive number?"));
	return 0;
}


