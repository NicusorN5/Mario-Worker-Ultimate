#pragma once
#include "IEnemy.hpp"

enum class GoombaType
{
	Normal,
	Gray,
	Red,
};

class Goomba : public IEnemy
{
	int8_t _direction; // 1 = forward, -1 = backwards.
public:
	Goomba(int X, int Y,GoombaType t) : IEnemy("Goomba", X, Y, static_cast<int>(t)),_direction(1) {};
	bool WhenHit(DamageByPlayer damage, IEnemy* replaceInitialEnemy) final;
	void Update(float dt) final;
	void Render(float dt) final;
};

