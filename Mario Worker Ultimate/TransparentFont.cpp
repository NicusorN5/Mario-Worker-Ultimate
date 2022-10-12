#include "TransparentFont.hpp"

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
	_letters(nullptr),
	_maxLenght(std::numeric_limits<int>::min())
{
	_numLetters = strlen(avalableLetters);

	_letters = std::unique_ptr<FontLetter[]>(new FontLetter[_numLetters]);

	for(size_t i = 0; i < _numLetters; i++)
	{
		_letters[i].Letter = avalableLetters[i];
		_letters[i].GlyphRectangle = glyphsImageCoordinates[i];
		if(_letters[i].GlyphRectangle.width > _maxLenght)
			_maxLenght = _letters[i].GlyphRectangle.width;
	}
}

TransparentFont::TransparentFont() :
	_fontTexture{},
	_numLetters(0),
	_maxLenght(std::numeric_limits<int>::min())
{
};

void TransparentFont::Draw(const std::string& text, Vector2 position_norm, Vector2 scale,float spacing,size_t maxIndex, int maxLen)
{
	std::string text_l(text);
	if(maxLen == -1) maxLen = text_l.length();
	if(text_l.length() < maxLen) maxLen = text_l.length();

	std::transform(text_l.begin(), text_l.end(), text_l.begin(), std::toupper);
	float x = position_norm.x;
	for(size_t i = maxIndex, j = 0; i < text_l.length() && j <= maxLen; i++, j++)
	{
		int charIndex = _getIndexForGlyph(text_l[i]);
		if(charIndex >= 0)
		{
			Rectangle glyphSource = _letters[charIndex].GlyphRectangle;
			float lx = ((charIndex != _getIndexForGlyph(' ') ? glyphSource.width : _maxLenght) / _maxLenght) * scale.x;
			DrawTexturePro(_fontTexture, glyphSource, Game::ScreenRec({ x,position_norm.y, lx , scale.y }), { 0,0 }, 0.0f, WHITE);
			x += lx + spacing;
		}
	}
}

float TransparentFont::MeasureLenght(const std::string& text,Vector2 scale,float spacing)
{
	float c = 0;

	for(auto&& chr : text)
	{
		int charIndex = _getIndexForGlyph(chr);
		c += ((charIndex != _getIndexForGlyph(' ') ? _letters[charIndex].GlyphRectangle.width : _maxLenght) / _maxLenght) * scale.x;
		c += spacing;
	}
	return c;
}

bool TransparentFont::SupportsChar(char c)
{
	return _getIndexForGlyph(c) != -1;
}

TransparentFont::~TransparentFont()
{
	UnloadTexture(_fontTexture);
}
