#include "Game.hpp"

namespace Game
{
	unsigned CurrentGameSection = 0;
	Player MainPlayer = Player(0, 0);
	namespace Resolution
	{
		unsigned X;
		unsigned Y;

		Vector2 Vec()
		{
			return Vector2(X,Y);
		}
		float FltX()
		{
			return X;
		}
		float FltY()
		{
			return Y;
		}
	}
};