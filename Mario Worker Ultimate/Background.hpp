#pragma once
#include "Player.hpp"
#include "Resources.hpp"
#include "Resolution.hpp"

class Background
{
	Texture2D _BackgroundTexture;
public:
	bool RepeatX;
	bool RepeatY;
	bool LockToScreen;
	bool LockToY;
	bool FitEntireScreen;

	Color ColorA;
	Color ColorB;

	Color OverlayA = WHITE;
	Color OverlayB = WHITE;
	uint8_t OverlayAlphaA = 0;
	uint8_t OverlayAlphaB = 0;

	Background(const Background&) = delete;

	Background(const char* path, bool repeatX, bool repeatY, Color bottom, Color top);
	Background(const char* path, bool repeatX, bool repeatY);
	Background(Color bottom, Color top);

	void Draw(Vector2 camCoords, Vector2 levelSize);
};

