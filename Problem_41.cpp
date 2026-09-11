/*
  =============================================================================
  Problem #41 (Level 2):
  Write a program to fill an array with numbers, then check whether the
  array is a Palindrome (reads the same forwards and backwards) or not,
  and print the result.
  =============================================================================
*/
#include <iostream>
using namespace std;

void FillArray(int arr[100], int& arrLength)
{
	arrLength = 6;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 30;
	arr[4] = 20;
	arr[5] = 10;

}


bool CheckPalidormeArray(int arrSource[100], int arrLength)
{
	

	for (int i = 0; i < arrLength; i++)
	{
		if (arrSource[arrLength - (i + 1)] != arrSource[i] )
		{
			return 0;
		}

	}
	return 1;
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
	int arr[100] ,arrLength = 0;
	
	FillArray(arr, arrLength);

	cout << "\nArray 1 elements :\n";
	PrintArray(arr, arrLength);

	if (CheckPalidormeArray(arr, arrLength))
	{
		cout << "\nYes, array is a Palidorme";
	}
	else
	{
		cout << "\nNo, array is not a Palidorme";
	}

	return 0;
}
