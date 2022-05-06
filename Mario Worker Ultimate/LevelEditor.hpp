#pragma once
#include "IGamePart.hpp"
#include "Game.hpp"
#include "Libs.hpp"
#include "Resources.hpp"
#include "Resolution.hpp"
#include "TabButton.hpp"
#include "ShinyButton.hpp"

class LevelEditor : public IGamePart
{
	Vector2 cameraPosition = { 0,0 };
	Texture2D _square{};

	float levelPx = 0;
	float levelPy = 0;

	Rectangle calculateWorldTransformation(Rectangle normScreen);
	Rectangle calculateTileTransformation(Rectangle normScreen);

	bool _showElements = false;
	bool _previousSpacePress = false;
	// 1 = tiles
	// 2 = enemies
	// 3 = etc
	int categoryId = 0;
	//overwold tiles , desert tiles, et cetera
	int subCategoryId = 0;

	Texture2D W_selectItem{};
	Texture2D _tGlint{ 11,256,256,7 };

	// no, I'm not using arrays >:(
	//nor dictionaries

	//main categories
	TabButton _blocksBtn{};
	Texture2D _tBlocksTabHov{};
	Texture2D _tBlocksTabUnhov{};

	TabButton _enemiesBtn{};
	Texture2D _tEnemiesTabHov{};
	Texture2D _tEnemiesTabUnhov{};

	TabButton _bonusBtn{};
	Texture2D _tBonusTabHov{};
	Texture2D _tBonusTabUnhov{};

	TabButton _marksBtn{};
	Texture2D _tMarksTabHov{};
	Texture2D _tMarksTabUnhov{};

	TabButton _sceneryBtn{};
	Texture2D _tSceneryTabHov{};
	Texture2D _tSceneryTabUnhov{};

	TabButton _settingsBtn{};
	Texture2D _tSettingsTabHov{};
	Texture2D _tSettingsTabUnhov{};

	//block types
	Texture2D _tTerrainSub{};
	Texture2D _tBlocksSub{};
	Texture2D _tTankSub{};
	Texture2D _tPipesSub{};
	Texture2D _tCustomBlocks{};

	ShinyButton _btnTerrain{};
	ShinyButton _btnBlocks{};
	ShinyButton _btnTank{};
	ShinyButton _btnPipes{};
	ShinyButton _btnCustomBlocks{};

	//enemies types
	Texture2D _tEnemiesSub{};
	Texture2D _tHazardsSub{};
	Texture2D _tClonesSub{};
	Texture2D _tBossesSub{};
	Texture2D _tCustomEnemiesSub{};
	Texture2D _tCustomBossesSub{};

	ShinyButton _btnEnemies{};
	ShinyButton _btnHazard{};
	ShinyButton _btnClones{};
	ShinyButton _btnBosses{};
	ShinyButton _btnCustomEnemies{};
	ShinyButton _btnCustomBosses{};

	//bonuses types
	Texture2D _tBonusesSub{};
	Texture2D _tCustomBonuses{};

	ShinyButton _btnBonuses;
	ShinyButton _btnCustomBonuses;

	//mark types
	Texture2D _tLevelProgressSub{};
	Texture2D _tPlatformsSub{};
	Texture2D _tEnemyMarksSub{};
	Texture2D _tWarpsSub{};
	Texture2D _tScriptedInstances{ };

	ShinyButton _btnLevelProgress{};
	ShinyButton _btnPlatforms{};
	ShinyButton _btnEnemyMarks{};
	ShinyButton _btnWarps{};
	Texture2D _btnScripts{};

	//decoration types
	Texture2D _tOverworldSub{};
	Texture2D _tUndergroundSub{};
	Texture2D _tStarlandSub{};
	Texture2D _tShowlandSub{};
	Texture2D _tDarklandSub{};
	Texture2D _tSunsetSub{};
	Texture2D _tDesertSub{};
	Texture2D _tCastleSub{};
	Texture2D _tTilesSub{};
	Texture2D _tCustomDecoSub{};

	ShinyButton _btnOverworld{};
	ShinyButton _btnUnderground{};
	ShinyButton _btnStarland{};
	ShinyButton _btnShowland{};
	ShinyButton _btnDarkland{};
	ShinyButton _btnSunset{};
	ShinyButton _btnDesert{};
	ShinyButton _btnCastle{};
	ShinyButton _btnTiles{};
	ShinyButton _btnCustomDeco{};

	static LevelEditor* _singleton;
public:
	LevelEditor();

	void LoadContent() final override;
	void Update(float dt, MouseState* ms, ControllerState* cs) final override;
	void Draw(float dt) final override;

	static LevelEditor* GetSingleton();

	void SetItemCategory(int id);
	void SetSubCategory(int id);

	~LevelEditor();
};