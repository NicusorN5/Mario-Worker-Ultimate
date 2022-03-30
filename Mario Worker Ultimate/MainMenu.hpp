#pragma once
#include "IGamePart.hpp"
#include "Libs.hpp"
#include "Game.hpp"
class MainMenu : public IGamePart
{
	Texture2D TitleScreen;
public:
	void LoadContent() override;
	void Update(float dt) override;
	void Draw(float dt) override;

	~MainMenu();
};

