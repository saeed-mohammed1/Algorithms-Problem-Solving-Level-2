/*
  =============================================================================
  Problem #4 (Level 2):
  Write a program to ask the user to enter a positive number N, then print
  all Perfect Numbers from 1 to N.
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
	
	return  Number == sum;
	
}

void PrintPerfectNumber(int Number)
{
	 
	cout << "The perfect number from " << 1 << " to " << Number << " are :" << endl;
	for (int i = 2; i <= Number; i++)
	{
		if (CheckPerfectNumber(i) )
		{
			cout << i << endl;
		}
	}
}

int main()
{
	PrintPerfectNumber(ReadPositiveNumber("Please enter a positive number?"));
	return 0;
}
