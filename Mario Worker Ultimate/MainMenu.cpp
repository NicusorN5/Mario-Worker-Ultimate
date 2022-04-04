#include "MainMenu.hpp"

uint8_t MainMenu::_calculateGlintAlpha(float animTimer)
{
    if(animTimer <= 255) return animTimer;
    else return 255 - ((int)animTimer % 255);
}

void MainMenu::LoadContent()
{
    _backroundImg = Resources::LoadTextureChkF("Data\\UI\\MainMenuBackround.png");
    _logo = Resources::LoadTextureChkF("Data\\UI\\MarioWorkerUltimate.png");
    //buttons
    _btnEdit = Resources::LoadTextureChkF("Data\\UI\\ButtonEdit.png");
    _btnPlay = Resources::LoadTextureChkF("Data\\UI\\ButtonPlay.png");
    _glint = Resources::LoadTextureChkF("Data\\UI\\ButtonGlint.png");
    _btnQuit = Resources::LoadTextureChkF("Data\\UI\\ButtonQuit.png");

    //welcome screen animation things
    _welcomeMarioWorker = Resources::LoadSoundChkF("Data\\Sounds\\marioworker.ogg");
    _mainMenuMusic;
    _mainMenuMario = Resources::LoadTextureChkF("Data\\UI\\MarioTitleScreen.png");
    _applause = Resources::LoadSoundChkF("Data\\Sounds\\applause.ogg");
}

void MainMenu::Update(float dt,MouseState *ms,ControllerState *cs)
{
    //buttons
    if(ms->MouseInsideRectangle(_coordBtnEdit))
    {
        hoveredButtonIndex = 1;
        glintAnimTimer += 200 * dt;
    }
    else if(ms->MouseInsideRectangle(_coordBtnPlay))
    {
        hoveredButtonIndex = 2;
        glintAnimTimer += 200 * dt;
    }
    else if(ms->MouseInsideRectangle(_coordBtnQuit))
    {
        hoveredButtonIndex = 3;
        glintAnimTimer += 200 * dt;
    }
    else
    {
        hoveredButtonIndex = 0;
        glintAnimTimer = 0;
    }

    glintAnimTimer = (int)glintAnimTimer % 510;

    if(ms->MouseFinishedClickingRectangle(_coordBtnEdit))
    {
        Game::CurrentGameSection = 2;
    }
    if(ms->MouseFinishedClickingRectangle(_coordBtnPlay))
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
    if(ms->MouseFinishedClickingRectangle(_coordBtnQuit))
    {
        Game::GameRunning = false;
    }
    
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
    marioAnimTimer += dt;
}

void MainMenu::Draw(float dt)
{
    DrawTexturePro(_backroundImg, {0,0,1024,1024}, Game::ScreenRec({ 0,0,1,1 }), { 0,0 }, 0.0f, WHITE);
    DrawTexturePro(_logo, { 0,0,603,161 }, Game::ScreenRec({0.1f,0.05f,0.7f,0.2f}), { 0,0 }, 0.0f, WHITE);
    DrawTexturePro(_btnEdit, { 0,0,123,137 }, _coordBtnEdit, { 0,0 }, 0.0f, WHITE);
    DrawTexturePro(_btnPlay, { 0,0,120,163 }, _coordBtnPlay, { 0,0 }, 0.0f, WHITE);
    DrawTexturePro(_btnQuit, { 0,0,115,126 }, _coordBtnQuit, { 0,0 }, 0.0f, WHITE);

    uint8_t glintAlpha = _calculateGlintAlpha(glintAnimTimer);

    switch(hoveredButtonIndex)
    {
        case 1:
            DrawTexturePro(_glint, {0,0,256,256 }, _coordBtnEdit, { 0,0 }, 0.0f, {255,255,255,glintAlpha });
            break;
        case 2:
            DrawTexturePro(_glint, {0,0,256,256 }, _coordBtnPlay, { 0,0 }, 0.0f, { 255,255,255,glintAlpha });
            break;
        case 3:
            DrawTexturePro(_glint, { 0,0,256,256 }, _coordBtnQuit, { 0,0 }, 0.0f, { 255,255,255,glintAlpha });
            break;
        default: break;
    }

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
