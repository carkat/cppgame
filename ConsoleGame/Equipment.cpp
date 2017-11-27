#include "Entity.h"
#include "Equipment.h"

MeleeWeapon::MeleeWeapon(std::string n, int attack) { 
	SetName(n);
	SetDamageModifier(attack); 
}
void MeleeWeapon::Equip(Equipment* eq, Entity* ent)
{
	ent->IncreaseBaseAttack(GetDamageModifier());
}
void MeleeWeapon::UnEquip(Equipment* eq, Entity* ent)
{
	ent->DecreaseBaseAttack(GetDamageModifier());
}

Trinket::Trinket(int hp) { 
	SetName("Golden Ring");
	SetHealthModifier(hp);
}
void Trinket::Equip(Equipment* eq, Entity* ent)
{
	ent->IncreaseMaxHealth(GetHealthModifier());
}
void Trinket::UnEquip(Equipment* eq, Entity* ent)
{
	ent->DecreaseMaxHealth(GetHealthModifier());
}
