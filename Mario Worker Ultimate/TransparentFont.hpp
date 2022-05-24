#pragma once
#include "Libs.hpp"

struct FontLetter
{
	char Letter;
	Rectangle GlyphRectangle;
};

class TransparentFont
{
	Texture2D _fontTexture;

	size_t _numLetters;
	std::unique_ptr<FontLetter[]> _letters;

	float _spacing;

	int _getIndexForGlyph(char c);

public:
	TransparentFont(Texture2D texture, const char* avalableLetters, Rectangle* glyphsImageCoordinates,float spacing);
	TransparentFont() :
		_spacing(0), 
		_fontTexture{}, 
		_numLetters(0) 
	{};

	void Draw(const std::string& text,Vector2 position_norm,Vector2 scale);

	~TransparentFont();
};
