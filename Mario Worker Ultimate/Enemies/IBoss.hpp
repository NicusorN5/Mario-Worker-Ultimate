#pragma once
#include "IEnemy.hpp"

class IBoss : public IEnemy
{
public:
	IBoss(const std::string& Name, int X, int Y);

	int HealthPoints = 1;
	float AttackWaitTime = 1;

	virtual void Attack() = 0;
};