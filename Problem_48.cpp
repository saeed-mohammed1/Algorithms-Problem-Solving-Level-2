/*
  =============================================================================
  Problem #48 (Level 2):
  Write a program to find the floor value of a floating-point number (MyFloor)
  without using the built-in floor function, and compare the result with the
  built-in C++ floor/cmath function.
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

float GetFractionPart(float Number)
{
	return Number - int(Number);
}

int MyFloor(float Number)
{
	if (Number > 0)
		return int(Number);
	else
		return int(Number) - 1;

}



int main()
{
	float Number = 0;
	Number = ReadNumber();
	cout << "My floor Result: " << MyFloor(Number) << endl;
	cout << "C++ floor Result: " << floor(Number);

	return 0;
}
