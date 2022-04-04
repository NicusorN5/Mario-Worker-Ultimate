#pragma once
#include "IGamePart.hpp"

class LevelEditor : public IGamePart
{

public:
	void LoadContent() final override;
	void Update(float dt, MouseState* ms, ControllerState* cs) final override;
	void Draw(float dt) final override;
	~LevelEditor();
};

