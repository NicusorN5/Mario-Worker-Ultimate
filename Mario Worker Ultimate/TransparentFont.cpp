#include "TransparentFont.hpp"
#include "Resolution.hpp"

int TransparentFont::_getIndexForGlyph(char c)
{
	for(size_t i = 0; i < _numLetters; i++)
	{
		if(_letters[i].Letter == c) return i;
	}
	return -1;
}

TransparentFont::TransparentFont(Texture2D texture, const char* avalableLetters, Rectangle* glyphsImageCoordinates):
	_fontTexture(texture),
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

void TransparentFont::Draw(const std::string& text, Vector2 position_norm, Vector2 scale,float spacing)
{
	std::string text_l(text);

	std::transform(text_l.begin(), text_l.end(), text_l.begin(), std::toupper);
	float x = position_norm.x;
	for(size_t i = 0; i < text_l.length(); i++)
	{
		int charIndex = _getIndexForGlyph(text_l[i]);
		if(charIndex >= 0)
		{
			Rectangle gR = _letters[charIndex].GlyphRectangle;
			Rectangle gS = { x,position_norm.y, scale.x , scale.y };
			DrawTexturePro(_fontTexture,gR, Game::ScreenRec(gS),{0,0},0.0f,WHITE);
			x += scale.x + spacing;
		}
	}
}

TransparentFont::~TransparentFont()
{
	UnloadTexture(_fontTexture);
}
