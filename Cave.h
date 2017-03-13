#ifndef CAVE_H
#define CAVE_H

std::string TabCheck(std::string String, int Tick);
void ExitG();
void Intro();
void ClearScreen();
void Shop();
void ShowHome();
void ShowNewGame();
void Load();
void CaveIntro();
void BattleDisplay(std::string PName,std::string MName,int PHP,int MHP,int PExp,int PNExp,int MExp);
int RoundDown(int RDNum);
int Random(int Max);
int Menu();
int NewGame(char NTag[15]);
int Tavern(bool Qing);
int TavernQuest(int TQuest);
int Town();
int Cave(int clvl);
int Select();
int BattleChoose();
bool AreYouSure();

using namespace std;

class Player
{
	public:
		int SaveArray[20];
		char Name[15];
		char SName[15];
		int CT;
		int Lvl;
		int	Exp;
		int HP;
		int MP;
		int Str;
		int Def;
		int Magic;
		int Luck;
		int SPoints;
		int Gold;
		int Quest;
		int QB;
		int MaxHP;
		int MaxMP;
		int MaxExp;
		int CaveLevel;
		bool Questing;
		bool Encumbered;
	
		string SetName();
		
		void ShowStats();
		void LoadPlayer();	    
		void SavePlayer();	  	  
		void InitSetUp(int CTtemp);
		int LevelUp();	  	  
		int LevelScreen();
};

class Spell
{
	string Name;
	string Type;
	string Des;
	string Stat;
	char Target;
	int Cost;
	int Amnt;
	int Turn;
};

#endif

