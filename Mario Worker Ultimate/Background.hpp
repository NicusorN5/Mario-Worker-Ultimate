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

	Color ColorA;
	Color ColorB;

	Background(Background&) = delete;
	Background(const char* path, bool repeatX, bool repeatY, Color bottom, Color top);
	Background(const char* path, bool repeatX, bool repeatY);
	Background(Color bottom, Color top);

	void Draw(Vector2 camCoords, Vector2 levelSize);

	~Background();
};

