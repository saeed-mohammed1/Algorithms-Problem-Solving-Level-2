/*
  =============================================================================
  Problem #38 (Level 2):
  Write a program to fill an array of max size 100 with random numbers from
  1 to 100, copy only odd numbers to another array using the AddArrayElement
  function, and print both arrays.
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

void AddArrayElements(int Number, int arr[100], int& arrLength)
{
	
		arrLength++;
		arr[arrLength - 1] = Number;
	
}

void ReadArray(int arr[100], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
	{

		arr[i] = RandomNumber(1, 100);

	}
}

void CopyArrayOddElements(int arr[100], int arr2[100], int arrLength, int &Length2)
{
	
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] % 2 != 0)
		{
			AddArrayElements(arr[i], arr2, Length2);
		}
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




int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength = 0, arrCopy[100], Length2 = 0;
	arrLength = ReadPositiveNumber("Please enter your Length?");
	ReadArray(arr, arrLength);

	CopyArrayOddElements(arr, arrCopy, arrLength, Length2);
	cout << "\nArray 1 elements :\n";
	PrintArray(arr, arrLength);

	cout << "\nArray 2 elements odd number:\n";
	PrintArray(arrCopy, Length2);

	return 0;
}
