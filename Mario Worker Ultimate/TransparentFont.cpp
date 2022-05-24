#include "TransparentFont.hpp"

int TransparentFont::_getIndexForGlyph(char c)
{
	for(size_t i = 0; i < _numLetters; i++)
	{
		if(_letters[i].Letter == c) return i;
	}
	return -1;
}

TransparentFont::TransparentFont(Texture2D texture, const char* avalableLetters, Rectangle* glyphsImageCoordinates,float spacing):
	_fontTexture(texture),
	_spacing(spacing),
	_letters(nullptr)
{
	_numLetters = strlen(avalableLetters);

	_letters = std::unique_ptr<FontLetter[]>(new FontLetter[_numLetters]);

	for(size_t i = 0; i < _numLetters; i++)
	{
		_letters[i].Letter = avalableLetters[i];
		_letters[i].GlyphRectangle = glyphsImageCoordinates[i];
	}
}

void TransparentFont::Draw(const std::string& text, Vector2 position_norm, Vector2 scale)
{
	float x = position_norm.x;
	for(size_t i = 0; i < text.length(); i++)
	{
		int charIndex = _getIndexForGlyph(text[i]);
		if(charIndex >= 0)
		{
			DrawTexturePro(_fontTexture, _letters[charIndex].GlyphRectangle, { x,position_norm.y, x + scale.x , position_norm.y + scale.y },{0,0},0.0f,WHITE);
			x += (_letters[charIndex].GlyphRectangle.width + _spacing ) * scale.x;
		}
	}
}

TransparentFont::~TransparentFont()
{
	UnloadTexture(_fontTexture);
}
