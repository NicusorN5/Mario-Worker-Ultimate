#include "Game.hpp"

namespace Game
{
	unsigned CurrentGameSection = 0;
	Player MainPlayer = Player(0, 0);
	Level CurrentLevel(nullptr);

	bool GameRunning = true;

};