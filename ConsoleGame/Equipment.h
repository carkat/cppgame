#pragma once
#include "Entity.h"
#include "HasName.h"
#include <vector>
#include <string>
class Entity;
class HasName;
class EquipmentStats
{
public:
	std::string name;
	int healthModifier;
	int damageModifier;
	int critModifier;
	int armorModifier;
	int speedModifier;
	EquipmentStats() {
		healthModifier = 0;
		damageModifier = 0;
		armorModifier = 0;
		speedModifier = 0;
		critModifier = 0;
	}
	EquipmentStats(int hp, int dmg, int crit, int armor, int speed)
	{
		healthModifier = hp;
		damageModifier = dmg;
		armorModifier = armor;
		speedModifier = speed;
		critModifier = crit;
	}
};
class EquipmentStatsAccessors:private EquipmentStats, HasName
{
public:
	int GetHealthModifier();
	void SetHealthModifier(int);

	int GetDamageModifier();
	void SetDamageModifier(int);

	int GetCritModifier();
	void SetCritModifier(int);
	
	int GetArmorModifier();
	void SetArmorModifier(int);

	int GetSpeedModifier();
	void SetSpeedModifier(int);

	std::string GetName();
	void SetName(std::string);

};

class Equipment : public EquipmentStatsAccessors
{
public:

	Equipment() {};
	Equipment(int level)
	{

	}
	virtual void Equip(Equipment* eq, Entity* ent) = 0;
	virtual void UnEquip(Equipment* eq, Entity* ent) = 0;
};
class MeleeWeapon : public Equipment
{
public:
	MeleeWeapon(std::string name, int attack);
	void Equip(Equipment* eq, Entity* ent)override;
	void UnEquip(Equipment* eq, Entity* ent)override;
};

class Trinket : public Equipment
{
public:
	Trinket(int hp);
	void Equip(Equipment* eq, Entity* ent)override;
	void UnEquip(Equipment* eq, Entity* ent)override;
};
