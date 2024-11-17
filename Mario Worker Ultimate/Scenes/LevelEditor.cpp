#include "LevelEditor.hpp"

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

void LevelEditor::LoadContent()
{
	_square = Texture2DW("Data\\Editor\\Square.png");

	levelPx = Game::CurrentLevel.Size.x * Game::Resolution::X / 20.0f;
	levelPy = Game::CurrentLevel.Size.y * Game::Resolution::Y / 15.0f;

	W_selectItem = Texture2DW("Data\\Editor\\Wnd_SelectItem.png");

	_tGlint = static_cast<Texture2D>(_tGlint);

	_tabTexturesHovered[0] = Texture2DW("Data\\Editor\\Editor_BlocksTab.png");
	_tabTexturesUnhovered[0] = Texture2DW("Data\\Editor\\Editor_BlocksTabClosed.png");
	_tabButtons[0] = TabButton(
		static_cast<Texture2D>(_tabTexturesUnhovered[0]),
		static_cast<Texture2D>(_tabTexturesHovered[0]),
		Game::ScreenRec({ 0.257f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.257f,0.067f,0.15f,0.075f }),
		[this]() -> void
		{
			SetItemCategory(0);
		}
	);

	_tabTexturesHovered[1] = Texture2DW("Data\\Editor\\Editor_EnemiesTab.png");
	_tabTexturesUnhovered[1] = Texture2DW("Data\\Editor\\Editor_EnemiesTabClosed.png");
	_tabButtons[1] = TabButton(
		static_cast<Texture2D>(_tabTexturesUnhovered[1]),
		static_cast<Texture2D>(_tabTexturesHovered[1]),
		Game::ScreenRec({ 0.333f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.333f,0.067f,0.15f,0.075f }),
		[this]() -> void
		{
			SetItemCategory(1);
		}
	);

	_tabTexturesHovered[2] = Texture2DW("Data\\Editor\\Editor_BonusTab.png");
	_tabTexturesUnhovered[2] = Texture2DW("Data\\Editor\\Editor_BonusTabClosed.png");
	_tabButtons[2] = TabButton(
		static_cast<Texture2D>(_tabTexturesUnhovered[2]),
		static_cast<Texture2D>(_tabTexturesHovered[2]),
		Game::ScreenRec({ 0.409f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.409f,0.067f,0.15f,0.075f }),
		[this]() -> void
		{
			SetItemCategory(2);
		}
	);

	_tabTexturesHovered[3] = Texture2DW("Data\\Editor\\Editor_MarksTab.png");
	_tabTexturesUnhovered[3] = Texture2DW("Data\\Editor\\Editor_MarksTabClosed.png");
	_tabButtons[3] = TabButton(
		static_cast<Texture2D>(_tabTexturesUnhovered[3]),
		static_cast<Texture2D>(_tabTexturesHovered[3]),
		Game::ScreenRec({ 0.485f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.485f,0.067f,0.15f,0.075f }),
		[this]() -> void
		{
			SetItemCategory(3);
		}
	);

	_tabTexturesHovered[4] = Texture2DW("Data\\Editor\\Editor_SceneryTab.png");
	_tabTexturesUnhovered[4] = Texture2DW("Data\\Editor\\Editor_SceneryTabClosed.png");
	_tabButtons[4] = TabButton(
		static_cast<Texture2D>(_tabTexturesUnhovered[4]),
		static_cast<Texture2D>(_tabTexturesHovered[4]),
		Game::ScreenRec({ 0.561f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.561f,0.067f,0.15f,0.075f }),
		[this]() -> void
		{
			SetItemCategory(4);
		}
	);

	_tabTexturesHovered[5] = Texture2DW("Data\\Editor\\Editor_SettingsTab.png");
	_tabTexturesUnhovered[5] = Texture2DW("Data\\Editor\\Editor_SettingsTabClosed.png");
	_tabButtons[5] = TabButton(static_cast<Texture2D>(_tabTexturesUnhovered[5]),
		static_cast<Texture2D>(_tabTexturesHovered[5]),
		Game::ScreenRec({ 0.637f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.637f,0.067f,0.15f,0.075f }),
		[this]() -> void
		{
			SetItemCategory(5);
		}
	);

	std::function<void()> ssc0 = [this]() -> void
	{
		SetSubCategory(0);
	};
	std::function<void()> ssc1 = [this]() -> void
	{
		SetSubCategory(1);
	};
	std::function<void()> ssc2 = [this]() -> void
	{
		SetSubCategory(2);
	};
	std::function<void()> ssc3 = [this]() -> void
	{
		SetSubCategory(3);
	};
	std::function<void()> ssc4 = [this]() -> void
	{
		SetSubCategory(4);
	};
	std::function<void()> ssc5 = [this]() -> void
	{
		SetSubCategory(5);
	};
	std::function<void()> ssc6 = [this]() -> void
	{
		SetSubCategory(6);
	};
	std::function<void()> ssc7 = [this]() -> void
	{
		SetSubCategory(7);
	};

	//blocks categories
	_blocksBtnTextures[0] = Texture2DW("Data\\Editor\\sb_Terrain.png");
	_blocksButtons[0] = ShinyButton(
		static_cast<Texture2D>(_blocksBtnTextures[0]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.148f,0.15f,0.075f }),
		ssc0
	);

	_blocksBtnTextures[1] = Texture2DW("Data\\Editor\\sb_Blocks.png");
	_blocksButtons[1] = ShinyButton(
		static_cast<Texture2D>(_blocksBtnTextures[1]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.225f,0.15f,0.075f }),
		ssc1
	);

	_blocksBtnTextures[2] = Texture2DW("Data\\Editor\\sb_Tank.png");
	_blocksButtons[2] = ShinyButton(
		static_cast<Texture2D>(_blocksBtnTextures[2]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.302f,0.15f,0.075f }),
		ssc2
	);

	_blocksBtnTextures[3] = Texture2DW("Data\\Editor\\sb_Pipes.png");
	_blocksButtons[3] = ShinyButton(
		static_cast<Texture2D>(_blocksBtnTextures[3]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.379f,0.15f,0.075f }),
		ssc3
	);

	_blocksBtnTextures[4] = Texture2DW("Data\\Editor\\sb_CustomBlocks.png");
	_blocksButtons[4] = ShinyButton(
		static_cast<Texture2D>(_blocksBtnTextures[4]),
		_tGlint, 
		Game::ScreenRec({ 0.095f,0.456f,0.15f,0.075f }),
		ssc4
	);

	//enemies categories
	_enemiesBtnTextures[0] = Texture2DW("Data\\Editor\\sb_Enemies.png");
	_enemiesButtons[0] = ShinyButton(
		static_cast<Texture2D>(_enemiesBtnTextures[0]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.148f,0.15f,0.075f }),
		ssc0
	);

	_enemiesBtnTextures[1] = Texture2DW("Data\\Editor\\sb_Hazards.png");
	_enemiesButtons[1] = ShinyButton(
		static_cast<Texture2D>(_enemiesBtnTextures[1]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.225f,0.15f,0.075f }),
		ssc1
	);

	_enemiesBtnTextures[2] = Texture2DW("Data\\Editor\\sb_Clones.png");
	_enemiesButtons[2] = ShinyButton(
		static_cast<Texture2D>(_enemiesBtnTextures[2]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.302f,0.15f,0.075f }),
		ssc2
	);

	_enemiesBtnTextures[3] = Texture2DW("Data\\Editor\\sb_Bosses.png");
	_enemiesButtons[3] = ShinyButton(
		static_cast<Texture2D>(_enemiesBtnTextures[3]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.379f,0.15f,0.075f }),
		ssc3
	);

	_enemiesBtnTextures[4] = Texture2DW("Data\\Editor\\sb_CustomEnemies.png");
	_enemiesButtons[4] = ShinyButton(
		static_cast<Texture2D>(_enemiesBtnTextures[4]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.456f,0.15f,0.075f }),
		ssc4
	);

	_enemiesBtnTextures[5] = Texture2DW("Data\\Editor\\sb_CustomBosses.png");
	_enemiesButtons[5] = ShinyButton(
		static_cast<Texture2D>(_enemiesBtnTextures[5]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.533f,0.15f,0.075f }),
		ssc5
	);

	//bonuses categories
	_bonusesBtnTextures[0] = Texture2DW("Data\\Editor\\sb_Bonuses.png");
	_bonusesButtons[0] = ShinyButton(
		static_cast<Texture2D>(_bonusesBtnTextures[0]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.148f,0.15f,0.075f }),
		ssc0
	);

	_bonusesBtnTextures[1] = Texture2DW("Data\\Editor\\sb_CustomBonuses.png");
	_bonusesButtons[1] = ShinyButton(
		static_cast<Texture2D>(_bonusesBtnTextures[1]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.225f,0.15f,0.075f }),
		ssc1
	);

	//marks
	_marksBtnTextures[0] = Texture2DW("Data\\Editor\\sb_LevelProgress.png");
	_marksButtons[0] = ShinyButton(
		static_cast<Texture2D>(_marksBtnTextures[0]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.148f,0.15f,0.075f }),
		ssc0
	);

	_marksBtnTextures[1] = Texture2DW("Data\\Editor\\sb_Platforms.png");
	_marksButtons[1] = ShinyButton(
		static_cast<Texture2D>(_marksBtnTextures[1]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.225f,0.15f,0.075f }),
		ssc1
	);

	_marksBtnTextures[2] = Texture2DW("Data\\Editor\\sb_Marks.png");
	_marksButtons[2] = ShinyButton(
		static_cast<Texture2D>(_marksBtnTextures[2]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.302f,0.15f,0.075f }),
		ssc2
	);

	_marksBtnTextures[3] = Texture2DW("Data\\Editor\\sb_Pipes.png");
	_marksButtons[3] = ShinyButton(
		static_cast<Texture2D>(_marksBtnTextures[3]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.379f,0.15f,0.075f }),
		ssc3
	);

	_marksBtnTextures[4] = Texture2DW("Data\\Editor\\sb_Scripts.png");
	_marksButtons[4] = ShinyButton(
		static_cast<Texture2D>(_marksBtnTextures[4]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.456f,0.15f,0.075f }),
		ssc4
	);

	//scenery
	_sceneryBtnTextures[0] = Texture2DW("Data\\Editor\\sb_Overworld.png");
	_sceneryButtons[0] = ShinyButton(
		static_cast<Texture2D>(_sceneryBtnTextures[0]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.148f,0.15f,0.075f }),
		ssc0
	);

	_sceneryBtnTextures[1] = Texture2DW("Data\\Editor\\sb_Underground.png");
	_sceneryButtons[1] = ShinyButton(static_cast<Texture2D>(_sceneryBtnTextures[1]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.225f,0.15f,0.075f }),
		ssc1
	);

	_sceneryBtnTextures[2] = Texture2DW("Data\\Editor\\sb_Starland.png");
	_sceneryButtons[2] = ShinyButton(
		static_cast<Texture2D>(_sceneryBtnTextures[2]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.302f,0.15f,0.075f }),
		ssc2
	);

	_sceneryBtnTextures[3] = Texture2DW("Data\\Editor\\sb_Snowland.png");
	_sceneryButtons[3] = ShinyButton(
		static_cast<Texture2D>(_sceneryBtnTextures[3]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.379f,0.15f,0.075f }),
		ssc3
	);

	_sceneryBtnTextures[4] = Texture2DW("Data\\Editor\\sb_Darkland.png");
	_sceneryButtons[4] = ShinyButton(
		static_cast<Texture2D>(_sceneryBtnTextures[4]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.456f,0.15f,0.075f }),
		ssc4
	);

	_sceneryBtnTextures[5] = Texture2DW("Data\\Editor\\sb_Sunset.png");
	_sceneryButtons[5] = ShinyButton(
		static_cast<Texture2D>(_sceneryBtnTextures[5]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.533f,0.15f,0.075f }), 
		ssc5
	);

	_sceneryBtnTextures[6] = Texture2DW("Data\\Editor\\sb_Desert.png");
	_sceneryButtons[6] = ShinyButton(
		static_cast<Texture2D>(_sceneryBtnTextures[6]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.610f,0.15f,0.075f }),
		ssc6
	);

	_sceneryBtnTextures[7] = Texture2DW("Data\\Editor\\sb_Castle.png");
	_sceneryButtons[7] = ShinyButton(
		static_cast<Texture2D>(_sceneryBtnTextures[7]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.687f,0.15f,0.075f }),
		ssc7
	);

	_sceneryBtnTextures[8] = Texture2DW("Data\\Editor\\sb_CustomScenery.png");
	_sceneryButtons[8] = ShinyButton(
		static_cast<Texture2D>(_sceneryBtnTextures[8]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.687f,0.15f,0.075f }),
		[this]() -> void
		{
			SetSubCategory(8);
		}
	);

	_squareMouse = Texture2DW("Data\\Editor\\CurrentTileSquare.png");

	_settingsBtnTextures[0] = Texture2DW("Data\\Editor\\sb_LevelInfo.png");
	_settingsButtons[0] = ShinyButton(
		static_cast<Texture2D>(_settingsBtnTextures[0]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.148f,0.15f,0.075f }),
		ssc0
	);

	_settingsBtnTextures[1] = Texture2DW("Data\\Editor\\sb_Settings.png");
	_settingsButtons[1] = ShinyButton(
		static_cast<Texture2D>(_settingsBtnTextures[1]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.225f,0.15f,0.075f }),
		ssc1
	);

	_settingsBtnTextures[2] = Texture2DW("Data\\Editor\\sb_Backgrounds.png");
	_settingsButtons[2] = ShinyButton(
		static_cast<Texture2D>(_settingsBtnTextures[2]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.302f,0.15f,0.075f }),
		ssc2
	);

	_settingsBtnTextures[3] = Texture2DW("Data\\Editor\\sb_Music.png");
	_settingsButtons[3] = ShinyButton(
		static_cast<Texture2D>(_settingsBtnTextures[3]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.379f,0.15f,0.075f }),
		ssc3
	);

	_settingsBtnTextures[4] = Texture2DW("Data\\Editor\\sb_Fluids.png");
	_settingsButtons[4] = ShinyButton(
		static_cast<Texture2D>(_settingsBtnTextures[4]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.456f,0.15f,0.075f }),
		ssc4
	);

	_settingsBtnTextures[5] = Texture2DW("Data\\Editor\\sb_BossSettings.png");
	_settingsButtons[5] = ShinyButton(
		static_cast<Texture2D>(_settingsBtnTextures[5]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.533f,0.15f,0.075f }),
		ssc5
	);

	_settingsBtnTextures[6] = Texture2DW("Data\\Editor\\sb_Effects.png");
	_settingsButtons[6] = ShinyButton(
		static_cast<Texture2D>(_settingsBtnTextures[6]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.610f,0.15f,0.075f }),
		ssc6
	);

	_settingsBtnTextures[7] = Texture2DW("Data\\Editor\\sb_FileIO.png");
	_settingsButtons[7] = ShinyButton(
		static_cast<Texture2D>(_settingsBtnTextures[7]),
		_tGlint,
		Game::ScreenRec({ 0.095f,0.687f,0.15f,0.075f }),
		ssc7
	);

	_levelNameTbs[0] = std::make_unique<Textbox>(
		static_cast<Texture2D>(Resources::TxtboxRectangle),
		Resources::LevelHudFont,
		"WORLD",
		Game::ScreenRec({ 0.6f,0.165f,0.3f,0.04f }),
		10,
		10
	);

	_levelNameTbs[1] = std::make_unique<Textbox>(
		static_cast<Texture2D>(Resources::TxtboxRectangle),
		Resources::LevelHudFont,
		"1-1",
		Game::ScreenRec({ 0.6f,0.22f,0.3f,0.04f }),
		10,
		10
	);

	_authorTb = std::make_unique<Textbox>(
		static_cast<Texture2D>(Resources::TxtboxRectangle),
		Resources::LevelHudFont,
		"YOUR NAME",
		Game::ScreenRec({ 0.6f,0.3f,0.3f,0.04f }),
		10,
		10
	);

	_emailTb = std::make_unique<Textbox>(
		static_cast<Texture2D>(Resources::TxtboxRectangle),
		Resources::LevelHudFont,
		"NAME[EXAMPLE.COM",
		Game::ScreenRec({ 0.6f,0.375f,0.3f,0.04f }),
		50,
		10
	);

	_websiteTb = std::make_unique<Textbox>(
		static_cast<Texture2D>(Resources::TxtboxRectangle),
		Resources::LevelHudFont,
		"EXAMPLE.COM",
		Game::ScreenRec({ 0.6f,0.45f,0.3f,0.04f }),
		50,
		10
	);

	_levelWidthSl = Slider(
		static_cast<Texture2D>(Resources::SliderBar),
		static_cast<Texture2D>(Resources::SliderBox),
		Game::ScreenRec({ 0.6f,0.52f,0.3f,0.04f }),
		20,
		400,
		60
	);
	_levelWidthSl.OnValueChange = [this](double oldVlaue, double newValue)
	{
		Game::CurrentLevel.Size.x = (float)newValue;
		levelPx = Game::CurrentLevel.Size.x * Game::Resolution::X / 20.0f;
	};

	_levelHeightSl = Slider(
		static_cast<Texture2D>(Resources::SliderBar),
		static_cast<Texture2D>(Resources::SliderBox),
		Game::ScreenRec({ 0.6f,0.59f,0.3f,0.04f }),
		15,
		225,
		30
	);
	_levelHeightSl.OnValueChange = [this](double oldValue, double newValue)
	{
		Game::CurrentLevel.Size.y = (float)newValue;
		levelPy = Game::CurrentLevel.Size.y * Game::Resolution::Y / 15.0f;
	};

	_levelTime = std::make_unique<Textbox>(
		static_cast<Texture2D>(Resources::TxtboxRectangle),
		Resources::NumericLevelHudFont,
		"360",
		Game::ScreenRec({ 0.6f,0.69f,0.3f,0.04f }),
		5,
		10
	);

	_levelSettingsTxs[0] = Texture2DW("Data\\Editor\\Param_PlayerGravity.png");
	_levelSettingsBtns[0] = ShinyButton(
		static_cast<Texture2D>(_levelSettingsTxs[0]),
		_tGlint,
		Game::ScreenRec({ 0.3f, 0.35f, 0.1f, 0.1f }),
		[this]()
		{
			_currentSettingId = 0;
			PlaySound(static_cast<Sound>(Resources::ClickSound1));
		}
	);

	_levelSettingsTxs[1] = Texture2DW("Data\\Editor\\Param_EnemySpeed.png");
	_levelSettingsBtns[1] = ShinyButton(
		static_cast<Texture2D>(_levelSettingsTxs[1]),
		_tGlint,
		Game::ScreenRec({ 0.41f,0.35f,0.1f,0.1f }),
		[this]()
		{
			_currentSettingId = 1;
			PlaySound(static_cast<Sound>(Resources::ClickSound1));
		}
	);

	_levelSettingsTxs[2] = Texture2DW("Data\\Editor\\Param_BillBlasterRoF.png");
	_levelSettingsBtns[2] = ShinyButton(
		static_cast<Texture2D>(_levelSettingsTxs[2]),
		_tGlint,
		Game::ScreenRec({ 0.52f,0.35f,0.1f,0.1f }),
		[this]()
		{
			_currentSettingId = 2;
			PlaySound(static_cast<Sound>(Resources::ClickSound1));
		}
	);

	_levelSettingsTxs[3] = Texture2DW("Data\\Editor\\Param_ProjectileSpeed.png");
	_levelSettingsBtns[3] = ShinyButton(
		static_cast<Texture2D>(_levelSettingsTxs[3]),
		_tGlint,
		Game::ScreenRec({ 0.63f,0.35f,0.1f,0.1f }),
		[this]()
		{
			_currentSettingId = 3;
			PlaySound(static_cast<Sound>(Resources::ClickSound1));
		}
	);

	_levelSettingsTxs[4] = Texture2DW("Data\\Editor\\Param_PinkFlowerFireballsCount.png");
	_levelSettingsBtns[4] = ShinyButton(
		static_cast<Texture2D>(_levelSettingsTxs[4]),
		_tGlint,
		Game::ScreenRec({ 0.3f,0.46f,0.1f,0.1f }),
		[this]()
		{
			_currentSettingId = 4;
			PlaySound(static_cast<Sound>(Resources::ClickSound1));
		}
	);

	_levelSettingsTxs[5] = Texture2DW("Data\\Editor\\Param_PlantSpeed.png");
	_levelSettingsBtns[5] = ShinyButton(
		static_cast<Texture2D>(_levelSettingsTxs[5]),
		_tGlint,
		Game::ScreenRec({ 0.41f,0.46f,0.1f,0.1f }),
		[this]()
		{
			_currentSettingId = 5;
			PlaySound(static_cast<Sound>(Resources::ClickSound1));
		}
	);

	_levelSettingsTxs[6] = Texture2DW("Data\\Editor\\Param_PodoboosSpeed.png");
	_levelSettingsBtns[6] = ShinyButton(
		static_cast<Texture2D>(_levelSettingsTxs[6]),
		_tGlint,
		Game::ScreenRec({ 0.52f,0.46f,0.1f,0.1f }),
		[this]()
		{
			_currentSettingId = 6;
			PlaySound(static_cast<Sound>(Resources::ClickSound1));
		}
	);

	_levelSettingsTxs[7] = Texture2DW("Data\\Editor\\Param_LakituAttackSpeed.png");
	_levelSettingsBtns[7] = ShinyButton(
		static_cast<Texture2D>(_levelSettingsTxs[7]),
		_tGlint,
		Game::ScreenRec({ 0.63f,0.46f,0.1f,0.1f }),
		[this]()
		{
			_currentSettingId = 7;
			PlaySound(static_cast<Sound>(Resources::ClickSound1));
		}
	);

	_levelSettingsTxs[8] = Texture2DW("Data\\Editor\\Param_FallingSpikes.png");
	_levelSettingsBtns[8] = ShinyButton(
		static_cast<Texture2D>(_levelSettingsTxs[8]),
		_tGlint,
		Game::ScreenRec({ 0.3f,0.57f,0.1f,0.1f }),
		[this]()
		{
			_currentSettingId = 8;
			PlaySound(static_cast<Sound>(Resources::ClickSound1));
		}
	);

	_levelSettingsTxs[9] = Texture2DW("Data\\Editor\\Param_PlatformSpeed.png");
	_levelSettingsBtns[9] = ShinyButton(
		static_cast<Texture2D>(_levelSettingsTxs[9]),
		_tGlint,
		Game::ScreenRec({ 0.41f,0.57f,0.1f,0.1f }),
		[this]()
		{
			_currentSettingId = 9;
			PlaySound(static_cast<Sound>(Resources::ClickSound1));
		}
	);

	_levelSettingsTxs[10] = Texture2DW("Data\\Editor\\Param_FishDensity.png");
	_levelSettingsBtns[10] = ShinyButton(
		static_cast<Texture2D>(_levelSettingsTxs[10]),
		_tGlint,
		Game::ScreenRec({ 0.52f,0.57f,0.1f,0.1f }),
		[this]()
		{
			_currentSettingId = 10;
			PlaySound(static_cast<Sound>(Resources::ClickSound1));
		}
	);

	_levelSettingsTxs[11] = Texture2DW("Data\\Editor\\Param_BroHammerThrowRate.png");
	_levelSettingsBtns[11] = ShinyButton(
		static_cast<Texture2D>(_levelSettingsTxs[11]),
		_tGlint,
		Game::ScreenRec({ 0.63f,0.57f,0.1f,0.1f }),
		[this]()
		{
			_currentSettingId = 11;
			PlaySound(static_cast<Sound>(Resources::ClickSound1));
		}
	);

	_levelSettingsSliders[0] = Slider(
		static_cast<Texture2D>(Resources::SliderBar),
		static_cast<Texture2D>(Resources::SliderBox),
		Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }),
		1,
		10,
		6
	); //gravity
	_levelSettingsSliders[0].OnValueChange = [](double old, double newVal)
	{
		Game::CurrentLevel.Gravity = (float)newVal;
	};

	_levelSettingsSliders[1] = Slider(
		static_cast<Texture2D>(Resources::SliderBar),
		static_cast<Texture2D>(Resources::SliderBox),
		Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }),
		1,
		10,
		5
	); //enemy speed
	_levelSettingsSliders[1].OnValueChange = [](double old, double newV)
	{
		Game::CurrentLevel.EnemySpeed = (unsigned int)newV;
	};

	_levelSettingsSliders[2] = Slider(
		static_cast<Texture2D>(Resources::SliderBar),
		static_cast<Texture2D>(Resources::SliderBox),
		Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }),
		1,
		10,
		5
	); //bill rof
	_levelSettingsSliders[2].OnValueChange = [](double old, double newV)
	{
		Game::CurrentLevel.BillBlasterROF = (unsigned int)newV;
	};

	_levelSettingsSliders[3] = Slider(
		static_cast<Texture2D>(Resources::SliderBar),
		static_cast<Texture2D>(Resources::SliderBox),
		Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }),
		1,
		10,
		5
	); //bill mov speed
	_levelSettingsSliders[3].OnValueChange = [](double old, double newV)
	{
		Game::CurrentLevel.BillBulletSpeed = (unsigned int)newV;
	};

	_levelSettingsSliders[4] = Slider(
		static_cast<Texture2D>(Resources::SliderBar),
		static_cast<Texture2D>(Resources::SliderBox),
		Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }),
		1,
		20,
		3
	); //pink flower fireballs
	_levelSettingsSliders[4].OnValueChange = [](double old, double newV)
	{
		Game::CurrentLevel.PinkFlowerFireballs = (unsigned int)newV;
	};

	_levelSettingsSliders[5] = Slider(
		static_cast<Texture2D>(Resources::SliderBar),
		static_cast<Texture2D>(Resources::SliderBox),
		Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }),
		1,
		10,
		5
	); //plant hiding timespan
	_levelSettingsSliders[5].OnValueChange = [](double old, double newV)
	{
		Game::CurrentLevel.PlantSpeed = (unsigned int)newV;
	};

	_levelSettingsSliders[6] = Slider(
		static_cast<Texture2D>(Resources::SliderBar),
		static_cast<Texture2D>(Resources::SliderBox),
		Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }),
		1,
		10,
		5
	); //podoboos frequency
	_levelSettingsSliders[6].OnValueChange = [](double old, double newV)
	{
		Game::CurrentLevel.PodoboosSpeed = (unsigned int)newV;
	};

	_levelSettingsSliders[7] = Slider(
		static_cast<Texture2D>(Resources::SliderBar),
		static_cast<Texture2D>(Resources::SliderBox),
		Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }),
		1,
		7,
		5
	); //lakitu attack speed
	_levelSettingsSliders[7].OnValueChange = [](double old, double newV)
	{
		Game::CurrentLevel.LakituAttackSpeed = (unsigned int)newV;
	};

	_levelSettingsSliders[8] = Slider(
		static_cast<Texture2D>(Resources::SliderBar),
		static_cast<Texture2D>(Resources::SliderBox),
		Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }),
		0,
		20,
		0
	); //falling spikes
	_levelSettingsSliders[8].OnValueChange = [](double old, double newV)
	{
		Game::CurrentLevel.FallingSpikesSpeed = (unsigned int)newV;
	};

	_levelSettingsSliders[9] = Slider(
		static_cast<Texture2D>(Resources::SliderBar),
		static_cast<Texture2D>(Resources::SliderBox),
		Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }),
		1,
		3,
		1
	); //platform speed
	_levelSettingsSliders[9].OnValueChange = [](double oldV, double newV)
	{
		Game::CurrentLevel.PlatformSpeed = (unsigned int)newV;
	};

	_levelSettingsSliders[10] = Slider(
		static_cast<Texture2D>(Resources::SliderBar),
		static_cast<Texture2D>(Resources::SliderBox),
		Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }),
		0,
		5,
		1
	); //fish density
	_levelSettingsSliders[10].OnValueChange = [](double o, double n)
	{
		Game::CurrentLevel.FishDensity = (unsigned int)n;
	};

	_levelSettingsSliders[11] = Slider(
		static_cast<Texture2D>(Resources::SliderBar),
		static_cast<Texture2D>(Resources::SliderBox),
		Game::ScreenRec({ 0.3f, 0.25f, 0.3f, 0.04f }),
		1,
		5,
		2
	); //bro hammer throw rate
	_levelSettingsSliders[11].OnValueChange = [](double o, double n)
	{
		Game::CurrentLevel.BroHammerAttackRate = (unsigned int)n;
	};

	_bckLeftBtn = ShinyButton(
		static_cast<Texture2D>(Resources::LeftBtn),
		_tGlint,
		Game::ScreenRec({ 0.3f,0.9f,0.05f,0.05f }),
		[this]()
	   {
		   _backgroundSettingId -= 1;
		   _backgroundSettingId = std::clamp(_backgroundSettingId, 0, 2);
		   PlaySound(static_cast<Sound>(Resources::ClickSound1));
	   }
	);
	_bckRightBtn = ShinyButton(
		static_cast<Texture2D>(Resources::RightBtn),
		_tGlint,
		Game::ScreenRec({ 0.9f,0.9f,0.05f,0.05f }),
		[this]()
		{
			_backgroundSettingId += 1;
			_backgroundSettingId = std::clamp(_backgroundSettingId, 0, 2);
			PlaySound(static_cast<Sound>(Resources::ClickSound1));
		}
	);

	_backgroundsTxds[0] = Texture2DW("Data\\Editor\\Bkrd_NoBackground.png");
	_backgroundsBtns[0] = ShinyButton(
		static_cast<Texture2D>(_backgroundsTxds[0]),
		_tGlint,
		Game::ScreenRec({ 0.3f,0.25f,0.2f,0.2f }),
		[]()
		{
			Game::CurrentLevel.LvlBackground = std::make_unique<Background>(WHITE, Color(60, 120, 160, 255)); //load default Background
		}
	);

	_backgroundsTxds[1] = Texture2DW("Data\\Editor\\Bkrd_Underground.png");
	_backgroundsBtns[1] = ShinyButton(
		static_cast<Texture2D>(_backgroundsTxds[1]),
		_tGlint,
		Game::ScreenRec({ 0.51f,0.25f,0.2f,0.2f }),
		[]()
		{
			Game::CurrentLevel.LvlBackground = std::make_unique<Background>("Data\\Backgrounds\\Underground.png", true, true, WHITE, WHITE);
		}
	);

	_backgroundsTxds[2] = Texture2DW("Data\\Editor\\Bkrd_Rocky.png");
	_backgroundsBtns[2] = ShinyButton(
		static_cast<Texture2D>(_backgroundsTxds[2]),
		_tGlint,
		Game::ScreenRec({ 0.72f,0.25f,0.2f,0.2f }),
		[]()
		{
			Game::CurrentLevel.LvlBackground = std::make_unique<Background>("Data\\Backgrounds\\Rocky.png", true, false, WHITE, Color(60, 120, 160, 255));
		}
	);

	_backgroundsTxds[3] = Texture2DW("Data\\Editor\\Bkrd_Castle.png");
	_backgroundsBtns[3] = ShinyButton(
		static_cast<Texture2D>(_backgroundsTxds[3]),
		_tGlint,
		Game::ScreenRec({ 0.3f,0.46f,0.2f,0.2f }),
		[]()
		{
			Game::CurrentLevel.LvlBackground = std::make_unique<Background>("Data\\Backgrounds\\Castle.png", true, true, WHITE, WHITE);
		}
	);

	_backgroundsTxds[4] = Texture2DW("Data\\Editor\\Bkrd_Underwater.png");
	_backgroundsBtns[4] = ShinyButton(
		static_cast<Texture2D>(_backgroundsTxds[4]),
		_tGlint,
		Game::ScreenRec({ 0.51f,0.46f,0.2f,0.2f }),
		[]()
		{
			Game::CurrentLevel.LvlBackground = std::make_unique<Background>("Data\\Backgrounds\\Underwater.png", true, false, WHITE, Color(60, 120, 160, 255));
		}
	);

	_backgroundsTxds[5] = Texture2DW("Data\\Editor\\Bkrd_Night.png");
	_backgroundsBtns[5] = ShinyButton(
		static_cast<Texture2D>(_backgroundsTxds[5]),
		_tGlint,
		Game::ScreenRec({ 0.72f,0.46f,0.2f,0.2f }),
		[]()
		{
			Game::CurrentLevel.LvlBackground = std::make_unique<Background>("Data\\Backgrounds\\Night.png", true, false, Color(60, 120, 160, 255), Color(0, 0, 255, 255));
		}
	);

	_backgroundsTxds[6] = Texture2DW("Data\\Editor\\Bkrd_DarkCave.png");
	_backgroundsBtns[6] = ShinyButton(
		static_cast<Texture2D>(_backgroundsTxds[6]),
		_tGlint,
		Game::ScreenRec({ 0.3f,0.67f,0.2f,0.2f }), 
		[]()
		{
			Game::CurrentLevel.LvlBackground = std::make_unique<Background>("Data\\Backgrounds\\DarkCave.png", true, true, WHITE, WHITE);
		}
	);

	_backgroundsTxds[7] = Texture2DW("Data\\Editor\\Bkrd_LavaCave.png");
	_backgroundsBtns[7] = ShinyButton(
		static_cast<Texture2D>(_backgroundsTxds[7]),
		_tGlint,
		Game::ScreenRec({ 0.51f,0.67f,0.2f,0.2f }),
		[]()
		{
			Game::CurrentLevel.LvlBackground = std::make_unique<Background>("Data\\Backgrounds\\LavaCave.png", true, true, WHITE, WHITE);
		}
	);

	_backgroundsTxds[8] = Texture2DW("Data\\Editor\\Bkrd_Custom.png");
	_backgroundsBtns[8] = ShinyButton(
		static_cast<Texture2D>(_backgroundsTxds[8]),
		_tGlint,
		Game::ScreenRec({ 0.72f,0.67f,0.2f,0.2f }),
		[]()
		{
			FileDialogResult* r = ShowOpenFileDialog("Open a background image...");
			if(r->Result == 0)
			{
				Texture2DW t;
				bool s = true;
				try
				{
					t = Texture2DW(r->File);
				}
				catch(GameResourceLoadException& e)
				{
					std::stringstream errmsg("The file you selected: \r\n");
					errmsg << e.what() << "\r\n is not a valid or supported image format!";
					ShowMessageBoxError(GetWindowHandle(), errmsg.str().c_str(), "Error!");
					s = false;
				}
				if(s)
				{
					Game::CurrentLevel.LvlBackground = std::make_unique<Background>(r->File, true, true, WHITE, Color(60, 120, 160, 255));
					ProperlySetWorkingPath();
				}
			}

			delete r;
		}
	);

	_topColorTxd = Texture2DW("Data\\Editor\\Btn_TopColor.png");
	_topColorBtn = ShinyButton(
		static_cast<Texture2D>(_topColorTxd),
		_tGlint,
		Game::ScreenRec({ 0.46f,0.3f,0.15f,0.075f }),
		[]()
		{
			ColorDialogResult r(
				Game::CurrentLevel.LvlBackground->ColorB.r,
				Game::CurrentLevel.LvlBackground->ColorB.g,
				Game::CurrentLevel.LvlBackground->ColorB.b
			);
			if(r.Result == 0)
				Game::CurrentLevel.LvlBackground->ColorB = {
					r.ResultColor.R,
					r.ResultColor.G,
					r.ResultColor.B,
					255
			};
		}
	);

	_bottomColorTxd = Texture2DW("Data\\Editor\\Btn_BottomColor.png");
	_bottomColorBtn = ShinyButton(
		static_cast<Texture2D>(_bottomColorTxd),
		_tGlint, 
		Game::ScreenRec({ 0.46f, 0.38f, 0.15f, 0.075f }),
		[]()
		{
			ColorDialogResult r(
				Game::CurrentLevel.LvlBackground->ColorA.r,
				Game::CurrentLevel.LvlBackground->ColorA.g,
				Game::CurrentLevel.LvlBackground->ColorA.b
			);

			if(r.Result == 0)
				Game::CurrentLevel.LvlBackground->ColorA = {
					r.ResultColor.R,
					r.ResultColor.G,
					r.ResultColor.B,
					255
			};
		}
	);

	_repeatXCb = std::make_unique<Checkbox>(
		static_cast<const Texture2D>(Resources::CbTrue),
		static_cast<const Texture2D>(Resources::CbFalse),
		Resources::LevelHudFont,
		"Repeat X",
		false,
		Vector2(0.3f, 0.25f),
		Game::ScreenRec(Vector2(0.03f, 0.03f)), 
		Vector2( 0.025f,0.025f ),
		0.001f
	);

	_repeatXCb->OnStateChange = [](bool state)
	{
		Game::CurrentLevel.LvlBackground->RepeatX = state;
	};

	_repeatYCb = std::make_unique<Checkbox>(
		static_cast<const Texture2D>(Resources::CbTrue),
		static_cast<const Texture2D>(Resources::CbFalse),
		Resources::LevelHudFont,
		"Repeat Y",
		false,
		Vector2(0.3f, 0.30f),
		Game::ScreenRec(Vector2(0.03f, 0.03f)), 
		Vector2( 0.025f,0.025f ),
		0.001f
	);

	_repeatYCb->OnStateChange = [](bool state)
	{
		Game::CurrentLevel.LvlBackground->RepeatY = state;
	};

	_lockToScreenCb = std::make_unique<Checkbox>(
		static_cast<Texture2D>(Resources::CbTrue),
		static_cast<Texture2D>(Resources::CbFalse),
		Resources::LevelHudFont,
		"Lock to screen X and Y",
		false,
		Vector2(0.3f, 0.35f),
		Game::ScreenRec(Vector2(0.03f, 0.03f)),
		Vector2( 0.025f,0.025f),
		0.001f
	);
	_lockToScreenCb->OnStateChange = [](bool state)
	{
		Game::CurrentLevel.LvlBackground->LockToScreen = state;
	};

	_lockToYCb = std::make_unique<Checkbox>(
		static_cast<Texture2D>(Resources::CbTrue),
		static_cast<Texture2D>(Resources::CbFalse),
		Resources::LevelHudFont,
		"Lock to players Y coord",
		false,
		Vector2(0.3f, 0.4f),
		Game::ScreenRec(Vector2(0.03f, 0.03f)),
		Vector2( 0.025f,0.025f),
		0.001f
	);
	_lockToYCb->OnStateChange = [](bool state)
	{
		Game::CurrentLevel.LvlBackground->LockToY = state;
	};

	_fitScreenCb = std::make_unique<Checkbox>(
		static_cast<Texture2D>(Resources::CbTrue),
		static_cast<Texture2D>(Resources::CbFalse),
		Resources::LevelHudFont,
		"Fit entire screen",
		false,
		Vector2(0.3f, 0.45f),
		Game::ScreenRec(Vector2(0.03f, 0.03f)),
		Vector2(0.025f,0.025f),
		0.001f
	);
	_fitScreenCb->OnStateChange = [](bool state)
	{
		Game::CurrentLevel.LvlBackground->FitEntireScreen = state;
	};

	_overlayGradientCol1Btn = ShinyButton(
		static_cast<Texture2D>(_topColorTxd),
		_tGlint,
		Game::ScreenRec({ 0.46f,0.56f,0.15f,0.075f }),
		[]()
		{
			ColorDialogResult r(
				Game::CurrentLevel.LvlBackground->OverlayB.r,
				Game::CurrentLevel.LvlBackground->OverlayB.g,
				Game::CurrentLevel.LvlBackground->OverlayB.b
			);
			if(r.Result == 0)
				Game::CurrentLevel.LvlBackground->OverlayB = {
					r.ResultColor.R,
					r.ResultColor.G,
					r.ResultColor.B,
					255
			};
		}
	);

	_overlayGradientAlphaBSli = Slider(
		static_cast<Texture2D>(Resources::SliderBar),
		static_cast<Texture2D>(Resources::SliderBox),
		Game::ScreenRec({ 0.62f,0.56f,0.3f,0.04f }),
		0,
		255,
		0
	);
	_overlayGradientAlphaBSli.OnValueChange = [](double o, double n)
	{
		Game::CurrentLevel.LvlBackground->OverlayAlphaB = n;
	};

	_overlayGradientCol2Btn = ShinyButton(
		static_cast<Texture2D>(_bottomColorTxd),
		_tGlint, 
		Game::ScreenRec({ 0.46f,0.66f,0.15f,0.075f }),
		[]()
		{
			ColorDialogResult r(
				Game::CurrentLevel.LvlBackground->OverlayA.r,
				Game::CurrentLevel.LvlBackground->OverlayA.g,
				Game::CurrentLevel.LvlBackground->OverlayA.b
			);
			if(r.Result == 0)
				Game::CurrentLevel.LvlBackground->OverlayA = {
					r.ResultColor.R,
					r.ResultColor.G,
					r.ResultColor.B,
					255
			};
		}
	);

	_overlayGradientAlphaASli = Slider(
		static_cast<Texture2D>(Resources::SliderBar),
		static_cast<Texture2D>(Resources::SliderBox), 
		Game::ScreenRec({ 0.62f,0.66f,0.3f,0.04f }),
		0,
		255,
		0
	);
	_overlayGradientAlphaASli.OnValueChange = [](double o, double n)
	{
		Game::CurrentLevel.LvlBackground->OverlayAlphaA = n;
	};

	MusicList = std::unique_ptr<Listbox>(new Listbox(
		static_cast<Texture2D>(Resources::SliderBar), 
		static_cast<Texture2D>(Resources::SliderBox),
		static_cast<Texture2D>(Resources::Window),
		_tGlint,
		Resources::LevelHudFont,
		Game::ScreenRec({ 0.3f,0.3f,0.6f,0.6f }),
		std::vector<std::string>{
			"Overworld",
			"Cave",
			"Rockland",
			"Lava castle",
			"Map 1",
			"Underwater",
			"Castle 1",
			"Map 2",
			"Starland",
			"Starland Platforms", //Yoshi 3
			"Castle 2",
			"Map 3",
			"Yoshi 1",
			"Rockland 2",
			"Fastrun 1",
			"Fastrun 2",
			"Yoshi 2",
			"Apoplexy",
			"Select Save",
			"Import music..."
		},
		Vector2(0.025f, 0.025f),
		0.001f
	));
	MusicList->OnItemClick = [this](const std::string& music, int index)
	{
		const char* MusicPaths[20] =
		{
			"Data\\Music\\Overworld.mp3",
			"Data\\Music\\Cave.mp3",
			"Data\\Music\\Rockland.mp3",
			"Data\\Music\\Castle.mp3",
			"Data\\Music\\Map1.mp3",
			"Data\\Music\\Underwater.mp3",
			"Data\\Music\\Castle2.mp3",
			"Data\\Music\\Map2.mp3",
			"Data\\Music\\Starland.mp3",
			"Data\\Music\\Yoshi3.mp3",
			"Data\\Music\\GhostHouse.mp3",
			"Data\\Music\\Map3.mp3",
			"Data\\Music\\Yoshi1.mp3",
			"Data\\Music\\Rockland.mp3",
			"Data\\Music\\Fastrun1.mp3",
			"Data\\Music\\Fastrun2.mp3",
			"Data\\Music\\Yoshi2.mp3",
			"Data\\Music\\Apoplexy.mp3",
			"Data\\Music\\SelectSave.mp3",
			"not used",
		};

		if(index != 19) Game::CurrentLevel.SetMusic(MusicPaths[index]);
		else
		{
			FileDialogResult *r = ShowOpenFileDialog("Open a song file...");
			if(r->Result == 0)
			{
				try
				{
					Game::CurrentLevel.SetMusic(r->File);
				}
				catch(const GameResourceLoadException& e)
				{
					std::string errmsg("The file: ");
					errmsg += r->File;
					errmsg += " doesn't contain a supported music format!";
					ShowMessageBoxError(GetWindowHandle(), errmsg.c_str(), "Error!");
				}
				ProperlySetWorkingPath();
			}

			delete r;
		}

		_music = Game::CurrentLevel.GetMusic();
	};

	_playMusicTxd = Texture2DW("Data\\Editor\\MPlayBtn.png");
	_playMusicBtn = ShinyButton(
		static_cast<Texture2D>(_playMusicTxd),
		_tGlint,
		Game::ScreenRec({ 0.3f,0.2f,0.05f,0.05f }),
		[this]()
		{
			_musicState = 1;
		}
	);

	_pauseMusicTxd = Texture2DW("Data\\Editor\\MPauseBtn.png");
	_pauseMusicBtn = ShinyButton(
		static_cast<Texture2D>(_pauseMusicTxd),
		_tGlint,
		Game::ScreenRec({ 0.35f,0.2f,0.05f,0.05f }),
		[this]()
		{
			_musicState = 2;
		}
	);

	_stopMusicTxd = Texture2DW("Data\\Editor\\MStopBtn.png");
	_stopMusicBtn = ShinyButton(
		static_cast<Texture2D>(_stopMusicTxd),
		_tGlint,
		Game::ScreenRec({ 0.4f,0.2f,0.05f,0.05f }),
		[this]()
		{
			_musicState = 0;
		}
	);

	_waterCb = std::make_unique<Checkbox>(
		static_cast<Texture2D>(Resources::CbTrue),
		static_cast<Texture2D>(Resources::CbFalse),
		Resources::LevelHudFont,
		"Water",
		true,
		Vector2(0.3f, 0.25f),
		Game::ScreenRec(Vector2(0.03f, 0.03f)),
		Vector2( 0.025f, 0.025f),
		0.001f
	);
	_waterCb->OnStateChange = [this](bool state)
	{
		if(state)
			Game::CurrentLevel.Liquid = LiquidType::Water;
		else
			Game::CurrentLevel.Liquid = LiquidType::None;

		_lavaCb->Checked = false;
		_poisonCb->Checked = false;
	};

	_lavaCb = std::make_unique<Checkbox>(
		static_cast<Texture2D>(Resources::CbTrue),
		static_cast<Texture2D>(Resources::CbFalse),
		Resources::LevelHudFont,
		"Lava",
		false,
		Vector2( 0.3f,0.3f ),
		Game::ScreenRec(Vector2(0.03f, 0.03f)),
		Vector2( 0.025f,0.025f ),
		0.001f
	);
	_lavaCb->OnStateChange = [this](bool state)
	{
		if(state)
			Game::CurrentLevel.Liquid = LiquidType::Lava;
		else
			Game::CurrentLevel.Liquid = LiquidType::None;

		_waterCb->Checked = false;
		_poisonCb->Checked = false;
	};

	_poisonCb = std::make_unique<Checkbox>(
		static_cast<Texture2D>(Resources::CbTrue),
		static_cast<Texture2D>(Resources::CbFalse),
		Resources::LevelHudFont,
		"Poison",
		false,
		Vector2(0.3f, 0.35f),
		Game::ScreenRec(Vector2(0.03f, 0.03f)),
		Vector2(0.025f, 0.025f),
		0.001f
	);
	_poisonCb->OnStateChange = [this](bool state)
	{
		if(state)
			Game::CurrentLevel.Liquid = LiquidType::Poison;
		else
			Game::CurrentLevel.Liquid = LiquidType::None;

		_waterCb->Checked = false;
		_lavaCb->Checked = false;
	};
}

