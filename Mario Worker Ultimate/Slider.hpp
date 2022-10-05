#pragma once
#include "TransparentFont.hpp"
#include "MouseState.hpp"

class Slider
{
	int _min;
	int _max;
	int _value;
	double _sliderPos;

	Texture2D _bar;
	Texture2D _slider;

	Rectangle _coords;

	Rectangle _coordsLim();
public:
	Slider();
	Slider(Texture2D& bar, Texture2D& slider,const Rectangle &coords, int min, int max, int defaultValue,std::function<void(double,double)> valchange = nullptr);

	void Draw(float dt);
	void Update(const MouseState* ms, float dt);

	std::function<void(double,double)> OnValueChange; // oldValue, newValue;

	template<typename N>
	int GetValue()
	{
		return std::lerp<N>(_min, _max, _sliderPos);
	}

};

