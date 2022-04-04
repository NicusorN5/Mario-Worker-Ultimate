#pragma once
#include "IGamePart.hpp"
#include "Game.hpp"
#include "Resources.hpp"

class MainMenu : public IGamePart
{
	Texture2D _backroundImg;
	Texture2D _btnEdit;
	Texture2D _logo;
	Texture2D _btnPlay;
	Texture2D _btnQuit;

	Rectangle _coordBtnEdit = Game::ScreenRec({ 0.25f,0.3f,0.2f,0.2f });
	Rectangle _coordBtnPlay = Game::ScreenRec({ 0.25f,0.55f,0.2f,0.2f });
	Rectangle _coordBtnQuit = Game::ScreenRec({ 0.75f, 0.55f,0.2f,0.2f });

	float glintAnimTimer = 0.0f;
	Texture2D _glint;
	uint8_t hoveredButtonIndex = 0;

	uint8_t _calculateGlintAlpha(float animTimer);

	float marioAnimTimer = 0.0f;
	Sound _welcomeMarioWorker;
	Music _mainMenuMusic;
	Texture _mainMenuMario;

	bool _playedApplause = false;
	Sound _applause;
public:
	void LoadContent() override;
	void Update(float dt,MouseState *ms, ControllerState* cs) override;
	void Draw(float dt) override;

	~MainMenu();
};

