#pragma once
#include "Resolution.hpp"

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

	int _getIndexForGlyph(char c);

	int _maxLenght;

public:
	TransparentFont(Texture2D texture, const char* avalableLetters, Rectangle* glyphsImageCoordinates);
	TransparentFont();

	void Draw(const std::string& text,Vector2 position_norm,Vector2 scale,float spacing,size_t startIndex = 0,int maxLen = -1);

	float MeasureLenght(const std::string &text,Vector2 scale,float spacing);

	~TransparentFont();
};
