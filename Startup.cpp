#include <iostream>
#include <stdlib.h>
#include <string>
#include "Cave.h"
#include "Monsters.h"
#include "Items.h"

using namespace std;

//Invintory Save Complete need to start and finish load function
//Player Weapon Max coming in as 0


int MenuChoice;
int NewGameChoice;
int TownChoice;
int TavernChoice;
int TQ;
int CaveChoice;
int Cavelvl;
int MS;				//MonsterSearch
int BattleChoice;
int NoPot;
int PDmgMin;
int PDmgMax;
int PBlockCh;
int PBlockAm;
bool Block;
bool Sure;
bool Turn;
void ExitGame();
void MonsterDrop();
void PlayerWin();
void PlayerAttack(int min, int max);
void MonsterAttack();
int Potions();

	Player Player;
	PlayerInv PlayerInv;
	Weapon PWeapon;
	Shield PShield;
	Weapon PlayerOffWeapon;
	Armor PArmor;
	Consumable PlayerCons1;
	Consumable PlayerCons2;
	
	Monster Monster;
	
int main()
{
	menu:
	{
		MenuChoice = Menu();
		if(MenuChoice == 1)
		{
			ClearScreen();
			cout<<"This will Erase all progress.";
			Sure = AreYouSure();
			if(Sure == false)
			{
				goto menu;
			}
			else 
			{ 	  
				goto newgame;	
			}
		}
		else if(MenuChoice == 2)
		{
			goto loadgame;
		}	 
		else if(MenuChoice == 3)
		{
			ExitG();
		}
	}
	
	newgame:
	{
		string TSN = Player.SetName();
		strcpy(Player.Name, TSN.c_str());
		NewGameChoice = NewGame(Player.Name);
		if(NewGameChoice == 1)
		{
			ClearScreen();
			Player.CT = 1;
			PlayerInv.EqItems[1][1] = 3;
			PlayerInv.EqItems[1][2] = 1;
			MakeItem(3,1);
			PWeapon.LoadItem();
			PWeapon.MakeWeapon();
			PlayerInv.EqItems[2][1] = 4;
			PlayerInv.EqItems[2][2] = 1;
			MakeItem(4,1);
			PShield.LoadItem();
			PShield.MakeShield();
		}
		else if(NewGameChoice == 2)
		{
			Player.CT = 2;
		}	
		else if(NewGameChoice == 3)
		{
			Player.CT = 3;
		}	
		else if(NewGameChoice == 4)
		{
			goto menu;
		}	
		else if(NewGameChoice == 5)
		{
			goto newgame;
		}
		MakeItem(2,1);
		PlayerCons1.LoadItem();
		PlayerCons1.Quant = 2;
		MakeItem(2,2);
		PlayerCons2.LoadItem();
		PlayerCons2.Quant = 2;
		PArmor.LoadItem();
		PArmor.MakeArmor();
		PlayerInv.EqItems[3][1] = 5;
		PlayerInv.EqItems[3][2] = 1;
		Player.InitSetUp(NewGameChoice);
		Player.LevelScreen();
		Player.SavePlayer();
		PlayerInv.Potions[1][1] = PlayerCons1.TID;
		PlayerInv.Potions[1][2] = PlayerCons1.ID;
		PlayerInv.Potions[1][3] = PlayerCons1.Quant;
		PlayerInv.Potions[2][1] = PlayerCons2.TID;
		PlayerInv.Potions[2][2] = PlayerCons2.ID;
		PlayerInv.Potions[2][3] = PlayerCons2.Quant;
		PlayerInv.SaveInvintory();
		ClearScreen();
		Intro();
		goto town;	  
	}
	
	loadgame:
	{
		ClearScreen();
		int EQC = 1;
		int NEI;
		int II;
		Player.LoadPlayer();
		PlayerInv.LoadInvintory();
		NEI = PlayerInv.CheckEqSpot();
		while(EQC <= NEI)
		{
			II = PlayerInv.EqItems[EQC][1];
			MakeItem(II,PlayerInv.EqItems[EQC][2]);
			if(II == 3 and PWeapon.ExA == 0)
			{
				PWeapon.LoadItem();
				PWeapon.MakeWeapon();
			}
			else if(II == 3 and PWeapon.ExA !=0)
			{
				//secondary weapon
			}
			else if(II == 4)
			{
				PShield.LoadItem();
				PShield.MakeShield();
			}
			else if(II == 5)
			{
				PArmor.LoadItem();
				PArmor.MakeArmor();
			}
			Select();
			EQC++;
		}
		MakeItem(PlayerInv.Potions[1][1],PlayerInv.Potions[1][2]);
		PlayerCons1.LoadItem();
		PlayerCons1.MakeCons();
		PlayerCons1.Quant = PlayerInv.Potions[1][3];
		MakeItem(PlayerInv.Potions[2][1],PlayerInv.Potions[2][2]);
		PlayerCons2.LoadItem();
		PlayerCons2.MakeCons();
		PlayerCons2.Quant = PlayerInv.Potions[1][3];
		PlayerInv.ShowInvintory();
		goto town;
	}
	
	town:
	{
		TownChoice = Town();
		if(TownChoice == 1)
		{
			goto tavern;
		}
		else if(TownChoice == 2)
		{
			Shop();
			goto town;
		}
		else if(TownChoice == 3)
		{
			cout<<"\n"<<TownChoice<<"\n"<<Player.CaveLevel<<"\n";
			if(Player.CaveLevel == 0)
			{
				Player.CaveLevel = 1;
				Cavelvl = 1;
				CaveIntro();
				goto cave;
			}
			else 
			{
				
				ClearScreen();
				cout<<"You hold your breath and enter the cave...(Submit any number to  continue)";
				Select();
				goto cave;
			}
		}
		else if(TownChoice == 4)
		{
			ExitGame();
		}
	}
	
	tavern:
	{
		TavernChoice = Tavern(Player.Questing);
		if(TavernChoice == 1)
		{
			goto tavernquest;
		}
		else if(TavernChoice == 2)
		{
			goto town;
		}
		else if(TavernChoice == 3)
		{
			goto tavern;
		}
	}
	
	tavernquest:
	{
		TQ = TavernQuest(Player.Quest);
		if(TQ == 1)
		{
			Player.Quest = 1;
			Player.Questing = true;
			goto tavern;
		}	
		else if(TQ== 2)
		{
			goto tavern;
		}
		else if(TQ == 3)
		{
			goto tavernquest;
		}
	}
	
	cave:
	{
		CaveChoice = Cave(Cavelvl);
		if(CaveChoice == 1)
		{
			goto monster;
			goto battle;
		}
		else if(CaveChoice == 2)
		{
			goto cave;
			//Player.LevelSearch();
		}
		else if(CaveChoice == 3)
		{
			goto town;
		}
		else if(CaveChoice == 4)
		{
			goto town;
		}
		else if(CaveChoice == 5)
		{
			PlayerInv.Potions[1][1] = PlayerCons1.TID;
			PlayerInv.Potions[1][2] = PlayerCons1.ID;
			PlayerInv.Potions[1][3] = PlayerCons1.Quant;
			PlayerInv.Potions[2][1] = PlayerCons2.TID;
			PlayerInv.Potions[2][2] = PlayerCons2.ID;
			PlayerInv.Potions[2][3] = PlayerCons2.Quant;
			PlayerInv.ShowInvintory();
			Select();
			goto cave;
		}
		else if(CaveChoice == 6)
		{
			Player.ShowStats();
			Select();
			goto cave;
		}
		else if(CaveChoice == 7)
		{
			goto cave;
		}
		else if(CaveChoice == 8)
		{
			ExitGame();	   
		}
	}
	
	monster:
	{
		ClearScreen();
		cout<<"You search the deep dark for a sign of life...";
		Select();
		MS = MonsterSearch(Player.Lvl);
		MonsterDet(Player.CaveLevel, MS);
		Monster.Load();
		Monster.HMSetUp();
		int PAtk = (Player.Str + Player.Def)/2 + Random(10);
		int MAtk = (Monster.Str + Monster.Def)/2 + Random(20);
		ClearScreen();
		cout<<"You have found a "<<Monster.Name<<".\n";
		cout<<"Monster Str:\t\t"<<Monster.Str<<"\n";
		cout<<"Monster Def:\t\t"<<Monster.Def<<"\n";
		cout<<"Monster HP:\t\t"<<Monster.HP<<"\n";
		Select();
		if(PAtk>MAtk)
		{
			Turn = true;
		}
		else 
		{
			Turn = false;
		}
		goto battle;
	}
	
	battle:
	{
		PDmgMin = PWeapon.Min;
		PDmgMax	= PWeapon.Max;
		cout<<"Min Damage:\t"<<PWeapon.Min;
		cout <<"Weapon Max:\t"<<PWeapon.Max;
		Select();
		if(Player.CT == 1)
		{
			PBlockCh = PShield.BCH;
			PBlockAm = PShield.Bamnt;
		}
		else if(Player.CT == 2)
		{
			PDmgMin		=	PDmgMin + PlayerOffWeapon.Min;
			PDmgMax		=	PDmgMax + PlayerOffWeapon.Max;
		}
		ClearScreen();
		if(Monster.HP < 1)
		{
			PlayerWin();
			if(Player.Exp >= Player.MaxExp)
			{
				Player.LevelUp();
			}
			else 
			{
				goto cave;
			}
		}
		else if(Player.HP < 1)
		{
			ClearScreen();
			cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tGame Over.\n\n\n\n\n";
			ExitG();
		}
		if(Turn == true)
		{
			
			BattleDisplay(Player.Name,Monster.Name,Player.HP,Monster.HP,Player.Exp,Player.MaxExp,Monster.Exp);	  	  	  
			BattleChoice = BattleChoose();
			if(BattleChoice == 1)
			{
				PlayerAttack(PDmgMin,PDmgMax);
			}
			else if(BattleChoice == 2)
			{
				//Spells
				ClearScreen();
				cout <<"Coming Soon...";
				Select();
				goto battle;
			}
			else if(BattleChoice == 3)
			{
				goto potion;
			}
			else if(BattleChoice == 4)
			{
				ClearScreen();
				cout <<"You run for your life back to town.\n";
				goto town;
			}
			Turn = false;
			goto battle;
		}
		else 
		{	 
			if(Player.CT == 1)
			{
				int R;
				R = Random(100);
				if(R <= PShield.BCH)
				{
					cout<<"You block"<<PShield.Bamnt<<"with your shield.\n";
					Select();
					Block = true;
				}
			}
			MonsterAttack();
			Turn = true;
			goto battle;
		}
	}
	
	potion:
	{
		PlayerCons1.MakeCons();
		ClearScreen();
		int NoPot;
		NoPot = Potions();
		int PPSel;
		PPSel = Select();
		if(NoPot > 0)
		{
			if(PPSel == 1 and NoPot != 2)
			{
				Player.HP = Player.HP + PlayerCons1.Amnt;
				cout<<"Health potion administered.\n";
				Select();
				cout<<"You healed "<<PlayerCons1.Amnt<<".\n";
				if(Player.HP > Player.MaxHP)
				{
					Player.HP = Player.MaxHP;
				}
			}
			else if((PPSel == 1 and NoPot == 2) or (PPSel == 2 and NoPot == 3))
			{
				Player.MP = Player.MP + PlayerCons2.Amnt;
				if(Player.MP > Player.MaxMP)
				{
					Player.MP = Player.MaxMP;
				}
			}	   	   	   	   	   
			else if((PPSel == 2 and NoPot != 3) or (PPSel == 3 and NoPot == 3))
			{
				goto battle;
			}
			else 
			{
				goto potion;
			}
		}
		else 
		{
			ClearScreen();
			cout <<"You have no potions!";
			Select();
			goto battle;
		}	 	 	 	 
		Turn = false;	 
		goto battle;
	}
}

