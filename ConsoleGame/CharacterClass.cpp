#include <vector>
#include "Entity.h"
#include "CharacterRoles.h"
void Warrior::Init(Entity* me)
{
	CombatActions.push_back(new Melee(me));
}

void Mage::Init(Entity* me)
{
	CombatActions.push_back(new MagicDamage(me, "Fireball", 40));
}
