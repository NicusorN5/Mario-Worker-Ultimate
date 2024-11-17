#pragma once
#include "Libs.hpp"
#include "UI/Dialogs.hpp"
#include "GameResourceLoadException.hpp"
#include <random>
#include "UI/TransparentFont.hpp"
#include "Raylib/Texture2DW.hpp"
#include "Raylib\SoundW.hpp"
#include "Raylib\MusicW.hpp"

namespace Resources
{
	extern Texture2DW GradientA;
	extern Texture2DW GradientB;

	extern Texture2DW Goomba1; //normal goomba
	extern Texture2DW Goomba2; //gray goomba (immune to fire)

	extern Texture2DW Window;
	extern Texture2DW TxtboxRectangle;

	extern std::array<SoundW,3> LakituDrop;

	extern Texture2DW SliderBar;
	extern Texture2DW SliderBox;
	
	template<size_t N>
	void PlayRandomSound(std::array<SoundW, N> sounds)
	{
		PlaySound(static_cast<Sound>(sounds[Random(0, N)]));
	}

	extern std::random_device rd;
	extern std::mt19937 mt;

	int Random(int min, int max);

	extern TransparentFont LevelHudFont;
	extern TransparentFont NumericLevelHudFont;

	extern Texture2DW LeftBtn;
	extern Texture2DW RightBtn;

	extern SoundW ClickSound1;

	extern Texture2DW BtnGlint;

	extern Texture2DW CbTrue;
	extern Texture2DW CbFalse;

	void LoadAll();
}