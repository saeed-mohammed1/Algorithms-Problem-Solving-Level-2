/*
  =============================================================================
  Problem Statement:
  Problem #1 (Level 2):
  Write a program to print the full multiplication table from 1 to 10.
  =============================================================================
*/
#include <iostream>
using namespace std;

void PrintTableHeader()
{
	cout << "\n\n\t \t \t Multiplication Table From 1 to 10 \n\n";
	cout << "\t";
	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t";
	}
	cout << "\n\n";
	cout << "----------------------------------------------------------------------------------- \n";
	
}

string ColumSeprator(int i)
{
	if (i < 10)
		return "  |";
	else
		return " |";
}

void PrintMultiplicationFrom1To10()
{
	PrintTableHeader();
	for (int i = 1; i <= 10; i++)
	{
		cout << " " << i << ColumSeprator(i) << "\t";
		for (int j = 1; j <= 10; j++)
		{
			cout << i * j << "\t";
		}
		cout << endl;
	}
}



int main()
{
	PrintMultiplicationFrom1To10();
	
	return 0;
}

