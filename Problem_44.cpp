/*
  =============================================================================
  Problem #44 (Level 2):
  Write a program to fill an array of max size 100 with random numbers
  from -100 to 100, count the number of positive numbers in the array,
  and print the count.
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


void FillArray(int arr[100], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
	{

		arr[i] = RandomNumber(-100, 100);

	}
}

int PositiveCount(int arr[100], int arrLength)
{
	int Count = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] >= 0)
		{
			Count++;
		}
	}
	return Count;
}

void PrintArray(int arr[100], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
	{

		cout << arr[i] << " ";

	}
	cout << endl;
}




int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength = 0;
	arrLength = ReadPositiveNumber("Please enter your Length?");
	FillArray(arr, arrLength);

	
	cout << "\nArray elements :";
	PrintArray(arr, arrLength);

	cout << "\nPositive number count is: " << PositiveCount(arr, arrLength) << endl;
	

	return 0;
}
