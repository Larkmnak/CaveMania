#include <iostream>
#include <fstream>
#include "Monsters.h"
#include "Cave.h"

using namespace std;

int MonsterSearch(int PL)
{
	int Monst;
	Monst = Random(100) + (PL - 5) * 10;
	if(Monst <= 50)
	{
		return 1;
	}
	else if(Monst <= 80 & Monst > 50)
	{
		return 2;
	}
	else if(Monst <= 95 & Monst > 80)
	{
		return 3;
	}
	else 
	{
		return 4;
	}
}

void MonsterDet(int CL, int MS)
{
	if(CL == 1)
	{
		if(MS == 1)
		{
			Rat Rat;
			Rat.SetupRat();
			Rat.Store();
		}
		if(MS == 2)
		{
			Bat Bat;
			Bat.SetupBat();
			Bat.Store();
			}
		if(MS == 3)
		{
			Wolf Wolf;
			Wolf.SetupWolf();
			Wolf.Store();
		}
		if(MS == 4)
		{
			Underling Underling;
			Underling.SetupUnderling();
			Underling.Store();
		}
	}
}

void Monster:: HMSetUp()
{
	MaxHP = Str * 2 + Def * 4 + 100;
	MaxSP = Magic * 3 + 100;
	HP = MaxHP;
	SP = MaxSP;
	Exp = Lvl * 2;
}

void Monster::Store()
{
	ofstream outfile;
	outfile.open("Monsters.txt");
	outfile<<Name<<"\n";
	outfile<<Lvl<<"\n";
	outfile<<Gold<<"\n";
	outfile<<Str<<"\n";
	outfile<<Def<<"\n";
	outfile<<Magic<<"\n";
	outfile<<Luck<<"\n";
	outfile.close();
}

void Monster::Load()
{
	string line;
	ifstream inputStream;
    inputStream.open("Monsters.txt");
	if(!inputStream)
	{
		ClearScreen();
		cout<<"Fatal Error: No file to load";
		Select();
	}
	
	getline(inputStream,line);
		Name = line.c_str();
	getline(inputStream,line);
		Lvl = atoi(line.c_str());
	getline(inputStream,line);
		Gold = atoi(line.c_str());
	getline(inputStream,line);
		Str = atoi(line.c_str());
	getline(inputStream,line);
		Def = atoi(line.c_str());
	getline(inputStream,line);
		Magic = atoi(line.c_str());
	getline(inputStream,line);
		Luck = atoi(line.c_str());
	inputStream.close();
}

int Monster::Drop(int PLuck)
{
	int R = Random(100) + RoundDown(PLuck/10);
	if(R > 20)
	{	   	   	   	   	   	   	   //Change back to > 60
		return 1;
	}
	else 
	{
		return 0;
	}
}

void Rat::SetupRat()
{
	Name	=	"Rat";
	Lvl 	= 	4;
	Gold 	= 	Random(Lvl);
	Str		= 	4;
	Def		=	4;
	Magic	=	2;
	Luck	=	5;
}

void Bat::SetupBat()
{
	Name	=	"Bat";
	Lvl		=	5;
	Gold	=	Random(Lvl);
	Str		=	8;
	Def		=	4;
	Magic	=	6;
	Luck	=	7;
}

void Wolf::SetupWolf()
{
	Name	=	"Wolf";
	Lvl		=	6;
	Gold	=	Random(Lvl);
	Str		=	12;
	Def		=	10;
	Magic	=	3;
	Luck	=	10;
}

void Underling::SetupUnderling()
{
	Name	=	"Imp Underling";
	Lvl		=	7;
	Gold	=	Random(Lvl);
	Str		=	12;
	Def		=	10;
	Magic	=	10;
	Luck	=	8;
}

