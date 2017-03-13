#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "Cave.h"
#include "Monsters.h"
#include "Items.h"

using namespace std;

void ExitG()
{
	exit(0);
}

void ClearScreen()
{
	cout << string( 100, '\n' );
}

string TabCheck(string String, int Tick)
{
	int Size;
	double Tab;
	Size = String.size();
	Tab = Tick - round(Size/5);
	string Tabs(Tab, '\t');
	return Tabs;
}

void ShowHome()
{
	ClearScreen();
	cout <<"\n\n\n\n\n\n\n\n\t\t\t\tCave Mania\n\n\n\n\t\t  1:New Game\t2:Load\t\t3:Quit\n\n\n\n\n\n\n\n\nPlease select an option:";
}

void ShowNewGame()
{
	ClearScreen();
	cout <<"Will you Select...\n\n\n\n\n1: The Knight\t\t A Strong warior focused on statistical wining.\n\n\n2: The Scoundrel\t A Cuning and stealthy character who uses \n\t\t\t skill and stats.\n\n\n3: The Mage\t\t MAXIMUM POWAH!\n\n\n\n\n\n\nSelect 4 to return.\n";
}

bool AreYouSure()
{
	int Sure;
	ClearScreen();
	cout <<"Are you sure...?(1:Yes or 2:No)";
	Sure = Select();
	if(Sure == 1)
		return true;
	if(Sure == 2)
		return false;
	if(Sure == 3)
		AreYouSure();
}

int Select()
{
	int Selection;
	Selection = 0;
	cin>>Selection;
	return Selection;
}

int Random(int RMax)
{
	int mod1 = rand() % 3;
	int mod2 = rand() % 3;
	int Rnum;
	Rnum = rand() % RMax;
	Rnum = Rnum + mod1 - mod2;
	if(Rnum > RMax)
	{
		Rnum = RMax;
	}
	if(Rnum < 0)
	{
		Rnum = 0;
	}
	return Rnum;
}

int RoundDown(int RDNum)
{
	int RDReturn;
	floor (RDNum);
	return RDReturn;
}

int Menu()
{
	int MSelect;
	ShowHome();
	MSelect = Select();
	if(MSelect == 1)
		return 1;	//NewGame();
	else if(MSelect == 2)
		return 2;	 //LoadGame();
	else if(MSelect == 3)
	{
		bool AYS;
		AYS = AreYouSure();
		if(AYS == true)
		{
			return 3;
		}
		else 
		{
			Menu();	  //menu
		}
	}
	else 
	   Menu(); //Menu();
}

int NewGame(char NTag[15])
{
	int NSelect;
	ShowNewGame();
	NSelect = Select();
	ClearScreen();
	ClearScreen();
	if(NSelect == 1)
	{
		cout<<"Very well Sir "<<NTag<<", Knight of Old.\n";
		Select();
		return 1;		//Player.LevelScreen();	  Player.SavePlayer();	  Intro();	  Set Character to Knight
	}
	else if(NSelect == 2)
	{
		cout<<"Welcome abord Mr."<<NTag<<", Scallywag and Scoundrel.";
		Select();
		return 2;	//Set Character to Scoundrel
	}
	else if(NSelect == 3)
	{
		cout<<"Greatings Master "<<NTag<<", the Mage.";
		Select();
		return 3;	//Set Character to Mage
	}
	else if(NSelect == 4)
			return 4;
	else 
		return 5;
}

void Load()
{
	ClearScreen();
	cout <<"Coming Soon...(Select any number to return)";
	Select();
	Menu();
}

