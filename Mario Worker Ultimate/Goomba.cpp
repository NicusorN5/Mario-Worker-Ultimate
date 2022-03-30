#include "Goomba.hpp"

bool Goomba::WhenHit(DamageByPlayer damage, IEnemy* replaceInitialEnemy)
{
    if(this->_variant == 1 && damage == DamageByPlayer::ByFire) return false; //gray goombas are invulnerable to fire
    else return true;
}

void Goomba::Update(float dt)
{

}

void Goomba::Render(float dt)
{
}
