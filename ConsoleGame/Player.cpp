class Entities;
class Menu;
#include <iostream>
#include "EntityCollections.h"
#include "Player.h"
#include "Actions.h"

Player::Player() 
{
	SetHealth(20);
	SetMaxHealth(200);
	SetBaseAttack(20);
	SetName(CreateName());
	SelectRole();
}
Player::Player(int hp, int atk)
{
	SetHealth(hp);
	SetBaseAttack(atk);
	SetName(CreateName());
}
void Player::SelectRole() 
{
	CharacterRoleFactory factory;
	Menu.DisplayMessage({ "What would you like to be?" });
	Menu.DisplayMessage(factory.Roles, true);
	int input = Menu.GetSelection();
	SetRole(factory.GetRole(input, this));
}
std::string Player::CreateName()
{
	Menu.DisplayMessage({ "What is the name of the illustrious hero?" });
	std::string input;
	std::getline(std::cin, input);
	return input;
}

Entity* Player::AcquireTarget(Entities es)
{
	Menu.DisplayMessage({ "This is where to get user input for target selection" });
	return es.GetEnemy(0);
}

void Player::PerformActions(Entities es)
{
	Menu.DisplayMessage({ "What would you like to do?" });
	Menu.DisplayMessage({ "Attack", "Heal", "View Inventory" }, true);
	int input = Menu.GetSelection();
	if (input == 0)
		this->Attack(es);
	else if (input == 1)
		this->Heal(20);
	else
		this->ViewInventory();
}

void Player::ViewInventory()
{
	Menu.DisplayMessage({ "Equipment", "Items" }, true);
	int input = Menu.GetSelection();
	if (input == 0)
		EquipSelection();
	else
		UseItem();
}
void Player::EquipSelection()
{
	Menu.Show<Equipment*>(PlayerInventory.EquipmentInventory);
	int input = Menu.GetSelection();
	EquipGear(PlayerInventory.EquipmentInventory[input], this);
	std::string afterEquip = GetName() + " now has " + std::to_string(GetBaseAttack()) + " base attack, with the " + PlayerInventory.EquipmentInventory[input]->GetName() + " equipped.";
	Menu.DisplayMessage({ afterEquip });
}

void Player::UseItem()
{
	Menu.Show<Item*>(PlayerInventory.ItemInventory);
	int input = Menu.GetSelection();
}

void Player::Attack(Entities es)
{
	Menu.DisplayMessage({ "Select Combat Action: " }, false);
	Menu.Show<Action*>(GetRole().CombatActions);

	Entity* target = AcquireTarget(es);
	GetRole().CombatActions[Menu.GetSelection()]->PerformActionOn(target);

	Menu.DisplayMessage({ target->GetName() + " how has " + std::to_string(target->GetHealth()) + " hit points." }, false);
}
