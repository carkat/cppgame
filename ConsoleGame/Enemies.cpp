#include "Entity.h"

class Dragon : public Enemy
{
public:
	Dragon() 
	{
		SetHealth(300);
		SetMaxHealth(2000);
		SetBaseAttack(5);
		SetLevel(10);
		SetName("Dragon");
	}
};

class Goblin : public Enemy
{
public:
	Goblin() 
	{
		SetHealth(20);
		SetMaxHealth(20);
		SetBaseAttack(5);
		SetLevel(1);
		SetName("Goblin");
	}
};

class MountainLion : public Enemy
{
public:
	MountainLion() 
	{
		SetHealth(20);
		SetMaxHealth(200);
		SetBaseAttack(10);
		SetLevel(5);
		SetName("Mountain Lion");
	}
};