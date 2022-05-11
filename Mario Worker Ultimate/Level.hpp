#pragma once
#include "Block.hpp"
#include "Player.hpp"
#include "Libs.hpp"
#include "IEnemy.hpp"
#include "Decoration.hpp"
#include "Bonus.hpp"
#include "Backround.hpp"
#include "Resolution.hpp"

enum class Liqiud
{
	None = 0,
	Water,
	Lava,
	Poison
};

class Level
{
public:
	Level(const char* path);

	bool IsValid = false;
	int Time = 360;
	float Gravity = 9.81f;
	float LiquidLevel = -5.0f;

	int EnemySpeedMultiplier = 1;
	const char* MusicPath = nullptr;

	Vector2 Size = { 60,40 };

	std::vector<Block> Blocks;
	std::vector<IEnemy*> Enemies;
	std::vector<Decoration> Decorations;
	std::vector<Bonus> Bonuses;
	Backround LvlBackround;
};

