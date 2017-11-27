#pragma once
#include <vector>
#include "Entity.h"
#include "Actions.h"

class Action;

class CharacterRole
{
public:
	CharacterRole() {}
	std::vector<Action*> CombatActions;
	std::vector<Action*> SpecialActions;
	virtual void Init(Entity*) {};
};
class Warrior : public CharacterRole
{
public:
	void Init(Entity*);
};
class Mage : public CharacterRole
{
public:
	void Init(Entity*);
};
class Ranger : public CharacterRole
{
public:
	void Init(Entity*);
};