void MonsterDrop()
{
	Item TempItem;
	DropDet(Player.Lvl, Monster.Luck); //Determine what the items is then save to file
	TempItem.LoadItem();
	cout <<"Item type "<<TempItem.TID<<"\n";
	cout <<"Item number "<<TempItem.ID<<"\n";
	if(TempItem.TID == 2)
	{
		/*
		Consumable Cons1;
		Cons1.LoadItem();
		Cons1.Amnt = Cons1.ExA;
		*/
		if(TempItem.ID == 1)
		{
			cout <<"Droping HP pot.\n";
			PlayerCons1.Quant++;
			cout <<"Health potions "<<PlayerCons1.Quant<<"\n";
		}
		else if(TempItem.ID == 2)
		{
			cout <<"Droping MP pot.\n";
			PlayerCons2.Quant++;
			cout <<"Mana potions "<<PlayerCons2.Quant<<"\n";
		}
		PlayerInv.Potions[1][1] = PlayerCons1.TID;
		PlayerInv.Potions[1][2] = PlayerCons1.ID;
		PlayerInv.Potions[1][3] = PlayerCons1.Quant;
		PlayerInv.Potions[2][1] = PlayerCons2.TID;
		PlayerInv.Potions[2][2] = PlayerCons2.ID;
		PlayerInv.Potions[2][3] = PlayerCons2.Quant;
	}
	cout <<Monster.Name<<" dropped a "<<TempItem.Name<<"\n";
}

