#include "Backround.hpp"

void Backround::Draw(Player* player)
{
	DrawTextureEx(BackroundTexture, { 0,0 }, 0.0f, 1.0f, { 255,255,255,255 });
}

Backround::~Backround()
{
	UnloadTexture(BackroundTexture);
}
