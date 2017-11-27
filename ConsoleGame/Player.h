#pragma once

#include "Entity.h"
#include "Inventory.h"
class Inventory;
class Player : public Entity
{
	Menu Menu;
public:
	Inventory PlayerInventory;
	Player();
	Player(int, int);
	Entity* AcquireTarget(Entities) override;
	void PerformActions(Entities) override;
	void Attack(Entities) override;
	std::string CreateName();
	void EquipSelection();
	void ViewInventory();
	void SelectRole();
	void UseItem();
};
