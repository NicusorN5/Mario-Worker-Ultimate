#include "Backround.hpp"

void Backround::Draw(Vector2 camCoords,Vector2 levelSize)
{
	Rectangle screenRect = Game::ScreenRec({ 0,0,1,1 });

	Rectangle backroundRect = screenRect;
	backroundRect.y = -camCoords.y;
	backroundRect.height *= (levelSize.y + 15) / 15.0f;

	if(_gradient)
	{
		DrawTexturePro(Resources::GradientA, { 0,0,1920,1080 }, backroundRect, {0,0}, 0, ColorA);
		DrawTexturePro(Resources::GradientB, { 0,0,1920,1080 }, backroundRect, { 0,0 }, 0, ColorB);
	}
	else
		DrawTexturePro(_backroundTexture, { 0,0,(float)_backroundTexture.width,(float)_backroundTexture.height}, screenRect, {0,0}, 0.0f, WHITE);
}

Backround::~Backround()
{
	UnloadTexture(_backroundTexture);
}
