/*
  =============================================================================
  Problem #50 (Level 2):
  Write a program to find the square root of a number (MySqrt) without
  using the built-in sqrt function, and compare the result with the
  built-in C++ sqrt/cmath function.
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



float MySqrt(float Number)
{
	return pow(Number, 0.5);

}



int main()
{
	float Number = 0;
	Number = ReadNumber();
	cout << "My sqrt Result: " << MySqrt(Number) << endl;
	cout << "C++ sqrt Result: " << sqrt(Number) << endl;;

	return 0;
}
