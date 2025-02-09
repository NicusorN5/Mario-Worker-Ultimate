#pragma once
#include "Libs.hpp"
#include "UI/Dialogs.hpp"
#include "GameResourceLoadException.hpp"
#include <random>
#include "UI/SpriteFont.hpp"
#include "World\Tileset.hpp"

namespace Resources
{
	extern Texture2D GradientA;
	extern Texture2D GradientB;

	extern Texture2D Goomba1; //normal goomba
	extern Texture2D Goomba2; //gray goomba (immune to fire)

	extern Texture2D Window;
	extern Texture2D TxtboxRectangle;

	extern Sound LakituDrop[3];

	extern Texture2D SliderBar;
	extern Texture2D SliderBox;
	
	void PlayRandomSound(Sound* sounds, size_t numSounds);

	extern std::random_device rd;
	extern std::mt19937 mt;

	int Random(int min, int max);

	extern SpriteFont LevelHudFont;
	extern SpriteFont NumericLevelHudFont;

	extern Texture2D LeftBtn;
	extern Texture2D RightBtn;

	extern Sound ClickSound1;

	extern Texture2D BtnGlint;

	extern Texture2D CbTrue;
	extern Texture2D CbFalse;

	extern Texture2D Water;
	extern Color WaterColor;

	extern Texture2D Lava;
	extern Color LavaColor;

	extern Texture2D Poison;
	extern Color PoisonColor;

	extern Font KeystrokesMT;

	extern Texture2D TerrainTilesetTexture;
	extern Texture2D BlocksTilesetTexture;
	extern Texture2D TankTilesetTexture;
	extern Texture2D PipesTilesetTexture;

	extern Tileset TerrainTileset;
	extern Tileset BlocksTileset;
	extern Tileset TankTileset;
	extern Tileset PipesTileset;

	/// <summary>
	/// Loads the texture and checks if it is correctly loaded. Otherwise a GameResourceLoadException is thrown.
	/// </summary>
	/// <param name="path">Path to image</param>
	/// <returns>raylib Texture2D struct</returns>
	Texture2D LoadTextureChkF(const std::filesystem::path& path);
	/// <summary>
	/// Loads all gameplay sprites (enemies, player sprite, maps, etc...)
	/// </summary>
	void LoadAll();
	/// <summary>
	/// Loads a sound and checks if it correctly loaded.
	/// </summary>
	/// <param name="path"></param>
	/// <returns></returns>
	Sound LoadSoundChkF(const std::filesystem::path& path);
	/// <summary>
	/// Loads a music stream then checks if it is successfully loaded..
	/// </summary>
	/// <param name="path"></param>
	/// <returns></returns>
	Music LoadMusicChkF(const std::filesystem::path& path);

	void UnloadAll();
}