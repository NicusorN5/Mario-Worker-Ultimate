#include "ShinyButton.hpp"

void ShinyButton::Update(MouseState* ms, float dt)
{
	_isHovered = ms->MouseInsideRectangle(_coords);
	_isClicked = ms->MouseFinishedClickingRectangle(_coords);

	if(_isHovered)
	{
		_shiningAnimTimer += 200 * dt;
	}
	else _shiningAnimTimer = 0;

	_alpha = _calculateGlintAlpha((int)_shiningAnimTimer % 510);

	if(_isClicked) _eClick();
}

void ShinyButton::Draw(float dt)
{
	DrawTexturePro(_button, { 0,0,(float)_button.width,(float)_button.height }, _coords, { 0,0 }, 0, WHITE);
	
	if(_isHovered) 
		DrawTexturePro(_shine, { 0,0,(float)_shine.width,(float)_shine.height }, _coords, { 0,0 }, 0, { 255,255,255,_alpha });
}

uint8_t ShinyButton::_calculateGlintAlpha(int animTimer)
{
	if(animTimer <= 255) return (uint8_t)animTimer;
	else return (uint8_t)(255 - ((int)animTimer % 255));
}