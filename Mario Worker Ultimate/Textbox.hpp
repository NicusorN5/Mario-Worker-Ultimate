#pragma once
#include "MouseState.hpp"
#include "TransparentFont.hpp"

class Textbox
{
	std::string _text = "";
	Rectangle _coords{};
	bool _focus = false;
	float _keyTimer = 0;

	Texture2D _textboxTexture;
	TransparentFont *_textFont;
	size_t _textIndex = 0;
	size_t _maxLenght;
public:
	Textbox(Texture2D texture, TransparentFont *font,std::string defaultText, Rectangle r,size_t maxLenght) :
		_textboxTexture(texture),
		_textFont(font),
		_text(defaultText), 
		_coords(r),
		_maxLenght(maxLenght) {};

	void Draw(float dt);
	void Update(MouseState* ms,float dt);

	void DisableFocus();

	const std::string GetText();
};

