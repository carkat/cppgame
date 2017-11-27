#include "Inventory.h"
Inventory::Inventory() 
{
	ItemInventory.push_back(new Potion(1, 200));
	EquipmentInventory.push_back(new MeleeWeapon{ "Giant Sword", 50 });
	EquipmentInventory.push_back(new MeleeWeapon{ "Smaller Sword", 20 });
}
