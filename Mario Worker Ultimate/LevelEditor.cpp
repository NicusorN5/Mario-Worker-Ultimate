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

	_tBlocksTabHov = Resources::LoadTextureChkF("Data\\Editor\\Editor_BlocksTab.png");
	_tBlocksTabUnhov = Resources::LoadTextureChkF("Data\\Editor\\Editor_BlocksTabClosed.png");
	_blocksBtn = TabButton(_tBlocksTabUnhov, _tBlocksTabHov,
		Game::ScreenRec({ 0.257f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.257f,0.067f,0.15f,0.075f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(0);
		}
	);

	_tEnemiesTabHov = Resources::LoadTextureChkF("Data\\Editor\\Editor_EnemiesTab.png");
	_tEnemiesTabUnhov = Resources::LoadTextureChkF("Data\\Editor\\Editor_EnemiesTabClosed.png");
	_enemiesBtn = TabButton(_tEnemiesTabUnhov, _tEnemiesTabHov,
		Game::ScreenRec({ 0.333f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.333f,0.067f,0.15f,0.075f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(1);
		}
	);

	_tBonusTabHov = Resources::LoadTextureChkF("Data\\Editor\\Editor_BonusTab.png");
	_tBonusTabUnhov = Resources::LoadTextureChkF("Data\\Editor\\Editor_BonusTabClosed.png");
	_bonusBtn = TabButton(_tBonusTabUnhov, _tBonusTabHov,
		Game::ScreenRec({ 0.409f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.409f,0.067f,0.15f,0.075f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(2);
		}
	);

	_tMarksTabHov = Resources::LoadTextureChkF("Data\\Editor\\Editor_MarksTab.png");
	_tMarksTabUnhov = Resources::LoadTextureChkF("Data\\Editor\\Editor_MarksTabClosed.png");
	_marksBtn = TabButton(_tMarksTabUnhov, _tMarksTabHov,
		Game::ScreenRec({ 0.485f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.485f,0.067f,0.15f,0.075f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(3);
		}
	);

	_tSceneryTabHov = Resources::LoadTextureChkF("Data\\Editor\\Editor_SceneryTab.png");
	_tSceneryTabUnhov = Resources::LoadTextureChkF("Data\\Editor\\Editor_SceneryTabClosed.png");
	_sceneryBtn = TabButton(_tSceneryTabUnhov, _tSceneryTabHov,
		Game::ScreenRec({ 0.561f,0.067f,0.075f,0.075f }),
		Game::ScreenRec({ 0.561f,0.067f,0.15f,0.075f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetItemCategory(4);
		}
	);

	_tSettingsTabHov = Resources::LoadTextureChkF("Data\\Editor\\Editor_SettingsTab.png");
	_tSettingsTabUnhov = Resources::LoadTextureChkF("Data\\Editor\\Editor_SettingsTabClosed.png");
	_settingsBtn = TabButton(_tSettingsTabUnhov, _tSettingsTabHov,
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

	//blocks categories
	_tTerrainSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Terrain.png");
	_btnTerrain = ShinyButton(_tTerrainSub, _tGlint,Game::ScreenRec({ 0.095f,0.148f,0.15f,0.075f }),ssc0);

	_tBlocksSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Blocks.png");
	_btnBlocks = ShinyButton(_tBlocksSub, _tGlint,Game::ScreenRec({ 0.095f,0.225f,0.15f,0.075f }),ssc1);

	_tTankSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Tank.png");
	_btnTank = ShinyButton(_tTankSub, _tGlint,Game::ScreenRec({ 0.095f,0.302f,0.15f,0.075f }),ssc2);

	_tPipesSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Pipes.png");
	_btnPipes = ShinyButton(_tPipesSub, _tGlint,Game::ScreenRec({ 0.095f,0.379f,0.15f,0.075f }),ssc3);

	_tCustomBlocks = Resources::LoadTextureChkF("Data\\Editor\\sb_CustomBlocks.png");
	_btnCustomBlocks = ShinyButton(_tCustomBlocks, _tGlint, Game::ScreenRec({ 0.095f,0.456f,0.15f,0.075f }),ssc4);

	//enemies categories
	_tEnemiesSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Enemies.png");
	_btnEnemies = ShinyButton(_tEnemiesSub, _tGlint,Game::ScreenRec({ 0.095f,0.148f,0.15f,0.075f }),ssc0);

	_tHazardsSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Hazards.png");
	_btnHazard = ShinyButton(_tHazardsSub, _tGlint, Game::ScreenRec({ 0.095f,0.225f,0.15f,0.075f }), ssc1);

	_tClonesSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Clones.png");
	_btnClones = ShinyButton(_tClonesSub, _tGlint, Game::ScreenRec({ 0.095f,0.302f,0.15f,0.075f }), ssc2);

	_tBossesSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Bosses.png");
	_btnBosses = ShinyButton(_tBossesSub, _tGlint, Game::ScreenRec({ 0.095f,0.379f,0.15f,0.075f }), ssc3);

	_tCustomEnemiesSub = Resources::LoadTextureChkF("Data\\Editor\\sb_CustomEnemies.png");
	_btnCustomEnemies = ShinyButton(_tCustomEnemiesSub, _tGlint, Game::ScreenRec({ 0.095f,0.456f,0.15f,0.075f }), ssc4);

	_tCustomBossesSub = Resources::LoadTextureChkF("Data\\Editor\\sb_CustomBoss.png");
	_btnCustomBosses = ShinyButton(_tCustomBossesSub, _tGlint, Game::ScreenRec({ 0.095f,0.533f,0.15f,0.075f }), ssc5);

	_tBonusesSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Bonuses.png");
	_btnBonuses = ShinyButton(_tBonusesSub, _tGlint, Game::ScreenRec({ 0.095f,0.148f,0.15f,0.075f }), ssc0);

	_tCustomBonuses = Resources::LoadTextureChkF("Data\\Editor\\sb_CustomBonuses.png");
	_btnCustomBonuses = ShinyButton(_tCustomBonuses, _tGlint, Game::ScreenRec({ 0.095f,0.225f,0.15f,0.075f }), ssc1);


	_tLevelProgressSub = Resources::LoadTextureChkF("Data\\Editor\\sb_LevelProgress.png");
	_btnLevelProgress = ShinyButton(_tLevelProgressSub, _tGlint, Game::ScreenRec({ 0.095f,0.148f,0.15f,0.075f }), ssc0);

	_tPlatformsSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Platforms.png");
	_btnPlatforms = ShinyButton(_tPlatformsSub,_tGlint, Game::ScreenRec({ 0.095f,0.225f,0.15f,0.075f }), ssc1);

	_tMarksSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Marks.png");
	_btnMarks = ShinyButton(_tMarksSub,_tGlint, Game::ScreenRec({ 0.095f,0.302f,0.15f,0.075f }), ssc2);

	_tWarpsSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Pipes.png");
	_btnPipes = ShinyButton(_tWarpsSub,_tGlint, Game::ScreenRec({ 0.095f,0.379f,0.15f,0.075f }), ssc3);

	_tScriptedInstances = Resources::LoadTextureChkF("Data\\Editor\\sb_Scripts.png");
	_btnScripts = ShinyButton(_tScriptedInstances,_tGlint, Game::ScreenRec({ 0.095f,0.456f,0.15f,0.075f }), ssc4);

	_squareMouse = Resources::LoadTextureChkF("Data\\Editor\\CurrentTileSquare.png");

	_tOverworldSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Overworld.png");
	_btnOverworld = ShinyButton(_tOverworldSub,_tGlint, Game::ScreenRec({ 0.095f,0.148f,0.15f,0.075f }), ssc0);

	_tUndergroundSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Underground.png");
	_btnUnderground = ShinyButton(_tUndergroundSub, _tGlint, Game::ScreenRec({ 0.095f,0.225f,0.15f,0.075f }), ssc1);

	_tStarlandSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Starland.png");
	_btnStarland = ShinyButton(_tStarlandSub,_tGlint, Game::ScreenRec({ 0.095f,0.302f,0.15f,0.075f }), ssc2);

	_tSnowlandSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Starland.png");
	_btnSnowland = ShinyButton(_tSnowlandSub,_tGlint, Game::ScreenRec({ 0.095f,0.379f,0.15f,0.075f }), ssc3);

	_tDarklandSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Darkland.png");
	_btnDarkland = ShinyButton(_tDarklandSub, _tGlint, Game::ScreenRec({ 0.095f,0.456f,0.15f,0.075f }), ssc4);

	_tSunsetSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Sunset.png");
	_btnSunset = ShinyButton(_tSunsetSub, _tGlint, Game::ScreenRec({ 0.095f,0.533f,0.15f,0.075f }), ssc5);

	_tDesertSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Desert.png");
	_btnDesert = ShinyButton(_tDesertSub, _tGlint, Game::ScreenRec({ 0.095f,0.610f,0.15f,0.075f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetSubCategory(6);
		}
	);

	_tCastleSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Castle.png");
	_btnCastle = ShinyButton(_tCastleSub,_tGlint, Game::ScreenRec({ 0.095f,0.687f,0.15f,0.075f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetSubCategory(7);
		}
	);

	_tTilesSub = Resources::LoadTextureChkF("Data\\Editor\\sb_Tiles.png");
	_btnTiles = ShinyButton(_tTilesSub,_tGlint,Game::ScreenRec({ 0.095f,0.764f,0.15f,0.075f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetSubCategory(8);
		}
	);

	_tCustomDecoSub = Resources::LoadTextureChkF("Data\\Editor\\sb_CustomScenery.png");
	_btnCustomDeco = ShinyButton(_tCustomDecoSub,_tGlint, Game::ScreenRec({ 0.095f,0.841f,0.15f,0.075f }),
		[]() -> void
		{
			LevelEditor::GetSingleton()->SetSubCategory(9);
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
			_enemiesBtn.SetXOffset(0.075f);
			_bonusBtn.SetXOffset(0.075f);
			_marksBtn.SetXOffset(0.075f);
			_sceneryBtn.SetXOffset(0.075f);
			_settingsBtn.SetXOffset(0.075f);
		}
		else if(_enemiesBtn.Raised())
		{
			_enemiesBtn.SetXOffset(0);
			_bonusBtn.SetXOffset(0.075f);
			_marksBtn.SetXOffset(0.075f);
			_sceneryBtn.SetXOffset(0.075f);
			_settingsBtn.SetXOffset(0.075f);
		}
		else if(_bonusBtn.Raised())
		{
			_marksBtn.SetXOffset(0.075f);
			_sceneryBtn.SetXOffset(0.075f);
			_settingsBtn.SetXOffset(0.075f);
		}
		else if(_marksBtn.Raised())
		{
			_sceneryBtn.SetXOffset(0.075f);
			_settingsBtn.SetXOffset(0.075f);
		}
		else if(_sceneryBtn.Raised())
		{
			_settingsBtn.SetXOffset(0.075f);
		}
		else
		{
			_enemiesBtn.SetXOffset(0);
			_bonusBtn.SetXOffset(0);
			_marksBtn.SetXOffset(0);
			_sceneryBtn.SetXOffset(0);
			_settingsBtn.SetXOffset(0);
		}
		//updating tab buttons logic
		_blocksBtn.Update(ms, dt);
		_enemiesBtn.Update(ms, dt);
		_bonusBtn.Update(ms, dt);
		_marksBtn.Update(ms, dt);
		_sceneryBtn.Update(ms, dt);
		_settingsBtn.Update(ms, dt);

		switch(categoryId)
		{
			case 0:
			{
				_btnTerrain.Update(ms, dt);
				_btnBlocks.Update(ms, dt);
				_btnTank.Update(ms, dt);
				_btnPipes.Update(ms, dt);
				_btnCustomBlocks.Update(ms, dt);
				switch(subCategoryId)
				{
					default:break;
				}
				break;
			}
			case 1:
			{
				_btnEnemies.Update(ms, dt);
				_btnHazard.Update(ms, dt);
				_btnClones.Update(ms, dt);
				_btnBosses.Update(ms, dt);
				_btnCustomEnemies.Update(ms, dt);
				_btnCustomBosses.Update(ms, dt);
				switch(subCategoryId)
				{
					default:break;
				}
				break;
			}
			case 2:
			{
				_btnBonuses.Update(ms, dt);
				_btnCustomBonuses.Update(ms, dt);
				switch(subCategoryId)
				{
					default: break;
				}
				break;
			}
			case 3:
			{
				_btnLevelProgress.Update(ms, dt);
				_btnPlatforms.Update(ms, dt);
				_btnMarks.Update(ms, dt);
				_btnWarps.Update(ms, dt);
				_btnPipes.Update(ms, dt);
				_btnScripts.Update(ms, dt);
				switch(subCategoryId)
				{
					default: break;
				}
				break;
			}
			case 4:
			{
				_btnOverworld.Update(ms,dt);
				_btnUnderground.Update(ms, dt);
				_btnStarland.Update(ms, dt);
				_btnSnowland.Update(ms, dt);
				_btnDarkland.Update(ms, dt);
				_btnSunset.Update(ms, dt);
				_btnDesert.Update(ms, dt);
				_btnCastle.Update(ms, dt);
				_btnTiles.Update(ms, dt);
				_btnCustomDeco.Update(ms, dt);
				switch(subCategoryId)
				{
					default: break;
				}
				break;
			}
			default:break;
		}

		if(!_previousSpacePress && cs->Space) _showElements = false;
	}
	_previousSpacePress = cs->Space;
	_lastMousePos = { (float)ms->X,(float)ms->Y };
}

void LevelEditor::Draw(float dt)
{
	Game::CurrentLevel.LvlBackround.Draw(cameraPosition, Game::CurrentLevel.Size);
	
	DrawTexturePro(_square, { 0,0,64 * Game::CurrentLevel.Size.x,64 * Game::CurrentLevel.Size.y}, calculateTileTransformation(Game::ScreenRec({0,0,Game::CurrentLevel.Size.x / 20,Game::CurrentLevel.Size.y / 15})), {0,0}, 0.0f, WHITE);
	DrawTexturePro(Resources::Goomba1, { 0,0,31,32 }, calculateWorldTransformation(Game::ScreenRec({ 0,0,0.05f,1/15.0f })), { 0,0 }, 0.0f, WHITE); // <-- test goomba

	if(_showElements)
	{
		DrawTexturePro(W_selectItem, { 0,0,800,600 }, Game::ScreenRec({ 0,0,1,1 }), { 0,0 }, 0.0f, WHITE);
		_blocksBtn.Draw(dt);
		_enemiesBtn.Draw(dt);
		_bonusBtn.Draw(dt);
		_marksBtn.Draw(dt);
		_sceneryBtn.Draw(dt);
		_settingsBtn.Draw(dt);

		switch(categoryId)
		{
			case 0:
			{
				_btnTerrain.Draw(dt);
				_btnBlocks.Draw(dt);
				_btnTank.Draw(dt);
				_btnPipes.Draw(dt);
				_btnCustomBlocks.Draw(dt);
				switch(subCategoryId)
				{
					default:break;
				}
				break;
			}
			case 1:
			{
				_btnEnemies.Draw(dt);
				_btnHazard.Draw(dt);
				_btnClones.Draw(dt);
				_btnBosses.Draw(dt);
				_btnCustomEnemies.Draw(dt);
				_btnCustomBosses.Draw(dt);
				switch(subCategoryId)
				{
					default:break;
				}
				break;
			}
			case 2:
			{
				_btnBonuses.Draw(dt);
				_btnCustomBonuses.Draw(dt);
				switch(subCategoryId)
				{
					default: break;
				}
				break;
			}
			case 3:
			{
				_btnLevelProgress.Draw(dt);
				_btnPlatforms.Draw(dt);
				_btnMarks.Draw(dt);
				_btnWarps.Draw(dt);
				_btnPipes.Draw(dt);
				_btnScripts.Draw(dt);
				switch(subCategoryId)
				{
					default: break;
				}
				break;
			}
			case 4:
			{
				_btnOverworld.Draw(dt);
				_btnUnderground.Draw(dt);
				_btnStarland.Draw(dt);
				_btnSnowland.Draw(dt);
				_btnDarkland.Draw(dt);
				_btnSunset.Draw(dt);
				_btnDesert.Draw(dt);
				_btnCastle.Draw(dt);
				_btnTiles.Draw(dt);
				_btnCustomDeco.Draw(dt);
				switch(subCategoryId)
				{
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
}