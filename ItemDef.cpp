#include <iostream>
#include <string>
#include <fstream>
#include "Items.h"
#include "Cave.h"

using namespace std;

int PlayerInv::CheckEqSpot()
{
	int Spot = 1;
	while(EqItems[Spot][1] != 0)
	{
		Spot ++;
	}
	if(EqItems[Spot][1] == 0)
	{
		Spot = Spot - 1;
	}
	return Spot;
}

int PlayerInv::CheckInvSpot()
{
	int Spot = 1;
	while(Items[Spot][1] != 0)
	{
		Spot ++;
	}
	if(Items[Spot][1] == 0)
	{
		Spot = Spot - 1;
	} 
	return Spot;
}

int PlayerInv::CheckPotSpot()
{
	int Spot = 1;
	if(Potions[Spot][1] != 0)
	{
		Spot ++;
	}
	else if(Potions[Spot][1] == 0)
	{
		Spot = Spot - 1;
	} 
}

void PlayerInv::ShowInvintory()
{
	ClearScreen();
	int InvSpt = 1;
	int EqSpt = 1;
	int PotSpt = 1;
	int ConstSpt;
	int InvSptConst  = CheckInvSpot();
	int EqSptConst	 = CheckEqSpot();
	int PotSptConst	 = CheckPotSpot();
	cout <<InvSptConst<<" Items in invintory.\n";
	cout <<EqSptConst<<" Equipped Items.\n";
	
	Select();
	ClearScreen();
	cout <<" _______________________________________________________\n";
	cout <<"|Invintory\t\t\t\t\t\t|\n";
	cout <<"|-------------------------------------------------------|\n";
	cout <<"|Equiped Items\t\t\t\t\t\t|\n";
	cout <<"|-------------------------------------------------------|\n";
	cout <<"|Name\t\t\t\tType\t\tWorth\t|\n";
	if(EqSptConst != 0)
	{
		while(EqSpt <= EqSptConst)
		{
			Item EqItem;
			MakeItem(EqItems[EqSpt][1],EqItems[EqSpt][2]);
			EqItem.LoadItem();
			string NTab = TabCheck(EqItem.Name, 4);
			cout <<"|"<<EqSpt<<": "<<EqItem.Name<<NTab<<"\t"<<EqItem.Type<<"\t\t"<<EqItem.Worth<<"\t|\n";
			EqSpt++;
		}
	}
	else 
	{
		cout <<"|You have no items here.\t\t\t\t\n";
	}
	cout <<"|-------------------------------------------------------|\n";
	cout <<"|Potions\t\t\t\t\t\t|\n";
	cout <<"|-------------------------------------------------------|\n";
	cout <<"|Name\t\t\t\tQuant\t\tWorth\t|\n";
	if(PotSptConst != 0)
	{
		while(PotSpt <= PotSptConst)
		{
			Consumable Item;
			MakeItem(Potions[PotSpt][1],Potions[PotSpt][2]);
			Item.LoadItem();
			Item.Quant = Potions[PotSpt][3];
			ConstSpt = PotSpt + EqSptConst;
			string NTab = TabCheck(Item.Name, 4);
			cout <<"|"<<ConstSpt<<": "<<Item.Name<<NTab<<"\t"<<Item.Quant<<"\t\t"<<Item.Worth<<"\t|\n";
			PotSpt++;
		}
	}
	else 
	{
		cout <<"|You have no items here.\t\t\t|\n";
	}
	cout <<"|-------------------------------------------------------|\n";
	cout <<"|BackPack\t\t\t\t\t\t|\n";
	cout <<"|-------------------------------------------------------|\n";
	cout <<"|Name\t\t\t\tType\t\tWorth\t|\n";
	if(InvSptConst != 0)
	{
		while(InvSpt <= InvSptConst)
		{
			Item Item;
			MakeItem(Items[InvSpt][1],Items[InvSpt][2]);
			Item.LoadItem();
			ConstSpt = InvSpt + EqSptConst + PotSptConst;
			string NTab = TabCheck(Item.Name, 4);
			cout <<"|"<<ConstSpt<<": "<<Item.Name<<NTab<<"\t"<<Item.Type<<"\t\t"<<Item.Worth<<"\t|\n";
			InvSpt++;
		}
	}
	else 
	{
		cout <<"|You have no items here.\t\t\t\t|\n";
	}
	cout <<"|_______________________________________________________|\n";
	Select();
}

