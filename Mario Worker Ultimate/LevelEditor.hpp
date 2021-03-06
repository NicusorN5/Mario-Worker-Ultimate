#pragma once
#include "IGamePart.hpp"
#include "Game.hpp"
#include "Libs.hpp"
#include "Resources.hpp"
#include "Resolution.hpp"
#include "TabButton.hpp"
#include "ShinyButton.hpp"
#include "Textbox.hpp"

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

	int categoryId = 0;
	int subCategoryId = 0;

	Texture2D W_selectItem{};
	Texture2D _tGlint{ 13,256,256,7 };

	//main categories
	TabButton _tabButtons[6];
	Texture2D _tabTexturesHovered[6];
	Texture2D _tabTexturesUnhovered[6];

	//blocks types
	Texture2D _blocksBtnTextures[5];
	ShinyButton _blocksButtons[5];

	//enemies types
	Texture2D _enemiesBtnTextures[6];
	ShinyButton _enemiesButtons[6];

	//bonuses types
	Texture2D _bonusesBtnTextures[2];
	ShinyButton _bonusesButtons[2];

	//mark types
	Texture2D _marksBtnTextures[5];
	ShinyButton _marksButtons[5];

	//decoration types
	Texture2D _sceneryBtnTextures[10];
	ShinyButton _sceneryButtons[10];

	//level settings buttons
	Texture2D _settingsBtnTextures[8];
	ShinyButton _settingsButtons[8];

	Texture2D _squareMouse;
	Vector2 _lastMousePos;

	Textbox _levelNameTbs[2];
	Textbox emailTb;
	Textbox websiteTb;

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