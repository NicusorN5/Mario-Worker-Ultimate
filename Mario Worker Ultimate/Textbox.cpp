#include "Textbox.hpp"

void Textbox::Draw(float dt)
{
	DrawTexturePro(_textboxTexture, { 0,0,(float)_textboxTexture.width,(float)_textboxTexture.height }, _coords, { 0,0 }, 0.0, WHITE);
	
	Vector2 txtpos = { _coords.x + (0.025f * _coords.width),_coords.y + (0.2f * _coords.height) };
	Vector2 scale = { (_coords.width * 0.9f) / (_displayedCharacters+1),_coords.height * 0.7f};

	float rezx = Game::Resolution::FltX();
	float rezy = Game::Resolution::FltY();

	txtpos.x /= rezx;
	txtpos.y /= rezy;

	scale.x /= rezx;
	scale.y /= rezy;

	_textFont->Draw(_text, txtpos,scale,_spacing);
	
	if(_focus)
	{
		float tl = _textFont->MeasureLenght(std::string(_text).erase(this->_textIndex),scale,_spacing) * rezx;
		float il = _textFont->MeasureLenght("I", scale,_spacing) * rezx *  0.25f ;
		DrawRectangle((int)(_coords.x + tl),(int)_coords.y, (int)il, (int)(_coords.height), {255, 0, 0,128});
	}
}

void Textbox::Update(MouseState* ms, float dt)
{
	if(ms->MouseClickingRectangle(_coords)) _focus = true;
	else if(ms->MouseClickingOutsideRectangle(_coords) && _focus) _focus = false;

	if(_focus)
	{
		for(int key = GetKeyPressed(); key > 0; key = GetKeyPressed())
		{
			key = key >= 32 && key <= 126 ? key : 0;
			if(key)
			{
				if(_text.length() <= (int)_maxLenght)
				{
					_text.insert(_text.begin() + _textIndex, (char)key);
					_textIndex += 1;
				}
			}
		}
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
		if(IsKeyDown(KEY_ENTER)) _focus = false;

		if(_delTimer == 0)
		{
			_textIndex += (IsKeyDown(KEY_LEFT) ? -1 : 0) + (IsKeyDown(KEY_RIGHT) ? 1 : 0);
			_textIndex = std::clamp<int>(_textIndex, 0, _text.length());
			_delTimer += _deletionTime;
		}

		_delTimer -= dt;
		_delTimer = std::clamp<float>(_delTimer, 0, 0.025f);
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

const std::string& Textbox::GetText()
{
	return _text;
}
