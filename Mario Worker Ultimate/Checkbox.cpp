#include "Checkbox.hpp"

Checkbox::Checkbox(Texture2D _cTxd, Texture2D _ucTxd,TransparentFont& f ,const std::string& text, bool defState, Vector2 txtpos):
	_checkedTxd(_cTxd),
	_uncheckedTxd(_ucTxd),
	_font(f),
	_text(text),
	_checked(defState),
	_pos(txtpos)
{

}

void Checkbox::Update(MouseState* ms, float dt)
{

}

void Checkbox::Draw(float dt)
{

}

bool Checkbox::GetState()
{
	return this->_checked;
}