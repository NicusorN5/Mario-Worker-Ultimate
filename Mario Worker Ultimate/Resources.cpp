#include "Resources.hpp"

Texture2D Resources::GradientA{};
Texture2D Resources::GradientB{};

Texture2D Resources::Goomba1{};
Texture2D Resources::Goomba2{};

Texture2D Resources::Window{};

Texture2D Resources::SliderBar{};
Texture2D Resources::SliderBox{};

Sound Resources::LakituDrop[3]{};

std::random_device Resources::rd;
std::mt19937 Resources::mt;

SpriteFont Resources::LevelHudFont;
SpriteFont Resources::NumericLevelHudFont;
Texture2D Resources::TxtboxRectangle;

Texture2D Resources::LeftBtn;
Texture2D Resources::RightBtn;

Sound Resources::ClickSound1;

Texture2D Resources::BtnGlint;

Texture2D Resources::CbTrue;
Texture2D Resources::CbFalse;

Texture2D Resources::Water;
Color Resources::WaterColor(90, 140, 231, 128);

Texture2D Resources::Lava;
Color Resources::LavaColor(123, 0, 0, 255);

Texture2D Resources::Poison;
Color Resources::PoisonColor(154, 0, 230, 128);

Font Resources::KeystrokesMT;

Texture2D Resources::TerrainTilesetTexture;
Texture2D Resources::BlocksTilesetTexture;
Texture2D Resources::TankTilesetTexture;
Texture2D Resources::PipesTilesetTexture;

Tileset Resources::TerrainTileset;
Tileset Resources::BlocksTileset;
Tileset Resources::TankTileset;
Tileset Resources::PipesTileset;

void Resources::PlayRandomSound(Sound* sounds, size_t numSounds)
{
	PlaySound(sounds[Random(0, static_cast<int>(numSounds))]);
}

int Resources::Random(int min, int max)
{
	return min + (mt() % (max - min));
}

Texture2D Resources::LoadTextureChkF(const std::filesystem::path& path)
{
	auto p = path.string();
	Texture2D t = LoadTexture(p.c_str());
	if(t.id == 0) throw GameResourceLoadException(path);
	return t;
}