void PlayerInv::SaveInvintory()
{
	int EI = 1;
	int P = 1;
	int I = 1;
	int NoEI = CheckEqSpot();
	int NoP = CheckPotSpot();
	int NoI = CheckInvSpot();
	ofstream outfile;
	outfile.open("Invintory.txt");
	outfile<<NoEI<<"\n";
	outfile<<NoP<<"\n";
	outfile<<NoI<<"\n";
	cout <<NoEI<<"Items Equiped.\n";
	cout <<NoP<<"Potions.\n";
	cout <<NoI<<"Invintory Items.\n";
	Select();
	ClearScreen();
	cout <<"Equiped Items.\n";
	while(EI <= NoEI)
	{
		outfile<<EqItems[EI][1]<<"\n";
		outfile<<EqItems[EI][2]<<"\n";
		cout<<"Item:\t"<<EqItems[EI][1]<<","<<EqItems[EI][2]<<"\n";
		EI++;
	}
	Select();
	ClearScreen();
	cout <<"Potions.\n";
	while(P <= NoP)
	{
		outfile<<Potions[P][1]<<"\n";
		outfile<<Potions[P][2]<<"\n";
		outfile<<Potions[P][3]<<"\n";	 	 
		cout<<"Item:\t"<<Potions[P][1]<<","<<Potions[P][2]<<","<<Potions[P][3]<<"\n";
		P++;
	}
	Select();
	ClearScreen();
	cout <<"Invintory Items.\n";
	while(I <= NoI)
	{
		outfile<<Items[I][1]<<"\n";
		outfile<<Items[I][2]<<"\n";
		cout<<"Item:\t"<<Items[I][1]<<","<<Items[I][2]<<"\n";
		I++;
	}
	Select();
	ClearScreen();
	outfile.close();
}

void PlayerInv::LoadInvintory()
{
	int EI = 1;
	int P = 1;
	int I = 1;
	int NoEI;
	int NoP;
	int NoI;	
	string line;
	ifstream inputStream;
    inputStream.open("Invintory.txt");
	if(!inputStream)
	{
		ClearScreen();
		cout<<"Fatal Error: No file to load";
		Select();
	}	 
	getline(inputStream,line);
		NoEI = atoi(line.c_str());
	getline(inputStream,line);
		NoP = atoi(line.c_str());
	getline(inputStream,line);
		NoI = atoi(line.c_str());
	cout <<"Equipped\t"<<NoEI<<"\n";
	cout <<"Potions\t"<<NoP<<"\n";
	cout <<"Invintory\t"<<NoI<<"\n";
	Select();
	cout <<"Equiped:\n";
	while(EI <= NoEI)
	{
		getline(inputStream,line);
			EqItems[EI][1] = atoi(line.c_str());
		getline(inputStream,line);
			EqItems[EI][2] = atoi(line.c_str());
		cout <<EqItems[EI][1]<<EqItems[EI][2]<<"\n";
		EI++;
	}
	Select();
	cout <<"Potions";
	while(P <= NoP)
	{
		getline(inputStream,line);
			Potions[P][1] = atoi(line.c_str());
		getline(inputStream,line);
			Potions[P][2] = atoi(line.c_str());
		getline(inputStream,line);
			Potions[P][3] = atoi(line.c_str());
		cout <<Potions[P][1]<<Potions[P][2]<<Potions[P][3]<<"\n";
		P++;
	}
	Select();
	cout <<"Invintory:\n";
	while(I <= NoI)
	{
		getline(inputStream,line);
			Items[I][1] = atoi(line.c_str());
		getline(inputStream,line);
			Items[I][2] = atoi(line.c_str());
		cout <<Items[I][1]<<Items[I][2]<<"\n";
			I++;
	}
	inputStream.close();
}
void Item::LoadItem()
{
	string line;
	ifstream inputStream;
    inputStream.open("Items.txt");
	if(!inputStream)
	{
		ClearScreen();
		cout<<"Fatal Error: No file to load";
		Select();
	}
	
	getline(inputStream,line);
		Name = line.c_str();
	getline(inputStream,line);
		Des = line.c_str();
	getline(inputStream,line);
		Type = line.c_str();
	getline(inputStream,line);
		TID = atoi(line.c_str());
	getline(inputStream,line);
		ID = atoi(line.c_str());
	getline(inputStream,line);
		Worth = atoi(line.c_str());
	getline(inputStream,line);
		Weight = atoi(line.c_str());
	getline(inputStream,line);
		Eble = atoi(line.c_str());
	getline(inputStream,line);
		Eped = atoi(line.c_str());
	getline(inputStream,line);
		Table = atoi(line.c_str());
	getline(inputStream,line);
		Quest = atoi(line.c_str());
	if(TID == 2 or TID == 5)
	{
		getline(inputStream,line);
			ExA = atoi(line.c_str());
	}
	else if(TID == 3 or TID == 4)
	{
		getline(inputStream,line);
			ExA = atoi(line.c_str());
		getline(inputStream,line);
			ExB = atoi(line.c_str());
	}
	inputStream.close();
}

