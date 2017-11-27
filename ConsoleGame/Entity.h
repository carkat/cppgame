#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "EntityCollections.h"
#include "CharacterRoles.h"
#include "CharacterFactory.h"
#include "Equipment.h"

class Entities;
class Equipment;
class EntityStats
{
public:
	std::string name;
	int health;
	int maxHealth;
	int armor;
	int baseAttack;
	int critChance;
	int speed;
	int level;
	std::vector<std::string> status;
	CharacterRole Role;
	std::vector<Equipment*> Gear;
};
class EntityStatAccessors: private EntityStats
{
public:
	std::string GetName();
	void SetName(std::string);

	int GetHealth();
	void SetHealth(int);
	void Heal(int);
	void TakeDamage(int);

	int GetMaxHealth();
	void SetMaxHealth(int);
	void IncreaseMaxHealth(int);
	void DecreaseMaxHealth(int);

	int GetArmor();
	void SetArmor(int);
	void IncreaseArmor(int);
	void DecreaseArmor(int);

	int GetBaseAttack();
	void SetBaseAttack(int);
	void IncreaseBaseAttack(int);
	void DecreaseBaseAttack(int);

	int GetSpeed();
	void SetSpeed(int);
	void IncreaseSpeed(int);
	void DecreaseSpeed(int);

	int GetCritChance();
	void SetCritChance(int);
	void IncreaseCritChance(int);
	void DecreaseCritChance(int);

	int GetLevel();
	void SetLevel(int);
	void LevelUp();

	CharacterRole GetRole();
	void SetRole(CharacterRole*);

	void AddStatus(std::string);
	void RemoveStatus(std::string);

	void EquipGear(Equipment*, Entity*);
	void UnequipGear(Equipment*, Entity*);
	std::vector<Equipment*> GetGear();
};

class Entity : public EntityStatAccessors
{
public:
	Entity();
	Entity(int, int, std::string);

	virtual std::string CreateName(std::string);
	virtual Entity* AcquireTarget(Entities);
	virtual void PerformActions(Entities);
	virtual void DealDamageTo(Entity*);
	virtual void Attack(Entities);
	bool IsAlive();
};

class Enemy : public Entity
{
	Entity::Entity;
};