void LevelEditor::Update(float dt, MouseState* ms, ControllerState* cs)
{
	if(IsKeyReleased(KEY_ESCAPE))
	{
		if(_progressSaved) Game::CurrentGameSection = 1;
		else _showNotifNotSaved = true;
	}

	//camera movment stuff
	float movmentSpeed = 500 * dt * (cs->Shift ? 5 : 1);

	if(cs->Up) cameraPosition.y -= movmentSpeed;
	if(cs->Down) cameraPosition.y += movmentSpeed;

	if(cs->Left) cameraPosition.x -= movmentSpeed;
	if(cs->Right) cameraPosition.x += movmentSpeed;

	cameraPosition.x = std::clamp<float>(cameraPosition.x, 0.0f, levelPx - (Game::Resolution::FltX()));
	cameraPosition.y = std::clamp<float>(cameraPosition.y, 0.0f, levelPy - (Game::Resolution::FltY()));

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
				for(size_t i = 0; i < 5; i++) _blocksButtons[i].Update(ms, dt);
				switch(subCategoryId)
				{
					default:break;
				}
				break;
			case 1:
				for(size_t i = 0; i < 6; i++) _enemiesButtons[i].Update(ms, dt);
				switch(subCategoryId)
				{
					default:break;
				}
				break;
			case 2:
				for(size_t i = 0; i < 2; i++) _bonusesButtons[i].Update(ms, dt);
				switch(subCategoryId)
				{
					default: break;
				}
				break;
			case 3:
				for(size_t i = 0; i < 5; i++) _marksButtons[i].Update(ms, dt);
				switch(subCategoryId)
				{
					default: break;
				}
				break;
			case 4:
				for(size_t i = 0; i < 9; i++) _sceneryButtons[i].Update(ms, dt);
				switch(subCategoryId)
				{
					default: break;
				}
				break;
			case 5:
				for(size_t i = 0; i < 8; i++) _settingsButtons[i].Update(ms, dt);
				switch(subCategoryId)
				{
					case 0:
					{
						for(size_t j = 0; j < 2; j++)
						{
							_levelNameTbs[j]->Update(ms, dt);
							if(_levelNameTbs[j]->IsFocused()) usingTxtbox = true;
						}

						_authorTb->Update(ms, dt);
						if(_authorTb->IsFocused()) usingTxtbox = true;

						_emailTb->Update(ms, dt);
						if(_emailTb->IsFocused()) usingTxtbox = true;

						_websiteTb->Update(ms, dt);
						if(_websiteTb->IsFocused()) usingTxtbox = true;

						_levelWidthSl.Update(ms, dt);
						_levelHeightSl.Update(ms, dt);
						_levelTime->Update(ms, dt);

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
					case 2:
					{
						_bckLeftBtn.Update(ms, dt);
						_bckRightBtn.Update(ms, dt);

						switch(_backgroundSettingId)
						{
							case 0:
							{
								for(size_t i = 0; i < 9; i++)
									_backgroundsBtns[i].Update(ms, dt);
								break;
							}
							case 1:
							{
								_topColorBtn.Update(ms, dt);
								_bottomColorBtn.Update(ms, dt);

								_overlayGradientAlphaASli.Update(ms, dt);
								_overlayGradientAlphaBSli.Update(ms, dt);
								_overlayGradientCol1Btn.Update(ms, dt);
								_overlayGradientCol2Btn.Update(ms, dt);
								break;
							}
							case 2:
							{
								//update values
								_repeatXCb->Checked = Game::CurrentLevel.LvlBackground->RepeatX;
								_repeatYCb->Checked = Game::CurrentLevel.LvlBackground->RepeatY;
								_lockToScreenCb->Checked = Game::CurrentLevel.LvlBackground->LockToScreen;
								_lockToYCb->Checked = Game::CurrentLevel.LvlBackground->LockToY;
								_fitScreenCb->Checked = Game::CurrentLevel.LvlBackground->FitEntireScreen;

								//update checkboxes
								_repeatXCb->Update(ms, dt);
								_repeatYCb->Update(ms, dt);
								_lockToScreenCb->Update(ms, dt);
								_lockToYCb->Update(ms, dt);
								_fitScreenCb->Update(ms, dt);
								break;
							}
							default: break;
						}
						break;
					}
					case 3:
					{
						_playMusicBtn.Update(ms,dt);
						_pauseMusicBtn.Update(ms, dt);
						_stopMusicBtn.Update(ms, dt);

						MusicList->Update(ms, dt);

						if(_musicState == 1)
						{
							PlayMusicStream(_music);
							_musicState = 3;
						}
						if(_musicState == 3)
						{
							UpdateMusicStream(_music);
						}
						break;
					}
					case 4:
					{
						_waterCb->Update(ms, dt);
						_lavaCb->Update(ms, dt);
						_poisonCb->Update(ms, dt);
						break;
					}
					default:break;
				break;
			}
			default:break;
		}

		if(!_previousSpacePress && cs->Space && !usingTxtbox) _showElements = false;
	}

	if(IsKeyDown(KEY_KP_ADD))
	{
		Game::CurrentLevel.LiquidLevel += 10 * dt;
	}
	else if(IsKeyDown(KEY_MINUS))
	{
		Game::CurrentLevel.LiquidLevel -= 10 * dt;
	}

	_previousSpacePress = cs->Space;
	_lastMousePos = { (float)ms->X,(float)ms->Y };
}

