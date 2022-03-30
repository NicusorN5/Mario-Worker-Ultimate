#pragma once
#include "Player.hpp"

class Backround
{
public:
	Texture2D BackroundTexture;
	bool RepeatX;
	bool RepeatY;

	Backround(const char* path, bool repeatX, bool repeatY) : BackroundTexture(LoadTexture(path)), RepeatX(repeatX), RepeatY(repeatY) {};

	void Draw(Player* player);

	~Backround();
};

