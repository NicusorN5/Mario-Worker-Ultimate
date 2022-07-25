#include "MainMenu.hpp"

void MainMenu::LoadContent()
{
	_backroundImg = Resources::LoadTextureChkF("Data\\UI\\MainMenuBackground.png");
	_logo = Resources::LoadTextureChkF("Data\\UI\\MarioWorkerUltimate.png");
	//buttons
	_btnEdit = Resources::LoadTextureChkF("Data\\UI\\ButtonEdit.png");
	_btnPlay = Resources::LoadTextureChkF("Data\\UI\\ButtonPlay.png");
	_glint = Resources::LoadTextureChkF("Data\\UI\\ButtonGlint.png");
	_btnQuit = Resources::LoadTextureChkF("Data\\UI\\ButtonQuit.png");

	//welcome screen animation things
	_welcomeMarioWorker = Resources::LoadSoundChkF("Data\\Sounds\\marioworker.ogg");
	_mainMenuMusic = Resources::LoadMusicChkF("Data\\Music\\GameSelect.wav");
	_mainMenuMario = Resources::LoadTextureChkF("Data\\UI\\MarioTitleScreen.png");
	_applause = Resources::LoadSoundChkF("Data\\Sounds\\applause.ogg");

	_editButton = ShinyButton(_btnEdit, _glint, Game::ScreenRec({ 0.25f,0.3f,0.2f,0.2f }), 
		[]() -> void
		{
			Game::CurrentGameSection = 2;
		}
	);

	_playButton = ShinyButton(_btnPlay, _glint, Game::ScreenRec({ 0.25f,0.55f,0.2f,0.2f }),
		[]() -> void
		{
			FileDialogResult *r = ShowOpenFileDialog("Open a level...");
			if(r->Result == 0)
			{
				Game::CurrentLevel = Level(r->File);
				if(Game::CurrentLevel.IsValid)
				{
					Game::CurrentGameSection = 2;
				}
			}
			delete r;
		}
	);

	_quitButton = ShinyButton(_btnQuit, _glint, Game::ScreenRec({ 0.75f, 0.55f,0.2f,0.2f }),
		[]() -> void
		{
			Game::GameRunning = false;
		}
	);
}

void MainMenu::Update(float dt,MouseState *ms,ControllerState *cs)
{
	//buttons
	_editButton.Update(ms, dt);
	_playButton.Update(ms, dt);
	_quitButton.Update(ms, dt);

	//mario worker welcome animation
	
	if(marioAnimTimer == 0.0f)
	{
		PlaySound(_welcomeMarioWorker);
	}
	if(marioAnimTimer >= 3.0f && !_playedApplause)
	{
		_playedApplause = true;
		PlaySound(_applause);
	}
	if(marioAnimTimer >= 4.0f)
	{
		if(!playingMusic)
		{
			playingMusic = true;
			PlayMusicStream(_mainMenuMusic);
		}
		UpdateMusicStream(_mainMenuMusic);
	}
	marioAnimTimer += dt;
}

void MainMenu::Draw(float dt)
{
	
	DrawTexturePro(_backroundImg, {0,0,1024,1024}, Game::ScreenRec({ 0,0,1,1 }), { 0,0 }, 0.0f, WHITE);
	DrawTexturePro(_logo, { 0,0,603,161 }, Game::ScreenRec({0.1f,0.05f,0.7f,0.2f}), { 0,0 }, 0.0f, WHITE);

	_editButton.Draw(dt);
	_playButton.Draw(dt);
	_quitButton.Draw(dt);
	
	DrawTexturePro(_mainMenuMario, { 0,0,143,358 }, Game::ScreenRec({ 0.01f,1.0f - (std::clamp(marioAnimTimer,0.0f,3.0f)/5) ,0.2f,0.6f}), {0,0}, 0.0f, WHITE);
}

MainMenu::~MainMenu()
{
	UnloadTexture(_backroundImg);
	UnloadTexture(_logo);
	UnloadTexture(_glint);

	UnloadTexture(_btnPlay);
	UnloadTexture(_btnEdit);
	UnloadTexture(_btnQuit);

	UnloadSound(_welcomeMarioWorker);
	UnloadMusicStream(_mainMenuMusic);
	UnloadTexture(_mainMenuMario);
}
