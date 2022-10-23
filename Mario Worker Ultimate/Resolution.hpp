#pragma once
#include "Libs.hpp"

namespace Game
{
	namespace Resolution
	{
		extern unsigned X;
		extern unsigned Y;

		Vector2 Vec();
		float FltX();
		float FltY();
	}
	Rectangle ScreenRec(Rectangle norm);
	Vector2 ScreenRec(Vector2 norm);
}

