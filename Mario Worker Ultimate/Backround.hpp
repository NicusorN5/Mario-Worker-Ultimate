#pragma once
#include "Player.hpp"
#include "Resources.hpp"
#include "Resolution.hpp"

class Backround
{
	Texture2D _backroundTexture;
	bool _gradient;
public:
	bool RepeatX;
	bool RepeatY;

	Color ColorA;
	Color ColorB;

	Backround(const char* path, bool repeatX, bool repeatY) : _backroundTexture(Resources::LoadTextureChkF(path)), RepeatX(repeatX), RepeatY(repeatY), _gradient(false), ColorA(WHITE), ColorB(WHITE) {};
	Backround(Color bottom,Color top): _backroundTexture(), RepeatX(false), RepeatY(false), _gradient(true), ColorA(bottom), ColorB(top) {};

	void Draw(Vector2 camCoords, Vector2 levelSize);

	~Backround();
};

