/*
  =============================================================================
  Problem #31 (Level 2):
  Write a program to fill an array with ordered numbers from 1 to N, then print
  it, shuffle (randomize) this array, and print it after shuffling.
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

void ReadArray1ToN(int arr[100], int arrLength)
{
	
	for (int i = 0; i < arrLength; i++)
	{
		
		arr[i] = i +1;

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

void SwapArray(int arrSource[100] , int arrLength)
{
	
	for (int i = 0; i < arrLength; i++)
	{

		SwapNumber(arrSource[RandomNumber(0, arrLength-1)], arrSource[RandomNumber(0, arrLength -1)]);
		

	}
	
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength;
	arrLength = ReadPositiveNumber("Please enter length array?");

	ReadArray1ToN(arr, arrLength);
	
	
	cout << "\nArray 1 Elements: \n";
	PrintArray(arr, arrLength);
	
	SwapArray(arr, arrLength);

	cout << "\nArray 2 Elements after shuffle: \n";
	PrintArray(arr, arrLength);

	
	return 0;
}
