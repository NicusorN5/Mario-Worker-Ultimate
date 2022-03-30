#include "MainMenu.hpp"

void MainMenu::LoadContent()
{
    _backroundImg = Resources::LoadTextureChkF("Data\\UI\\MainMenuBackround.png");
    _btnEdit = Resources::LoadTextureChkF("Data\\UI\\ButtonEdit.png");
    _logo = Resources::LoadTextureChkF("Data\\UI\\MarioWorkerUltimate.png");
    _btnPlay = Resources::LoadTextureChkF("Data\\UI\\ButtonPlay.png");
    _glint = Resources::LoadTextureChkF("Data\\UI\\ButtonGlint.png");
}

void MainMenu::Update(float dt,MouseState *ms,ControllerState *cs)
{
    if(ms->MouseInsideRectangle(_coordBtnEdit))
    {
        hoveredButtonIndex = 1;
        glintAnimTimer += 100 * dt;
    }
    else if(ms->MouseInsideRectangle(_coordBtnPlay))
    {
        hoveredButtonIndex = 2;
        glintAnimTimer += 100 * dt;
    }
    else
    {
        hoveredButtonIndex = 0;
        glintAnimTimer = 0;
    }

    hoveredButtonIndex = (int)hoveredButtonIndex % 255;

    if(ms->MouseFinishedClickingRectangle(_coordBtnEdit))
    {
        Game::CurrentGameSection = 1;
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

}

void MainMenu::Draw(float dt)
{
    DrawTexturePro(_backroundImg, {0,0,1024,1024}, Game::ScreenRec({ 0,0,1,1 }), { 0,0 }, 0.0f, WHITE);
    DrawTexturePro(_logo, { 0,0,603,161 }, Game::ScreenRec({0.1f,0.05f,0.7f,0.2f}), { 0,0 }, 0.0f, WHITE);
    DrawTexturePro(_btnEdit, { 0,0,123,137 }, _coordBtnEdit, { 0,0 }, 0.0f, WHITE);
    DrawTexturePro(_btnPlay, { 0,0,120,163 }, _coordBtnPlay, { 0,0 }, 0.0f, WHITE);

    switch(hoveredButtonIndex)
    {
        case 1:
            DrawTexturePro(_glint, { 256,256 }, _coordBtnEdit, { 0,0 }, 0.0f, {255,255,255,255 });
            break;
        case 2:
            DrawTexturePro(_glint, { 256,256 }, _coordBtnPlay, { 0,0 }, 0.0f, { 255,255,255,255 });
            break;
        default: break;
    }
}

MainMenu::~MainMenu()
{
}
