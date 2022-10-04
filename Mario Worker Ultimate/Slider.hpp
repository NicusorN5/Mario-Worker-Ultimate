#pragma once
#include "TransparentFont.hpp"
#include "MouseState.hpp"

class Slider
{
	int _min;
	int _max;
	int _value;
	float _sliderPos;

	Texture2D _bar;
	Texture2D _slider;

	Rectangle _coords;
public:
	Slider();
	Slider(Texture2D& bar, Texture2D& slider,const Rectangle &coords, int min, int max, int defaultValue);

	void Draw(float dt);
	void Update(const MouseState* ms, float dt);

	template<typename N>
	int GetValue()
	{
		return std::lerp<N>(_min, _max, _sliderPos);
	}

};

