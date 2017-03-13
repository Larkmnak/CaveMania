#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

//void GetItem(int GTID, int GID);
//void LoadItem(int LTID, int LID);
void DropDet(int PL,int ML); //Player Level, Monster Luck
void MakeItem(int LTID, int LID);

class PlayerInv
{

	public:
		int EqItems[6][3];
		int Potions[3][4];
		int Items[15][3];
		
		int CheckEqSpot();
		int CheckInvSpot();
		int CheckPotSpot();
		void ShowInvintory();
		void SaveInvintory();
		void LoadInvintory();
		//int PickUp();
};

class Item
{
	public:
		string Name;
		string Des;
		string Type;
		int TID;	   	   //Type 
		int ID;	      
		int Worth;
		int Weight;
		int ExA;
		int ExB;
		bool Eble;		//Equipable
		bool Eped;		//Equipped
		bool Table;		//Tradable
		bool Quest;
		string GetName();
		string GetDes();
		string GetType();
		int GetWeight();
		int GetWorth();
		void LoadItem();
		
		void Drop();
};

class Consumable: public Item
{
	public:
		int Quant;
		int Amnt;			//Heal amount
		void MakeCons();
};

class Weapon: public  Item
{
	public:
		int Min;
		int Max;
		void MakeWeapon();	  
};

class Shield: public Item
{
	public:
		int BCH;
		int Bamnt;
		void MakeShield();
};

class Armor: public Item
{
	public:
		int Defense;
		void MakeArmor();
};

#endif

