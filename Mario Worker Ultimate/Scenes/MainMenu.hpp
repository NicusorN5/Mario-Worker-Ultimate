#pragma once
#include "IScene.hpp"
#include "../Game.hpp"
#include "../Resources.hpp"
#include "../UI/ShinyButton.hpp"
#include "../ControllerState.hpp"

class MainMenu : public IScene
{
	Texture2D _BackgroundImg{};
	Texture2D _btnEdit{};
	Texture2D _logo{};
	Texture2D _btnPlay{};
	Texture2D _btnQuit{};

	ShinyButton _editButton{};
	ShinyButton _createMapButton{};
	ShinyButton _settingsButton{};

	ShinyButton _playButton{};
	ShinyButton _playMapButton{};
	ShinyButton _quitButton{};

	Texture2D _glint{};

	float marioAnimTimer = 0.0f;
	Sound _welcomeMarioWorker{};
	Texture _mainMenuMario{};

	bool _playedApplause = false;
	Sound _applause{};

	bool playingMusic = false;
	Music _mainMenuMusic{};

	bool _disableAnimations = false;
public:
	void LoadContent() final override;
	void Update(float dt,MouseState *ms, ControllerState* cs) final override;
	void Draw(float dt) final override;

	~MainMenu();
};

