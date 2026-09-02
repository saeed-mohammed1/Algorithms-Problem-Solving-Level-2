/*
  =============================================================================
  Problem #24 (Level 2):
  Write a program to fill an array of size N with random numbers in the range
  [1 to 100], print the array, then find and print the maximum number in it.
  =============================================================================
*/
#include <iostream>
#include <string>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void ReadArray(int arr[100], int& arrLength)
{
	cout << "enter length of array? \n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		
		arr[i] = RandomNumber(1 , 100);

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

int MaxNumberInArray(int arr[100], int arrLength)
{
	int Max = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (Max < arr[i])
		{
			Max = arr[i];
		}
	}
	return Max;
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength;

	ReadArray(arr, arrLength);
	cout << "\nArray Elements: ";
	PrintArray(arr, arrLength);
	cout << "\nMax Number is ";
	cout << MaxNumberInArray(arr, arrLength) << endl;
	return 0;
}
