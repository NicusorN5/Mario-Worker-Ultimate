#include "Level.hpp"

Level::Level(const char* path) : LvlBackround(WHITE, {60,120,160,255})
{
	if(path == nullptr)
	{
		EnemySpeedMultiplier = 1;
		Gravity = 1;
		MusicPath = nullptr;
		Time = 360;
		IsValid = false;
		Size = { 60, 40 };
		return;
	}
	if(strlen(path) == 0)
	{
		LvlBackround = Backround(nullptr, false, false);
		EnemySpeedMultiplier = 1;
		Gravity = 1;
		MusicPath = nullptr;
		Time = 360;
		IsValid = false;
		return;
	}

	IsValid = true;
	LvlBackround = Backround("",false,false);

	std::ifstream file(path);
	if(file.bad() || file.fail())
	{
		std::stringstream err;
		err << "Level file " << path << " doesn't exist!";
		file.close();
		throw std::runtime_error(err.str().c_str());
	}
	file.close();
}