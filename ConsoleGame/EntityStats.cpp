#include <string>
#include "Entity.h"

int add(int a, int b)
{
	return a + b;
}
std::string EntityStatAccessors::GetName()
{
	return name;

}
void EntityStatAccessors::SetName(std::string n)
{
	name = n;
}

int EntityStatAccessors::GetHealth()
{
	return health;
}
void EntityStatAccessors::SetHealth(int n)
{
	health = n;
}
void EntityStatAccessors::Heal(int n)
{
	int increaseHealth = GetHealth() + n;
	if (increaseHealth > GetMaxHealth())
		SetHealth(GetMaxHealth());
	else
		SetHealth(increaseHealth);
}
void EntityStatAccessors::TakeDamage(int n)
{
	int reducedHealth = GetHealth() - n;
	if (reducedHealth < 0)
		SetHealth(0);
	else
		SetHealth(reducedHealth);
}

int EntityStatAccessors::GetMaxHealth()
{
	return maxHealth;
}
void EntityStatAccessors::SetMaxHealth(int n)
{
	maxHealth = n;
}
void EntityStatAccessors::IncreaseMaxHealth(int n)
{
	SetMaxHealth(GetMaxHealth() + n);
}
void EntityStatAccessors::DecreaseMaxHealth(int n)
{
	SetMaxHealth(GetMaxHealth() - n);
}

int EntityStatAccessors::GetArmor()
{
	return armor;
}
void EntityStatAccessors::SetArmor(int n)
{
	armor = n;
}
void EntityStatAccessors::IncreaseArmor(int n)
{
	SetArmor(GetArmor() + n);
}
void EntityStatAccessors::DecreaseArmor(int n)
{
	SetArmor(GetArmor() - n);
}

int EntityStatAccessors::GetBaseAttack()
{
	return baseAttack;
}
void EntityStatAccessors::SetBaseAttack(int n)
{
	baseAttack = n;
}
void EntityStatAccessors::IncreaseBaseAttack(int n)
{
	baseAttack += n;
}
void EntityStatAccessors::DecreaseBaseAttack(int n)
{
	baseAttack -= n;
}

int EntityStatAccessors::GetSpeed()
{
	return speed;
}
void EntityStatAccessors::SetSpeed(int n)
{
	speed = n;
}
void EntityStatAccessors::IncreaseSpeed(int n)
{
	speed += n;
}
void EntityStatAccessors::DecreaseSpeed(int n)
{
	speed -= n;
}

int EntityStatAccessors::GetCritChance()
{
	return critChance;
}
void EntityStatAccessors::SetCritChance(int n)
{
	critChance = n;
}
void EntityStatAccessors::IncreaseCritChance(int n)
{
	critChance += n;
}
void EntityStatAccessors::DecreaseCritChance(int n)
{
	critChance -= n;
}

int EntityStatAccessors::GetLevel()
{
	return level;
}
void EntityStatAccessors::SetLevel(int n)
{
	level = n;
}
void EntityStatAccessors::LevelUp()
{
	level += 1;
}

void EntityStatAccessors::AddStatus(string s)
{
	status.push_back(s);
}
void EntityStatAccessors::RemoveStatus(string s)
{
	status.pop_back();
}

CharacterRole EntityStatAccessors::GetRole()
{
	return Role;
}
void EntityStatAccessors::SetRole(CharacterRole* R)
{
	this->Role = *R;
}

void EntityStatAccessors::EquipGear(Equipment* eq, Entity* me)
{
	eq->Equip(eq, me);
	Gear.push_back(eq);
}
void EntityStatAccessors::UnequipGear(Equipment* eq, Entity* me)
{
	Gear.pop_back();
	eq->UnEquip(eq, me);
}
std::vector<Equipment*> EntityStatAccessors::GetGear()
{
	return Gear;

}