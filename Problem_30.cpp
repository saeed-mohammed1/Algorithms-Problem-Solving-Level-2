/*
  =============================================================================
  Problem #30 (Level 2):
  Write a program to fill two arrays with max size 100 with random numbers
  from 1 to 100, sum their elements into a third array, and print all three arrays.
  =============================================================================
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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

void ReadArrayRandom(int arr[100], int arrLength)
{
	

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

void Sum2Array(int arrSource[100], int arrDestination[100], int arrLength, int Sum[100])
{
	for (int i = 0; i < arrLength; i++)
	{
		Sum[i] = arrDestination[i] + arrSource[i];
		

	}
	
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arr2[100], Sum[100], arrLength;
	arrLength = ReadPositiveNumber("Please enter length array?");

	ReadArrayRandom(arr, arrLength);
	ReadArrayRandom(arr2, arrLength);
	Sum2Array(arr, arr2, arrLength, Sum);
	cout << "\nArray 1 Elements: \n";
	PrintArray(arr, arrLength);
	
	cout << "\nArray 2 Elements: \n";
	PrintArray(arr2, arrLength);

	cout << "\nSum 2 Array Elements: \n";
	PrintArray(Sum, arrLength);
	return 0;
}
