#include "LevelEditor.hpp"

Rectangle LevelEditor::calculateWorldTransformation(Rectangle normScreen)
{
	return { normScreen.x - cameraPosition.x,
		normScreen.y - cameraPosition.y,
		normScreen.width, normScreen.height };
}

Rectangle LevelEditor::calculateTileTransformation(Rectangle normScreen)
{
	return { normScreen.x - ((int)cameraPosition.x % 641),
		normScreen.y - ((int)cameraPosition.y % 481),
		normScreen.width + normScreen.x / 20 , normScreen.height + normScreen.x / 15 };
}

void LevelEditor::LoadContent()
{
	_square = Resources::LoadTextureChkF("Data\\Editor\\Square.png");

	levelPx = Game::CurrentLevel.Size.x * Game::Resolution::X / 20.0f;
	levelPy = Game::CurrentLevel.Size.y * Game::Resolution::Y / 15.0f;

	W_selectItem = Resources::LoadTextureChkF("Data\\Editor\\Wnd_SelectItem.png");
}

void LevelEditor::Update(float dt, MouseState* ms, ControllerState* cs)
{
	//camera movment stuff
	float movmentSpeed = 500 * dt * (cs->Shift ? 5 : 1);

	if(cs->Up) cameraPosition.y -= movmentSpeed;
	if(cs->Down) cameraPosition.y += movmentSpeed;

	if(cs->Left) cameraPosition.x -= movmentSpeed;
	if(cs->Right) cameraPosition.x += movmentSpeed;

	cameraPosition.x = std::clamp<float>(cameraPosition.x, 0.0f, levelPx);
	cameraPosition.y = std::clamp<float>(cameraPosition.y, 0.0f, levelPy);

	//allowing the player to select a block

	if(!_previousSpacePress && !_showElements && cs->Space)
		_showElements = true;
	else if(_showElements)
	{

		if(!_previousSpacePress && cs->Space) _showElements = false;
	}
	
	_previousSpacePress = cs->Space;
}

void LevelEditor::Draw(float dt)
{
	Game::CurrentLevel.LvlBackround.Draw(cameraPosition, Game::CurrentLevel.Size);
	
	DrawTexturePro(_square, { 0,0,2560,1920 }, calculateTileTransformation(Game::ScreenRec({ 0,0,2,2 })), { 0,0 }, 0.0f, WHITE);
	DrawTexturePro(Resources::Goomba1, { 0,0,31,32 }, calculateWorldTransformation(Game::ScreenRec({ 0,0,0.05,1/15.0f })), { 0,0 }, 0.0f, WHITE); // <-- test goomba

	if(_showElements)
	{
		DrawTexturePro(W_selectItem, { 0,0,800,600 }, Game::ScreenRec({ 0,0,1,1 }), { 0,0 }, 0.0f, WHITE);
	}
}

LevelEditor::~LevelEditor()
{
	UnloadTexture(_square);
}
