#ifndef MONSTERS_H
#define MONSTERS_H


int MonsterSearch(int PL);
void MonsterDet(int CL, int MS);

class Monster
{
	public:
		int Lvl;
		int	Exp;
		int Gold;
		int Str;
		int Def;
		int Magic;
		int Luck;
		int HP;
		int SP;
		int MaxHP;
		int MaxSP;
		int MAray[10];
		std::string Name;
		void HMSetUp();
		void Store();
		void Load();
		int Drop(int PLuck);
};
	
	class Animal: public Monster
	{
		public:
			//Bite();
	};
	class Imp: public Monster
	{
		public:
			//int Attack();
	};
		
		class Rat: public Animal
		{
			public:
				void SetupRat();
				//int Squeak();
		};
		class Bat: public Animal
		{
			public:
				void SetupBat();
				//int Vamp();
		};
		class Wolf: public Animal
		{
			public:
				void SetupWolf();
				//int Howl();
		};
		class Underling: public Imp
		{
			public:
				void SetupUnderling();
				//int Spark();
		};

#endif

