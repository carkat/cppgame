#pragma once
#include "Item.h"
#include "Equipment.h"
#include <vector>
class Equipment;
class Item;

class Inventory
{
public:
	Inventory();
	std::vector<Item*> ItemInventory;
	std::vector<Equipment*> EquipmentInventory;

};