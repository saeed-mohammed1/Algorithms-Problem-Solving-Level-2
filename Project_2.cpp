#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   
using namespace std;

enum enQuezLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOperType { Add = 1, Sub = 2, Mul = 3, Div = 4, Mixx = 5 };
enum enWinner { Pass = 1, Fail = 2 };


struct stQuezInfo
{
	enQuezLevel QuezLevel;
	short Num1 = 0;
	short Num2 = 0;
	enOperType OperType;
	char OperTypeName;
	enWinner Winner;
	int Result;
	short Player1Choice;
};

struct stResultQuez
{
	short NumOfQuestions;
	enOperType OperType;
	enQuezLevel QuestionLevel;
	string QuestionLevelName;
	string OperTypeName;
	short NumOfRightAnswer;
	short NumOfWrongAnswer;
	enWinner PassOrfail;
	string PassOrfailName;
};

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

int HowManyQuestions()
{
	int NumQuestions = 0;
	do
	{
		cout << "How Many Questions do you Want to answer? 1 : 10 ?";
		cin >> NumQuestions;
	} while (NumQuestions < 1 || NumQuestions > 10);
	return NumQuestions;
}

enQuezLevel ReadLevel()
{
	short Level = 0;
	do
	{
		cout << "Enter Question Level [1]Easy, [2]Med, [3]Hard, [4]Mix? ";
		cin >> Level;

	} while (Level < 1 || Level > 4);
	return (enQuezLevel)Level;
}

enOperType ReadOperType()
{
	short OperType = 0;
	do
	{
		cout << "Enter Operation Type,  [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix? ";
		cin >> OperType;

	} while (OperType < 1 || OperType > 6);
	return (enOperType)OperType;
}

string LevelName(enQuezLevel Level)
{
	string ArrLevel[4] = { "Easy","Med","Hard","Mix" };
	return ArrLevel[Level - 1];
}

string OperTypeName(enOperType OperType)
{
	string ArrOperType[5] = { "Add","Sub","Mul","Div","Mix" };
	return ArrOperType[OperType - 1];
}

string PassOrFailName(enWinner PassOrFail)
{
	string ArrPassOrFail[2] = { "Pass" , "Fail" };
	return ArrPassOrFail[PassOrFail - 1];
}

void SetScreenColor(stQuezInfo QuezInfo)
{
	if (QuezInfo.Player1Choice == QuezInfo.Result)
	{
		cout << "Correct Answer :-) \n";
		system("color 2F");
	}
	else
	{
		cout << "Wrong Answer :-( \n";
		cout << "The right answer is : " << QuezInfo.Result << endl;
		cout << "\a";
		system("color 4F");

	}

}

enWinner WhoWonTheRound(stQuezInfo QuezInfo)
{
	if (QuezInfo.Player1Choice == QuezInfo.Result)
	{

		return enWinner::Pass;
	}
	else
	{
		return enWinner::Fail;
	}
}

int Player1Chioce()
{
	int Num;
	cin >> Num;
	return Num;
}

void PrintRoundInfo(stQuezInfo& QuezInfo)
{
	cout << QuezInfo.Num1 << endl;
	cout << QuezInfo.Num2 << " " << QuezInfo.OperTypeName << endl;
	cout << "---------------\n";
	QuezInfo.Player1Choice = Player1Chioce();
	SetScreenColor(QuezInfo);
}

void FillQuezInfo(stQuezInfo& QuezInfo)
{
	switch (QuezInfo.QuezLevel)
	{
	case enQuezLevel::Easy:
		QuezInfo.Num1 = RandomNumber(1, 10);
		QuezInfo.Num2 = RandomNumber(1, 10);
		break;
	case enQuezLevel::Med:
		QuezInfo.Num1 = RandomNumber(10, 50);
		QuezInfo.Num2 = RandomNumber(10, 50);
		break;
	case enQuezLevel::Hard:
		QuezInfo.Num1 = RandomNumber(50, 100);
		QuezInfo.Num2 = RandomNumber(50, 100);
		break;
	default:
	{
		QuezInfo.Num1 = RandomNumber(1, 100);
		QuezInfo.Num2 = RandomNumber(1, 100);
		break;
	}
	}

	if (QuezInfo.OperType == enOperType::Mixx)
	{
		QuezInfo.OperType = (enOperType)RandomNumber(1, 4);
	}

	switch (QuezInfo.OperType)
	{
	case enOperType::Add:
		QuezInfo.Result = QuezInfo.Num1 + QuezInfo.Num2;
		break;
	case enOperType::Sub:
		QuezInfo.Result = QuezInfo.Num1 - QuezInfo.Num2;
		break;
	case enOperType::Mul:
		QuezInfo.Result = QuezInfo.Num1 * QuezInfo.Num2;
		break;
	case enOperType::Div:
		QuezInfo.Result = QuezInfo.Num1 / QuezInfo.Num2;
		break;
	default:
	{

		break;
	}
	}


}

