#include "Goomba.hpp"

Goomba::Goomba(int X, int Y, GoombaType t):
    IAnimatedEnemy("Goomba", X, Y, static_cast<int>(t)),_direction(1), _animTimer(0),_spriteAnim(0)
{
};

bool Goomba::WhenHit(DamageByPlayer damage, IEnemy* replaceInitialEnemy)
{
    if(this->_variant == 1 && damage == DamageByPlayer::ByFire) return false; //gray goombas are invulnerable to fire
    else return true;
}

void Goomba::Update(float dt)
{
    IAnimatedEnemy::Update(dt);
    this->Position.x += _direction * 5 * Game::CurrentLevel.EnemySpeed * dt;
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
            throw std::logic_error("Unknown goomba type");
            break;
    }

    DrawTexturePro(
        *goombaTexture,
        GetFrame({0,0,32,32}), 
        {Position.x,Position.y,Position.x + 32,Position.y + 31}, 
        {0,0},
        0.0f,
        WHITE
    );
}
