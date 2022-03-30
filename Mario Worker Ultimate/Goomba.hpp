#pragma once
#include "IEnemy.hpp"
#include "Resources.hpp"
#include "Game.hpp"

enum class GoombaType
{
	Normal,
	Gray,
	Red,
};

class Goomba : public IEnemy
{
	int8_t _direction; // 1 = forward, -1 = backwards.
	float _animTimer;
	int8_t _spriteAnim;
public:
	Goomba(int X, int Y,GoombaType t) : IEnemy("Goomba", X, Y, static_cast<int>(t)),_direction(1), _animTimer(0),_spriteAnim(0) {};
	bool WhenHit(DamageByPlayer damage, IEnemy* replaceInitialEnemy) final;
	void Update(float dt) final;
	void Draw(float dt) final;
};

