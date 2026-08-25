/*
  =============================================================================
  Problem #9 (Level 2):
  Write a program to ask the user to enter a positive number, then count and
  print the frequency of all digits (0 to 9) that appear in that number.
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


int CountDigitFrequency(int Number , short Digit)
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

void PrintAllDigitFrequency(int Number)
{
	for (int i = 0; i < 10; i++)
	{
		short Frequency = CountDigitFrequency(Number, i);
		if (Frequency != 0)
			cout << "Digit " << i << " Frequency is " << Frequency << " Time(s)." << endl;
	}
}


int main()
{
	int Number = ReadPositiveNumber("Please enter the main number?");
	PrintAllDigitFrequency(Number);
	
	return 0;
}
