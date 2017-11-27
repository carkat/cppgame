#include <vector>

#include "EntityCollections.h"
class Entity;
void Entities::PushPlayer(Entity* p)
{
	players.push_back(p);
}

void Entities::PushEnemy(Entity* e)
{
	enemies.push_back(e);
}

std::vector<Entity*> Entities::GetPlayers()
{
	return players;
}

Entity* Entities::GetPlayer(int target)
{
	return players[target];
}

std::vector<Entity*> Entities::GetEnemies()
{
	return enemies;
}

Entity* Entities::GetEnemy(int target)
{
	return enemies[target];
}

bool Entities::PlayersStillAlive() 
{
	for (auto e : players) {
		if (e->IsAlive())
			return true;
	}
	return false;
}

bool Entities::EnemiesStillAlive() 
{
	std::vector<int> toDelete;
	for (int i = 0; i < enemies.size(); i++) 
	{
		Entity* e = this->GetEnemy(i);
		if (e->IsAlive())
			return true;
		else
			toDelete.push_back(i);
	}
	if (toDelete.size() > 0) 
	{
		for (auto i : toDelete) 
		{
			enemies.erase(enemies.begin() + i);
		}
	}
	return false;
}

void Entities::TakeTurn(std::vector<Entity*> es)
{
	Entities es2 = *this;
	for (auto e : es) 
	{
		if (e->IsAlive()) 
		{
			e->PerformActions(es2);
		}
	}
}

void Entities::TakeTurns() 
{
	this->TakeTurn(players);
	this->TakeTurn(enemies);
}