#pragma once
#include <map>
#include <vector>
#include "Entity.h"
#include "EntityCollections.h"
#include "Equipment.h"
#include "HasName.h"
using namespace std;
class Entity;
class Equipment;
class Action : HasName
{
public:
	std::string name;
	Action() {};
	std::string GetName()
	{
		return name;
	}
	int amount;
	Entity* owner;
	virtual void PerformActionOn(Entity*) {};
};

class Menu : public Action 
{
public:
	void Equip(Equipment* eq, Entity* ent);
	void UnEquip(Equipment* eq, Entity* ent);
	void DisplayMessage(std::vector<std::string>, bool cond = false);
	int GetSelection();
	template <typename T>
	void Show(std::vector<T> menuItems) 
	{
		std::vector<std::string> names;
		for (auto i : menuItems)
			names.push_back(i->GetName());

		DisplayMessage(names, true);
	}
};

class MagicHeal : public Action
{
public:
	MagicHeal(Entity*, std::string, int);
	void PerformActionOn(Entity*);
};
class MagicDamage : public Action
{
public:
	MagicDamage(Entity*, std::string, int);
	void PerformActionOn(Entity*);
};
class Melee : public Action 
{
public:
	Melee(Entity*);
	void PerformActionOn(Entity*);
};

class Status
{
public:
	std::string name;
	std::string effect;
	virtual void Effect();

};
class Burn : Status {};
class Sleep : Status {};


