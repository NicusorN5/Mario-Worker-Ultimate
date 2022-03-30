#pragma once
#include "Block.hpp"
#include "Player.hpp"
#include "Libs.hpp"
#include "IEnemy.hpp"
#include "Decoration.hpp"
#include "Bonus.hpp"
#include "Backround.hpp"

class Level
{
public:
	Level(const char* path);

	int Time;
	int Gravity;

	int EnemySpeedMultiplier;
	const char* MusicPath;

	std::vector<Block> Blocks;
	std::vector<IEnemy*> Enemies;
	std::vector<Decoration> Decorations;
	std::vector<Bonus> Bonuses;
	Backround LvlBackround;
	
};

