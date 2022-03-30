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

	Rectangle _coordBtnEdit = Game::ScreenRec({ 0.15f,0.3f,0.2f,0.2f });
	Rectangle _coordBtnPlay = Game::ScreenRec({ 0.15f,0.55f,0.2f,0.2f });

	float glintAnimTimer = 0.0f;
	Texture2D _glint;
	uint8_t hoveredButtonIndex = 0;
public:
	void LoadContent() override;
	void Update(float dt,MouseState *ms, ControllerState* cs) override;
	void Draw(float dt) override;

	~MainMenu();
};

