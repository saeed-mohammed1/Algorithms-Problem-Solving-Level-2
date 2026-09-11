/*
  =============================================================================
  Problem #40 (Level 2):
  Write a program to fill an array with numbers (with duplicates), then
  copy only distinct (unique) numbers to another array using the
  AddArrayElement function, and print both arrays.
  =============================================================================
*/
#include <iostream>
using namespace std;

void FillArray(int arr[100], int& arrLength)
{
	arrLength = 10;
	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 50;
	arr[4] = 50;
	arr[5] = 70;
	arr[6] = 70;
	arr[7] = 70;
	arr[8] = 70;
	arr[9] = 90;

}

void AddArrayElements(int Number, int arr[100], int& arrLength)
{
	
		arrLength++;
		arr[arrLength - 1] = Number;
	
}

short FindNumberPostion(int arr2[100],int Number, int Length2)
{
	for (int i = 0; i <= Length2; i++)
	{
		if (Number == arr2[i])
			return i;
	}
	return -1;
}

bool IsNumberInArray(int arr2[100], int Number, int Length2)
{
	return FindNumberPostion(arr2, Number, Length2) != -1;
}

void CopyArraydistinctElements(int arr[100], int arr2[100], int arrLength, int &Length2)
{
	
	for (int i = 0; i < arrLength; i++)
	{
		if (!IsNumberInArray(arr2,arr[i], Length2))
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
	int arr[100] ,arrLength = 0, arrCopy[100], Length2 = 0;
	
	FillArray(arr, arrLength);

	CopyArraydistinctElements(arr, arrCopy, arrLength, Length2);
	cout << "\nArray 1 elements :\n";
	PrintArray(arr, arrLength);

	cout << "\nArray 2 distinct number:\n";
	PrintArray(arrCopy, Length2);

	return 0;
}
