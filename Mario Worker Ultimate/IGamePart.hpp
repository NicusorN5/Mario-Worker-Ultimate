#pragma once
#include "MouseState.hpp"
#include "ControllerState.hpp"

class IGamePart
{
public:
	virtual void LoadContent() = 0;
	virtual void Update(float dt,MouseState *ms,ControllerState *cs) = 0;
	virtual void Draw(float dt) = 0;

	~IGamePart();
};

