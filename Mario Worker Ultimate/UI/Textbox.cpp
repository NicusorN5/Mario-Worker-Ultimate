#include "Textbox.hpp"

Textbox::Textbox(Texture2D texture, SpriteFont* font, const std::string& defaultText, Rectangle r, size_t maxLength, size_t displayedChars, float spacing) :
	_textboxTexture(texture),
	_textFont(font),
	_text(defaultText),
	_coords(r),
	_maxLength(maxLength),
	_spacing(spacing),
	_displayedCharacters(displayedChars),
	_textIndex(defaultText.length())
{
};

int Textbox::_getTextStartLen()
{
	return (_textIndex > _displayedCharacters) ? std::max(_textIndex - (int)_displayedCharacters, 0) : 0;
}

void Textbox::Draw(float dt)
{
	DrawTexturePro(_textboxTexture, { 0,0,(float)_textboxTexture.width,(float)_textboxTexture.height }, _coords, { 0,0 }, 0.0, WHITE);
	
	Vector2 txtpos = { _coords.x + (0.025f * _coords.width),_coords.y + (0.2f * _coords.height) };
	Vector2 scale = { (_coords.width * 0.9f) / (_displayedCharacters+1), _coords.height * 0.7f};

	float rezx = Game::Resolution::FltX();
	float rezy = Game::Resolution::FltY();

	txtpos.x /= rezx;
	txtpos.y /= rezy;

	scale.x /= rezx;
	scale.y /= rezy;

	int startLen = _getTextStartLen();

	_textFont->Draw(_text, txtpos,scale,_spacing, startLen, _displayedCharacters);

	if(_focus)
	{
		std::string measuredText(_text);

		measuredText.erase(measuredText.begin() + _textIndex, measuredText.end());
		if(_textIndex > _displayedCharacters)
			measuredText.erase(measuredText.begin() + _displayedCharacters, measuredText.end());

		float tl = _textFont->MeasureLength(measuredText,scale,_spacing) * rezx;
		float il = _textFont->MeasureLength("I", scale,_spacing) * rezx *  0.25f;
		DrawRectangle((int)(_coords.x + tl),(int)_coords.y, (int)il, (int)(_coords.height), {255, 0, 0,128});
	}
}

void Textbox::Update(MouseState* ms, float dt)
{
	// if just clicked inside the textbox, set focus and set index based on mouse position
	if(ms->MouseClickingRectangle(_coords))
	{
		_focus = true;

		auto deltaX = (ms->X) - _coords.x;
		Vector2 scale = { (_coords.width * 0.9f) / (_displayedCharacters+1), _coords.height * 0.7f};

		if(deltaX >= _textFont->MeasureLength(_text, scale, _spacing))
		{
			_textIndex = _text.length();
		}
		else
		{
			auto start = _getTextStartLen();
			for(auto i = start; i < _text.length(); ++i)
			{
				auto len = _textFont->MeasureLength(_text.substr(start, i), scale, _spacing);
				if(deltaX <= len)
				{
					_textIndex = i;
					break;
				}
			}
		}
	}
	else if(ms->MouseClickingOutsideRectangle(_coords) && _focus)
	{
		_focus = false;
		return;
	}

	if(_focus)
	{
		//process letters being written
		for(int key = GetKeyPressed(); key > 0; key = GetKeyPressed())
		{
			key = key >= 32 && key <= 126 ? key : 0;
			if(key && _textFont->SupportsChar((char)key))
			{
				if(_text.length() <= (int)_maxLength)
				{
					_text.insert(_text.begin() + _textIndex, (char)key);
					_textIndex += 1;
				}
			}
		}

		//check if deleting characters.
		const float _deletionTime = 0.4f; //100 ms (average key press time for reference)
		if(IsKeyDown(KEY_BACKSPACE) && _delTimer == 0)
		{
			if(_textIndex > 0)
			{
				_text.erase(_text.begin() + _textIndex - 1, _text.begin() + _textIndex);
				_textIndex -= 1;
				_delTimer += _deletionTime;
			}
		}
		//we don't support new lines, enter is considered as a finished input.
		if(IsKeyDown(KEY_ENTER)) _focus = false;

		//update index if user is pressing left/right keys.
		if(_delTimer == 0)
		{
			_textIndex += (IsKeyDown(KEY_LEFT) ? -1 : 0) + (IsKeyDown(KEY_RIGHT) ? 1 : 0);
			_textIndex = std::clamp<int>(_textIndex, 0, _text.length()); // 0 <= index <= len(text)
			_delTimer += _deletionTime;
		}

		_delTimer -= dt; //update _delTimer.
		_delTimer = std::clamp<float>(_delTimer, 0, 0.025f); //do not allow _delTimer to be below 0.
	}
}

void Textbox::DisableFocus()
{
	_focus = false;
}

bool Textbox::IsFocused()
{
	return _focus;
}

const std::string& Textbox::GetText() const noexcept
{
	return _text;
}
