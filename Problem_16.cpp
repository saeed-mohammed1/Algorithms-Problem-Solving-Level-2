/*
  =============================================================================
  Problem #16 (Level 2):
  Write a program to print all 3-letter word combinations from "AAA" to "ZZZ".
  =============================================================================
*/
#include <iostream>
#include <string>
using namespace std;

void PrintAllCharAAAToZZZ()
{
	cout << "\n";
	string word = "";
	for (int i = 65 ; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				word = word + (char)i;
				word = word + (char)j;
				word = word + (char)k;
				cout <<word << endl;
				word = "";
			}
		}
		cout << "\n-----------------------------\n";
	}
}



int main()
{
	
	PrintAllCharAAAToZZZ();
		
	return 0;
}
