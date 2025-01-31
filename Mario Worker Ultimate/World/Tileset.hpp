#pragma once
#include "Block.hpp"

class GameBase;
class Tileset
{
	Texture2D* _tileset;
	Point_i32 _bsize;
	Point_i32 _numBlocks;

	GameBase* _scene;
public:
	Tileset(Texture2D* tileset, Point block_size);

	void SetScene(GameBase* scene);
	void DrawTile(Block b);

	void DrawTiles(const std::span<Block>& blocks);
	void DrawForEditor(Vector2 offset);
};