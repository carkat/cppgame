#include "Equipment.h"
#include <string>

int EquipmentStatsAccessors::GetHealthModifier()
{
	return healthModifier;
}
void EquipmentStatsAccessors::SetHealthModifier(int n)
{
	healthModifier = n;
}

int EquipmentStatsAccessors::GetDamageModifier()
{
	return damageModifier;
}
void EquipmentStatsAccessors::SetDamageModifier(int n)
{
	damageModifier = n;
}

int EquipmentStatsAccessors::GetCritModifier()
{
	return critModifier;
}
void EquipmentStatsAccessors::SetCritModifier(int n)
{
	critModifier = n;
}

int EquipmentStatsAccessors::GetArmorModifier()
{
	return armorModifier;
}
void EquipmentStatsAccessors::SetArmorModifier(int n)
{
	armorModifier = n;
}

int EquipmentStatsAccessors::GetSpeedModifier()
{
	return speedModifier;
}
void EquipmentStatsAccessors::SetSpeedModifier(int n)
{
	speedModifier = n;
}

std::string EquipmentStatsAccessors::GetName()
{
	return name;
}
void EquipmentStatsAccessors::SetName(std::string n)
{
	name = n;
}

