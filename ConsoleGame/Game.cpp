#include <iostream>
#include "EntityCollections.h"
#include "EntityFactory.h"
#include "Inventory.h"

//TODO make singleton

class Game {
	Entities es;
	EntityFactory factory;
public:
	Game()
	{
		es.PushPlayer(factory.GetEntity(factory.PlayerType));
		es.PushEnemy(factory.GetEntity(factory.GoblinType));
	}

	std::string GetInput() 
	{
		std::string input;
		std::cin.ignore();
		std::getline(std::cin, input);
		return input;
	}
	bool Continue(std::string winOrLose) 
	{
		std::cout << "YOU" <<  winOrLose << "!!!" << std::endl;
		std::cout << "Would you like fight another enemy? Y/N" << std::endl;
		std::string input = GetInput();
		if (input == "Y")
		{
			es.PushEnemy(factory.GetEntity(factory.DragonType));
			return true;
		}
		return false;

	}

	void Loop() 
	{
		bool playing = true;
		while (es.PlayersStillAlive() && playing) 
		{
			es.TakeTurns();
			if (!es.EnemiesStillAlive())
				playing = Continue("WIN");
		};
		if (Continue(" Can't quit now"))
			Loop();
	}
};
