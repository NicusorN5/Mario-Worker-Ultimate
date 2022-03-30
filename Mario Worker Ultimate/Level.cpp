#include "Level.hpp"

Level::Level(const char* path) : LvlBackround(nullptr,false,false)
{
	LvlBackround = Backround("",false,false);

	if(FileExists(path))
	{
		std::ifstream file(path);
		file.close();
	}
	else
	{
		char buff[300]{ 0 };
		sprintf_s(buff, "Level file %s doesn't exist!", path);
		throw std::runtime_error(buff);
	}
}
