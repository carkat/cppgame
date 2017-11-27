#pragma once
#include "Factory.h"
#include "Entity.h"
#include "Enemies.cpp"
#include "Player.h"
class EntityFactory : Factory<Entity>
{
	void Register()
	{
		registerChildrenTypes<Player>(PlayerType);
		registerChildrenTypes<Dragon>(DragonType);
		registerChildrenTypes<Goblin>(GoblinType);
		registerChildrenTypes<MountainLion>(MountainLionType);
	}
public:
	enum EntityTypes
	{
		PlayerType, DragonType, GoblinType, MountainLionType
	};
	EntityFactory()
	{
		Register();
	};
	Entity* GetEntity(int i)
	{
		return create(i);
	}
};
