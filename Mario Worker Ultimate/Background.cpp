#include "Background.hpp"

Background::Background(const char* path, bool repeatX, bool repeatY, Color bottom, Color top) :
	_BackgroundTexture(Resources::LoadTextureChkF(path)),
	RepeatX(repeatX),
	RepeatY(repeatY),
	ColorA(bottom),
	ColorB(top),
	LockToScreen(false),
	LockToY(false),
	FitEntireScreen(false)
{

};

Background::Background(const char* path, bool repeatX, bool repeatY) :
	_BackgroundTexture(Resources::LoadTextureChkF(path)),
	RepeatX(repeatX),
	RepeatY(repeatY),
	ColorA(WHITE),
	ColorB(WHITE),
	LockToScreen(false),
	LockToY(false),
	FitEntireScreen(false)
{

};

Background::Background(Color bottom, Color top) :
	_BackgroundTexture(),
	RepeatX(false),
	RepeatY(false),
	ColorA(bottom),
	ColorB(top),
	LockToScreen(false),
	LockToY(false),
	FitEntireScreen(false)
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

	Rectangle OverlayGradientRect = BackgroundRect;

	//background
	Rectangle source = { 0,0,(float)_BackgroundTexture.width,(float)_BackgroundTexture.height };

	if(!FitEntireScreen)
	{
		if(LockToScreen)
		{
			BackgroundRect.x = 0;
			BackgroundRect.y = 0;
			BackgroundRect.width = Game::Resolution::FltX();
			BackgroundRect.height = Game::Resolution::FltY();
		}
		else
		{
			if(this->RepeatX)
				source.width *= levelSize.x / 20.0f;

			if(this->LockToY)
			{
				BackgroundRect.y = 0;
				BackgroundRect.height = Game::Resolution::FltY();
			}
			else if(this->RepeatY)
				source.height *= levelSize.y / 15.0f;
			else //put the backround at the bottom of the level if it is not repeated along the Y axis
			{
				BackgroundRect.y = -camCoords.y + ((std::max<float>(0.0f, levelSize.y - 15.0f) * Game::Resolution::FltY()) / 15.0f);
				BackgroundRect.height = Game::Resolution::FltY();
			}
		}
	}
	DrawTexturePro(_BackgroundTexture, source, BackgroundRect, { 0,0 }, 0.0f, WHITE);
	
	if(OverlayAlphaA > 0)
	{
		DrawTexturePro(
			Resources::GradientA,
			{ 0,0,(float)Resources::GradientA.width, (float)Resources::GradientA.height },
			OverlayGradientRect,
			{ 0,0 },
			0,
			{ OverlayA.r,OverlayA.g,OverlayA.b,OverlayAlphaA }
		);
	}

	if(OverlayAlphaB > 0)
	{
		DrawTexturePro(
			Resources::GradientB,
			{ 0,0,(float)Resources::GradientB.width, (float)Resources::GradientB.height },
			OverlayGradientRect,
			{ 0,0 },
			0,
			{ OverlayB.r,OverlayB.g,OverlayB.b,OverlayAlphaB }
		);
	}
}

Background::~Background()
{
	UnloadTexture(_BackgroundTexture);
}
