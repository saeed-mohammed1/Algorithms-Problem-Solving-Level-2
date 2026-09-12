/*
  =============================================================================
  Problem #46 (Level 2):
  Write a program to print the absolute value of a number (MyABS) without
  using the built-in abs function, and compare the result with the built-in
  C++ abs/cmath function.
  =============================================================================
*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

float ReadNumber()
{
	float Number;
	
	cout << "Please enter a number?" << endl;
	cin >> Number;
	
	return Number;
}

float MyAbs(int Number)
{
	if (Number > 0)
		return Number ;
	else
		return Number * -1;
}



int main()
{
	float Number = 0;
	Number = ReadNumber();
	cout << "My abs Result: " << MyAbs(Number) << endl;
	cout << "C++ abs Result: " << abs(Number);

	return 0;
}
