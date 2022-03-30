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
