#include "Background.hpp"

Background::Background(const char* path, bool repeatX, bool repeatY, Color bottom, Color top) :
	_BackgroundTexture(Resources::LoadTextureChkF(path)),
	RepeatX(repeatX),
	RepeatY(repeatY),
	ColorA(bottom),
	ColorB(top)
{

};

Background::Background(const char* path, bool repeatX, bool repeatY) :
	_BackgroundTexture(Resources::LoadTextureChkF(path)),
	RepeatX(repeatX),
	RepeatY(repeatY),
	ColorA(WHITE),
	ColorB(WHITE)
{

};

Background::Background(Color bottom, Color top) :
	_BackgroundTexture(),
	RepeatX(false),
	RepeatY(false),
	ColorA(bottom),
	ColorB(top)
{

};

void Background::Draw(Vector2 camCoords, Vector2 levelSize)
{
 	Rectangle screenRect = Game::ScreenRec({ 0,0,1,1 });

	Rectangle BackgroundRect = screenRect;

	BackgroundRect.x = -camCoords.x;
	BackgroundRect.width *= levelSize.x / 20.0f;

	BackgroundRect.y = -camCoords.y;
	BackgroundRect.height *= levelSize.y / 15.0f;

	//gradient
	DrawTexturePro(
		Resources::GradientA,
		{ 0,0,(float)Resources::GradientA.width, (float)Resources::GradientA.height },
		BackgroundRect,
		{ 0,0 },
		0,
		ColorA
	);
	DrawTexturePro(
		Resources::GradientB,
		{ 0,0,(float)Resources::GradientB.width, (float)Resources::GradientB.height },
		BackgroundRect,
		{ 0,0 },
		0,
		ColorB
	);

	//background
	Rectangle source = { 0,0,(float)_BackgroundTexture.width,(float)_BackgroundTexture.height };

	if(this->RepeatX)
		source.width *= levelSize.x / 20.0f;

	if(this->RepeatY)
		source.height *= levelSize.y / 15.0f;
	else
	{
 		BackgroundRect.y = -camCoords.y + ((std::max<float>(0.0f,levelSize.y - 15.0f) * Game::Resolution::FltY()) / 15.0f);
		BackgroundRect.height = Game::Resolution::FltY();
	}
	DrawTexturePro(_BackgroundTexture, source, BackgroundRect, { 0,0 }, 0.0f, WHITE);
}

Background::~Background()
{
	UnloadTexture(_BackgroundTexture);
}
