#include "EntityCollections.h"
#include "Entity.h"

Entity::Entity() { }
Entity::Entity(int hp, int atk, std::string n)
{
	SetHealth(hp);
	SetMaxHealth(200);
	SetBaseAttack(atk);
	SetName(n);
}

bool Entity::IsAlive() 
{
	return GetHealth() > 0;
}

string Entity::CreateName(std::string n)
{
	SetName(n);
	return n;
}

Entity* Entity::AcquireTarget(Entities es)
{
	return es.GetPlayer(0);
}

void Entity::DealDamageTo(Entity* target)
{
	target->TakeDamage(GetBaseAttack());
}

void Entity::PerformActions(Entities es) 
{
	this->Attack(es);
}

void Entity::Attack(Entities es)
{
	Entity* target = AcquireTarget(es);
	this->DealDamageTo(target);
	std::cout << target->GetName() << " now has " << target->GetHealth() << std::endl;
}
