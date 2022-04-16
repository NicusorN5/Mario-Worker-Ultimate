#pragma once
#include "IButton.hpp"
#include "Resolution.hpp"

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
	TabButton(Texture2D btn, Texture2D btnHovered, Rectangle r, Rectangle rHovered, std::function<void()> click) :
		_tUnhovered(btn), _tHovered(btnHovered), _rUnhovered(r), _rHovered(rHovered), _onClick(click), _rAnim{0,0,_rHovered.width,0}{ };

	void Draw(float dt) override final;
	void Update(MouseState* ms, float dt) override final;

	void SetXOffset(float offset);
	bool Raised();
};
