/*
  =============================================================================
  Problem #6 (Level 2):
  Write a program to ask the user to enter a positive number, then calculate
  and print the sum of its digits.
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


int SumOfDigits(int Number)
{
	int Reminder = 0 , sum = 0;
	while (Number > 0)
	{
		Reminder = Number % 10;
		Number = Number / 10;
		sum += Reminder;
	}
	return sum;
}

int main()
{
	cout<<SumOfDigits(ReadPositiveNumber("Please enter a positive number ?"))<<"\n";
	return 0;
}
