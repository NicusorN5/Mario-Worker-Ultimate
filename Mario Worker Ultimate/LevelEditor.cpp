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
	return { normScreen.x - ((int)cameraPosition.x % (Game::Resolution::X)),
		normScreen.y - ((int)cameraPosition.y % (Game::Resolution::Y)),
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

	_tabTexturesHovered[0] = Resources::LoadTextureChkF("Data\\Editor\\Editor_BlocksTab.png");
	_tabTexturesUnhovered[0] = Resources::LoadTextureChkF("Data\\Editor\\Editor_BlocksTabClosed.png");
	_tabButtons[0] = TabButton(_tabTexturesUnhovered[0], _tabTexturesHovered[0],
		Game::ScreenRec({ 0.257f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.257f,0.067f,0.15f,0.075f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(0);
		}
	);

	_tabTexturesHovered[1] = Resources::LoadTextureChkF("Data\\Editor\\Editor_EnemiesTab.png");
	_tabTexturesUnhovered[1] = Resources::LoadTextureChkF("Data\\Editor\\Editor_EnemiesTabClosed.png");
	_tabButtons[1] = TabButton(_tabTexturesUnhovered[1], _tabTexturesHovered[1],
		Game::ScreenRec({ 0.333f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.333f,0.067f,0.15f,0.075f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(1);
		}
	);

	_tabTexturesHovered[2] = Resources::LoadTextureChkF("Data\\Editor\\Editor_BonusTab.png");
	_tabTexturesUnhovered[2] = Resources::LoadTextureChkF("Data\\Editor\\Editor_BonusTabClosed.png");
	_tabButtons[2] = TabButton(_tabTexturesUnhovered[2], _tabTexturesHovered[2],
		Game::ScreenRec({ 0.409f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.409f,0.067f,0.15f,0.075f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(2);
		}
	);

	_tabTexturesHovered[3] = Resources::LoadTextureChkF("Data\\Editor\\Editor_MarksTab.png");
	_tabTexturesUnhovered[3] = Resources::LoadTextureChkF("Data\\Editor\\Editor_MarksTabClosed.png");
	_tabButtons[3] = TabButton(_tabTexturesUnhovered[3], _tabTexturesHovered[3],
		Game::ScreenRec({ 0.485f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.485f,0.067f,0.15f,0.075f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(3);
		}
	);

	_tabTexturesHovered[4] = Resources::LoadTextureChkF("Data\\Editor\\Editor_SceneryTab.png");
	_tabTexturesUnhovered[4] = Resources::LoadTextureChkF("Data\\Editor\\Editor_SceneryTabClosed.png");
	_tabButtons[4] = TabButton(_tabTexturesUnhovered[4], _tabTexturesHovered[4],
		Game::ScreenRec({ 0.561f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.561f,0.067f,0.15f,0.075f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(4);
		}
	);

	_tabTexturesHovered[5] = Resources::LoadTextureChkF("Data\\Editor\\Editor_SettingsTab.png");
	_tabTexturesUnhovered[5] = Resources::LoadTextureChkF("Data\\Editor\\Editor_SettingsTabClosed.png");
	_tabButtons[5] = TabButton(_tabTexturesUnhovered[5], _tabTexturesHovered[5],
		Game::ScreenRec({ 0.637f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.637f,0.067f,0.15f,0.075f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(5);
		}
	);

	std::function<void()> ssc0 = []() -> void
	{
		LevelEditor::GetSingleton()->SetSubCategory(0);
	};
	std::function<void()> ssc1 = []() -> void
	{
		LevelEditor::GetSingleton()->SetSubCategory(1);
	};
	std::function<void()> ssc2 = []() -> void
	{
		LevelEditor::GetSingleton()->SetSubCategory(2);
	};
	std::function<void()> ssc3 = []() -> void
	{
		LevelEditor::GetSingleton()->SetSubCategory(3);
	};
	std::function<void()> ssc4 = []() -> void
	{
		LevelEditor::GetSingleton()->SetSubCategory(4);
	};
	std::function<void()> ssc5 = []() -> void
	{
		LevelEditor::GetSingleton()->SetSubCategory(5);
	};
	std::function<void()> ssc6 = []() -> void
	{
		LevelEditor::GetSingleton()->SetSubCategory(6);
	};
	std::function<void()> ssc7 = []() -> void
	{
		LevelEditor::GetSingleton()->SetSubCategory(7);
	};

	//blocks categories
	_blocksBtnTextures[0] = Resources::LoadTextureChkF("Data\\Editor\\sb_Terrain.png");
	_blocksButtons[0] = ShinyButton(_blocksBtnTextures[0], _tGlint, Game::ScreenRec({0.095f,0.148f,0.15f,0.075f}), ssc0);

	_blocksBtnTextures[1] = Resources::LoadTextureChkF("Data\\Editor\\sb_Blocks.png");
	_blocksButtons[1] = ShinyButton(_blocksBtnTextures[1], _tGlint,Game::ScreenRec({ 0.095f,0.225f,0.15f,0.075f }),ssc1);

	_blocksBtnTextures[2] = Resources::LoadTextureChkF("Data\\Editor\\sb_Tank.png");
	_blocksButtons[2] = ShinyButton(_blocksBtnTextures[2], _tGlint,Game::ScreenRec({ 0.095f,0.302f,0.15f,0.075f }),ssc2);

	_blocksBtnTextures[3] = Resources::LoadTextureChkF("Data\\Editor\\sb_Pipes.png");
	_blocksButtons[3] = ShinyButton(_blocksBtnTextures[3], _tGlint,Game::ScreenRec({ 0.095f,0.379f,0.15f,0.075f }),ssc3);

	_blocksBtnTextures[4] = Resources::LoadTextureChkF("Data\\Editor\\sb_CustomBlocks.png");
	_blocksButtons[4] = ShinyButton(_blocksBtnTextures[4], _tGlint, Game::ScreenRec({ 0.095f,0.456f,0.15f,0.075f }),ssc4);

	//enemies categories
	_enemiesBtnTextures[0] = Resources::LoadTextureChkF("Data\\Editor\\sb_Enemies.png");
	_enemiesButtons[0] = ShinyButton(_enemiesBtnTextures[0], _tGlint, Game::ScreenRec({0.095f,0.148f,0.15f,0.075f}), ssc0);

	_enemiesBtnTextures[1] = Resources::LoadTextureChkF("Data\\Editor\\sb_Hazards.png");
	_enemiesButtons[1] = ShinyButton(_enemiesBtnTextures[1], _tGlint, Game::ScreenRec({0.095f,0.225f,0.15f,0.075f}), ssc1);

	_enemiesBtnTextures[2] = Resources::LoadTextureChkF("Data\\Editor\\sb_Clones.png");
	_enemiesButtons[2] = ShinyButton(_enemiesBtnTextures[2], _tGlint, Game::ScreenRec({0.095f,0.302f,0.15f,0.075f}), ssc2);

	_enemiesBtnTextures[3] = Resources::LoadTextureChkF("Data\\Editor\\sb_Bosses.png");
	_enemiesButtons[3] = ShinyButton(_enemiesBtnTextures[3], _tGlint, Game::ScreenRec({0.095f,0.379f,0.15f,0.075f}), ssc3);

	_enemiesBtnTextures[4] = Resources::LoadTextureChkF("Data\\Editor\\sb_CustomEnemies.png");
	_enemiesButtons[4] = ShinyButton(_enemiesBtnTextures[4], _tGlint, Game::ScreenRec({0.095f,0.456f,0.15f,0.075f}), ssc4);

	_enemiesBtnTextures[5] = Resources::LoadTextureChkF("Data\\Editor\\sb_CustomBosses.png");
	_enemiesButtons[5] = ShinyButton(_enemiesBtnTextures[5], _tGlint, Game::ScreenRec({0.095f,0.533f,0.15f,0.075f}), ssc5);

	//bonuses categories
	_bonusesBtnTextures[0] = Resources::LoadTextureChkF("Data\\Editor\\sb_Bonuses.png");
	_bonusesButtons[0] = ShinyButton(_bonusesBtnTextures[0], _tGlint, Game::ScreenRec({0.095f,0.148f,0.15f,0.075f}), ssc0);

	_bonusesBtnTextures[1] = Resources::LoadTextureChkF("Data\\Editor\\sb_CustomBonuses.png");
	_bonusesButtons[1] = ShinyButton(_bonusesBtnTextures[1], _tGlint, Game::ScreenRec({ 0.095f,0.225f,0.15f,0.075f }), ssc1);

	//marks
	_marksBtnTextures[0] = Resources::LoadTextureChkF("Data\\Editor\\sb_LevelProgress.png");
	_marksButtons[0] = ShinyButton(_marksBtnTextures[0], _tGlint, Game::ScreenRec({0.095f,0.148f,0.15f,0.075f}), ssc0);

	_marksBtnTextures[1] = Resources::LoadTextureChkF("Data\\Editor\\sb_Platforms.png");
	_marksButtons[1] = ShinyButton(_marksBtnTextures[1],_tGlint, Game::ScreenRec({ 0.095f,0.225f,0.15f,0.075f }), ssc1);

	_marksBtnTextures[2] = Resources::LoadTextureChkF("Data\\Editor\\sb_Marks.png");
	_marksButtons[2] = ShinyButton(_marksBtnTextures[2],_tGlint, Game::ScreenRec({ 0.095f,0.302f,0.15f,0.075f }), ssc2);

	_marksBtnTextures[3] = Resources::LoadTextureChkF("Data\\Editor\\sb_Pipes.png");
	_marksButtons[3] = ShinyButton(_marksBtnTextures[3],_tGlint, Game::ScreenRec({ 0.095f,0.379f,0.15f,0.075f }), ssc3);

	_marksBtnTextures[4] = Resources::LoadTextureChkF("Data\\Editor\\sb_Scripts.png");
	_marksButtons[4] = ShinyButton(_marksBtnTextures[4],_tGlint, Game::ScreenRec({ 0.095f,0.456f,0.15f,0.075f }), ssc4);

	//scenery
	_sceneryBtnTextures[0] = Resources::LoadTextureChkF("Data\\Editor\\sb_Overworld.png");
	_sceneryButtons[0] = ShinyButton(_sceneryBtnTextures[0], _tGlint, Game::ScreenRec({0.095f,0.148f,0.15f,0.075f}), ssc0);

	_sceneryBtnTextures[1] = Resources::LoadTextureChkF("Data\\Editor\\sb_Underground.png");
	_sceneryButtons[1] = ShinyButton(_sceneryBtnTextures[1], _tGlint, Game::ScreenRec({ 0.095f,0.225f,0.15f,0.075f }), ssc1);

	_sceneryBtnTextures[2] = Resources::LoadTextureChkF("Data\\Editor\\sb_Starland.png");
	_sceneryButtons[2] = ShinyButton(_sceneryBtnTextures[2],_tGlint, Game::ScreenRec({ 0.095f,0.302f,0.15f,0.075f }), ssc2);

	_sceneryBtnTextures[3] = Resources::LoadTextureChkF("Data\\Editor\\sb_Snowland.png");
	_sceneryButtons[3] = ShinyButton(_sceneryBtnTextures[3],_tGlint, Game::ScreenRec({ 0.095f,0.379f,0.15f,0.075f }), ssc3);

	_sceneryBtnTextures[4] = Resources::LoadTextureChkF("Data\\Editor\\sb_Darkland.png");
	_sceneryButtons[4] = ShinyButton(_sceneryBtnTextures[4], _tGlint, Game::ScreenRec({ 0.095f,0.456f,0.15f,0.075f }), ssc4);

	_sceneryBtnTextures[5] = Resources::LoadTextureChkF("Data\\Editor\\sb_Sunset.png");
	_sceneryButtons[5] = ShinyButton(_sceneryBtnTextures[5], _tGlint, Game::ScreenRec({ 0.095f,0.533f,0.15f,0.075f }), ssc5);

	_sceneryBtnTextures[6] = Resources::LoadTextureChkF("Data\\Editor\\sb_Desert.png");
	_sceneryButtons[6] = ShinyButton(_sceneryBtnTextures[6], _tGlint, Game::ScreenRec({ 0.095f,0.610f,0.15f,0.075f }),ssc6);

	_sceneryBtnTextures[7] = Resources::LoadTextureChkF("Data\\Editor\\sb_Castle.png");
	_sceneryButtons[7] = ShinyButton(_sceneryBtnTextures[7],_tGlint, Game::ScreenRec({ 0.095f,0.687f,0.15f,0.075f }),ssc7);

	_sceneryBtnTextures[8] = Resources::LoadTextureChkF("Data\\Editor\\sb_CustomScenery.png");
	_sceneryButtons[8] = ShinyButton(_sceneryBtnTextures[8],_tGlint, Game::ScreenRec({ 0.095f,0.687f,0.15f,0.075f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetSubCategory(8);
		}
	);

	_squareMouse = Resources::LoadTextureChkF("Data\\Editor\\CurrentTileSquare.png");

	_settingsBtnTextures[0] = Resources::LoadTextureChkF("Data\\Editor\\sb_LevelInfo.png");
	_settingsButtons[0] = ShinyButton(_settingsBtnTextures[0],_tGlint, Game::ScreenRec({ 0.095f,0.148f,0.15f,0.075f }), ssc0);

	_settingsBtnTextures[1] = Resources::LoadTextureChkF("Data\\Editor\\sb_Settings.png");
	_settingsButtons[1] = ShinyButton(_settingsBtnTextures[1], _tGlint, Game::ScreenRec({ 0.095f,0.225f,0.15f,0.075f }), ssc1);

	_settingsBtnTextures[2] = Resources::LoadTextureChkF("Data\\Editor\\sb_Backgrounds.png");
	_settingsButtons[2] = ShinyButton(_settingsBtnTextures[2], _tGlint, Game::ScreenRec({ 0.095f,0.302f,0.15f,0.075f }), ssc2);

	_settingsBtnTextures[3] = Resources::LoadTextureChkF("Data\\Editor\\sb_Music.png");
	_settingsButtons[3] = ShinyButton(_settingsBtnTextures[3], _tGlint, Game::ScreenRec({ 0.095f,0.379f,0.15f,0.075f }), ssc3);

	_settingsBtnTextures[4] = Resources::LoadTextureChkF("Data\\Editor\\sb_Fluids.png");
	_settingsButtons[4] = ShinyButton(_settingsBtnTextures[4], _tGlint, Game::ScreenRec({ 0.095f,0.456f,0.15f,0.075f }), ssc4);

	_settingsBtnTextures[5] = Resources::LoadTextureChkF("Data\\Editor\\sb_BossSettings.png");
	_settingsButtons[5] = ShinyButton(_settingsBtnTextures[5], _tGlint, Game::ScreenRec({ 0.095f,0.533f,0.15f,0.075f }), ssc5);

	_settingsBtnTextures[6] = Resources::LoadTextureChkF("Data\\Editor\\sb_Effects.png");
	_settingsButtons[6] = ShinyButton(_settingsBtnTextures[6], _tGlint, Game::ScreenRec({ 0.095f,0.610f,0.15f,0.075f }), ssc6);

	_settingsBtnTextures[7] = Resources::LoadTextureChkF("Data\\Editor\\sb_FileIO.png");
	_settingsButtons[7] = ShinyButton(_settingsBtnTextures[7], _tGlint, Game::ScreenRec({ 0.095f,0.687f,0.15f,0.075f }), ssc7);

	_levelNameTbs[0] = Textbox(Resources::TxtboxRectangle, &Resources::LevelHudFont, "WORLD", Game::ScreenRec({ 0.6f,0.165f,0.3f,0.04f }), 10, 10);
	_levelNameTbs[1] = Textbox(Resources::TxtboxRectangle, &Resources::LevelHudFont, "1-1", Game::ScreenRec({ 0.6f,0.22f,0.3f,0.04f }), 10, 10);
	
	_authorTb = Textbox(Resources::TxtboxRectangle, &Resources::LevelHudFont, "YOUR NAME", Game::ScreenRec({ 0.6f,0.3f,0.3f,0.04f }), 10, 10);
	_emailTb = Textbox(Resources::TxtboxRectangle, &Resources::LevelHudFont, "USERNAME[EXAMPLE.COM", Game::ScreenRec({ 0.6f,0.375f,0.3f,0.04f }), 50, 10);
	_websiteTb = Textbox(Resources::TxtboxRectangle, &Resources::LevelHudFont, "EXAMPLE.COM", Game::ScreenRec({ 0.6f,0.45f,0.3f,0.04f }), 50, 10);

	_levelWidthSl = Slider(Resources::SliderBar, Resources::SliderBox, Game::ScreenRec({0.6f,0.52f,0.3f,0.04f}), 20, 400, 60);
	_levelWidthSl.OnValueChange = [this](double oldVlaue, double newValue)
	{
		Game::CurrentLevel.Size.x = newValue;
		levelPx = Game::CurrentLevel.Size.x * Game::Resolution::X / 20.0f;
	};

	_levelHeightSl = Slider(Resources::SliderBar, Resources::SliderBox, Game::ScreenRec({ 0.6f,0.59f,0.3f,0.04f }), 15, 225, 30);
	_levelHeightSl.OnValueChange = [this](double oldValue, double newValue)
	{
		Game::CurrentLevel.Size.y = newValue;
		levelPy = Game::CurrentLevel.Size.y * Game::Resolution::Y / 15.0f;
	};

	_levelTime = Textbox(Resources::TxtboxRectangle, &Resources::NumericLevelHudFont, "360", Game::ScreenRec({ 0.6f,0.66f,0.3f,0.04f }), 5, 10);
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
		//FIXME: buttons overlapping when hovering multiple buttons in a horizontal mouse movement

		bool _anyBtnHovered = false;
		for(size_t i = 0; i < 6; i++)
		{
			if(_tabButtons[i].IsHovered())
			{
				for(size_t j = i + 1; j < 6; j++)
				{
					_tabButtons[j].SetXOffset(0.075f);
					_anyBtnHovered = true;
				}
			}
		}
		for(size_t i = 0; i < 6; i++)
		{
			if(!_anyBtnHovered) _tabButtons[i].SetXOffset(0);
			_tabButtons[i].Update(ms, dt);
		}

		bool usingTxtbox = false;

		switch(categoryId)
		{
			case 0:
			{
				for(size_t i = 0; i < 5; i++) _blocksButtons[i].Update(ms, dt);
				switch(subCategoryId)
				{
					default:break;
				}
				break;
			}
			case 1:
			{
				for(size_t i = 0; i < 6; i++) _enemiesButtons[i].Update(ms, dt);
				switch(subCategoryId)
				{
					default:break;
				}
				break;
			}
			case 2:
			{
				for(size_t i = 0; i < 2; i++) _bonusesButtons[i].Update(ms, dt);
				switch(subCategoryId)
				{
					default: break;
				}
				break;
			}
			case 3:
			{
				for(size_t i = 0; i < 5; i++) _marksButtons[i].Update(ms, dt);
				switch(subCategoryId)
				{
					default: break;
				}
				break;
			}
			case 4:
			{
				for(size_t i = 0; i < 9; i++) _sceneryButtons[i].Update(ms, dt);
				switch(subCategoryId)
				{
					default: break;
				}
				break;
			}
			case 5:
			{
				for(size_t i = 0; i < 8; i++) _settingsButtons[i].Update(ms, dt);
				switch(subCategoryId)
				{
					case 0:
					{
						for(size_t j = 0; j < 2; j++)
						{
							_levelNameTbs[j].Update(ms, dt);
							if(_levelNameTbs[j].IsFocused()) usingTxtbox = true;
						}

						_authorTb.Update(ms, dt);
						if(_authorTb.IsFocused()) usingTxtbox = true;

						_emailTb.Update(ms, dt);
						if(_emailTb.IsFocused()) usingTxtbox = true;

						_websiteTb.Update(ms, dt);
						if(_websiteTb.IsFocused()) usingTxtbox = true;

						_levelWidthSl.Update(ms, dt);
						_levelHeightSl.Update(ms, dt);
						_levelTime.Update(ms, dt);

						break;
					}
					default:break;
				}
			}
			default:break;
		}

		if(!_previousSpacePress && cs->Space && !usingTxtbox) _showElements = false;
	}

	_previousSpacePress = cs->Space;
	_lastMousePos = { (float)ms->X,(float)ms->Y };
}

void LevelEditor::Draw(float dt)
{
	Game::CurrentLevel.LvlBackround.Draw(cameraPosition, Game::CurrentLevel.Size);
	
	DrawTexturePro(_square, { 0,0,64 * Game::CurrentLevel.Size.x,64 * Game::CurrentLevel.Size.y}, calculateTileTransformation(Game::ScreenRec({0,0,Game::CurrentLevel.Size.x / 20,Game::CurrentLevel.Size.y / 15})), {0,0}, 0.0f, WHITE);
	//debug goomba
	DrawTexturePro(Resources::Goomba1, { 0,0,31,32 }, calculateWorldTransformation(Game::ScreenRec({ 0,0,0.05f,1/15.0f })), { 0,0 }, 0.0f, WHITE); // <-- test goomba

	//TODO: draw level stuff
	Resources::LevelHudFont.Draw(
		"CamPos " + std::to_string(cameraPosition.x) + " " + std::to_string(cameraPosition.y),
		{ 0.01f,0.97f }, 
		{ 0.025f,0.025f },
		0.001f
	);

	if(_showElements)
	{
		DrawTexturePro(W_selectItem, { 0,0,800,600 }, Game::ScreenRec({ 0,0,1,1 }), { 0,0 }, 0.0f, WHITE);
		for(size_t i = 0; i < 6; i++)
		{
			_tabButtons[i].Draw(dt);
		}

		switch(categoryId)
		{
			case 0:
			{
				for(size_t i = 0 ; i < 5; i++) _blocksButtons[i].Draw(dt);
				
				switch(subCategoryId)
				{
					default:break;
				}
				break;
			}
			case 1:
			{
				for(size_t i = 0; i < 6; i++) _enemiesButtons[i].Draw(dt);

				switch(subCategoryId)
				{
					default:break;
				}
				break;
			}
			case 2:
			{
				for(size_t i = 0; i < 2; i++) _bonusesButtons[i].Draw(dt);
				switch(subCategoryId)
				{
					default: break;
				}
				break;
			}
			case 3:
			{
				for(size_t i = 0; i < 5; i++) _marksButtons[i].Draw(dt);
				switch(subCategoryId)
				{
					default: break;
				}
				break;
			}
			case 4:
			{
				for(size_t i = 0; i < 9; i++) _sceneryButtons[i].Draw(dt);
				switch(subCategoryId)
				{
					default: break;
				}
				break;
			}
			case 5:
			{
				for(size_t i = 0; i < 8; i++) _settingsButtons[i].Draw(dt);
				switch(subCategoryId)
				{
					case 0:
					{
						Resources::LevelHudFont.Draw("Level Name", { 0.3f,0.175f }, { 0.025f,0.025f }, 0.001f);
						Resources::LevelHudFont.Draw("Author", { 0.3f,0.3f }, { 0.025f,0.025f }, 0.001f);
						Resources::LevelHudFont.Draw("Email", { 0.3f,0.375f }, { 0.025f,0.025f }, 0.001f);
						Resources::LevelHudFont.Draw("Website", { 0.3f,0.450f }, { 0.025f,0.025f }, 0.001f);
						
						Resources::LevelHudFont.Draw("Level width", { 0.3f,0.525f }, { 0.025f,0.025f }, 0.001f);
						Resources::LevelHudFont.Draw("Level height", { 0.3f,0.6f }, { 0.025f,0.025f }, 0.001f);

						for(size_t j = 0; j < 2; j++) _levelNameTbs[j].Draw(dt);
						_authorTb.Draw(dt);
						_emailTb.Draw(dt);
						_websiteTb.Draw(dt);

						_levelWidthSl.Draw(dt);
						Resources::LevelHudFont.Draw(std::to_string(_levelWidthSl.GetValue<int>()), { 0.91f,0.525f}, { 0.025f,0.025f }, 0.001f);

						_levelHeightSl.Draw(dt);
						Resources::LevelHudFont.Draw(std::to_string(_levelHeightSl.GetValue<int>()), { 0.91f,0.6f }, { 0.025f,0.025f }, 0.001f);

						_levelTime.Draw(dt);
						Resources::LevelHudFont.Draw("Level time", { 0.3f,0.7f }, { 0.025f,0.025f }, 0.001f);
						break;
					}
					default: break;
				}
				break;
			}
			default:break;
		}
	}
	else
	{
		DrawTexturePro(_squareMouse, { 0,0,64,64 }, calculateWorldTransformation(Game::ScreenRec(
			{
				((_lastMousePos.x + cameraPosition.x) - std::fmod(_lastMousePos.x + cameraPosition.x,Game::Resolution::FltX()/20)) / Game::Resolution::FltX() ,
				((_lastMousePos.y + cameraPosition.y) - std::fmod(_lastMousePos.y + cameraPosition.y,Game::Resolution::FltY()/15)) / Game::Resolution::FltY() ,
				0.05f,
				1 / 15.0f 
			}
		)), { 0.0f,0.0f }, 0.0f, WHITE);
	}
}

LevelEditor* LevelEditor::GetSingleton()
{
	return _singleton;
}

void LevelEditor::SetItemCategory(int id)
{
	categoryId = id;
	PlaySound(Resources::LakituDrop[2]);
}

void LevelEditor::SetSubCategory(int id)
{
	subCategoryId = id;
	PlaySound(Resources::LakituDrop[2]);
}

LevelEditor::~LevelEditor()
{
	UnloadTexture(_square);
	UnloadTexture(_squareMouse);
	for(size_t i = 0; i < 5; i++) UnloadTexture(_blocksBtnTextures[i]);
	for(size_t i = 0; i < 6; i++) UnloadTexture(_enemiesBtnTextures[i]);
	for(size_t i = 0; i < 2; i++) UnloadTexture(_bonusesBtnTextures[i]);
	for(size_t i = 0; i < 5; i++) UnloadTexture(_marksBtnTextures[i]);
	for(size_t i = 0; i < 9; i++) UnloadTexture(_sceneryBtnTextures[i]);
	for(size_t i = 0; i < 8; i++) UnloadTexture(_settingsBtnTextures[i]);
}