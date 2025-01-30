#pragma once
#include "../Libs.hpp"

class GameBase;

enum class DamageByPlayer
{
	NoDamage,
	HitAboveHead,
	ByFire,
	ByBeet,
	ByHammer,
};

class IEnemy
{
protected:
	std::string _name;
	unsigned _variant;

	bool _fellOfMap = false;

	GameBase* _scene;
public:
	IEnemy(const std::string& Name, int X, int Y, unsigned variant);

	Vector2 Position;

	bool InEditor = false;

	const std::string& GetName() const noexcept;
	unsigned GetVariant() const noexcept;

	bool FellOfMap() const noexcept;

	void SetScene(GameBase* scene) noexcept;

	virtual bool WhenHit(DamageByPlayer damage, IEnemy* replaceInitialEnemy) = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw(float dt) = 0;

	~IEnemy() = default;
};