void PlayerWin()
{
	int MD;
	ClearScreen();
	Player.Exp = Player.Exp + Monster.Exp;
	Player.Gold = Monster.Gold + Player.Gold;
	MD = Monster.Drop(Player.Luck);
	cout <<"You killed a "<<Monster.Name<<".\n";
	cout <<"You gained "<<Monster.Exp<<".\n";
	cout <<"You found "<<Monster.Gold<<" gold pieces.\n";
	cout <<"MD = "<<MD<<"\n";
	if(MD == 1)
	{
		cout <<"Dropping Item.\n";
		MonsterDrop();
	}
	else 
	{
		cout <<"No Items Found\n";
	}
	Select();
}

void PlayerAttack(int min, int max)
{
	cout <<"Initialize PlayerAttack()";
	int DmgMod;
	int TrueDmg;
	DmgMod = (Monster.Def - Player.Str);
	cout <<"Damage mod found.\nDamage mod: "<<DmgMod<<"\n";
	max = Random(max);
	cout <<"Randomized max.\nmax: "<<max<<"\n";
	TrueDmg = (Player.Str - DmgMod) + max + min;
	cout <<"True Damage found.\nTrue Damage: "<<TrueDmg<<"\n";
	if(TrueDmg < 0)
	{
		cout <<"Adjusting True Damage.\n";
		TrueDmg = 0;
	}
	Monster.HP = Monster.HP - TrueDmg;
	ClearScreen();
	BattleDisplay(Player.Name,Monster.Name,Player.HP,Monster.HP,Player.Exp,Player.MaxExp,Monster.Exp);
	cout <<"|You swing your blade.\t\t\t\t\t|\n";
	cout <<"|You hit the "<<Monster.Name<<" for "<<TrueDmg<<" Damage.\t\t\t\t|\n";
	cout <<"|The "<<Monster.Name<<" has "<<Monster.HP<<" health left.\t\t\t\t|\n";
	cout <<"|_______________________________________________________|\n";
	Select();
}

