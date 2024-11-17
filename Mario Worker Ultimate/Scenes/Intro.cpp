#include "Intro.hpp"

uint8_t Intro::introImageAlpta(float t)
{
	if(t < 1.0f)
	{
		return 255 * t;
	}
	if(t >= 5.0f) return 255 * (5 - t);
	if(t >= 1.0f) return 255;

	return 0;
}

void Intro::LoadContent()
{
	_introImage = Texture2DW("Data\\UI\\IntroImage.png");
}

void Intro::Update(float dt, MouseState* ms, ControllerState* cs)
{
	_introTimer += dt;

	if(_introTimer >= 6.0f) Game::CurrentGameSection = 1;
}

void Intro::Draw(float dt)
{
	DrawTexturePro(
		static_cast<Texture2D>(_introImage),
		Rectangle{ 0,0,796,597 },
		Game::ScreenRec({ 0,0,1,1 }),
		Vector2{ 0,0 },
		0,
		Color{ 255,255,255,introImageAlpta(_introTimer) }
	);
}
