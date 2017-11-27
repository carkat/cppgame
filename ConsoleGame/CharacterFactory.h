#pragma once
#include "Factory.h"
#include "CharacterRoles.h"
class CharacterRoleFactory : Factory<CharacterRole>
{
	void RegisterCharacterRoles()
	{
		registerChildrenTypes<Warrior>(0);
		registerChildrenTypes<Mage>(1);
	}
public:
	
	std::vector<std::string> Roles {
		"Warrior",
		"Mage"
	};
	CharacterRoleFactory()
	{
		RegisterCharacterRoles();
	}
	CharacterRole* GetRole(int i, Entity* me)
	{
		CharacterRole* cr = create(i);
		cr->Init(me);
		return cr;
	}
};

