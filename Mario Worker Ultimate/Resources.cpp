#include "Resources.hpp"

Texture2D Resources::Goomba1{};
Texture2D Resources::Goomba2{};

Texture2D Resources::LoadTextureChkF(const char* path)
{
	Texture2D t = LoadTexture(path);
	if(t.id <= 0) throw GameResourceLoadException(path);
}

void Resources::LoadAll()
{
	Goomba1 = LoadTextureChkF("Data\\Enemies\\BrownGoomba.png");
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
		//if(w.data == nullptr) throw GameResourceLoadException(path);
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