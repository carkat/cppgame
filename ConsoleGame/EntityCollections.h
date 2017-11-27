#pragma once
#include "Entity.h"
#include <vector>

class Entity;

using namespace std;

class Entities
{
	std::vector<Entity*> players;
	std::vector<Entity*> enemies;
	void TakeTurn(vector<Entity*>);
public:
	void PushPlayer(Entity*);
	void PushEnemy(Entity*);

	virtual std::vector<Entity*> GetPlayers();
	virtual Entity* GetPlayer(int);

	virtual std::vector<Entity*> GetEnemies();
	virtual Entity* GetEnemy(int);

	bool PlayersStillAlive();
	bool EnemiesStillAlive();
	void TakeTurns(); 
};


