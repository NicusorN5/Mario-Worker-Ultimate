#pragma once
#include "IAnimatedEnemy.hpp"
#include "../Resources.hpp"
#include "../Game.hpp"

enum class GoombaType
{
	Normal,
	Gray,
	Red,
};

class Goomba : public IAnimatedEnemy
{
	int8_t _direction; // 1 = forward, -1 = backwards.
public:
	Goomba(int X, int Y, GoombaType t);
	bool WhenHit(DamageByPlayer damage, IEnemy* replaceInitialEnemy);
	void Update(float dt);
	void Draw(float dt);
};

