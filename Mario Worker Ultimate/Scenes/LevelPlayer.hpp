#pragma once
#include "GameBase.hpp"
#include "BlankScene.hpp"
#include "../Enemies/Goomba.hpp"

class LevelPlayer: public GameBase, public BlankScene
{
	Goomba testGoomba;
public:
	LevelPlayer();
	void LoadContent() override;
	void Update(float dt, MouseState* ms, ControllerState* cs) override;
	void Draw(float dt) override;
};