void Intro()
{
	string Megan("\t\tHI MEGAN!!!!!!\n");
	ClearScreen();
	cout <<" You grew up a farm boy; knowing little of the world and less about yourself.\n";
	cout<<"Make your parents proud, grow up, and start a family. Such a simple and easy\n";
	cout<<"life; thats all we ever wanted...";
	Select();
	ClearScreen();
	cout <<" One dark and Hell-born day, a gloomy and forgotten cave was overrun with\n demons. Then, the monster that haunted my darkest dreams walked the Earth\nand festered my land...";
	Select();
	ClearScreen();
	cout <<" They destroyed my farm, my family, my future...everything. In doing so, they \nhave doomed themselves. I won't rest until I see every last one of their corpses free from my land...";
	Select();
	ClearScreen();
	cout<<"CAVE MANIA!";
	Select();
	ClearScreen();
}

int Town()
{
	int TSel = 0;
	ClearScreen();
	cout <<"You have entered town. Where do you want to go?\n";
	cout <<" _________________\n";
	cout <<"|      Town       |\n";
	cout <<"|_________________|\n";
	cout <<"|                 |\n";
	cout <<"|1:Tavern         |\n";
	cout <<"|2:Shop           |\n";
	cout <<"|3:Cave           |\n";
	cout <<"|4:Save and Quit  |\n";
	cout <<"|_________________|\n";
	TSel = Select();
	if(TSel == 1)
	{
		return 1;	//Tavern();
	}
	else if(TSel == 2)
	{
		return 2;	//Shop();
	}
	else if(TSel == 3)
	{
		return 3;	//Cave();
	}
	else if(TSel == 4)
	{
		bool AYS;
		AYS = AreYouSure();
		if(AYS == true)
		{
			return 4;
		}
		else 
		{
			Town();
		}
	}
	else 
	{
		Town();
	}
}

int Tavern(bool Qing)
{
	//run questcheck first in main then wire it to here
	ClearScreen();
	cout <<"You enter the tavern...\n";
	if(Qing == false)
	{
		int ASel = 0;
		cout <<"As you enter, you see an old man who beckons you closer...\nDo you approach him?\n1:Approach\n2:Ignore and Leave\n";
		ASel = Select();
		ClearScreen();
		if(ASel == 1)
		{
			return 1;	//TavernQuest();
		}
		else if(ASel == 2)
		{
			return 2;
		}
		else 
		{
			Tavern(Qing);	//Tavern();
		}
	}
	else 
	{
		cout <<"Everyone is too drunk to be bothered...(Submit any number to continue)";
		Select();
		return 2;
	}
}

int TavernQuest(int TQuest)
{	  
	//wire Player.CheckQuest and QuestNumberhere
	ClearScreen();
	if(TQuest != 1)
	{
		int PQSel;
		cout <<" There is a gang of wolves in the first level of the cave that have killed\n";
		cout<<"several villagers. I would reward you if you dispatched them.\nDo you take the quest?(Y:1/N:2)";
		PQSel = Select();
		ClearScreen();
		if(PQSel == 1)
		{
			//Questing = true;
			//Quest= 1
			cout <<"Good luck son...";
			return 1;	//Tavern();
		}
		else if(PQSel == 2)
		{
			cout <<"Very well then...";
			return 2;	//Tavern();
		}
		else 
		{
			return 3;	//TavernQuest();
		}
	}
	else if(TQuest == 1)
	{
		cout <<"Thank you for your help. I have no more quests right now.";
		Select();
		Town();
	}
}

void Shop()
{
	ClearScreen();
	cout <<"The shop is closed right now...(Submit any number to continue)";
	Select();
}

void CaveIntro()
{
	ClearScreen();
	cout<<"As the mouth of the cave begins to engulf you, you feel a creeping sense of\n doom. Knowing that only cleansing the cave of its rancore would stop the evil\n of the cave from devouring the town; then, soon, the world.\n";
	cout<<"(Submit any number to continue)";
	Select();
}

