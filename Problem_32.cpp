/*
  =============================================================================
  Problem #32 (Level 2):
  Write a program to fill an array of max size 100 with random numbers from
  1 to 100, copy its elements into another array in reverse order, and print
  both arrays.
  =============================================================================
*/
#include <iostream>
#include <string>
using namespace std;

void SwapNumber(int &A, int &B)
{
	int Swap = A;
	A = B;
	B = Swap;

}

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

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

void ReadArrayRandom(int arr[100], int arrLength)
{
	
	for (int i = 0; i < arrLength; i++)
	{
		
		arr[i] = RandomNumber(0, 100);

	}
}

void PrintArray(int arr[100], int arrLength)
{
	
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void ReverseArray(int arrSource[100], int arrDestination[100], int arrLength)
{
	
	for (int i = 0; i < arrLength; i++)
	{

		arrDestination[i] = arrSource[arrLength - (i+1)];
		

	}
	
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength;
	arrLength = ReadPositiveNumber("Please enter length array?");

	ReadArrayRandom(arr, arrLength);
	
	
	cout << "\nArray 1 Elements: \n";
	PrintArray(arr, arrLength);
	int arr2[100];
	ReverseArray(arr, arr2, arrLength);

	cout << "\nArray 2 Elements after copying Array 1 reversed order: \n";
	PrintArray(arr2, arrLength);

	
	return 0;
}
