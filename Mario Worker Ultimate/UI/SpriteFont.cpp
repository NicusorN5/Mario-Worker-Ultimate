#include "SpriteFont.hpp"

int SpriteFont::_getIndexForGlyph(char c) const noexcept
{
	for(size_t i = 0; i < _numLetters; i++)
	{
		if(_letters[i].Letter == c) return i;
	}
	return -1;
}

SpriteFont::SpriteFont(Texture2D texture, const char* avalableLetters, Rectangle* glyphsImageCoordinates):
	_fontTexture(texture),
	_letters(nullptr),
	_maxLength(std::numeric_limits<int>::min())
{
	_numLetters = strlen(avalableLetters);

	_letters = std::unique_ptr<FontLetter[]>(new FontLetter[_numLetters]);

	for(size_t i = 0; i < _numLetters; i++)
	{
		_letters[i].Letter = avalableLetters[i];
		_letters[i].GlyphRectangle = glyphsImageCoordinates[i];
		if(_letters[i].GlyphRectangle.width > _maxLength)
			_maxLength = _letters[i].GlyphRectangle.width;
	}
}

SpriteFont::SpriteFont() :
	_fontTexture{},
	_numLetters(0),
	_maxLength(std::numeric_limits<int>::min())
{
};

void SpriteFont::Draw(const std::string& text, Vector2 position_norm, Vector2 scale,float spacing,size_t maxIndex, int maxLen)
{
	std::string text_l(text);
	if(maxLen == -1) maxLen = text_l.length();
	if(text_l.length() < maxLen) maxLen = text_l.length();

	std::transform(text_l.begin(), text_l.end(), text_l.begin(), [](char c) { return std::toupper(c); });
	float x = position_norm.x;
	for(size_t i = maxIndex, j = 0; i < text_l.length() && j <= maxLen; i++, j++)
	{
		int charIndex = _getIndexForGlyph(text_l[i]);
		if(charIndex >= 0)
		{
			Rectangle glyphSource = _letters[charIndex].GlyphRectangle;
			float lx = ((charIndex != _getIndexForGlyph(' ') ? glyphSource.width : _maxLength) / _maxLength) * scale.x;
			DrawTexturePro(_fontTexture, glyphSource, Game::ScreenRec({ x,position_norm.y, lx , scale.y }), { 0,0 }, 0.0f, WHITE);
			x += lx + spacing;
		}
	}
}

float SpriteFont::MeasureLength(const std::string& text,Vector2 scale,float spacing)
{
	std::string txtc(text);
	std::transform(txtc.begin(), txtc.end(), txtc.begin(), [](char c) { return std::toupper(c); });

	float c = 0;

	for(auto&& chr : txtc)
	{
		int charIndex = _getIndexForGlyph(chr);
		c += ((charIndex != _getIndexForGlyph(' ') ? _letters[charIndex].GlyphRectangle.width : _maxLength) / _maxLength) * scale.x;
		c += spacing;
	}
	return c;
}

float SpriteFont::MeasureHeight(const std::string& text, Vector2 scale)
{
	std::string txtc(text);
	std::transform(txtc.begin(), txtc.end(), txtc.begin(), [](char c) { return std::toupper(c); });
	
	float h = std::numeric_limits<float>::min();
	
	for(auto&& chr : txtc)
	{
		int charIndex = _getIndexForGlyph(chr);
		float pmh = ((charIndex != _getIndexForGlyph(' ') ? _letters[charIndex].GlyphRectangle.width : _maxLength) / _maxLength) * scale.y;
		if(pmh > h) h = pmh;
	}
	return h;
}

bool SpriteFont::SupportsChar(char c) const noexcept
{
	return _getIndexForGlyph(c) != -1;
}

SpriteFont::~SpriteFont()
{
	UnloadTexture(_fontTexture);
}
