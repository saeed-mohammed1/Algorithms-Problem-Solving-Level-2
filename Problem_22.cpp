/*
  =============================================================================
  Problem #22 (Level 2):
  Write a program to read N elements into an array, print the array, then read
  a number to check and print how many times this number is repeated in the array.
  =============================================================================
*/
#include <iostream>
#include <string>
using namespace std;

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

void ReadArray(int arr[100], int& arrLength)
{
	cout << "enter length of array? \n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		cout << "Element[" << i + 1 << "]: ";
		cin >> arr[i];

	}
}

void PrintArray(int arr[100], int arrLength)
{
	cout<< "Original array: ";
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int TimesRepeated(int arr[100], int& arrLength,int NumberToCheck)
{
	int Counter = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (NumberToCheck == arr[i])
		{
			Counter++;
		}
	}
	return Counter;
}




int main()
{
	int arr[100], arrLength, NumberToCheck;

	ReadArray(arr, arrLength);

	NumberToCheck = ReadPositiveNumber("Please enter Number of Check?");

	PrintArray(arr, arrLength);


	
	
	cout << NumberToCheck << " repeated " << TimesRepeated(arr, arrLength, NumberToCheck) << " time(s).";

	return 0;
}
