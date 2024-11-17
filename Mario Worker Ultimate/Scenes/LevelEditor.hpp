#pragma once
#include "IScene.hpp"
#include "../Game.hpp"
#include "../Libs.hpp"
#include "../Resources.hpp"
#include "../Resolution.hpp"
#include "../UI/TabButton.hpp"
#include "../UI/ShinyButton.hpp"
#include "../UI/Textbox.hpp"
#include "../UI/Slider.hpp"
#include "../UI/Checkbox.hpp"
#include "../UI/Listbox.hpp"

class LevelEditor : public IScene
{
	Vector2 cameraPosition = { 0,0 };
	Texture2DW _square;

	float levelPx = 0;
	float levelPy = 0;

	Rectangle calculateWorldTransformation(Rectangle normScreen);
	Rectangle calculateTileTransformation(Rectangle normScreen);

	bool _showElements = false;
	bool _previousSpacePress = false;

	int categoryId = 0;
	int subCategoryId = 0;

	Texture2DW W_selectItem;
	Texture2D _tGlint;

	//main categories
	std::array<TabButton, 6> _tabButtons;
	std::array<Texture2DW, 6> _tabTexturesHovered;
	std::array<Texture2DW, 6> _tabTexturesUnhovered;

	//blocks types
	std::array<Texture2DW, 5> _blocksBtnTextures;
	std::array<ShinyButton, 5> _blocksButtons;

	//enemies types
	std::array<Texture2DW, 6> _enemiesBtnTextures;
	std::array<ShinyButton, 6> _enemiesButtons;

	//bonuses types
	std::array<Texture2DW, 2> _bonusesBtnTextures;
	std::array<ShinyButton, 2> _bonusesButtons;

	//mark types
	std::array<Texture2DW, 5> _marksBtnTextures;
	std::array<ShinyButton, 5> _marksButtons;

	//decoration types
	std::array<Texture2DW, 9> _sceneryBtnTextures;
	std::array<ShinyButton, 9> _sceneryButtons;

	//level settings buttons
	std::array<Texture2DW, 8> _settingsBtnTextures;
	std::array<ShinyButton, 8> _settingsButtons;

	//level editor stuff
	Texture2DW _squareMouse;
	Vector2 _lastMousePos;

	bool _progressSaved = true;
	bool _showNotifNotSaved = false;

	//settings -> level info
	std::array<std::unique_ptr<Textbox>, 2> _levelNameTbs;
	std::unique_ptr<Textbox> _authorTb;
	std::unique_ptr<Textbox> _emailTb;
	std::unique_ptr<Textbox> _websiteTb;

	Slider _levelWidthSl;
	Slider _levelHeightSl;

	std::unique_ptr<Textbox> _levelTime;

	//settings -> settings
	std::array<Texture2DW, 12> _levelSettingsTxs;
	std::array<ShinyButton, 12> _levelSettingsBtns;

	int _currentSettingId = 0;
	std::array<Slider, 12> _levelSettingsSliders;

	//settings -> backrounds
	int _backgroundSettingId = 0;

	ShinyButton _bckLeftBtn;
	ShinyButton _bckRightBtn;

	std::array<Texture2DW, 9> _backgroundsTxds;
	std::array<ShinyButton, 9> _backgroundsBtns;

	Texture2DW _topColorTxd;
	ShinyButton _topColorBtn;

	Texture2DW _bottomColorTxd;
	ShinyButton _bottomColorBtn;

	Slider _overlayGradientAlphaASli;
	Slider _overlayGradientAlphaBSli;
	ShinyButton _overlayGradientCol1Btn;
	ShinyButton _overlayGradientCol2Btn;

	std::unique_ptr<Checkbox> _repeatXCb;
	std::unique_ptr<Checkbox> _repeatYCb;
	std::unique_ptr<Checkbox> _lockToScreenCb;
	std::unique_ptr<Checkbox> _lockToYCb;
	std::unique_ptr<Checkbox> _fitScreenCb;

	//settings -> music
	std::unique_ptr<Listbox> MusicList;

	Texture2DW _playMusicTxd;
	ShinyButton _playMusicBtn;

	Texture2DW _pauseMusicTxd;
	ShinyButton _pauseMusicBtn;

	Texture2DW _stopMusicTxd;
	ShinyButton _stopMusicBtn;
	
	Music _music{};

	/// <summary>
	/// 0 = stopped
	/// 1 = start playing
	/// 2 = paused
	/// 3 = playing
	/// </summary>
	int8_t _musicState = 0;

	//settings -> fluids
	std::unique_ptr<Checkbox> _waterCb;
	std::unique_ptr<Checkbox> _lavaCb;
	std::unique_ptr<Checkbox> _poisonCb;
public:
	LevelEditor() = default;

	LevelEditor(const LevelEditor&) = delete;
	LevelEditor(LevelEditor&&) noexcept = default;

	LevelEditor& operator=(const LevelEditor&) = delete;
	LevelEditor& operator=(LevelEditor&&) noexcept = default;

	void LoadContent() final override;
	void Update(float dt, MouseState* ms, ControllerState* cs) final override;
	void Draw(float dt) final override;

	void SetItemCategory(int id);
	void SetSubCategory(int id);
};