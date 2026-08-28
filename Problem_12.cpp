/*
  =============================================================================
  Problem #12 (Level 2):
  Write a program to ask the user to enter a positive number N, then print
  the inverted number pattern from N down to 1.
  =============================================================================
*/
#include <iostream>
#include <string>
using namespace std;


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


void PrintInvertedNumberPattern(int Number)
{
	for (int i = Number; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}
		cout << endl;
	}
}



int main()
{
	
	PrintInvertedNumberPattern(ReadPositiveNumber("Please enter the main number?"));
		
	return 0;
}
