#include "Resources.hpp"

Texture2D Resources::GradientA{};
Texture2D Resources::GradientB{};

Texture2D Resources::Goomba1{};
Texture2D Resources::Goomba2{};

Texture2D Resources::Window{};

Sound Resources::LakituDrop[3]{};

std::random_device Resources::rd;
std::mt19937 Resources::mt;

void Resources::PlayRandomSound(Sound* sounds, size_t numSounds)
{
	PlaySound(sounds[Random(0, numSounds)]);
}

int Resources::Random(int min, int max)
{
	return min + (mt() % (max - min));
}

Texture2D Resources::LoadTextureChkF(const char* path)
{
	Texture2D t = LoadTexture(path);
	if(t.id <= 0) throw GameResourceLoadException(path);
	return t;
}

void Resources::LoadAll()
{
	mt = std::mt19937(rd());

	GradientA = LoadTextureChkF("Data\\Backrounds\\GradientA.png");
	GradientB = LoadTextureChkF("Data\\Backrounds\\GradientB.png");

	Goomba1 = LoadTextureChkF("Data\\Enemies\\BrownGoomba.png");

	for(size_t i = 0; i < 3; i++)
	{
		std::string path = "Data\\Sounds\\Lakitu";
		path += std::to_string(i+1) + ".ogg";
		LakituDrop[i] = LoadSoundChkF(path.c_str());
	}
}

Sound Resources::LoadSoundChkF(const char* path)
{
	bool isWave = false;
	size_t pathLen = strlen(path);
	if(path[pathLen - 4] == '.' &&
		path[pathLen - 3] == 'w' &&
		path[pathLen - 2] == 'a' &&
		path[pathLen - 1] == 'v')
		isWave = true;

	if(isWave)
	{
		Wave w = LoadWave(path);
		if(w.data == nullptr) throw GameResourceLoadException(path);
		return LoadSoundFromWave(w);
	}
	
	Sound s = LoadSound(path);
	if(s.stream.buffer == nullptr) throw GameResourceLoadException(path);
	return s;
}

Music Resources::LoadMusicChkF(const char* path)
{
	Music m = LoadMusicStream(path);
	if(m.ctxData == nullptr) throw GameResourceLoadException(path);
	return m;
}