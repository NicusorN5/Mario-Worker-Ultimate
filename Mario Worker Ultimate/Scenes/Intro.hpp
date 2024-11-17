#pragma once
#include "IScene.hpp"
#include "../Resources.hpp"
#include "../Game.hpp"

class Intro : public IScene
{
	Texture _introImage{};
	float _introTimer = 0.0f;

	uint8_t introImageAlpta(float t);
public:
	void LoadContent() final override;
	void Update(float dt, MouseState* ms, ControllerState* cs) final override;
	void Draw(float dt) final override;
	~Intro();
};

