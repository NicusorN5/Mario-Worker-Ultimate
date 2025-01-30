#include "BlankScene.hpp"
#include "..\Resources.hpp"
#include "..\Game.hpp"


void BlankScene::Update()
{
	if(IsKeyReleased(KEY_ESCAPE))
	{
		Game::CurrentGameSection = 1;
	}
}

void BlankScene::Draw()
{
	DrawRectangleGradientV(0, 0, GetScreenWidth(), GetScreenHeight(), Color(60, 120, 160, 255), WHITE);
	Resources::LevelHudFont.Draw("This is an invalid scene!.", { 0.2f,0.4825f }, { 0.025f,0.025f }, 0.001f);
	Resources::LevelHudFont.Draw("Press ESC to return to main menu.", { 0.1f,0.5225f }, { 0.025f,0.025f }, 0.001f);
}
