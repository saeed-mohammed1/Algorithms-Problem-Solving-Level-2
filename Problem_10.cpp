/*
  =============================================================================
  Problem #10 (Level 2):
  Write a program to ask the user to enter a positive number, then print
  its digits in the correct order (from left to right) by reversing the
  number first and then extracting the digits.
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


int ReverseDigit(int Number)
{
	int Reminder = 0, Number2 = 0;
	
	while (Number > 0)
	{
		Reminder = Number % 10;
		Number = Number / 10;
		Number2 = Number2 * 10 + Reminder;
	}
	return Number2;
}

void PrintCorrectDigit(int Number)
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
	PrintCorrectDigit(ReverseDigit(ReadPositiveNumber("Please enter the main number?")));
	
	
	return 0;
}
