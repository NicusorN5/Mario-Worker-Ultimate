#pragma once
#include "TransparentFont.hpp"
#include "MouseState.hpp"
#include "StringsCollection.hpp"

class Listbox
{
	Texture2D _sliderBar;
	Texture2D _sliderBox;
	Texture2D _listboxBody;
	Texture2D _glint;
	TransparentFont* _font;

	Rectangle _coords;
	Vector2 _scaling;
	float _spacing;

	float _sliderPos;
	int _numElemBox = 0; //number of elements that can fit into the box
	int _idElemHov = -1;

	float _glintAnimTimer =0;
public:
	Listbox() = default;
	Listbox(Texture2D sliderBar, Texture2D sliderBox, Texture2D listBoxTxd,Texture2D glint, TransparentFont* font, Rectangle coords, StringsCollection initial_items,Vector2 textScaling, float spacing);

	StringsCollection Items;

	void Update(MouseState* ms, float dt);
	void Draw(float dt);

	std::function<void(const std::string&)> OnItemClick;
};

