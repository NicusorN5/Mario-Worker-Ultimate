#pragma once
#include "../MouseState.hpp"
#include "TransparentFont.hpp"

class Textbox
{
	std::string _text = "";
	Rectangle _coords{};
	bool _focus = false;
	float _keyTimer = 0;

	Texture2D _textboxTexture;
	TransparentFont *_textFont;
	int _textIndex = 0;
	size_t _maxLength;
	float _spacing;
	size_t _displayedCharacters;

	float _delTimer = 0;
public:
	Textbox() :
		_textboxTexture{},
		_textFont{},
		_text(""),
		_coords{},
		_maxLength(0),
		_spacing(0),
		_displayedCharacters(0)
	{};
	Textbox(Texture2D texture, TransparentFont* font, const std::string& defaultText, Rectangle r, size_t maxLength, size_t displayedChars, float spacing = 0.001f);

	void Draw(float dt);
	void Update(MouseState* ms,float dt);

	void DisableFocus();
	bool IsFocused();

	const std::string& GetText() const noexcept;
};

