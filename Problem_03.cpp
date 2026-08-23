/*
  =============================================================================
  Problem #3 (Level 2):
  Write a program to ask the user to enter a positive number N, then check
  if it is a Perfect Number or not.
  =============================================================================
*/
#include <iostream>
#include <cmath>
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

bool CheckPerfectNumber(int Number)
{
	int M = round((float)Number / 2);
	int sum = 0;
	for (int i = 1; i <= M; i++)
	{
		
		if (Number % i == 0)
		{
			sum += i;
		}
	}
	
	return sum == Number;
	
}

void PrintPerfectNumber(int Number)
{
	 
		if (CheckPerfectNumber(Number) )
		{
			cout << Number<<" The Perfect Number" << endl;
		}
		else 
			cout << Number << " The Not Perfect Number" << endl;
	
}

int main()
{
	PrintPerfectNumber(ReadPositiveNumber("Please enter a positive number?"));
	return 0;
}
