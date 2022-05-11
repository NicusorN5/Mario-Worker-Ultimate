#pragma once
#include "MouseState.hpp"

class Textbox
{
	std::string _text = "";
	Rectangle _coords{};
	bool _focus = false;
	float _keyTimer = 0;

	Texture2D _textboxTexture;
	Font _textFont;
public:
	Textbox(Texture2D texture,Font font,std::string defaultText, Rectangle r) : _textboxTexture(texture),_textFont(font), _text(defaultText), _coords(r) {};

	void Draw(float dt);
	void Update(MouseState* ms,float dt);

	void DisableFocus();

	const std::string GetText();
};

