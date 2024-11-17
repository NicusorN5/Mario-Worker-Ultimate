#pragma once
#include "../Resolution.hpp"
#include "../Raylib/Texture2DW.hpp"

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

	int _maxLength;

public:
	TransparentFont(
		const Texture2D &texture,
		const std::string &avalableLetters,
		std::span<Rectangle> glyphsImageCoordinates
	);
	TransparentFont();

	void Draw(const std::string& text,Vector2 position_norm,Vector2 scale,float spacing,size_t startIndex = 0,int maxLen = -1);
	
	float MeasureLength(const std::string &text,Vector2 scale,float spacing);
	float MeasureHeight(const std::string &text,Vector2 scale);
	
	bool SupportsChar(char c);
};
