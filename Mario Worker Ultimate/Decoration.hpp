#pragma once
#include "Libs.hpp"

class Decoration
{
	unsigned SpriteID;
	Vector2 Position;
	float _animTimer;

	void Draw(float dt);
};

