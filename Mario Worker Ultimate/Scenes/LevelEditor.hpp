#pragma once
#include "GameBase.hpp"
#include "../UI/TabButton.hpp"
#include "../UI/ShinyButton.hpp"
#include "../UI/Textbox.hpp"
#include "../UI/Slider.hpp"
#include "../UI/Checkbox.hpp"
#include "../UI/Listbox.hpp"

constexpr float LiquidEditorRaiseSpeed = 10.0f;

class LevelEditor : public GameBase
{
	Texture2D _square{};

	float levelPx = 0;
	float levelPy = 0;

	bool _showElements = false;
	bool _previousSpacePress = false;

	int categoryId = 0;

	Texture2D W_selectItem{};
	Texture2D _tGlint{};

	//main categories
	TabButton _tabButtons[6]{};
	Texture2D _tabTexturesHovered[6]{};
	Texture2D _tabTexturesUnhovered[6]{};

	//blocks types
	Texture2D _blocksBtnTextures[5]{};
	ShinyButton _blocksButtons[5]{};
	int _blocksPageId = 0;

	//enemies types
	Texture2D _enemiesBtnTextures[6]{};
	ShinyButton _enemiesButtons[6]{};
	int _enemiesPageId = 0;

	//bonuses types
	Texture2D _bonusesBtnTextures[2]{};
	ShinyButton _bonusesButtons[2]{};
	int _bonusesPageId = 0;

	//mark types
	Texture2D _marksBtnTextures[4]{}; // !! - We're using a previous sub-category Button sprite! Namely sb_Pipes.
	ShinyButton _marksButtons[5];
	int _marksPageId = 0;

	//decoration types
	Texture2D _sceneryBtnTextures[9]{};
	ShinyButton _sceneryButtons[9];
	int _sceneryPageId = 0;

	//level settings buttons
	Texture2D _settingsBtnTextures[8]{};
	ShinyButton _settingsButtons[8];
	int _settingsPageId = 0;

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
	std::array<Texture2D, 13> _levelSettingsTxs;
	std::array<ShinyButton, 13> _levelSettingsBtns;

	int _currentSettingId = 0;
	int _settingsSubPageId = 0;
	std::array<Slider, 13> _levelSettingsSliders;

	ShinyButton _settingsLeftBtn;
	ShinyButton _settingsRightBtn;

	std::array<Checkbox,2> _levelToggles;

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
	std::unique_ptr<Listbox> MusicList;

	Texture2D _playMusicTxd;
	ShinyButton _playMusicBtn;

	Texture2D _pauseMusicTxd;
	ShinyButton _pauseMusicBtn;

	Texture2D _stopMusicTxd;
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
	Checkbox _waterCb;
	Checkbox _lavaCb;
	Checkbox _poisonCb;

	void _setItemCategory(int id);
public:
	LevelEditor() = default;

	void LoadContent() final override;
	void Update(float dt, MouseState* ms, ControllerState* cs) final override;
	void Draw(float dt) final override;

	~LevelEditor();
};