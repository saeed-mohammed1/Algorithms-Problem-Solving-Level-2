/*
  =============================================================================
  Problem #14 (Level 2):
  Write a program to ask the user to enter a positive number N, then print
  the inverted letter pattern from the N-th uppercase letter down to 'A'.
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


void PrintIvertedCharPattern(int Number)
{
	cout << "\n";
	for (int i = 65 + Number - 1; i >= 65; i--)
	{
		for (int j = 1; j <= Number - (65 + Number - 1 - i); j++)
		{
			cout <<(char) i;
		}
		cout << endl;
	}
}



int main()
{
	
	PrintIvertedCharPattern(ReadPositiveNumber("Please enter the main number?"));
		
	return 0;
}
