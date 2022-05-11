#include "Intro.hpp"

uint8_t Intro::introImageAlpta(float t)
{
	if(t < 1.0f)
	{
		return 255 * t;
	}
	if(t >= 5.0f) return 255 * (5 - t);
	if(t >= 1.0f) return 255;
}

void Intro::LoadContent()
{
	_introImage = Resources::LoadTextureChkF("Data\\UI\\IntroImage.png");
}

void Intro::Update(float dt, MouseState* ms, ControllerState* cs)
{
	_introTimer += dt;

	if(_introTimer >= 6.0f) Game::CurrentGameSection = 1;
}

void Intro::Draw(float dt)
{
	DrawTexturePro(_introImage, { 0,0,796,597 }, Game::ScreenRec({ 0,0,1,1 }), { 0,0 }, 0, { 255,255,255,introImageAlpta(_introTimer) });
}

Intro::~Intro()
{
	UnloadTexture(_introImage);
}
