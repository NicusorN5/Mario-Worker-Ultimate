#pragma once
#include "Block.hpp"
#include "Player.hpp"
#include "Libs.hpp"
#include "IEnemy.hpp"
#include "Decoration.hpp"
#include "Bonus.hpp"
#include "Background.hpp"
#include "Resolution.hpp"

enum class LiquidType
{
	None = 0,
	Water,
	Lava,
	Poison
};

class Level
{
	Music LvlMusic;
public:
	/// <summary>
	/// Loads a level from the specifed path.
	/// </summary>
	Level(const char* path);

	bool IsValid = false;
	int Time = 360;
	float Gravity = 1.0f;
	float LiquidLevel = -5.0f;

	unsigned EnemySpeed;
	unsigned BillBlasterROF;
	unsigned BillBulletSpeed;
	unsigned PinkFlowerFireballs;
	unsigned PlantSpeed;
	unsigned PodoboosSpeed;
	unsigned LakituAttackSpeed;
	unsigned FallingSpikesSpeed; // 0 = disabled
	unsigned PlatformSpeed;
	unsigned FishDensity;
	unsigned BroHammerAttackRate;

	Vector2 Size = { 60,40 };

	std::vector<Block> Blocks;
	std::vector<IEnemy*> Enemies;
	std::vector<Decoration> Decorations;
	std::vector<Bonus> Bonuses;
	std::unique_ptr<Background> LvlBackground;

	LiquidType Liquid;

	Music GetMusic();
	void SetMusic(const char* newMusicPath);

	void Save(const char* path);
};

