#pragma once
#include <raylib.h>

enum PlayerState
{
	Dead = -1,
	NotCreated = 0,
	Small,
	Big,
	PowerupFLower,
	PowerupBeet,
	PowerupLui,
	PowerupHammer,
};

class Player
{
	const char* characterName = nullptr;
	Texture2D PlayerDead{};
	Texture2D PlayerSmall{};
	Texture2D PlayerBig{};
	Texture2D PlayerFlower{};
	Texture2D PlayerBeet{};
	Texture2D PlayerLui{};
	Texture2D PlayerHammer{};
public:
	Player(int x, int y) : Position{ static_cast<float>(x), static_cast<float>(y)} {};

	bool LoadSprites(const char* characterName);

	void Render();
	void Update(float dt);

	Vector2 Position;

	~Player();
};

