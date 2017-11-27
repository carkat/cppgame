#pragma once
#include "Entity.h"
#include "HasName.h"
#include <string>
class Item : HasName
{
	std::string name;
public:
	Item() {};
	int weight;
	std::string GetName()
	{
		return name;
	};
	void SetName(std::string n)
	{
		name = n;
	};
	virtual void Use(Entity* e) = 0;
};
class Consumable : public Item
{
public:
	int stats;
	int count;
};
class Potion : public Consumable 
{
public:
	Potion(int, int);
	void Use(Entity* e);
};
