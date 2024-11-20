#pragma once
#include "../Resolution.hpp"

struct FontLetter
{
	char Letter;
	Rectangle GlyphRectangle;
};

class SpriteFont
{
	Texture2D _fontTexture;

	size_t _numLetters;
	std::unique_ptr<FontLetter[]> _letters;

	int _getIndexForGlyph(char c) const noexcept;

	int _maxLength;

public:
	SpriteFont(Texture2D texture, const char* avalableLetters, Rectangle* glyphsImageCoordinates);
	SpriteFont();

	void Draw(const std::string& text,Vector2 position_norm,Vector2 scale,float spacing,size_t startIndex = 0,int maxLen = -1);
	
	float MeasureLength(const std::string &text,Vector2 scale,float spacing);
	float MeasureHeight(const std::string &text,Vector2 scale);
	
	bool SupportsChar(char c) const noexcept;

	~SpriteFont();
};
