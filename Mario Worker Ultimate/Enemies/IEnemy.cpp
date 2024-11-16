#include "IEnemy.hpp"

const char* IEnemy::GetName()
{
    return this->_name;
}

unsigned IEnemy::GetVariant()
{
    return this->_variant;
}

IEnemy::~IEnemy()
{
}
