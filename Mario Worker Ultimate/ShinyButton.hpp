#pragma once
#include "MouseState.hpp"

class ShinyButton
{
	Texture2D _button;
	Texture2D _shine;
	Rectangle _coords;

	bool _isHovered = false;
	bool _isClicked = false;
	float _shiningAnimTimer = 0;
	bool _lastClickState = false;
	uint8_t _alpha = 0;

	std::function<void()> _eClick;

	uint8_t _calculateGlintAlpha(int animTimer);
public: 
	ShinyButton() = default;
	ShinyButton(Texture2D button, Texture2D shine, Rectangle coords,std::function<void()> whenClick) : 
		_button(button), _shine(shine), _coords(coords), _eClick(whenClick) { };

	void Update(MouseState *ms,float dt);
	void Draw(float dt);

	bool IsClicked();
	bool IsHovered();
};

