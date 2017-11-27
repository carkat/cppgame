#include <map>
#include <iostream>
#include <vector>
#include "Actions.h"
using namespace std;


Melee::Melee(Entity* me)
{
	owner = me;
	//Swing Primary Weapon
	name = "Melee";
	amount = 10;
}
void Melee::PerformActionOn(Entity* target)
{
	auto gear = owner->GetGear();
	int bonus = 0;
	for (auto g : gear)
		bonus += g->GetHealthModifier();

	target->TakeDamage(owner->GetBaseAttack() + bonus);
}

MagicDamage::MagicDamage(Entity* me, std::string n, int a)
{
	owner = me;
	name = n;
	amount = a;
}
void MagicDamage::PerformActionOn(Entity* target)
{
	target->TakeDamage(owner->GetBaseAttack() + amount);
}


void Menu::DisplayMessage(std::vector<std::string> ss, bool count)
{
	if (count) 
	for (int i = 0; i < ss.size(); i++)
		std::cout << i << ": " << ss[i] << std::endl;
	else
		std::cout << ss[0] << std::endl;
}
int Menu::GetSelection()
{
	int input = 0;
	cin >> input;
	return input;
}
