/*
  =============================================================================
  Problem #29 (Level 2):
  Write a program to fill an array of size N with random numbers in the range
  [1 to 100], copy only prime numbers to another array, and print both arrays.
  =============================================================================
*/
#include <iostream>
#include <string>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void ReadArrayRandom(int arr[100], int& arrLength)
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

enPrimeNotPrime CheckPrimeNumber(int Number)
{
	int M = round(Number / 2);
	for (int counter = 2; counter <= M; counter++)
	{
		if (Number % counter == 0)
			return enPrimeNotPrime::NotPrime;
	}
	return enPrimeNotPrime::Prime;
}

void CopyOnlyPrimeArray(int arrSource[100], int arrDestination[100], int arrLength, int &arr2Length)
{
	int Count = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (CheckPrimeNumber(arrSource[i]) == enPrimeNotPrime::Prime)
		{
			arrDestination[Count] = arrSource[i];
			Count++;
		}

	}
	arr2Length = Count;
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrCopy[100], arrLength, arr2Length;

	ReadArrayRandom(arr, arrLength);
	cout << "\nArray 1 Elements: \n";
	PrintArray(arr, arrLength);

	CopyOnlyPrimeArray(arr, arrCopy, arrLength, arr2Length);

	cout << "\nArray 2 Elements after copy Prime Number: \n";
	PrintArray(arrCopy, arr2Length);
	return 0;
}
