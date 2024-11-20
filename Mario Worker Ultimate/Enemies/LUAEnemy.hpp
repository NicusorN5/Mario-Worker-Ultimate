#pragma once
#include "IEnemy.hpp"

class LUAEnemy : public IEnemy
{
public:
	LUAEnemy(const std::filesystem::path& scriptPath, int x, int y);

	bool WhenHit(DamageByPlayer damage, IEnemy* replaceInitialEnemy) override;
	void Update(float dt) override;
	void Draw(float dt) override;
};