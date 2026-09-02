/*
  =============================================================================
  Problem #28 (Level 2):
  Write a program to fill an array of size N with random numbers in the range
  [1 to 100], copy all its elements to another array, and print both arrays.
  =============================================================================
*/
#include <iostream>
using namespace std;

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

void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arrDestination[i] = arrSource[i];
    }
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrCopy[100], arrLength;

	ReadArrayRandom(arr, arrLength);
	cout << "\nArray 1 Elements: \n";
	PrintArray(arr, arrLength);

	CopyArray(arr, arrCopy, arrLength);

	cout << "\nArray 2 Elements after copy: \n";
	PrintArray(arrCopy, arrLength);
	return 0;
}
