/*
  =============================================================================
  Problem #27 (Level 2):
  Write a program to fill an array of size N with random numbers in the range
  [1 to 100], print the array, then calculate and print the average of all
  its elements.
  =============================================================================
*/
#include <iostream>
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

int SumArray(int arr[100], int arrLength)
{
	int Sum = 0;
	
	for (int i = 0; i < arrLength; i++)
	{
		Sum += arr[i];
	}
	return Sum ;
}

float AverageArray(int arr[100], int arrLength)
{
	return (float)SumArray( arr , arrLength) / arrLength;
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength;

	ReadArray(arr, arrLength);
	cout << "\nArray Elements: ";
	PrintArray(arr, arrLength);
	cout << "\nAverage of all Number is ";
	cout << AverageArray(arr, arrLength) << endl;
	return 0;
}
