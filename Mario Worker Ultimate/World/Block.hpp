#pragma once
#include "../Libs.hpp"

struct Block
{
	unsigned ID;
	Vector2 Position;
};

/// <summary>
/// Used when parsing the level. Then multiple Block arrays are created, divided by the tileset.
/// </summary>
struct BlockEx
{
	unsigned TilesetID;
	unsigned ID;
	Vector2 Position;
};
