#include "Checkbox.hpp"

Checkbox::Checkbox(Texture2D _cTxd, Texture2D _ucTxd,TransparentFont* f ,const std::string& text, bool defState, Vector2 txtpos,Vector2 boxScale,Vector2 scale,float spacing):
	_checkedTxd(_cTxd),
	_uncheckedTxd(_ucTxd),
	_font(f),
	_text(text),
	Checked(defState),
	_pos(txtpos),
	_scale(scale),
	_spacing(spacing),
	_boxS(boxScale)
{

}

void Checkbox::Update(MouseState* ms, float dt)
{
	Rectangle box = {
		(_pos.x * Game::Resolution::FltX()) - _boxS.x - (Game::Resolution::FltX() * 0.01f),
		_pos.y * Game::Resolution::FltY(),
		_boxS.x,
		_boxS.y
	};

	if(ms->MouseFinishedClickingRectangle(box))
	{
		Checked = ! Checked;
		OnStateChange(Checked);
	}
}

void Checkbox::Draw(float dt)
{
	_font->Draw(_text, _pos, _scale, _spacing);

	Texture2D cTxd = Checked ? _checkedTxd : _uncheckedTxd;
	DrawTexturePro(
		cTxd,
		{ 
			0,
			0,
			(float)cTxd.width,
			(float)cTxd.height 
		}, 
		{
			(_pos.x * Game::Resolution::FltX()) - _boxS.x - (Game::Resolution::FltX() * 0.01f),
			_pos.y * Game::Resolution::FltY(),
			_boxS.x,
			_boxS.y
		},
		{0,0},
		0.0f,
		WHITE
	);
}