#include "Level.hpp"

Level::Level(const char* path) : LvlBackground(std::make_unique<Background>(WHITE, Color(60, 120, 160, 255)))
{	
	if(path == nullptr)
	{
		EnemySpeed = 1;
		Gravity = 1;
		Time = 360;
		IsValid = false;
		Size = { 60, 40 };
		return;
	}
	if(strlen(path) == 0)
	{
		LvlBackground = std::make_unique<Background>(nullptr, false, false);
		EnemySpeed = 1;
		Gravity = 1;
		Time = 360;
		IsValid = false;
		return;
	}

	IsValid = true;
	LvlBackground = std::make_unique<Background>("",false,false);

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

Music Level::GetMusic()
{
	return Music(LvlMusic); //create a copy of this->LvlMusic.
}
void Level::SetMusic(const char* newMusicPath)
{
	if(LvlMusic.ctxData != nullptr || LvlMusic.stream.buffer != nullptr)
	{
		UnloadMusicStream(LvlMusic);
	}

	LvlMusic = Resources::LoadMusicChkF(newMusicPath);
}