void MakeItem(int LTID, int LID)
{
	Item LoadItem;
	if(LTID == 1)
	{
		if(LID == 1)
		{
			LoadItem.Name	=	 "Wolf Skull";
			LoadItem.Des	=	 "Proof I have done my job; the old man will be wanting this";
			LoadItem.Type	=	 "Trophy";
			LoadItem.Eble	=	 false;
			LoadItem.Eped	=	 false;
			LoadItem.Table	=	 false;
			LoadItem.Quest	=	 true;
			LoadItem.Worth 	=   0;
			LoadItem.Weight =	5;
		}
	}
	else if(LTID == 2)
	{
		if(LID == 1)
		{
			LoadItem.Name	 =	 "Small Health Potion";
			LoadItem.Des	 =	  "This will heal 50";
			LoadItem.Type	 =	 "Potion";
			LoadItem.Eble	 =	 false;
			LoadItem.Eped	 =	 false;
			LoadItem.Table	 =	 true;
			LoadItem.Quest	 =   false;
			LoadItem.Worth	 =	 5 ;
			LoadItem.ExA	 =	 50;
			LoadItem.ExB	 =	 0;
		}
		else if(LID == 2)
		{
			LoadItem.Name	 =	 "Small Mana Potion";
			LoadItem.Des	=	   "This will heal 50";
			LoadItem.Type	 =	  "Potion";
			LoadItem.Table	 =	  true;
			LoadItem.Worth	 =	  5;
			LoadItem.ExA	=	 50;
		}
	}
	else if(LTID == 3)
	{
		if(LID == 1)
		{
			LoadItem.Name	  =	  "Short Sword";
			LoadItem.Des	  =	  "My father's blade.";
			LoadItem.Type	  =	  "Sword";
			LoadItem.Eble	  =	  true;
			LoadItem.Table	  =	  true;
			LoadItem.Worth	  =	  10;
			LoadItem.Weight	  =	  10;
			LoadItem.ExA	  =	  1;
			LoadItem.ExB	  =	  4;
		}
	}
	else if(LTID == 4)
	{
		if(LID == 1)
		{

			LoadItem.Name	   =	"Makeshift Shield";
			LoadItem.Des	   =	"A shield I fashoned from our stool.";
			LoadItem.Type	   =	"Shield";
			LoadItem.Eble	   =	true;
			LoadItem.Table	   =	true;
			LoadItem.Worth	   =	10;
			LoadItem.Weight	   =	10;
			LoadItem.ExA	   =	10;
			LoadItem.ExB	 =	  10;
		}
	}
	else if(LTID == 5)
	{
		if(LID == 1)
		{
			LoadItem.Name	  =	  "Farmers Clothes";
			LoadItem.Des	  =	  "Tattered and blood-stained, fashon was my last concern that day";
			LoadItem.Type	  =	  "Armor";
			LoadItem.Eble	  =	  true;
			LoadItem.Table	  =	  true;
			LoadItem.Worth	  =	  3;
			LoadItem.Weight	  =	  5;
			LoadItem.ExA	=	  5;
		}
	}
	LoadItem.TID	=	LTID;
	LoadItem.ID	   =	LID;
	LoadItem.Drop();
}

void DropDet(int PL,int ML)
{
	int R = Random(100) + RoundDown(PL) + 5;
	int x;
	int y;
	if(ML < 15)
	{
		if(R < 50)		//SHP
		{
			x = 2;
			y = 1;
		}
		else 			// SMP	   
		{
			x = 2;
			y = 2;
		}
	}
	MakeItem(x,y);
}

string Item::GetName()
{
	return Name;
}

string Item::GetDes()
{
	return Des;
}

string Item::GetType()
{
	return Type;
}

int Item::GetWeight()
{
	return Weight;
}

int Item::GetWorth()
{
	return Worth;
}

void Item::Drop()
{
	ofstream outfile;
	outfile.open("Items.txt");
	outfile<<Name<<"\n";
	outfile<<Des<<"\n";
	outfile<<Type<<"\n";
	outfile<<TID<<"\n";
	outfile<<ID<<"\n";
	outfile<<Worth<<"\n";
	outfile<<Weight<<"\n";
	outfile<<Eble<<"\n";
	outfile<<Eped<<"\n";
	outfile<<Table<<"\n";
	outfile<<Quest<<"\n";
	outfile<<ExA<<"\n";
	outfile<<ExB<<"\n";
	outfile.close();	
}

void Consumable::MakeCons()
{
	Quant = ExA;
	Amnt = ExB;
}

void Weapon::MakeWeapon()
{
	Min = ExA;
	Max = ExB;
}

void Shield::MakeShield()
{
	BCH = ExA;
	Bamnt = ExB;
}

void Armor::MakeArmor()
{
	Defense = ExA;
}

