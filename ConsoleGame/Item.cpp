#include "Item.h"
Potion::Potion(int weight, int stats)
{
	SetName("Potion");
	this->stats = stats;
	this->weight = weight;
}
void Potion::Use(Entity* e)
{
	e->Heal(stats);
}
