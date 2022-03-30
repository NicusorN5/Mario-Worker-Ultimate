#include "MainMenu.hpp"

void MainMenu::LoadContent()
{
    TitleScreen = LoadTexture("Data\\UI\\MainMenuBackround.png");
}

void MainMenu::Update(float dt)
{
    
}

void MainMenu::Draw(float dt)
{
    DrawTexturePro(TitleScreen, { 0,0,1024,1024 }, { 0,0,Game::Resolution::FltX(),Game::Resolution::FltY() }, { 0,0 }, 0.0f, WHITE);
}

MainMenu::~MainMenu()
{
}
