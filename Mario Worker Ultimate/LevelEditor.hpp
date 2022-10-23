#pragma once
#include "IGamePart.hpp"
#include "Game.hpp"
#include "Libs.hpp"
#include "Resources.hpp"
#include "Resolution.hpp"
#include "TabButton.hpp"
#include "ShinyButton.hpp"
#include "Textbox.hpp"
#include "Slider.hpp"
#include "Checkbox.hpp"

class LevelEditor : public IGamePart
{
	static LevelEditor* _singleton;

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
	Texture2D _tGlint;

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
	Texture2D _sceneryBtnTextures[9];
	ShinyButton _sceneryButtons[9];

	//level settings buttons
	Texture2D _settingsBtnTextures[8];
	ShinyButton _settingsButtons[8];

	//level editor stuff
	Texture2D _squareMouse;
	Vector2 _lastMousePos;

	bool _progressSaved = true;
	bool _showNotifNotSaved = false;

	//settings -> level info
	Textbox _levelNameTbs[2];
	Textbox _authorTb;
	Textbox _emailTb;
	Textbox _websiteTb;

	Slider _levelWidthSl;
	Slider _levelHeightSl;

	Textbox _levelTime;

	//settings -> settings
	Texture2D _levelSettingsTxs[12];
	ShinyButton _levelSettingsBtns[12];

	int _currentSettingId = 0;
	Slider _levelSettingsSliders[12];

	//settings -> backrounds
	int _backgroundSettingId = 0;

	ShinyButton _bckLeftBtn;
	ShinyButton _bckRightBtn;

	Texture2D _backgroundsTxds[9];
	ShinyButton _backgroundsBtns[9];

	Texture2D _topColorTxd;
	ShinyButton _topColorBtn;

	Texture2D _bottomColorTxd;
	ShinyButton _bottomColorBtn;

	Slider _overlayGradientAlphaASli;
	Slider _overlayGradientAlphaBSli;
	ShinyButton _overlayGradientCol1Btn;
	ShinyButton _overlayGradientCol2Btn;

	Checkbox _repeatXCb;
	Checkbox _repeatYCb;
	Checkbox _lockToScreenCb;
	Checkbox _lockToYCb;
	Checkbox _fitScreenCb;

	//settings -> music


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