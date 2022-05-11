#include "Textbox.hpp"

void Textbox::Draw(float dt)
{
}

void Textbox::Update(MouseState* ms, float dt)
{
}

void Textbox::DisableFocus()
{
    _focus = false;
}

const std::string Textbox::GetText()
{
    return _text;
}
