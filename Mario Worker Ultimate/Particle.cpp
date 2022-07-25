#include "Particle.hpp"

Particle::Particle(Vector2 pos, ParticleModeInfo mode, std::function<Vector2(float)> vel,float time) :
	Position(pos),
	_mode(mode.Mode),
	_velocityFunction(vel),
	_lifetime(time),
	_velocityTime(0)
{
}

void Particle::Render(Texture2D texture,Rectangle source, Vector2 size)
{
	switch(this->_mode)
	{

	}
}

void Particle::Update()
{
	Vector2 velocity = this->_velocityFunction(_velocityTime);
	Position.x += velocity.x;
	Position.y += velocity.y;
}
