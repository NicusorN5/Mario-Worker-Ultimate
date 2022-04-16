#pragma once
#include "MouseState.hpp"

class IButton
{
protected:
	bool _isHovered = false;
	bool _isClicked = false;
public:
	virtual void Update(MouseState* ms, float dt) = 0;
	virtual void Draw(float dt) = 0;
	
	bool IsClicked();
	bool IsHovered();
};

