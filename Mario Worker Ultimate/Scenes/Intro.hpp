#pragma once
#include "IScene.hpp"
#include "../Resources.hpp"
#include "../Game.hpp"

class Intro : public IScene
{
	Texture2DW _introImage;
	float _introTimer = 0.0f;

	uint8_t introImageAlpta(float t);
public:
	Intro() = default;
	Intro(const Intro&) = delete;
	Intro(Intro&&) noexcept = default;

	Intro& operator=(const Intro&) = delete;
	Intro& operator=(Intro&&) noexcept = default;

	void LoadContent() final override;
	void Update(float dt, MouseState* ms, ControllerState* cs) final override;
	void Draw(float dt) final override;
};

