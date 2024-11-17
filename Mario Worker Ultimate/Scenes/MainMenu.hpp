#pragma once
#include "IScene.hpp"
#include "../Game.hpp"
#include "../Resources.hpp"
#include "../UI/ShinyButton.hpp"
#include "../ControllerState.hpp"

class MainMenu : public IScene
{
	Texture2DW _BackgroundImg;
	Texture2DW _btnEdit;
	Texture2DW _logo;
	Texture2DW _btnPlay;
	Texture2DW _btnQuit;

	ShinyButton _editButton;
	ShinyButton _createMapButton;
	ShinyButton _settingsButton;

	ShinyButton _playButton;
	ShinyButton _playMapButton;
	ShinyButton _quitButton;

	Texture2D _glint;

	float marioAnimTimer = 0.0f;
	SoundW _welcomeMarioWorker;
	Texture2DW _mainMenuMario;

	bool _playedApplause = false;
	SoundW _applause;

	bool playingMusic = false;
	MusicW _mainMenuMusic;

	bool _disableAnimations = false;
public:
	MainMenu() = default;
	MainMenu(const MainMenu&) = delete;
	MainMenu(MainMenu&&) noexcept = default;

	MainMenu& operator=(const MainMenu&) = delete;
	MainMenu& operator=(MainMenu&&) = delete;

	void LoadContent() final override;
	void Update(float dt,MouseState *ms, ControllerState* cs) final override;
	void Draw(float dt) final override;
};

