#include "Goomba.hpp"
#include "..\Scenes\GameBase.hpp"

Goomba::Goomba(int X, int Y, GoombaType t):
    IAnimatedEnemy(
        "Goomba",
        X, 
        Y,
        static_cast<int>(t),
        0.11,
        2), 
    _direction(1)
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

    if(InEditor) return;

    //physics
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

	_scene->DrawEnt(
		Rectangle{ this->Position.x, this->Position.y, 0.05f, 1/15.0f },
		goombaTexture,
		GetFrame({0,0,32,32}),
		WHITE
	);
}
