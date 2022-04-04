#include "Level.hpp"

Level::Level(const char* path) : LvlBackround(nullptr,false,false)
{
	if(path == nullptr)
	{
		LvlBackround = Backround(nullptr, false, false);
		EnemySpeedMultiplier = 1;
		Gravity = 1;
		MusicPath = nullptr;
		Time = 360;
		IsValid = false;
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

	if(FileExists(path))
	{
		std::ifstream file(path);
		file.close();
	}
	else
	{
		std::stringstream err;
		err << "Level file " << path << " doesn't exist!";
		throw std::runtime_error(err.str().c_str());
	}
}