int Cave(int clvl)
{
	int CSel;
	ClearScreen();
	cout<<"Now in the darkness of the cave, you look around.\n";
	cout<<"Will you...\n";
	cout<<" ________________________ \n";
	cout<<"|Cave Level "<<clvl<<"\t\t |\n";	  	  //Cave Lvl
	cout<<"|1:Search for Monsters 	 |\n";
	cout<<"|2:Search for Next Level |\n";
	cout<<"|3:Go back a level\t |\n";
	cout<<"|4:Go to town\t\t |\n";
	cout<<"|5:Invintory\t\t |\n";
	cout<<"|6:Stats\t\t |\n";
	cout<<"|7:Quest\t\t |\n";
	cout<<"|8:Quit\t\t\t |\n";
	cout<<"|________________________|\n";
	CSel = Select();
	if(CSel == 1)
	{
		return 1; //Monster Search
	}
	else if(CSel == 2)
	{
		ClearScreen();
		cout<<"coming soon...";
		Select();
		return 2;	//Level Search
	}
	else if(CSel == 3)
	{
		return 3;
	}
	else if(CSel == 4)
	{
		return 4;
	}
	else if(CSel == 5)
	{
		ClearScreen();
		cout<<"fetching invintory...";
		Select();
		return 5;
	}
	else if(CSel == 6)
	{
		return 6;	// Show Stats
	}
	else if(CSel == 7)
	{
		ClearScreen();
		cout<<"coming soon...";
		Select();
		return 7;
	}
	else if(CSel == 8)
	{
		return 8;
	}
	else 
	{
		return 5;
	}
}

void BattleDisplay(string PName,string MName,int PHP,int MHP,int PExp,int PNExp,int MExp)
{
	int NExp = PNExp - PExp;
	cout <<" _______________________________________________________\n";
	cout <<"|"<<PName<<"\t\t\t\t"<<MName<<"\t\t\t|\n";
	cout <<"|_______________________________________________________|\n";
	cout <<"|HP:\t\t"<<PHP<<"\t\tHP:\t"<<MHP<<"\t\t|\n";
	cout <<"|Exp Neded:\t"<<NExp<<"\t\tExp:\t"<<MExp<<"\t\t|\n";
	cout <<"|_______________________________________________________|\n";
	cout <<"|1:Attack                                               |\n";
	cout <<"|2:Spells                                               |\n";
	cout <<"|3:Potions                                              |\n";
	cout <<"|4:Run                                                  |\n";
	cout <<"|_______________________________________________________|\n";
}

void GetItem(int GTID, int GID, int ISpot)
{
	Item *TPItem;
	if(GTID == 1)
	{
		if(GID == 1)
		{
			//TPItem = &WolfSkull;
		}
	}
}

int BattleChoose()
{
	int BC;
	BC = Select();
	if(BC == 1)
	{
		return 1;
	}
	else if(BC == 2)
	{
		return 2;
	}
	else if(BC == 3)
	{
		return 3;
	}
	else if(BC == 4)
	{
		return 4;
	}
	else 
	{
		return 5;
	}
}

string Player::SetName()
{
	ClearScreen();
	char Tag[15];
	cout<<"Please enter your name : ";
	cin.getline(Tag,14);
	cin.getline(Tag,14);
	for(int NameCount;NameCount<15;NameCount++)
	{
		Name[NameCount] = Tag[NameCount];
	}
	string StringName(Tag);
	return StringName;
}

