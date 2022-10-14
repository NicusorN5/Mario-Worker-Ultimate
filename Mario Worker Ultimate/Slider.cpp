#include "Slider.hpp"

Rectangle Slider::_coordsLim()
{
	Rectangle coordsC = _coords;
	coordsC.x += Game::Resolution::X * 0.005;
	coordsC.width -= Game::Resolution::X * 0.02;

	return coordsC;
}

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

Slider::Slider(Texture2D& bar, Texture2D& slider,const Rectangle& coords, int min, int max, int defaultValue, std::function<void(double,double)> valchange) :
	_min(min),
	_max(max),
	_value(defaultValue),
	//_sliderPos((double)( (double)(defaultValue - min)) / (double)max), <- Loss of accuracy :(
	_sliderPos(0),
	_bar(bar),
	_slider(slider),
	_coords(coords),
	OnValueChange(valchange)
{
	//Floating point arithmetic moment
	double dmax = max;
	double dmin = min;
	double ddef = defaultValue;

	_sliderPos = defaultValue;
	_sliderPos /= max - min;

	//Wachy floating point hack
	for(; GetValue<int>() > defaultValue; _sliderPos -= 1.0 / (double)(max - min))
	{
	}
}

void Slider::Draw(float dt)
{
	Rectangle coordsC = this->_coordsLim();

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
			(float)( coordsC.x + (_sliderPos * coordsC.width) ),
			coordsC.y,
			0.01f * Game::Resolution::X,
			coordsC.height
		},
		{0,0},
		0.0f,
		WHITE
	);
}

void Slider::Update(const MouseState* ms, float dt)
{
	Rectangle coordsC = this->_coordsLim();

	Rectangle _slideRect = coordsC;
	_slideRect.x += _sliderPos * _slideRect.width;
	_slideRect.width /= _max - _min;

	float gx = Game::Resolution::X;
	float gy = Game::Resolution::Y;

	float sliderNewPos = (ms->X - (coordsC.x )) / (coordsC.width);

	bool _valChange = false;
	float oldValue = this->GetValue<double>();

	if(ms->MouseClickingRectangle(_slideRect))
	{
		_valChange = true;
		_sliderPos = sliderNewPos;
	}
	else if(ms->MouseClickingRectangle(_coords))
	{
		_valChange = true;
		_sliderPos = std::lerp(_sliderPos, sliderNewPos, 0.1f);
	}

	_sliderPos = std::clamp<float>(_sliderPos, 0.0f, 1.0f);

	if(_valChange)
		OnValueChange(oldValue, this->GetValue<double>());
}
