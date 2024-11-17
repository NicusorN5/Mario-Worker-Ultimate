#include "Resources.hpp"

Texture2DW Resources::GradientA;
Texture2DW Resources::GradientB;

Texture2DW Resources::Goomba1;
Texture2DW Resources::Goomba2;

Texture2DW Resources::Window;

Texture2DW Resources::SliderBar;
Texture2DW Resources::SliderBox;

std::array<SoundW,3> Resources::LakituDrop;

std::random_device Resources::rd;
std::mt19937 Resources::mt;

TransparentFont Resources::LevelHudFont;
TransparentFont Resources::NumericLevelHudFont;
Texture2DW Resources::TxtboxRectangle;

Texture2DW Resources::LeftBtn;
Texture2DW Resources::RightBtn;

SoundW Resources::ClickSound1;

Texture2DW Resources::BtnGlint;

Texture2DW Resources::CbTrue;
Texture2DW Resources::CbFalse;

int Resources::Random(int min, int max)
{
	return min + (mt() % (max - min));
}

void Resources::LoadAll()
{
	mt = std::mt19937(rd());

	GradientA = Texture2DW("Data\\Backgrounds\\GradientA.png");
	GradientB = Texture2DW("Data\\Backgrounds\\GradientB.png");

	Goomba1 = Texture2DW("Data\\Enemies\\BrownGoomba.png");

	for(size_t i = 0; i < 3; i++)
	{
		std::string path = "Data\\Sounds\\Lakitu";
		path += std::to_string(i+1) + ".wav";
		LakituDrop[i] = SoundW(path);
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

	Texture2DW hudFont = Texture2DW("Data\\UI\\Level_Font.png");
	
	new (&LevelHudFont) TransparentFont(
		static_cast<Texture2D>(hudFont),
		" 1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ.-&[]",
		coords
	);

	new (&NumericLevelHudFont) TransparentFont(
		static_cast<Texture2D>(hudFont),
		"1234567890",
		coords2
	);
	
	TxtboxRectangle = Texture2DW("Data\\UI\\Textbox_Rectangle.png");

	SliderBar = Texture2DW("Data\\UI\\SliderBar.png");
	SliderBox = Texture2DW("Data\\UI\\SliderBox.png");

	LeftBtn = Texture2DW("Data\\UI\\LeftBtn.png");
	RightBtn = Texture2DW("Data\\UI\\RightBtn.png");

	ClickSound1 = SoundW("Data\\Sounds\\ClickOption.wav");

	BtnGlint = Texture2DW("Data\\UI\\ButtonGlint.png");

	CbTrue = Texture2DW("Data\\UI\\CheckboxT.png");
	CbFalse = Texture2DW("Data\\UI\\CheckboxF.png");

	Window = Texture2DW("Data\\UI\\Window_Default.png");
}
