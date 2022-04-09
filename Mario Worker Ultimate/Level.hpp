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

	bool IsValid;
	int Time;
	int Gravity;
	float LiquidLevel;

	int EnemySpeedMultiplier;
	const char* MusicPath;

	Vector2 Size;

	std::vector<Block> Blocks;
	std::vector<IEnemy*> Enemies;
	std::vector<Decoration> Decorations;
	std::vector<Bonus> Bonuses;
	Backround LvlBackround;
};

