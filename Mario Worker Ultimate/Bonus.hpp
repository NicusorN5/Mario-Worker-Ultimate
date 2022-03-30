#pragma once
#include "Libs.hpp"

enum class BonusType
{
	Coin,
	Mushroom,
	Flower,
	Beet,
	Lui,
	Hammer,
	PoisonousMushroom,
	FlyingPoisonousMushroom,
};

class Bonus
{
	float _animationTimer = 0;
public:
	Bonus(int X, int Y, BonusType t) : Position{ static_cast<float>(X),static_cast<float>(Y) }, Type(t) {};
	Vector2 Position;
	BonusType Type;

	void Render(float dt);
	void Update(float dt);
};

