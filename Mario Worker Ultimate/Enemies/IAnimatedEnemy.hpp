#pragma once
#include "IEnemy.hpp"
#include "../Animable.hpp"

class IAnimatedEnemy: public IEnemy, public Animable
{
public:
	void Update(float dt) override;
	IAnimatedEnemy(const std::string& Name, int X, int Y, unsigned variant = 0, float animSpeed = 1, short numFrames = 2, short startFrame = 0);
};