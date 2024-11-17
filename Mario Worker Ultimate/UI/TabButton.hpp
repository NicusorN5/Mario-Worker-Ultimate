#pragma once
#include "IButton.hpp"
#include "../Resolution.hpp"

class TabButton : public IButton
{
	Texture2D _tUnhovered{};
	Texture2D _tHovered{};

	Rectangle _rUnhovered{};
	Rectangle _rHovered{};

	std::function<void()> _onClick;
	float movingAnim = 0.0f;

	Rectangle _rAnim;

	float xOffset = 0;
public:
	TabButton() = default;

	TabButton(
		const Texture2D& btn,
		const Texture2D& btnHovered,
		const Rectangle& r,
		const Rectangle& rHovered,
		std::function<void()> click
	);

	void Draw(float dt) override final;
	void Update(MouseState* ms, float dt) override final;

	void SetXOffset(float offset);
	bool Raised();
};