string PassOrFail(stResultQuez ResultQuez)
{
	if (ResultQuez.NumOfRightAnswer >= ResultQuez.NumOfWrongAnswer)
	{
		return "Pass :-)";
	}
	return "Fail :-(";
}

stResultQuez FillResultQuez(short NumOfQuestions, enQuezLevel QuestionLevel, char OperType, short NumOfRightAnswer, short NumOfWrongAnswer)
{
	stResultQuez ResultQuez;

	ResultQuez.NumOfQuestions = NumOfQuestions;
	ResultQuez.NumOfRightAnswer = NumOfRightAnswer;
	ResultQuez.NumOfWrongAnswer = NumOfWrongAnswer;
	ResultQuez.OperType = (enOperType)OperType;
	ResultQuez.OperTypeName = OperTypeName(ResultQuez.OperType);
	ResultQuez.QuestionLevel = (enQuezLevel)QuestionLevel;
	ResultQuez.QuestionLevelName = LevelName(ResultQuez.QuestionLevel);
	ResultQuez.PassOrfailName = PassOrFail(ResultQuez);
	return ResultQuez;
}

char ChoiceTostringType(enOperType OperType)
{
	switch (OperType)
	{
	case enOperType::Add:
		return '+';
	case enOperType::Sub:
		return '-';
	case enOperType::Mul:
		return '*';
	case enOperType::Div:
		return '/';
	default:
	{
		return '?';
		break;
	}
	}
}


stResultQuez PlayGame(short HowManyQuestions)
{
	stQuezInfo QuezInfo;
	short NumOfRightAnswer = 0, NumOfWrongAnswer = 0;
	enQuezLevel UserLevel = ReadLevel();
	enOperType OperType = ReadOperType();


	for (int GameRound = 1; GameRound <= HowManyQuestions; GameRound++)
	{
		QuezInfo.QuezLevel = UserLevel;
		QuezInfo.OperType = OperType;
		FillQuezInfo(QuezInfo);
		QuezInfo.OperTypeName = ChoiceTostringType(QuezInfo.OperType);
		cout << "Question [" << GameRound << "/" << HowManyQuestions << "]" << endl;

		PrintRoundInfo(QuezInfo);

		if (QuezInfo.Player1Choice == QuezInfo.Result)
			NumOfRightAnswer++;
		else
			NumOfWrongAnswer++;
	}
	QuezInfo.QuezLevel = UserLevel;
	QuezInfo.OperType = OperType;
	return FillResultQuez(HowManyQuestions, QuezInfo.QuezLevel, QuezInfo.OperType, NumOfRightAnswer, NumOfWrongAnswer);
}


void ShowGameOverScreen(string PassOrFail)
{
	cout << "----------------------------------\n\n";
	cout << "Final Result is " << PassOrFail << endl << endl;;
	cout << "----------------------------------\n\n";
}

void ShowFinalResults(stResultQuez ResultQuez)
{
	cout << "Number of question     : " << ResultQuez.NumOfQuestions << endl;
	cout << "Question Level         : " << ResultQuez.QuestionLevelName << endl;
	cout << "OpType                 : " << ResultQuez.OperTypeName << endl;
	cout << "Numner of right answer : " << ResultQuez.NumOfRightAnswer << endl;
	cout << "Numner of wrong answer : " << ResultQuez.NumOfWrongAnswer << endl;
	cout << "----------------------------------------------------------\n";

}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}


void PlayMathGame()
{
	stResultQuez ResultQuez = PlayGame(HowManyQuestions());
	ShowGameOverScreen(ResultQuez.PassOrfailName);
	ShowFinalResults(ResultQuez);
}

void StartGame()
{
	char TryAgain = 'Y';
	do
	{
		ResetScreen();
		PlayMathGame();

		cout << "Do you Try Agian ? Y/N? ";
		cin >> TryAgain;

	} while (TryAgain == 'Y' || TryAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}

