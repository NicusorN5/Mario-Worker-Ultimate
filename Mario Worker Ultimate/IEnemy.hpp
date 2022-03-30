#pragma once
#include "Libs.hpp"

enum class DamageByPlayer
{
	NoDamage,
	ByHit,
	ByFire,
	ByBeet,
	ByHammer,
};

class IEnemy
{
protected:
	const char* _name;
	unsigned _variant;
public:
	IEnemy(const char* Name, int X, int Y, unsigned v) : _name(Name), Position{ static_cast<float>(X),static_cast<float>(Y) }, _variant(v) {};

	Vector2 Position;

	const char* GetName();
	unsigned GetVariant();

	virtual bool WhenHit(DamageByPlayer damage, IEnemy* replaceInitialEnemy) = 0;
	virtual void Update(float dt) = 0;
	virtual void Render(float dt) = 0;

	~IEnemy();
};

