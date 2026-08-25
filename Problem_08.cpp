/*
  =============================================================================
  Problem #8 (Level 2):
  Write a program to ask the user to enter a positive number and a specific
  digit, then count and print the frequency of that digit within the number.
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


int CountDigitFrequency(int Number , int Digit)
{
	int Reminder = 0, Counter = 0;
	
	while (Number > 0)
	{
		Reminder = Number % 10;
		Number = Number / 10;
		if (Reminder == Digit)
			Counter++;
	}
	
	return Counter;
}


int main()
{
	int Number = ReadPositiveNumber("Please enter the main number?");
	short Digit = ReadPositiveNumber("Please enter one digit to check?");
	cout << "Digit " << Digit << " Frequency is " << CountDigitFrequency(Number, Digit) << " Time(s).";
	
	return 0;
}
