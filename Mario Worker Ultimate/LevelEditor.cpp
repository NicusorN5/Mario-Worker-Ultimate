#include "LevelEditor.hpp"

LevelEditor* LevelEditor::_singleton;

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

LevelEditor::LevelEditor()
{
	LevelEditor::_singleton = this;
}

void LevelEditor::LoadContent()
{
	_square = Resources::LoadTextureChkF("Data\\Editor\\Square.png");

	levelPx = Game::CurrentLevel.Size.x * Game::Resolution::X / 20.0f;
	levelPy = Game::CurrentLevel.Size.y * Game::Resolution::Y / 15.0f;

	W_selectItem = Resources::LoadTextureChkF("Data\\Editor\\Wnd_SelectItem.png");

	_tBlocksTabHov = Resources::LoadTextureChkF("Data\\Editor\\Editor_BlocksTab.png");
	_tBlocksTabUnhov = Resources::LoadTextureChkF("Data\\Editor\\Editor_BlocksTabClosed.png");
	_blocksBtn = TabButton(_tBlocksTabUnhov, _tBlocksTabHov, 
		Game::ScreenRec({0.255f,0.0975f,0.05f,0.05f}),
		Game::ScreenRec({0.255f,0.0975f,0.1f,0.05f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(0);
		}
	);

	_tEnemiesTabHov = Resources::LoadTextureChkF("Data\\Editor\\Editor_EnemiesTab.png");
	_tEnemiesTabUnhov = Resources::LoadTextureChkF("Data\\Editor\\Editor_EnemiesTabClosed.png");
	_enemiesBtn = TabButton(_tEnemiesTabUnhov,_tEnemiesTabHov,
		Game::ScreenRec({0.305f,0.0975f,0.05f,0.05f}),
		Game::ScreenRec({0.305f,0.0975f,0.1f,0.05f}),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(1);
		}	
	);

	_tBonusTabHov = Resources::LoadTextureChkF("Data\\Editor\\Editor_BonusTab.png");
	_tBonusTabUnhov = Resources::LoadTextureChkF("Data\\Editor\\Editor_BonusTabClosed.png");
	_bonusBtn = TabButton(_tBonusTabUnhov, _tBonusTabHov,
		Game::ScreenRec({ 0.355f,0.0975f,0.05f,0.05f }),
		Game::ScreenRec({ 0.355f,0.0975f,0.1f,0.05f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(2);
		}
	);

	_tMarksTabHov = Resources::LoadTextureChkF("Data\\Editor\\Editor_MarksTab.png");
	_tMarksTabUnhov = Resources::LoadTextureChkF("Data\\Editor\\Editor_MarksTabClosed.png");
	_marksBtn = TabButton(_tMarksTabUnhov, _tMarksTabHov,
		Game::ScreenRec({ 0.405f,0.0975f,0.05f,0.05f }),
		Game::ScreenRec({ 0.405f,0.0975f,0.1f,0.05f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(3);
		}
	);

	_tSceneryTabHov = Resources::LoadTextureChkF("Data\\Editor\\Editor_SceneryTab.png");
	_tSceneryTabUnhov = Resources::LoadTextureChkF("Data\\Editor\\Editor_SceneryTabClosed.png");
	_sceneryBtn = TabButton(_tSceneryTabUnhov, _tSceneryTabHov,
		Game::ScreenRec({0.455f,0.0975f,0.05f,0.05f}),
		Game::ScreenRec({0.455f,0.0975f,0.1f,0.05f}),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(4);
		}
	);

	_tSettingsTabHov = Resources::LoadTextureChkF("Data\\Editor\\Editor_SettingsTab.png");
	_tSettingsTabUnhov = Resources::LoadTextureChkF("Data\\Editor\\Editor_SettingsTabClosed.png");
	_settingsBtn = TabButton(_tSettingsTabUnhov, _tSettingsTabHov,
		Game::ScreenRec({ 0.505f,0.0975f,0.05f,0.05f }),
		Game::ScreenRec({ 0.505f,0.0975f,0.1f,0.05f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(5);
		}
	);

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
		//moving buttons to not overlap when hovered
		if(_blocksBtn.Raised())
		{
			_enemiesBtn.SetXOffset(0.05f);
			_bonusBtn.SetXOffset(0.05f);
			_marksBtn.SetXOffset(0.05f);
			_sceneryBtn.SetXOffset(0.05f);
			_settingsBtn.SetXOffset(0.05f);
		}
		else if(_enemiesBtn.Raised())
		{
			_enemiesBtn.SetXOffset(0);
			_bonusBtn.SetXOffset(0.05f);
			_marksBtn.SetXOffset(0.05f);
			_sceneryBtn.SetXOffset(0.05f);
			_settingsBtn.SetXOffset(0.05f);
		}
		else if(_bonusBtn.Raised())
		{
			_marksBtn.SetXOffset(0.05f);
			_sceneryBtn.SetXOffset(0.05f);
			_settingsBtn.SetXOffset(0.05f);
		}
		else if(_marksBtn.Raised())
		{
			_sceneryBtn.SetXOffset(0.05f);
			_settingsBtn.SetXOffset(0.05f);
		}
		else
		{
			_enemiesBtn.SetXOffset(0);
			_bonusBtn.SetXOffset(0);
			_marksBtn.SetXOffset(0);
			_sceneryBtn.SetXOffset(0);
			_settingsBtn.SetXOffset(0);
		}

		if(_sceneryBtn.Raised())
			_settingsBtn.SetXOffset(0.05f);
		else
		{

		}
		//updating tab buttons logic
		_blocksBtn.Update(ms, dt);
		_enemiesBtn.Update(ms, dt);
		_bonusBtn.Update(ms, dt);
		_marksBtn.Update(ms, dt);
		_sceneryBtn.Update(ms, dt);
		_settingsBtn.Update(ms, dt);
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
		_blocksBtn.Draw(dt);
		_enemiesBtn.Draw(dt);
		_bonusBtn.Draw(dt);
		_marksBtn.Draw(dt);
		_sceneryBtn.Draw(dt);
		_settingsBtn.Draw(dt);
	}
}

LevelEditor* LevelEditor::GetSingleton()
{
	return _singleton;
}

void LevelEditor::SetItemCategory(int id)
{
	categoryId = id;
}

void LevelEditor::SetSubCategory(int id)
{
	subCategoryId = id;
}

LevelEditor::~LevelEditor()
{
	UnloadTexture(_square);
}
