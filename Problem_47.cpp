/*
  =============================================================================
  Problem #47 (Level 2):
  Write a program to round a floating-point number (MyRound) without
  using the built-in round function, and compare the result with the
  built-in C++ round/cmath function.
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

int MyRound(float Number)
{
	int InPart = int(Number);
	float FractionPart = GetFractionPart(Number);
	if (abs(FractionPart) >= 0.5)
	{
		if (Number > 0)
			return ++InPart;
		else
			return --InPart;
	}
	else
	{
		return InPart;
	}

}



int main()
{
	float Number = 0;
	Number = ReadNumber();
	cout << "My Round Result: " << MyRound(Number) << endl;
	cout << "C++ Round Result: " << round(Number);

	return 0;
}
