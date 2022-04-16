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
	Texture _square;

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