#pragma once
#include "Libs.hpp"
#include "Dialogs.hpp"
#include "GameResourceLoadException.hpp"

namespace Resources
{
	extern Texture2D Goomba1; //normal goomba
	extern Texture2D Goomba2; //gray goomba (immune to fire)

	/// <summary>
	/// Loads the texture and checks if it is correctly loaded. Otherwise a GameResourceLoadException is thrown.
	/// </summary>
	/// <param name="path">Path to image</param>
	/// <returns>raylib Texture2D struct</returns>
	Texture2D LoadTextureChkF(const char* path);
	/// <summary>
	/// Loads all gameplay sprites (enemies, player sprite, maps, etc...)
	/// </summary>
	void LoadAll();
	/// <summary>
	/// Loads a sound and checks if it correctly loaded.
	/// </summary>
	/// <param name="path"></param>
	/// <returns></returns>
	Sound LoadSoundChkF(const char* path);
	/// <summary>
	/// Loads a music stream then checks if it is successfully loaded..
	/// </summary>
	/// <param name="path"></param>
	/// <returns></returns>
	Music LoadMusicChkF(const char* path);
}