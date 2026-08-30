/*
  =============================================================================
  Problem #17 (Level 2):
  Write a program to ask the user to enter a 3-letter uppercase password,
  then guess (brute-force) the password by iterating through all possible
  combinations from "AAA" to "ZZZ", printing each trial and showing the
  number of trials taken to find the password.
  =============================================================================
*/
#include <iostream>
#include <string>
using namespace std;

string ReadPassword()
{
	string Number;
	cout << "Please enetr 3 Capital char?" << endl;
	cin >> Number;
	return Number;
}

bool GuessPassword(string Password)
{
	cout << "\n";
	string word = "";
	int Counter = 0;
	for (int i = 65 ; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				Counter++;
				word = word + (char)i;
				word = word + (char)j;
				word = word + (char)k;
				cout << "Trial[" << Counter << "]: " << word << endl;
				if (Password == word)
				{
					
					cout << "Password is " << word << endl;
					cout << "Found after " << Counter << " Trail(s)." << endl;
					return true;
				}
				word = "";
			}
		}
		cout << "\n-----------------------------\n";
	}
	return false;
}



int main()
{

	GuessPassword(ReadPassword());
		
	return 0;
}
