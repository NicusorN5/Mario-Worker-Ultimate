#include "IEnemy.hpp"

IEnemy::IEnemy(const std::string& Name, int X, int Y, unsigned variant) :
	_name(Name),
	Position{ static_cast<float>(X),static_cast<float>(Y) },
	_variant(variant)
{
}

const std::string& IEnemy::GetName() const noexcept
{
    return this->_name;
}

unsigned IEnemy::GetVariant() const noexcept
{
    return this->_variant;
}

bool IEnemy::FellOfMap() const noexcept
{
    return this->_fellOfMap;
}

void IEnemy::SetScene(GameBase* scene) noexcept
{
	this->_scene = scene;
}
