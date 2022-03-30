#pragma once
#include "Block.h"
#include "Player.h"
#include "Libs.h"
#include "IEnemy.h"
#include "Decoration.h"

class Level
{
public:
	Player Player;

	int Time;
	int Gravity;
	std::vector<Block> Blocks;
	std::vector<IEnemy*> Enemies;
	std::vector<Decoration> Decorations;
};

