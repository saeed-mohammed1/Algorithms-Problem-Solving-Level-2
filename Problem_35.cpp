/*
  =============================================================================
  Problem #35 (Level 2):
  Write a program to fill an array of max size 100 with random numbers from
  1 to 100, read a number from the user, and check whether it exists in the array
  or not by reusing the search function from Problem #34.
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

void ReadArray(int arr[100], int arrLength)
{
	
	for (int i = 0; i < arrLength; i++)
	{
		
		arr[i] = RandomNumber(1, 100);

	}
}

void PrintArray(int arr[100], int arrLength)
{
	
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] <<" ";
	}
	cout << endl;
}

short SearchNumberOfArray(int arr[100], int arrLength, int SearchNumber)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (SearchNumber == arr[i])
		{
			return i;
		}
		
	}
	return -1;
}

bool CheckNumberInArray(int arr[100], int arrLength, int SearchNumber)
{
	
	return SearchNumberOfArray(arr, arrLength, SearchNumber) != -1;
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength;
	
	arrLength = ReadPositiveNumber("Please enter your length?");

	ReadArray(arr, arrLength);
	
	
	cout << "\nArray elements : \n\n";
	PrintArray(arr, arrLength);

	int SearchNumber = ReadPositiveNumber("Please enter search Number?");
	cout << "Number you are looking for as: " << SearchNumber << endl;
	
	
	if (!CheckNumberInArray(arr, arrLength, SearchNumber))
	{
		cout << "No,the number is not found:-(" << endl;
	}
	else
	{
		cout << "Yes,the number is found:-)" << endl;
	
	}
	return 0;
}