void Resources::LoadAll()
{
	mt = std::mt19937(rd());

	GradientA = LoadTextureChkF("Data\\Backgrounds\\GradientA.png");
	GradientB = LoadTextureChkF("Data\\Backgrounds\\GradientB.png");

	Goomba1 = LoadTextureChkF("Data\\Enemies\\BrownGoomba.png");

	for(size_t i = 0; i < 3; i++)
	{
		std::string path = "Data\\Sounds\\Lakitu";
		path += std::to_string(i+1) + ".wav";
		LakituDrop[i] = LoadSoundChkF(path.c_str());
	}

	Rectangle coords[] =
	{
		{0,0,1,1},
		{0,0,11,16},
		{11,0,15,16},
		{26,0,15,16},
		{41,0,15,16},
		{56,0,15,16},
		{71,0,15,16},
		{86,0,15,16},
		{101,0,15,16},
		{116,0,15,16},
		{131,0,15,16},
		{146,0,15,16},
		{161,0,15,16},
		{176,0,15,16},
		{191,0,15,16},
		{206,0,15,16},
		{221,0,15,16},
		{236,0,15,16},
		{251,0,15,16},
		{266,0,11,16},
		{277,0,15,16},
		{292,0,15,16},
		{307,0,13,16},
		{320,0,15,16},
		{335,0,15,16},
		{350,0,15,16},
		{365,0,15,16},
		{380,0,15,16},
		{395,0,15,16},
		{410,0,15,16},
		{425,0,15,16},
		{440,0,15,16},
		{455,0,15,16},
		{470,0,15,16},
		{485,0,15,16},
		{500,0,15,16},
		{515,0,15,16},
		{530,0,7,16},
		{537,0,15,16},
		{522,0,15,16},
		{567,0,15,16},
		{582,0,15,16}
	};

	Rectangle coords2[] =
	{
		{0,0,11,16},
		{11,0,15,16},
		{26,0,15,16},
		{41,0,15,16},
		{56,0,15,16},
		{71,0,15,16},
		{86,0,15,16},
		{101,0,15,16},
		{116,0,15,16},
		{131,0,15,16}
	};

	Texture2D hudFont = LoadTextureChkF("Data\\UI\\Level_Font.png");
	
	new (&LevelHudFont) SpriteFont(
		hudFont,
		" 1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ.-&[]",
		coords
	);

	new (&NumericLevelHudFont) SpriteFont(
		hudFont,
		"1234567890",
		coords2
	);
	
	TxtboxRectangle = LoadTextureChkF("Data\\UI\\Textbox_Rectangle.png");

	SliderBar = LoadTextureChkF("Data\\UI\\SliderBar.png");
	SliderBox = LoadTextureChkF("Data\\UI\\SliderBox.png");

	LeftBtn = LoadTextureChkF("Data\\UI\\LeftBtn.png");
	RightBtn = LoadTextureChkF("Data\\UI\\RightBtn.png");

	ClickSound1 = LoadSoundChkF("Data\\Sounds\\ClickOption.wav");

	BtnGlint = Resources::LoadTextureChkF("Data\\UI\\ButtonGlint.png");

	CbTrue = Resources::LoadTextureChkF("Data\\UI\\CheckboxT.png");
	CbFalse = Resources::LoadTextureChkF("Data\\UI\\CheckboxF.png");

	Window = LoadTextureChkF("Data\\UI\\Window_Default.png");

	Water = LoadTextureChkF("Data\\World\\Water.png");
	Lava = LoadTextureChkF("Data\\\Enemies\\Lava.png");
	Poison = LoadTextureChkF("Data\\World\\Poison.png");

	KeystrokesMT = LoadFont("Data\\Fonts\\KeystrokesMTa.ttf");
	if(KeystrokesMT.texture.id == 0) throw new GameResourceLoadException("Data\\Fonts\\KeystrokesMT.ttf");

	TerrainTilesetTexture = LoadTextureChkF("Data\\World\\Tileset_Terrain.png");
	BlocksTilesetTexture = LoadTextureChkF("Data\\World\\Tileset_Blocks.png");
	TankTilesetTexture = LoadTextureChkF("Data\\World\\Tileset_Tank.png");
	PipesTilesetTexture = LoadTextureChkF("Data\\World\\Tileset_Pipes.png");

	TerrainTileset = Tileset(&TerrainTilesetTexture, { 32, 32 });
	BlocksTileset = Tileset(&BlocksTilesetTexture, { 32, 32 });
	TankTileset = Tileset(&TankTilesetTexture, { 32, 32 });
	PipesTileset = Tileset(&PipesTilesetTexture, { 32, 32 });
}

Sound Resources::LoadSoundChkF(const std::filesystem::path& path)
{
	auto rawPath = path.string();

	bool isWave = path.extension() == "wav";

	if(isWave)
	{
		Wave w = LoadWave(rawPath.c_str());
		if(w.data == nullptr) throw GameResourceLoadException(path);
		return LoadSoundFromWave(w);
	}

	Sound s = LoadSound(rawPath.c_str());
	if(s.stream.buffer == nullptr) throw GameResourceLoadException(path);
	return s;
}

Music Resources::LoadMusicChkF(const std::filesystem::path& path)
{
	Music m = LoadMusicStream(path.string().c_str());
	if(m.ctxData == nullptr) throw GameResourceLoadException(path);
	return m;
}

void Resources::UnloadAll()
{
	UnloadTexture(GradientA);
	UnloadTexture(GradientB);

	UnloadTexture(Goomba1); //normal goomba
	UnloadTexture(Goomba2); //gray goomba (immune to fire)

	UnloadTexture(Window);
	UnloadTexture(TxtboxRectangle);

	for(size_t i = 0; i < 3; i++)
	{
		UnloadSound(LakituDrop[i]);
	}

	UnloadTexture(SliderBar);
	UnloadTexture(SliderBox);
	//font

	UnloadTexture(LeftBtn);
	UnloadTexture(RightBtn);

	UnloadSound(ClickSound1);

	UnloadTexture(BtnGlint);

	UnloadTexture(CbTrue);
	UnloadTexture(CbFalse);

	UnloadTexture(Water);
	UnloadTexture(Lava);
	UnloadTexture(Poison);

	UnloadFont(KeystrokesMT);

	UnloadTexture(TerrainTilesetTexture);
	UnloadTexture(BlocksTilesetTexture);
	UnloadTexture(TankTilesetTexture);
	UnloadTexture(PipesTilesetTexture);
}
