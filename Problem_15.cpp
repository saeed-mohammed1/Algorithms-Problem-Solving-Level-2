/*
  =============================================================================
  Problem #15 (Level 2):
  Write a program to ask the user to enter a positive number N, then print
  the letter pattern starting from 'A' up to the N-th uppercase letter.
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


void PrintCharPattern(int Number)
{
	cout << "\n";
	for (int i = 65 ; i <= 65 + Number - 1; i++)
	{
		for (int j = 1; j <= i - 65 + 1; j++)
		{
			cout <<(char) i;
		}
		cout << endl;
	}
}



int main()
{
	
	PrintCharPattern(ReadPositiveNumber("Please enter the main number?"));
		
	return 0;
}
