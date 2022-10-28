#include "Listbox.hpp"

Listbox::Listbox(Texture2D sliderBar, Texture2D sliderBox, Texture2D listBoxTxd, Texture2D glint, TransparentFont* font, Rectangle coords, StringsCollection initial_items, Vector2 textScaling, float spacing) :
	_sliderBar(sliderBar),
	_sliderBox(sliderBox),
	_listboxBody(listBoxTxd),
	_font(font),
	_coords(coords),
	Items(initial_items),
	_spacing(spacing),
	_scaling(textScaling),
	_glint(glint),
	_sliderPos(0)
{
	float h = 0.0f;
	for(int i = 0; i < initial_items.Size(); i++)
	{
		h += (_font->MeasureHeight(Items[i], _scaling) + 0.01f) * Game::Resolution::Y;

		if(h <= coords.height) _numElemBox += 1;
		else break;
	}
}

void Listbox::Update(MouseState* ms, float dt)
{
	Rectangle sliderBar = _coords;
	sliderBar.x += sliderBar.width * 0.99f;

	float sliderNewPos = (ms->Y - sliderBar.y) / (sliderBar.height);

	if(ms->MouseClickingRectangle(sliderBar))
		_sliderPos = std::lerp(_sliderPos, sliderNewPos, 0.1f);

	Rectangle sliderBox = sliderBar;
	sliderBox.y += _sliderPos * sliderBar.height;
	sliderBox.height *= 0.01f;

	if(ms->MouseClickingRectangle(sliderBox))
		_sliderPos = sliderNewPos;

	float mwm = GetMouseWheelMove();
	if(mwm != 0)
	{
		_sliderPos += mwm * -0.05f;
	}

	_sliderPos = std::clamp(_sliderPos, 0.0f, 1.0f);

	int i = (Items.Size() - _numElemBox) * _sliderPos;
	if(i > Items.Size()) i = 0;

	float h = 0; //current height
	Rectangle currentTxtBounds;

	_idElemHov = -1;

	for(int j = 0; i < Items.Size() && j < _numElemBox; i++, j++)
	{
		currentTxtBounds = {
			_coords.x + Game::Resolution::X * 0.01f,
			_coords.y + Game::Resolution::Y * 0.01f + h,
			_font->MeasureLength(Items[i],_scaling,_spacing) * Game::Resolution::X,
			_font->MeasureHeight(Items[i],_scaling) * Game::Resolution::Y
		};

		if(ms->MouseInsideRectangle(currentTxtBounds))
		{
			_idElemHov = i;
		}

		if(ms->MouseClickingRectangle(currentTxtBounds))
		{
			OnItemClick(Items[i]); 
			break; //Can multiple cursors even exist? If they do, why would anyone use them, especially while playing a game like this one?
		}

		h += (_font->MeasureHeight(Items[i], _scaling) + 0.01f) * Game::Resolution::Y;
	}
}

void Listbox::Draw(float dt)
{
	DrawTexturePro(
		_listboxBody,
		{ 0,0,(float)_listboxBody.width,(float)_listboxBody.height},
		_coords,
		{0,0},
		0.0f, 
		WHITE
	);

	Rectangle sliderBar = _coords;
	std::swap(sliderBar.width, sliderBar.height); //90 deg translation applied to the bar
	sliderBar.x += 1.05f * sliderBar.height;
	sliderBar.height *= 0.1f;

	DrawTexturePro(
		_sliderBar,
		{ 0,0,(float)_sliderBar.width,(float)_sliderBar.height },
		sliderBar,
		{ 0,0 },
		90.0f,
		WHITE
	);	

	Rectangle sliderBox = _coords;
	std::swap(sliderBox.width, sliderBox.height);
	sliderBox.x += 1.05f * sliderBox.height;
	sliderBox.y += (sliderBox.width - Game::Resolution::X *0.01f) * _sliderPos;
	sliderBox.height *= 0.1f;
	sliderBox.width *= 0.05f;

	DrawTexturePro(
		_sliderBox,
		{ 0,0,(float)_sliderBox.width,(float)_sliderBox.height },
		sliderBox,
		{ 0,0 },
		90.0f,
		WHITE
	);

	int i = (Items.Size() - _numElemBox) * _sliderPos;
	if(i > Items.Size()) i = 0;

	float h = 0;

	for(int j = 0 ; i < Items.Size() && j < _numElemBox; i++, j++)
	{
		_font->Draw(
			Items[i],
			{
				(_coords.x) / Game::Resolution::X + 0.01f,
				(_coords.y) / Game::Resolution::Y + (h / Game::Resolution::Y) + 0.01f
			},
			_scaling,
			_spacing
		);

		if(_idElemHov == i)
		{
			DrawTexturePro(
				_glint,
				{ 0,0,(float)_glint.width,(float)_glint.height },
				{
					_coords.x + Game::Resolution::X * 0.01f,
					_coords.y + Game::Resolution::Y * 0.01f + h,
					_font->MeasureLength(Items[i],_scaling,_spacing) * Game::Resolution::X,
					_font->MeasureHeight(Items[i],_scaling) * Game::Resolution::Y
				},
				{ 0.0f,0.0f },
				0.0f,
				Color(255, 255, 255, (uint8_t)255*std::abs(std::sin(_glintAnimTimer / 200)))
			);
		}

		h += (_font->MeasureHeight(Items[i], _scaling) + 0.01f) * Game::Resolution::Y;
	}

	if(_idElemHov != -1) _glintAnimTimer += 200 * dt;
	else _glintAnimTimer = 0.0f;
}
