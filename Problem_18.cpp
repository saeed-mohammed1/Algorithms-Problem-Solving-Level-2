/*
  =============================================================================
  Problem #18 (Level 2):
  Write a program to ask the user to enter a text, then encrypt it using
  a simple Caesar cipher (+Key to ASCII value), and decrypt it back to
  the original text (-Key).
  =============================================================================
*/
#include <iostream>
#include <string>
using namespace std;

struct stCrpt
{
	string Text;
	string Encrpt;
	string Decrpt;
};
string ReadText()
{
	string Name;
	cout << "Please enetr text?" << endl;
	getline(cin, Name);
	return Name;
}

string Encrpted(string Name , short EncrptionKey)
{
	for (int i = 0; i != Name.length(); i++)
	{
		Name[i]= char( (int)Name[i] + EncrptionKey);
	}
	return Name;
}

string Decrpted(string Name , short EncrptionKey)
{
	for (int i = 0; i != Name.length(); i++)
	{
		Name[i] = char( (int)Name[i] - EncrptionKey);
	}
	return Name;
}

stCrpt ReadAll()
{
	const short EncrptionKey = 2;
	stCrpt Crpt;
	Crpt.Text = ReadText();
	Crpt.Encrpt = Encrpted(Crpt.Text , EncrptionKey);
	Crpt.Decrpt = Decrpted(Crpt.Encrpt , EncrptionKey);
	return Crpt;
}
int main()
{
	stCrpt Crpt = ReadAll();
	cout << "Before encrpt :" << Crpt.Text << endl;
	cout << "After encrpt :" << Crpt.Encrpt << endl;
	cout << "After decrpt :" << Crpt.Decrpt << endl;
		
	return 0;
}
