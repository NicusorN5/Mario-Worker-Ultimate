#include "Goomba.hpp"

bool Goomba::WhenHit(DamageByPlayer damage, IEnemy* replaceInitialEnemy)
{
    if(this->_variant == 1 && damage == DamageByPlayer::ByFire) return false; //gray goombas are invulnerable to fire
    else return true;
}

void Goomba::Update(float dt)
{
    _animTimer += dt;
    if(_animTimer >= 0.5f)
    {
        _animTimer = 0;
    }
    this->Position.x += _direction * 5 * Game::CurrentLevel.EnemySpeedMultiplier  * dt;
}

void Goomba::Draw(float dt)
{
    Texture2D* goombaTexture = nullptr;
    switch(this->_variant)
    {
        case 0:
            goombaTexture = &Resources::Goomba1;
            break;
        case 1:
            goombaTexture = &Resources::Goomba2;
            break;
        default:
            throw std::runtime_error("Unknown goomba type");
            break;
    }
    DrawTexturePro(*goombaTexture, { 0,0,31,32 }, { Position.x,Position.y,Position.x + 32,Position.y + 31 }, { 0,0 }, 0.0f, WHITE);
}
