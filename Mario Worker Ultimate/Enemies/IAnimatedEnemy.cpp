#include "IAnimatedEnemy.hpp"

void IAnimatedEnemy::Update(float dt)
{
	Animable::UpdateAnim(dt);
}

IAnimatedEnemy::IAnimatedEnemy(const std::string& Name, int X, int Y, unsigned variant, float animSpeed, short numFrames, short startFrame ) :
	IEnemy(Name, X, Y, variant),
	Animable(animSpeed, numFrames, startFrame )
{
}
