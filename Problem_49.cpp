/*
  =============================================================================
  Problem #49 (Level 2):
  Write a program to find the ceil value of a floating-point number (MyCeil)
  without using the built-in ceil function, and compare the result with the
  built-in C++ ceil/cmath function.
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

int MyCeil(float Number)
{
	int InPart = int(Number);
	float FractionPart = GetFractionPart(Number);

	if (FractionPart > 0)
	{
		return ++InPart;	
	}
	else
		return InPart;
}
/*
solution Dr.Mohammed Abu-Hadhoud
int MyCeil(float Number)
{
    // If the number has a fractional part greater than zero, round up if positive.
    if (abs(GetFractionPart(Number)) > 0)
    {
        if (Number > 0)
            return int(Number) + 1;  // Round up for positive numbers.
        else
            return int(Number);  // Keep the integer part for negative numbers.
    }
    else
        return Number;  // If the number is already an integer, return it as is.
}
  */


int main()
{
	float Number = 0;
	Number = ReadNumber();
	cout << "My ceil Result: " << MyCeil(Number) << endl;
	cout << "C++ ceil Result: " << ceil(Number) << endl;;

	return 0;
}
