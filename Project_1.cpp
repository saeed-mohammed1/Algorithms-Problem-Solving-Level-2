/*
  =============================================================================
  Project #1 (Level 2): Stone - Paper - Scissors Game
  Write a modular, console-based Stone-Paper-Scissors game that allows the
  player to play 1 to 10 rounds against the computer. The program should:
  - Read player choice and generate a random choice for the computer.
  - Determine the winner of each round and change console colors accordingly.
  - Display round results and aggregate total match statistics.
  - Announce the overall winner and prompt the user to play again.
  =============================================================================
*/
#include <iostream>
#include <string>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string NameWinner;
};

struct stGameResults
{
	short GameRounds = 0;
	short Player1WinTimes = 0;
	short Computer2WinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";
};

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

short ReadHowManyRounds()
{
	short GameRounds = 1;
	do
	{
		cout << "How Many Rounds 1 to 10 ? \n";
		cin >> GameRounds;
	} while (GameRounds < 1 || GameRounds > 10);

	return GameRounds;
}

enGameChoice ChoiceComputer()
{
	return (enGameChoice)RandomNumber(1, 3);
}

enGameChoice ReadPlayer1Choice()
{
	short Choice = 1;
	do
	{
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		cin >> Choice;
	} while (Choice < 1 || Choice > 3);

	return (enGameChoice)Choice;
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.ComputerChoice == RoundInfo.Player1Choice)
	{
		return enWinner::Draw;
	}

	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
			return enWinner::Computer;
		break;
	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
			return enWinner::Computer;
		break;
	case enGameChoice::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
			return enWinner::Computer;
		break;
	}

	return enWinner::Player1;
}

string WinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player1" , "Computer" , "Draw" };
	return arrWinnerName[Winner - 1];
}

string ChoiceToString(enGameChoice Choice)
{
	string arrChoiceName[3] = { "Stone" , "Paper" , "Scissors" };
	return arrChoiceName[Choice - 1];
}

void SetScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2F");
		break;
	case enWinner::Computer:
		cout << "\a";
		system("color 4F");
		break;
	case enWinner::Draw:
		system("color 6F");
		break;

	}


}

void PrintRoundResults(stRoundInfo RoundInfo)
{
	cout << "_____________Round[" << RoundInfo.RoundNumber << "]_____________ \n \n";
	cout << "Player1  Choice: " << ChoiceToString(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice: " << ChoiceToString(RoundInfo.ComputerChoice) << "\n";
	cout << "Round Winner   : [" << RoundInfo.NameWinner << "] \n";
	cout << "__________________________________ \n \n";

	SetScreenColor(RoundInfo.Winner);

}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;
	else if (Player1WinTimes < ComputerWinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

stGameResults FillGameResults(short GameRounds, short Player1WinTimes, short Computer2WinTimes, short DrawTimes)
{
	stGameResults GameResults;

	GameResults.GameRounds = GameRounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.Computer2WinTimes = Computer2WinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, Computer2WinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;


}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short Player1WinTimes = 0, Computer2WinTimes = 0, DrawTimes = 0;

	for (int RoundGame = 1; RoundGame <= HowManyRounds; RoundGame++)
	{
		cout << "\nRound [" << RoundGame << "] begins:\n";
		RoundInfo.Player1Choice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = ChoiceComputer();
		RoundInfo.RoundNumber = RoundGame;
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.NameWinner = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player1)
			Player1WinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			Computer2WinTimes++;
		else
			DrawTimes++;

		PrintRoundResults(RoundInfo);
		
			
	}
	return FillGameResults(HowManyRounds, Player1WinTimes, Computer2WinTimes, DrawTimes);

}

string Tabs(short Number)
{
	string t = "";
	for (int i = 0; i < Number;i++)
	{
		t = t + "\t";
	}
	return t;
}

void ShowGameOverScreen()
{
	cout << Tabs(2) << "__________________________________________________________\n\n";
	cout << Tabs(2) << "                 +++ G a m e  O v e r +++\n";
	cout << Tabs(2) << "__________________________________________________________\n\n";
}

void ShowFinalGameResults(stGameResults GameResults)
{
	cout << Tabs(2) << "_____________________ [Game Results] _____________________\n\n";
	cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player1 won times  : " << GameResults.Player1WinTimes << endl;
	cout << Tabs(2) << "Computer won times : " << GameResults.Computer2WinTimes << endl;
	cout << Tabs(2) << "Draw times         : " << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner       : " << GameResults.WinnerName << endl;
	cout << Tabs(2) << "__________________________________________________________\n";
	SetScreenColor(GameResults.GameWinner);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char TryAgain = 'Y';
	do
	{
		ResetScreen();
		 stGameResults GameResults = PlayGame(ReadHowManyRounds());
		 ShowFinalGameResults(GameResults);

		 cout << endl << Tabs(3) << "Do you Try Agian? Y/N?";
		 cin >> TryAgain;
	} while (TryAgain == 'Y' || TryAgain == 'y');

}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}