void Player::LoadPlayer()
{
	ClearScreen();
	string line;
	ifstream inputStream;
    inputStream.open("AutoSave.txt");
	if(!inputStream)
	{
		ClearScreen();
		cout<<"Fatal Error: No file to load";
		Select();
		Menu();
	}
	
	getline(inputStream,line);
		strcpy(Name, line.c_str());
	getline(inputStream,line);
		CT = atoi(line.c_str());
	getline(inputStream,line);
		Lvl = atoi(line.c_str());
	getline(inputStream,line);
		Exp = atoi(line.c_str());
	getline(inputStream,line);
		HP = atoi(line.c_str());
	getline(inputStream,line);
		MP = atoi(line.c_str());
	getline(inputStream,line);
		Str = atoi(line.c_str());
	getline(inputStream,line);
		Def = atoi(line.c_str());
	getline(inputStream,line);
		Magic = atoi(line.c_str());
	getline(inputStream,line);
		Luck = atoi(line.c_str());	
	getline(inputStream,line);
		SPoints = atoi(line.c_str());
	getline(inputStream,line);
		Gold = atoi(line.c_str());
	getline(inputStream,line);				//CT,Lvl,Exp,HP,SP,Str,Def,Magic,Luck,SPoints,Gold,Quest,QB,MaxHP,MaxSP,CaveLevel
		Quest = atoi(line.c_str());
	getline(inputStream,line);
		QB = atoi(line.c_str());
	getline(inputStream,line);
		MaxHP = atoi(line.c_str());
	getline(inputStream,line);
		MaxMP = atoi(line.c_str());
	getline(inputStream,line);
		MaxExp = atoi(line.c_str());
	getline(inputStream,line);
		CaveLevel = atoi(line.c_str());
		
	Select();
	if(QB == 1)
	{
		Questing = true;
	}
	else 
	{
		Questing = false;
	}
	
	
	ShowStats();
	
	inputStream.close();
}

void Player::SavePlayer()
{
	cout<<"\n***Saving***\n";
	Select();
	if(Questing == true)
	{
		QB = 1;
	}
	else 
	{
		QB = 0;
	}
	int SA[20]  =  {0,CT,Lvl,Exp,HP,MP,Str,Def,Magic,Luck,SPoints,Gold,Quest,QB,MaxHP,MaxMP,MaxExp,CaveLevel};
	ofstream outfile;
	outfile.open("AutoSave.txt");
	outfile<<Name<<"\n";
	outfile<<SA[1]<<"\n";
	outfile<<SA[2]<<"\n";
	outfile<<SA[3]<<"\n";
	outfile<<SA[4]<<"\n";
	outfile<<SA[5]<<"\n";
	outfile<<SA[6]<<"\n";
	outfile<<SA[7]<<"\n";
	outfile<<SA[8]<<"\n";
	outfile<<SA[9]<<"\n";
	outfile<<SA[10]<<"\n";
	outfile<<SA[11]<<"\n";
	outfile<<SA[12]<<"\n";
	outfile<<SA[13]<<"\n";
	outfile<<SA[14]<<"\n";
	outfile<<SA[15]<<"\n";
	outfile<<SA[16]<<"\n";
	outfile<<SA[17]<<"\n";
	outfile<<SA[18]<<"\n";
	outfile.close();
	cout<<"***Game Saved***\n";
	Select();
}

void Player::ShowStats()
{
	string Class;
	if(CT == 1)
	{
		Class = "Knight";
	}
	else if(CT == 2)
	{
		Class = "Scoundrel";
	}
	else if(CT == 3)
	{
		Class = "Mage";
	}
	int ExpNeeded = MaxExp - Exp;
	string Questring;
	ClearScreen();
	if(Questing == true)
	{
		Questring = "No";
	}
	else 
	{
		Questring = "Yes";
	}
	cout<<" _______________________________\n";
	cout<<"|"<<Name<<"\t\t\t\t|\n";
	cout<<"|"<<Class<<"\t\t\t\t|\n";
	cout<<" _______________________________\n";
	cout<<"|                               |\n";
	cout<<"|Cave Level:\t\t"<<CaveLevel<<"\t|\n";
	cout<<"|Level:\t\t\t"<<Lvl<<"\t|\n";
	cout<<"|Exp:\t\t\t"<<Exp<<"\t|\n";
	cout<<"|Exp Needed:\t\t"<<ExpNeeded<<"\t|\n";
	cout<<"|Health:\t\t"<<HP<<"\t|\n";
	cout<<"|Mana:\t\t\t"<<MP<<"\t|\n";
	cout<<"|Stregnth:\t\t"<<Str<<"\t|\n";
	cout<<"|Defense:\t\t"<<Def<<"\t|\n";
	cout<<"|Magic:\t\t\t"<<Magic<<"\t|\n";
	cout<<"|Luck:\t\t\t"<<Luck<<"\t|\n";
	cout<<"|Skill Points:\t\t"<<SPoints<<"\t|\n";
	cout<<"|Gold:\t\t\t"<<Gold<<"\t|\n";
	cout<<"|Quest Number:\t\t"<<Quest<<"\t|\n";
	cout<<"|Quest Completed:\t"<<Questring<<"\t|\n";
	cout<<"|_______________________________|\n\n";
	Select();
}

