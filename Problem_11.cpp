/*
  =============================================================================
  Problem #11 (Level 2):
  Write a program to ask the user to enter a positive number, then check
  if it is a Palindrome number or not (a number that reads the same backward
  as forward, e.g., 12321, 555).
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

bool CheckPalindrome(int Number)
{
	return Number == ReverseDigit(Number);
	

}




int main()
{
	
	if (CheckPalindrome(ReadPositiveNumber("Please enter the main number?")))
		cout << "yes, it is a palindrome number. \n";
	else
		cout << "No, it is NOT a palindrome number. \n";
	return 0;
}
