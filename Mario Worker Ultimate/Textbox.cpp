#include "Textbox.hpp"

void Textbox::Draw(float dt)
{
    DrawTexturePro(_textboxTexture, { 0,0,(float)_textboxTexture.width,(float)_textboxTexture.height }, _coords, { 0,0 }, 0.0, WHITE);
    _textFont->Draw(_text, { _coords.x,_coords.y }, { _coords.width,_coords.height });
}

void Textbox::Update(MouseState* ms, float dt)
{
    if(ms->MouseClickingRectangle(_coords)) _focus = true;
    else if(ms->MouseFinishedClickingOutsideRectangle(_coords)) _focus = false;

    if(_focus)
    {
        for(int key = GetKeyPressed(); key > 0; key = GetKeyPressed())
        {
            key = key >= 32 && key <= 126 ? key : 0;
            if(key)
            {
                _text += (char)key;
                _textIndex += 1;
            }
        }
        if(IsKeyDown(KEY_BACKSPACE))
        {
            _text.erase(_textIndex);
            if(_textIndex > 0) _textIndex -= 1;
        }
        if(IsKeyDown(KEY_ENTER)) _focus = false;
    }
}

void Textbox::DisableFocus()
{
    _focus = false;
}

const std::string Textbox::GetText()
{
    return _text;
}
