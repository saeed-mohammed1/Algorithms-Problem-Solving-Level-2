/*
  =============================================================================
  Extra Project (Level 2): Monster Hunter Arena
  Write a modular, turn-based RPG console game where a player battles a monster. 
  Both start with 100 HP. The program should:
  - Allow both the player and the monster to dynamically choose between 
    Fast Attack, Heavy Attack, or Healing Potion each round.
  - Calculate randomized damage and healing values based on the chosen action.
  - Cap maximum health at 100 HP to prevent logic glitches.
  - Determine the round outcome and change console colors accordingly 
    (Green for player advantage, Red for monster, Yellow for healing).
  - Display a round summary and update total health.
  - Announce the overall winner when health drops to 0 or below, 
    and prompt the user to play again.
  =============================================================================
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enChoiceFace { FastAttack = 1 , HeavyAttack = 2 , HealPotion = 3};

struct stRoundInfo
{
	short HealPlayer = 100;
	short HealMonster = 100;
	enChoiceFace PlayerChoice;
	enChoiceFace MonsterChoice;
	string NamePlayerChoice;
	string NameMonsterChoice;
	short PlayerdealtDamage;
	short MonsterdealtDamage;
	bool playerWinner = false;
};

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

string Tab(int Num)
{
	string t = "";
	for (int i = 0; i < Num;i++)
	{
		t = t + "\t";
	}
	return t;
}

void StartScreen()
{
	cout << "==================================================\n";
	cout <<Tab(1) <<" Welcome to Monster Hunter Arena  \n";
	cout << "==================================================\n";
}

enChoiceFace Player1Choice()
{
	short Select = 0;

	cout << "Select Your Action:\n";
	cout << "[1] Fast Attack (10-25 Damage)\n";
	cout << "[2] Heavy Attack (0-40 Damage, Risky!)\n";
	cout << "[3] Heal Potion (15-30 HP)\n\n";
	do
	{
		cout << "Your Choice? ";
		cin >> Select;
	} while (Select < 1 || Select > 3);

	return (enChoiceFace)Select;
}

enChoiceFace Monster1Choice()
{
	return (enChoiceFace)RandomNumber(1, 3);
}

short ValueChoice(enChoiceFace ChoiceFace)
{
	switch (ChoiceFace)
	{
	case enChoiceFace::FastAttack:
		return RandomNumber(10, 25);
	case enChoiceFace::HeavyAttack:
		return RandomNumber(0, 40);
	case enChoiceFace::HealPotion:
		return RandomNumber(15, 30);
	}
}

void WhatisHeal(stRoundInfo RoundInfo)
{
	if (RoundInfo.PlayerChoice == enChoiceFace::HealPotion && RoundInfo.MonsterChoice == enChoiceFace::HealPotion)
	{
		cout << "Player healed for " << RoundInfo.PlayerdealtDamage << " HP! \n";
		cout << "Monster healed for " << RoundInfo.MonsterdealtDamage << " HP! \n";
	}
	else
	{
		if (RoundInfo.PlayerChoice == enChoiceFace::HealPotion)
		{
			cout << "Player healed for " << RoundInfo.PlayerdealtDamage << " HP! \n";
			cout << "Monster dealt " << RoundInfo.MonsterdealtDamage << " Damage to the Player! \n";
		}
		else
		{
			cout << "Player dealt " << RoundInfo.PlayerdealtDamage << " Damage to the Monster! \n";
			cout << "Monster healed for " << RoundInfo.MonsterdealtDamage << " HP! \n";
		}
	}

}

void RoundSummary(stRoundInfo RoundInfo)
{
	cout << "Player Action : " << RoundInfo.NamePlayerChoice << endl;
	cout << "Monster Action: " << RoundInfo.NameMonsterChoice << endl;
	cout << "\n";

	if (RoundInfo.PlayerChoice != enChoiceFace::HealPotion && RoundInfo.MonsterChoice != enChoiceFace::HealPotion)
	{
		cout << "Player dealt " << RoundInfo.PlayerdealtDamage << " Damage to the Monster! \n";
		cout << "Monster dealt " << RoundInfo.MonsterdealtDamage << " Damage to the Player! \n";
	}
	else
	{
		WhatisHeal(RoundInfo);
	}


}

void CalcHealth(stRoundInfo& RoundInfo)
{
	if (RoundInfo.PlayerChoice == enChoiceFace::HealPotion && RoundInfo.MonsterChoice == enChoiceFace::HealPotion)
	{
		RoundInfo.HealPlayer += RoundInfo.PlayerdealtDamage;
		RoundInfo.HealMonster += RoundInfo.MonsterdealtDamage;
	}
	else
	{
		if (RoundInfo.PlayerChoice != enChoiceFace::HealPotion && RoundInfo.MonsterChoice != enChoiceFace::HealPotion)
		{
			RoundInfo.HealPlayer -= RoundInfo.MonsterdealtDamage;
			RoundInfo.HealMonster -= RoundInfo.PlayerdealtDamage;
		}
		else
		{
			if (RoundInfo.PlayerChoice == enChoiceFace::HealPotion)
			{
				RoundInfo.HealPlayer -= RoundInfo.MonsterdealtDamage;
				RoundInfo.HealPlayer += RoundInfo.PlayerdealtDamage;
			}
			else
			{
				RoundInfo.HealMonster -= RoundInfo.PlayerdealtDamage;
				RoundInfo.HealMonster += RoundInfo.MonsterdealtDamage;
			}
		}
	}

	if (RoundInfo.HealMonster > 100)
	{
		RoundInfo.HealMonster = 100;
		
	}
	if (RoundInfo.HealPlayer > 100)
	{
		RoundInfo.HealPlayer = 100;
	}
	
}

void ScreenHealth(stRoundInfo RoundInfo)
{
	cout << "Player Health  : [" << RoundInfo.HealPlayer << "] HP \n";
	cout << "Monster Health : [" << RoundInfo.HealMonster << "] HP \n\n";
}

void SetScreenColor(stRoundInfo RoundInfo)
{
	if (RoundInfo.PlayerChoice == enChoiceFace::HealPotion)
	{
		system("color 6F");
	}
	else
	{
		if (RoundInfo.PlayerdealtDamage > RoundInfo.MonsterdealtDamage)
		{
			system("color 2F");
		}
		else if (RoundInfo.PlayerdealtDamage < RoundInfo.MonsterdealtDamage)
		{
			system("color 4F");
			cout << "\a";
		}
		else
		{
			system("color 6F");
		}
	}
}

string NameChioce(enChoiceFace ChoiceFace)
{
	string Arr[3] = { "Fast Attack" , "Heavy Attack"  , "Heal Potion" };
	return Arr[ChoiceFace - 1];
}

stRoundInfo GameRound()
{
	stRoundInfo RoundInfo;
	int Count = 1;
	
	while (RoundInfo.HealMonster > 0 && RoundInfo.HealPlayer > 0)
	{
		cout << "---[ Round " << Count << " ]---\n";
		ScreenHealth(RoundInfo);
		RoundInfo.PlayerChoice = Player1Choice();
		RoundInfo.MonsterChoice = Monster1Choice();

		RoundInfo.NamePlayerChoice = NameChioce(RoundInfo.PlayerChoice);
		RoundInfo.NameMonsterChoice = NameChioce(RoundInfo.MonsterChoice);

		RoundInfo.PlayerdealtDamage = ValueChoice(RoundInfo.PlayerChoice);
		RoundInfo.MonsterdealtDamage = ValueChoice(RoundInfo.MonsterChoice);

		CalcHealth(RoundInfo);
		cout << "------------- Round [" << Count << "]Summary -------------\n";
		RoundSummary(RoundInfo);
		cout << "---------------------------------------------\n";
		SetScreenColor(RoundInfo);
		Count++;

	}
	return RoundInfo;
}



bool WhoWinner(stRoundInfo RoundInfo)
{
	return RoundInfo.HealPlayer > RoundInfo.HealMonster;
}

void GameOverScreen()
{
	cout << "\n==================================================\n";
	cout << Tab(2)<< " GAME OVER ";
	cout << "\n==================================================\n\n";
}

void ScreenResult(stRoundInfo RoundInfo)
{
	cout << "Final Player Health  : " << RoundInfo.HealPlayer << " HP \n";
	cout << "Final Monster Health : " << RoundInfo.HealMonster << " HP \n";

	if (RoundInfo.playerWinner)
	{
		cout << "CONGRATULATIONS! YOU KILLED THE MONSTER!  \n";
	}
	else
	{
		cout << " Oh No, The monster killed you. \n";
	}
	cout << "================================================== \n\n";
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char Again = 'Y';

	do
	{
		stRoundInfo RoundInfo;
		ResetScreen();
		StartScreen();
		RoundInfo = GameRound();
		RoundInfo.playerWinner = WhoWinner(RoundInfo);
		GameOverScreen();
		ScreenResult(RoundInfo);

		cout << "Do you want to play again? Y/N? ";
		cin >> Again;
	} while (Again == 'Y' || Again == 'y');
}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}
