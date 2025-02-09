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
	Tileset(Texture2D* tileset, Point_i32 block_size);

	Tileset() = default;

	void SetScene(GameBase* scene);
	void DrawTile(Block b);

	void DrawTiles(const std::span<Block>& blocks);
	void DrawForEditor(Vector2 offset, Vector2 scale = {0.65f, 0.65f});

	const Point_i32 NumBlocks() const noexcept;
};