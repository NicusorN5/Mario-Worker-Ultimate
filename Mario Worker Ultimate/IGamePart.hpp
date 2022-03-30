#pragma once

class IGamePart
{
public:
	virtual void LoadContent() = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw(float dt) = 0;

	~IGamePart();
};

