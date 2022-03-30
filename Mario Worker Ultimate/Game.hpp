#pragma once
#include "Player.hpp"
#include "Level.hpp"

namespace Game
{
	extern unsigned CurrentGameSection;
	extern Player MainPlayer;
	namespace Resolution
	{
		extern unsigned X;
		extern unsigned Y;

		Vector2 Vec();
		float FltX();
		float FltY();
	}
	extern Level CurrentLevel;

	Rectangle ScreenRec(Rectangle norm);
};

