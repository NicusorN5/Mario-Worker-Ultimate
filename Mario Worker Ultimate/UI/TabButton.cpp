#include "TabButton.hpp"

void TabButton::Draw(float dt)
{
	if(movingAnim == 0)
	{
		Rectangle r = { _rUnhovered.x + xOffset,_rUnhovered.y,_rUnhovered.width,_rUnhovered.height };
		DrawTexturePro(_tUnhovered, { 0,0,(float)_tUnhovered.width,(float)_tUnhovered.height }, r, { 0,0 }, 0, WHITE);
	}
	else
	{
		Rectangle r = { _rAnim.x + xOffset, _rAnim.y,_rAnim.width,_rAnim.height };
		DrawTexturePro(_tHovered, {0,0,(float)_tHovered.width,(float)_tHovered.height}, r, {0,0}, 0, WHITE);
	}
}

void TabButton::Update(MouseState* ms, float dt)
{
	if(movingAnim > 0)
	{
		Rectangle r = { _rHovered.x + xOffset, _rHovered.y,_rHovered.width,_rHovered.height };
		_isHovered = ms->MouseInsideRectangle(r);
		_isClicked = ms->MouseFinishedClickingRectangle(r);
	}
	else
	{
		Rectangle r = { _rUnhovered.x + xOffset,_rUnhovered.y,_rUnhovered.width,_rUnhovered.height };
		_isHovered = ms->MouseInsideRectangle(r);
		_isClicked = ms->MouseFinishedClickingRectangle(r);
	}

	_rAnim =
	{
		_rHovered.x,
		_rHovered.y + _rHovered.height - std::lerp(0.0f,_rHovered.height,movingAnim),
		_rHovered.width,
		std::lerp(0.0f,_rHovered.height,movingAnim)
	};

	if(_isHovered) movingAnim += 2.5f * dt;
	else movingAnim -= 2.5f * dt ;
	if(_isClicked) _onClick();

	movingAnim = std::clamp(movingAnim, 0.0f, 1.0f);
}

void TabButton::SetXOffset(float offset)
{
	xOffset = offset * Game::Resolution::X;
}

bool TabButton::Raised()
{
	return movingAnim > 0;
}
