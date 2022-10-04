#include "Slider.hpp"

Slider::Slider():
	_min(0),
	_max(0),
	_value(0),
	_sliderPos(0),
	_bar{},
	_slider{},
	_coords{}
{
}

Slider::Slider(Texture2D& bar, Texture2D& slider,const Rectangle& coords, int min, int max, int defaultValue) :
	_min(min),
	_max(max),
	_value(defaultValue),
	_sliderPos((float)(defaultValue - min) / max),
	_bar(bar),
	_slider(slider),
	_coords(coords)
{
}

void Slider::Draw(float dt)
{
	DrawTexturePro(
		_bar,
		{
			0,
			0,
			(float)_bar.width,
			(float)_bar.height
		},
		_coords,
		{ 0,0 },
		0.0f,
		WHITE
	);
	DrawTexturePro(
		_slider,
		{
			0,
			0,
			(float)_slider.width,
			(float)_slider.height
		},
		{
			_coords.x + (_sliderPos * _coords.width),
			_coords.y,
			std::max<float>(_coords.width / (_max - _min), 0.01f * Game::Resolution::X),
			_coords.height
		},
		{0,0},
		0.0f,
		WHITE
	);
}

void Slider::Update(const MouseState* ms, float dt)
{
	Rectangle _slideRect = _coords;
	_slideRect.x += _sliderPos * _slideRect.width;
	_slideRect.width /= _max - _min;

	float gx = Game::Resolution::X;
	float gy = Game::Resolution::Y;

	float sliderNewPos = (ms->X - (_coords.x )) / (_coords.width);

	if(ms->MouseClickingRectangle(_slideRect))
		_sliderPos = sliderNewPos;

	else if(ms->MouseClickingRectangle(_coords))
		_sliderPos = std::lerp(_sliderPos, sliderNewPos, 0.1f);

	_sliderPos = std::clamp<float>(_sliderPos, 0.0f, 1.0f);
}
