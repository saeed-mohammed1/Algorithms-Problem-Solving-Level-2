/*
  =============================================================================
  Problem #13 (Level 2):
  Write a program to ask the user to enter a positive number N, then print
  the number pattern from 1 up to N.
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


void PrintIvertedNumberPattern(int Number)
{
	cout << "\n";
	for (int i = 1; i <= Number; i++)
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
	
	PrintIvertedNumberPattern(ReadPositiveNumber("Please enter the main number?"));
		
	return 0;
}
