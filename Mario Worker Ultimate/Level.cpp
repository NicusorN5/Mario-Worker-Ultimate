#include "Level.hpp"

Level::Level(const std::filesystem::path& path) :
	LvlBackground(std::make_unique<Background>(WHITE, Color(60, 120, 160, 255))),
	EnemySpeed(1),
	Gravity(1),
	Time(360),
	IsValid(false),
	Size{ 60, 40 },
	LvlMusic{}
{	
	if(path.empty())
	{	
		return;
	}

	//IsValid = true;
	//LvlBackground = std::make_unique<Background>(nullptr,false,false);

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

void Level::SetMusic(const std::filesystem::path& newMusicPath)
{
	if(LvlMusic.ctxData != nullptr || LvlMusic.stream.buffer != nullptr)
	{
		UnloadMusicStream(LvlMusic);
	}

	LvlMusic = Resources::LoadMusicChkF(newMusicPath);
}

void Level::Save(const std::filesystem::path& path)
{

}