void LevelEditor::Draw(float dt)
{
	Game::CurrentLevel.LvlBackground->Draw(cameraPosition, Game::CurrentLevel.Size);
	
	DrawTexturePro(
		static_cast<Texture2D>(_square),
		{ 
			0,
			0,
			64 * Game::CurrentLevel.Size.x,
			64 * Game::CurrentLevel.Size.y
		},
		calculateTileTransformation(Game::ScreenRec(
			{
				0,
				0,
				Game::CurrentLevel.Size.x / 20,
				Game::CurrentLevel.Size.y / 15
			}
		)), 
		{0,0}, 
		0.0f,
		WHITE
	);
	//debug goomba
	DrawTexturePro(
		static_cast<Texture2D>(Resources::Goomba1),
		{ 0,0,31,32 },
		calculateWorldTransformation(Game::ScreenRec({ 0,0,0.05f,1/15.0f })),
		{ 0,0 },
		0.0f,
		WHITE
	); // <-- test goomba

	//TODO: draw level stuff
	Resources::LevelHudFont.Draw(
		"CamPos " + std::to_string(cameraPosition.x) + " " + std::to_string(cameraPosition.y),
		{ 0.01f,0.97f }, 
		{ 0.025f,0.025f },
		0.001f
	);

	if(_showElements)
	{
		DrawTexturePro(
			static_cast<Texture2D>(W_selectItem),
			{ 0,0,800,600 },
			Game::ScreenRec({ 0,0,1,1 }),
			{ 0,0 },
			0.0f,
			WHITE
		);
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

						for(size_t j = 0; j < 2; j++) _levelNameTbs[j]->Draw(dt);
						_authorTb->Draw(dt);
						_emailTb->Draw(dt);
						_websiteTb->Draw(dt);

						_levelWidthSl.Draw(dt);
						Resources::LevelHudFont.Draw(std::to_string(_levelWidthSl.GetValue<int>()), { 0.91f,0.525f}, { 0.025f,0.025f }, 0.001f);

						_levelHeightSl.Draw(dt);
						Resources::LevelHudFont.Draw(std::to_string(_levelHeightSl.GetValue<int>()), { 0.91f,0.6f }, { 0.025f,0.025f }, 0.001f);

						_levelTime->Draw(dt);
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
					case 2:
					{
						const char* BackgroundSettings[3] = {
							"Background image",
							"Background gradients",
							"Background settings"
						};

						Resources::LevelHudFont.Draw(BackgroundSettings[_backgroundSettingId], {0.3f,0.19f}, {0.025f,0.025f}, 0.001f);

						_bckLeftBtn.Draw(dt);
						_bckRightBtn.Draw(dt);

						switch(_backgroundSettingId)
						{
							case 0:
							{
								for(size_t i = 0; i < 9; i++)
									_backgroundsBtns[i].Draw(dt);
								break;
							}
							case 1:
							{
								Resources::LevelHudFont.Draw("Background main gradient", { 0.3f,0.25f }, { 0.025f,0.025f }, 0.001f);

								auto _drawGradient = [](Rectangle coords,Color colors[2])
								{
									DrawTexturePro(
										static_cast<Texture2D>(Resources::GradientA),
										{ 0,0, (float)Resources::GradientA.Width(), (float)Resources::GradientA.Height()},
										Game::ScreenRec(coords),
										{ 0,0 },
										0.0f,
										colors[0]
									);

									DrawTexturePro(
										static_cast<Texture2D>(Resources::GradientB),
										{ 0,0, (float)Resources::GradientB.Width(), (float)Resources::GradientB.Height()},
										Game::ScreenRec(coords),
										{ 0,0 },
										0.0f,
										colors[1]
									);
								};

								Color g1[2] = { Game::CurrentLevel.LvlBackground->ColorA,Game::CurrentLevel.LvlBackground->ColorB };
								_drawGradient({ 0.3f,0.3f,0.15f,0.15f },g1);

								_topColorBtn.Draw(dt);
								_bottomColorBtn.Draw(dt);

								Color g2[2] = {Game::CurrentLevel.LvlBackground->OverlayA,Game::CurrentLevel.LvlBackground->OverlayB};
								Resources::LevelHudFont.Draw("Overlay gradient", { 0.3f,0.5f }, { 0.025f,0.025f }, 0.001f);
								_drawGradient({ 0.3f,0.56f,0.15f,0.15f },g2);

								_overlayGradientAlphaASli.Draw(dt);
								_overlayGradientAlphaBSli.Draw(dt);
								_overlayGradientCol1Btn.Draw(dt);
								_overlayGradientCol2Btn.Draw(dt);
								break;
							}
							case 2:
							{
								_repeatXCb->Draw(dt);
								_repeatYCb->Draw(dt);
								_lockToScreenCb->Draw(dt);
								_lockToYCb->Draw(dt);
								_fitScreenCb->Draw(dt);
								break;
							}
							default:
								break;
						}
						break;
					}
					case 3:
					{
						_playMusicBtn.Draw(dt);
						_pauseMusicBtn.Draw(dt);
						_stopMusicBtn.Draw(dt);

						MusicList->Draw(dt);
						break;
					}
					case 4:
					{
						Resources::LevelHudFont.Draw("Liquid type", { 0.3f,0.2f }, { 0.025f,0.025f }, 0.001f);

						_waterCb->Draw(dt);
						_lavaCb->Draw(dt);
						_poisonCb->Draw(dt);

						Resources::LevelHudFont.Draw("Raise the liquid level by", { 0.3f,0.4f }, { 0.025f,0.025f }, 0.001f);
						Resources::LevelHudFont.Draw("using the  and  buttons", { 0.3f,0.43f }, { 0.025f,0.025f }, 0.001f); // draw + and - buttons separately
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
		//draw water

		DrawTexturePro(
			static_cast<Texture2D>(_squareMouse),
			{ 0,0,64,64 },
			calculateWorldTransformation(Game::ScreenRec(
			{
				((_lastMousePos.x + cameraPosition.x) - std::fmod(_lastMousePos.x + cameraPosition.x,Game::Resolution::FltX()/20)) / Game::Resolution::FltX() ,
				((_lastMousePos.y + cameraPosition.y) - std::fmod(_lastMousePos.y + cameraPosition.y,Game::Resolution::FltY()/15)) / Game::Resolution::FltY() ,
				0.05f,
				1 / 15.0f 
			}
			)),
			{ 0.0f,0.0f }, 
			0.0f, WHITE
		);
	}
}

void inline LevelEditor::SetItemCategory(int id)
{
	categoryId = id;
	PlaySound(static_cast<Sound>(Resources::LakituDrop[2]));
}

void inline LevelEditor::SetSubCategory(int id)
{
	subCategoryId = id;
	PlaySound(static_cast<Sound>(Resources::LakituDrop[2]));
}