/*
  =============================================================================
  Problem #7 (Level 2):
  Write a program to ask the user to enter a positive number, then reverse
  it mathematically and print the reversed integer.
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


int ReverseNumber(int Number)
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

int main()
{
	cout<< ReverseNumber(ReadPositiveNumber("Please enter a positive number ?"))<<"\n";
	return 0;
}
