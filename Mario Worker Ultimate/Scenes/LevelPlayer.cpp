#include "LevelPlayer.hpp"

LevelPlayer::LevelPlayer() :
	testGoomba(0, 0, GoombaType::Normal)
{

}

void LevelPlayer::LoadContent()
{
	testGoomba.InEditor = true;
	testGoomba.SetScene(this);
}

void LevelPlayer::Update(float dt, MouseState* ms, ControllerState* cs)
{
	//invalid level path
	if(!Game::CurrentLevel.IsValid)
	{
		BlankScene::Update();
		//return;
	}

	testGoomba.Update(dt);
}

void LevelPlayer::Draw(float dt)
{
	if(!Game::CurrentLevel.IsValid)
	{
		BlankScene::Draw();
		//return;
	}

	testGoomba.Draw(dt);
}
