#pragma once
#include "IButton.hpp"

class ShinyButton : public IButton
{
	Texture2D _button{};
	Texture2D _shine{};
	Rectangle _coords{};

	float _shiningAnimTimer = 0;
	bool _lastClickState = false;
	uint8_t _alpha = 0;

	std::function<void()> _eClick;

	uint8_t _calculateGlintAlpha(int animTimer);
public: 
	ShinyButton() = default;
	ShinyButton(Texture2D button, Texture2D shine, Rectangle coords, std::function<void()> whenClick);

	void Update(MouseState *ms,float dt) override final;
	void Draw(float dt) override final;
};

