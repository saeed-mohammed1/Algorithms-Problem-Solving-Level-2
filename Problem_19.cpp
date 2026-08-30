/*
  =============================================================================
  Problem #19 (Level 2):
  Write a program to generate and print 3 random numbers within a specific
  range [From, To] using rand(), srand(), and time(NULL).
  =============================================================================
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int Num = rand() % (To - From + 1) + From;
	return Num;
}


int main()
{
	srand((unsigned)time(NULL));

	cout << RandomNumber( 1 , 10 )<< endl;
	cout << RandomNumber(1, 10) << endl;
	cout << RandomNumber(1, 10) << endl;
	return 0;
}