int Potions()
{
	int NoPot;
	cout <<" _______________________________\n";
	cout <<"|Potions\t\t\t|\n";
	cout <<"|_______________________________|\n";
	if(PlayerCons1.Quant == 0 and PlayerCons2.Quant == 0)
	{
		return 0;
	}
	else if(PlayerCons1.Quant >= 1 and PlayerCons2.Quant == 0)
	{
		cout <<"|1:"<<PlayerCons1.Name<<"\t"<<PlayerInv.Potions[1][2]<<"\t|\n";
		cout <<"|2:Return\t\t\t|\n";
		cout <<"|_______________________________|\n";
		return 1;
	}
	else if(PlayerCons2.Quant >= 1 >= 1 and PlayerCons1.Quant == 0)
	{
		cout <<"|1:"<<PlayerCons2.Name<<"\t"<<PlayerInv.Potions[2][2]<<"\t|\n";
		cout <<"|2:Return\t\t\t|\n";
		cout <<"|_______________________________|\n";
		return 2;
	}
	else 
	{
		cout <<"|1:"<<PlayerCons1.Name<<"\t"<<PlayerCons1.Quant<<"\t|\n";
		cout <<"|2:"<<PlayerCons2.Name<<"\t"<<PlayerCons2.Quant<<"\t|\n";
		cout <<"|3:Return\t\t\t|\n";
		cout <<"|_______________________________|\n";
		return 3;
	}
}

void MonsterAttack()
{
	int DmgMod;
	int TrueDmg;
	DmgMod = Player.Def - Monster.Str;
	TrueDmg = Monster.Str - DmgMod + Random(10);
	if(Block == true)
	{
		TrueDmg = TrueDmg - PShield.Bamnt;
	}
	if(TrueDmg < 0)
	{
		TrueDmg = 0;
	}
	Player.HP = Player.HP - TrueDmg;
	ClearScreen();
	BattleDisplay(Player.Name,Monster.Name,Player.HP,Monster.HP,Player.Exp,Player.MaxExp,Monster.Exp);
	cout <<"|The "<<Monster.Name<<" Lunges at you.\t\t\t\t\t|\n";
	cout <<"|The "<<Monster.Name<<" hits you for "<<TrueDmg<<" Damge.\t\t\t\t|\n";
	cout <<"|You have "<<Player.HP<<" health left.\t\t\t\t|\n";
	cout <<"|_______________________________________________________|\n";
	Select();
}

void ExitGame()
{
	Player.SavePlayer();
	PlayerInv.Potions[1][1] = PlayerCons1.TID;
	PlayerInv.Potions[1][2] = PlayerCons1.ID;
	PlayerInv.Potions[1][3] = PlayerCons1.Quant;
	PlayerInv.Potions[2][1] = PlayerCons2.TID;
	PlayerInv.Potions[2][2] = PlayerCons2.ID;
	PlayerInv.Potions[2][3] = PlayerCons2.Quant;
	PlayerInv.SaveInvintory();
	ExitG();
}


