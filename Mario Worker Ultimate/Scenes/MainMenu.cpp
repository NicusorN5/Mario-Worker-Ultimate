#include "MainMenu.hpp"

void MainMenu::LoadContent()
{
	_BackgroundImg = Texture2DW("Data\\UI\\MainMenuBackground.png");
	_logo = Texture2DW("Data\\UI\\MarioWorkerUltimate.png");
	//buttons
	_btnEdit = Texture2DW("Data\\UI\\ButtonEdit.png");
	_btnPlay = Texture2DW("Data\\UI\\ButtonPlay.png");
	_glint = static_cast<Texture2D>(Resources::BtnGlint);
	_btnQuit = Texture2DW("Data\\UI\\ButtonQuit.png");

	//welcome screen animation things
	_welcomeMarioWorker = SoundW("Data\\Sounds\\MarioWorker.wav");
	_mainMenuMusic = MusicW("Data\\Music\\GameSelect.wav");
	_mainMenuMario = Texture2DW("Data\\UI\\MarioTitleScreen.png");
	_applause = SoundW("Data\\Sounds\\Applause.mp3");

	_editButton = ShinyButton(
		static_cast<Texture2D>(_btnEdit),
		_glint, Game::ScreenRec({ 0.25f,0.3f,0.2f,0.2f }),
		[this]() -> void
		{
			Game::CurrentGameSection = 2;
			_disableAnimations = true;
		}
	);

	_playButton = ShinyButton(
		static_cast<Texture2D>(_btnPlay),
		_glint,
		Game::ScreenRec({ 0.25f,0.55f,0.2f,0.2f }),
		[this]() -> void
		{
			FileDialogResult *r = ShowOpenFileDialog("Open a level...");
			if(r->Result == 0)
			{
				Game::CurrentLevel = Level(r->File);
				if(Game::CurrentLevel.IsValid)
				{
					Game::CurrentGameSection = 3;
				}
			}
			delete r;

			_disableAnimations = true;
		}
	);

	_quitButton = ShinyButton(
		static_cast<Texture2D>(_btnQuit),
		_glint,
		Game::ScreenRec({ 0.75f, 0.55f,0.2f,0.2f }),
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
	
	if(!_disableAnimations)
	{
		if(marioAnimTimer == 0.0f)
		{
			PlaySound(static_cast<Sound>(_welcomeMarioWorker));
		}
		if(marioAnimTimer >= 3.0f && !_playedApplause)
		{
			_playedApplause = true;
			PlaySound(static_cast<Sound>(_applause));
		}
		if(marioAnimTimer >= 4.0f)
		{
			if(!playingMusic)
			{
				playingMusic = true;
				PlayMusicStream(static_cast<Music>(_mainMenuMusic));
			}
			UpdateMusicStream(static_cast<Music>(_mainMenuMusic));
		}
		marioAnimTimer += dt;
	}
}

void MainMenu::Draw(float dt)
{
	DrawTexturePro(
		static_cast<Texture2D>(_BackgroundImg),
		Rectangle(0,0,1024,1024),
		Game::ScreenRec({ 0,0,1,1 }),
		Vector2( 0,0 ),
		0.0f,
		WHITE
	);
	DrawTexturePro(
		static_cast<Texture2D>(_logo),
		Rectangle{ 0,0,603,161 },
		Game::ScreenRec({0.1f,0.05f,0.7f,0.2f}),
		Vector2{ 0,0 },
		0.0f,
		WHITE
	);

	_editButton.Draw(dt);
	_playButton.Draw(dt);
	_quitButton.Draw(dt);
	
	if(!_disableAnimations)
	{
		DrawTexturePro(
			static_cast<Texture2D>(_mainMenuMario),
			{ 0,0,(float)_mainMenuMario.Width(),(float)_mainMenuMario.Height()},
			Game::ScreenRec({ 0.01f,1.0f - (std::clamp(marioAnimTimer,0.0f,3.0f) / 5) ,0.2f,0.6f }),
			{ 0,0 },
			0.0f,
			WHITE
		);
	}
}
