/*
  =============================================================================
  Problem #36 (Level 2):
  Write a program to dynamically read numbers from the user and add them to
  an array (simulating a dynamic array using AddArrayElement) until the user
  chooses not to add more, then print the array length and its elements.
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

void AddArrayElements(int Number, int arr[100], int &arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;
}

void ReadArray(int arr[100], int &arrLength)
{
	bool AddMore = 0;
	do
	{
		AddArrayElements(ReadPositiveNumber("Please enter your number?"),arr, arrLength) ;
		cout << "Do you want to add more numbers? [0]:No, [1]:Yes? ";
    cin >> AddMore;
	} while (AddMore);
}

void PrintArray(int arr[100], int arrLength)
{
	
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] <<" ";
	}
	cout << endl;
}




int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength=0;
	
	 ReadArray(arr, arrLength);
	
	cout << "\narrLength : " << arrLength;
	cout << "\nArray elements :";
	PrintArray(arr, arrLength);

	return 0;
}
