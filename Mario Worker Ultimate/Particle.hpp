#pragma once
#include "Libs.hpp"

enum class ParticleMode
{
	Disabled,
	FadeIn_FadeOut,
	FadeInOnly,
	FadeOutOnly,
	NoFading,
};

struct ParticleModeInfo
{
	ParticleMode Mode;
	float FadeTime;
};

class Particle
{
	ParticleMode _mode;
	std::function<Vector2(float)> _velocityFunction;

	float _velocityTime;
	float _lifetime;
public:
	Particle(Vector2 pos, ParticleModeInfo mode, std::function<Vector2(float)> vel,float time);

	Vector2 Position;

	void Render(Texture2D texture, Rectangle source, Vector2 size);
	void Update();
};

