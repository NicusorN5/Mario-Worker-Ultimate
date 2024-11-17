#include "Level.hpp"

Level::Level(const std::filesystem::path& path) :
	LvlBackground(std::make_unique<Background>(WHITE, Color(60, 120, 160, 255))),
	EnemySpeed(1),
	Gravity(1),
	Time(360),
	IsValid(false),
	Size{ 60, 40 }
{	
	if(path.empty())
	{
		
		return;
	}
	if(path.empty())
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
	return static_cast<Music>(LvlMusic); //create a copy of this->LvlMusic.
}

void Level::SetMusic(const std::filesystem::path& newMusicPath)
{
	LvlMusic = MusicW(newMusicPath);
}

void Level::Save(const std::filesystem::path& path)
{

}