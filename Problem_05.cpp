/*
  =============================================================================
  Problem #5 (Level 2):
  Write a program to ask the user to enter a positive number, then print its
  digits in reversed order (one digit per line).
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


void PrintDigits(int Number)
{
	int Reminder = 0;
	while (Number > 0)
	{
		Reminder = Number % 10;
		Number = Number / 10;
		cout << Reminder << endl;
	}
}

int main()
{
	PrintDigits(ReadPositiveNumber("Please enter a positive number ?"));
	return 0;
}