void Player::InitSetUp(int CTtemp)
{	 	 	 	 	 
	CT		=	CTtemp;
	Lvl		=	5;
	Exp		=	0;
	SPoints = 	5;
	Gold	=	10;
	Quest	=	0;
	QB 		=	0;
	CaveLevel = 0;
	Questing	=	false;
	Encumbered	=	false;
	if(CT == 1)
	{	//knight	
		Str = 	7;
		Def = 	7;
		Magic =	2;
		Luck =  4;
	}
	else if(CT == 2)
	{	//Scoundrel
		Str =	  5;
		Magic =	  3;
		Def =	  6;
		Luck = 	  6;
	}
	else if(CT == 3)
	{	//Mage
		Str =		2;
		Def	=		4;
		Magic =	  	7;
		Luck =		5;
	}
	MaxExp = 120;
	MaxHP = Str * 2 + Def * 4 + 100;
	MaxMP = Magic * 12;
	HP = MaxHP;
	MP = MaxMP;
}

int Player::LevelUp()
{
	int LevelSelect;
	Lvl++;
	SPoints = SPoints + 5;
	ClearScreen();
	cout <<"You've leveled up!...You have "<<SPoints<<" to spend.Do you wish to spend them now?(Y:1/N:2) ";
	MaxExp = (Lvl*12) + (Exp/8);
	LevelSelect = Select();
	if(LevelSelect == 1)
	{
		LevelScreen();
	}
	else 
	{
		return 0;
	}
}

int Player::LevelScreen()
{
	MaxHP = Str * 2 + Def * 4 + 100;
	MaxMP = Magic * 3 + 100;
	HP = MaxHP;
	MP = MaxMP;
	int PointSelect = 0;
	ClearScreen();	  
	cout<<"You have "<<SPoints<<" Points to spend.\n\n1:Stregnth\t\t"<<Str<<"\n2:Defense\t\t"<<Def<<"\n3:Magic\t\t\t"<<Magic<<"\n4:Luck\t\t\t"<<Luck<<"\n\nHealth\t\t\t"<<MaxHP<<"\nMana\t\t\t"<<MaxMP<<"\n\n5:Return\n\n";
	PointSelect = Select();
	if(PointSelect == 5)
	{
		PointSelect = 0;
		MaxHP = Str * 2 + Def * 4 + 100;
		MaxMP = Magic * 3 + 100;
		HP = MaxHP;
		MP = MaxMP;
		return 0;
	}
	if(SPoints < 1)
	{
		cout<<"\nOut of points.(Cotinue)\n";
		Select();
		LevelScreen();
	}
	if(PointSelect > 0 and PointSelect < 5);
	{
		if(PointSelect == 1 and SPoints > 0)
		{
			Str++;
			SPoints--;
			LevelScreen();
		}
		if(PointSelect == 2 and SPoints > 0)
		{
			Def++;
			SPoints--;
			LevelScreen();
		}
		if(PointSelect == 3 and SPoints > 0)
		{
			Magic++;
			SPoints--;
			LevelScreen();
		}
		if(PointSelect == 4 and SPoints > 0)
		{
			Luck++;
			SPoints--;
			LevelScreen();
		}
	}
	MaxHP = Str * 2 + Def * 4 + 100;
	MaxMP = Magic * 3 + 100;
	HP = MaxHP;
	MP = MaxMP;
	return 0;	  	    
}


