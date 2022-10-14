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

	_levelTime = Textbox(Resources::TxtboxRectangle, &Resources::NumericLevelHudFont, "360", Game::ScreenRec({ 0.6f,0.69f,0.3f,0.04f }), 5, 10);

	_levelSettingsTxs[0] = Resources::LoadTextureChkF("Data\\Editor\\Param_PlayerGravity.png");
	_levelSettingsBtns[0] = ShinyButton(_levelSettingsTxs[0], _tGlint, Game::ScreenRec({ 0.3f, 0.35f, 0.1f, 0.1f }), [this]()
		{
			_currentSettingId = 0;
		}
	);

	_levelSettingsTxs[1] = Resources::LoadTextureChkF("Data\\Editor\\Param_EnemySpeed.png");
	_levelSettingsBtns[1] = ShinyButton(_levelSettingsTxs[1], _tGlint, Game::ScreenRec({ 0.41f,0.35f,0.1f,0.1f }), [this]()
		{
			_currentSettingId = 1;
		}
	);

	_levelSettingsTxs[2] = Resources::LoadTextureChkF("Data\\Editor\\Param_BillBlasterRoF.png");
	_levelSettingsBtns[2] = ShinyButton(_levelSettingsTxs[2], _tGlint, Game::ScreenRec({ 0.52f,0.35f,0.1f,0.1f }), [this]()
		{
			_currentSettingId = 2;
		}
	);

	_levelSettingsTxs[3] = Resources::LoadTextureChkF("Data\\Editor\\Param_ProjectileSpeed.png");
	_levelSettingsBtns[3] = ShinyButton(_levelSettingsTxs[3], _tGlint, Game::ScreenRec({ 0.63f,0.35f,0.1f,0.1f }), [this]()
		{
			_currentSettingId = 3;
		}
	);

	_levelSettingsTxs[4] = Resources::LoadTextureChkF("Data\\Editor\\Param_PinkFlowerFireballsCount.png");
	_levelSettingsBtns[4] = ShinyButton(_levelSettingsTxs[4], _tGlint, Game::ScreenRec({ 0.3f,0.46f,0.1f,0.1f }), [this]()
		{
			_currentSettingId = 4;
		}
	);

	_levelSettingsTxs[5] = Resources::LoadTextureChkF("Data\\Editor\\Param_PlantSpeed.png");
	_levelSettingsBtns[5] = ShinyButton(_levelSettingsTxs[5], _tGlint, Game::ScreenRec({ 0.41f,0.46f,0.1f,0.1f }), [this]()
		{
			_currentSettingId = 5;
		}
	);

	_levelSettingsTxs[6] = Resources::LoadTextureChkF("Data\\Editor\\Param_PodoboosSpeed.png");
	_levelSettingsBtns[6] = ShinyButton(_levelSettingsTxs[6], _tGlint, Game::ScreenRec({ 0.52f,0.46f,0.1f,0.1f }), [this]()
		{
			_currentSettingId = 6;
		}
	);

	_levelSettingsTxs[7] = Resources::LoadTextureChkF("Data\\Editor\\Param_LakituAttackSpeed.png");
	_levelSettingsBtns[7] = ShinyButton(_levelSettingsTxs[7], _tGlint, Game::ScreenRec({ 0.63f,0.46f,0.1f,0.1f }), [this]()
		{
			_currentSettingId = 7;
		}
	);

	_levelSettingsTxs[8] = Resources::LoadTextureChkF("Data\\Editor\\Param_FallingSpikes.png");
	_levelSettingsBtns[8] = ShinyButton(_levelSettingsTxs[8], _tGlint, Game::ScreenRec({ 0.3f,0.57f,0.1f,0.1f }), [this]()
		{
			_currentSettingId = 8;
		}
	);

	_levelSettingsTxs[9] = Resources::LoadTextureChkF("Data\\Editor\\Param_PlatformSpeed.png");
	_levelSettingsBtns[9] = ShinyButton(_levelSettingsTxs[9], _tGlint, Game::ScreenRec({ 0.41f,0.57f,0.1f,0.1f }), [this]()
		{
			_currentSettingId = 9;
		}
	);

	_levelSettingsTxs[10] = Resources::LoadTextureChkF("Data\\Editor\\Param_FishDensity.png");
	_levelSettingsBtns[10] = ShinyButton(_levelSettingsTxs[10], _tGlint, Game::ScreenRec({ 0.52f,0.57f,0.1f,0.1f }), [this]()
		{
			_currentSettingId = 10;
		}
	);

	_levelSettingsTxs[11] = Resources::LoadTextureChkF("Data\\Editor\\Param_BroHammerThrowRate.png");
	_levelSettingsBtns[11] = ShinyButton(_levelSettingsTxs[11], _tGlint, Game::ScreenRec({ 0.63,0.57f,0.1f,0.1f }), [this]()
		{
			_currentSettingId = 11;
		}
	);

	_levelSettingsSliders[0] = Slider(Resources::SliderBar, Resources::SliderBox, Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }), 1, 10, 6); //gravity
	_levelSettingsSliders[0].OnValueChange = [](double old, double newVal)
	{
		Game::CurrentLevel.Gravity = newVal;
	};

	_levelSettingsSliders[1] = Slider(Resources::SliderBar, Resources::SliderBox, Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }), 1, 10, 5); //enemy speed
	_levelSettingsSliders[1].OnValueChange = [](double old, double newV)
	{
		Game::CurrentLevel.EnemySpeed = newV;
	};

	_levelSettingsSliders[2] = Slider(Resources::SliderBar, Resources::SliderBox, Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }), 1, 10, 5); //bill rof
	_levelSettingsSliders[2].OnValueChange = [](double old, double newV)
	{
		Game::CurrentLevel.BillBlasterROF = newV;
	};

	_levelSettingsSliders[3] = Slider(Resources::SliderBar, Resources::SliderBox, Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }), 1, 10, 5); //bill mov speed
	_levelSettingsSliders[3].OnValueChange = [](double old, double newV)
	{
		Game::CurrentLevel.BillBulletSpeed = newV;
	};

	_levelSettingsSliders[4] = Slider(Resources::SliderBar, Resources::SliderBox, Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }), 1, 20, 3); //pink flower fireballs
	_levelSettingsSliders[4].OnValueChange = [](double old, double newV)
	{
		Game::CurrentLevel.PinkFlowerFireballs = newV;
	};

	_levelSettingsSliders[5] = Slider(Resources::SliderBar, Resources::SliderBox, Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }), 1, 10, 5); //plant hiding timespan
	_levelSettingsSliders[5].OnValueChange = [](double old, double newV)
	{
		Game::CurrentLevel.PlantSpeed = newV;
	};

	_levelSettingsSliders[6] = Slider(Resources::SliderBar, Resources::SliderBox, Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }), 1, 10, 5); //podoboos frequency
	_levelSettingsSliders[6].OnValueChange = [](double old, double newV)
	{
		Game::CurrentLevel.PodoboosSpeed = newV;
	};

	_levelSettingsSliders[7] = Slider(Resources::SliderBar, Resources::SliderBox, Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }), 1, 7, 5); //lakitu attack speed
	_levelSettingsSliders[7].OnValueChange = [](double old, double newV)
	{
		Game::CurrentLevel.LakituAttackSpeed = newV;
	};

	_levelSettingsSliders[8] = Slider(Resources::SliderBar, Resources::SliderBox, Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }), 0, 20, 0); //falling spikes
	_levelSettingsSliders[8].OnValueChange = [](double old, double newV)
	{
		Game::CurrentLevel.FallingSpikesSpeed = newV;
	};

	_levelSettingsSliders[9] = Slider(Resources::SliderBar, Resources::SliderBox, Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }), 1, 3, 1); //platform speed
	_levelSettingsSliders[9].OnValueChange = [](double oldV, double newV)
	{
		Game::CurrentLevel.PlatformSpeed = newV;
	};

	_levelSettingsSliders[10] = Slider(Resources::SliderBar, Resources::SliderBox, Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }), 0, 5, 1); //fish density
	_levelSettingsSliders[10].OnValueChange = [](double o, double n)
	{
		Game::CurrentLevel.FishDensity = n;
	};

	_levelSettingsSliders[11] = Slider(Resources::SliderBar, Resources::SliderBox, Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }), 1, 5, 2); //bro hammer throw rate
	_levelSettingsSliders[11].OnValueChange = [](double o, double n)
	{
		Game::CurrentLevel.BroHammerAttackRate = n;
	};
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
					case 1:
					{
						_levelSettingsSliders[_currentSettingId].Update(ms, dt);

						for(size_t i = 0; i < 12; i++)
						{
							_levelSettingsBtns[i].Update(ms, dt);
						}
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
					case 1:
					{
						const char *settingNames[12] = {
							"Player gravity",
							"Enemy speed",
							"Bill Blaster rate of fire",
							"Bullet Bill speed",
							"Pink plant fireball count",
							"Plant hiding frequency",
							"Podoboos rising rate",
							"Lakitu attack rate",
							"Falling spike floor speed",
							"Moving platform speed",
							"Fish density",
							"Bro's attack rate"
						};

						Resources::LevelHudFont.Draw(settingNames[_currentSettingId],{0.3f, 0.19f },{0.025f,0.025f},0.001f);

						_levelSettingsSliders[_currentSettingId].Draw(dt);
						Resources::LevelHudFont.Draw(std::to_string(_levelSettingsSliders[_currentSettingId].GetValue<int>()), {0.61f,0.26f}, { 0.025f,0.025f }, 0.001f);

						for(size_t i = 0; i < 12; i++)
							_levelSettingsBtns[i].Draw(dt);
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

	for(size_t i = 0; i < 12; i++) UnloadTexture(_levelSettingsTxs[i]);
}