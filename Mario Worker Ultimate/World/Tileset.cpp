#include "Tileset.hpp"
#include "../Scenes/GameBase.hpp"

Tileset::Tileset(Texture2D* tileset, Point_i32 block_size) :
	_tileset(tileset),
	_bsize(block_size),
	_numBlocks( tileset->width / block_size.X, tileset->height / block_size.Y),
	_scene(nullptr)
{
}

void Tileset::SetScene(GameBase* scene)
{
	_scene = scene;
}

void Tileset::DrawTile(Block b)
{
	if(_scene == nullptr) throw std::logic_error("Scene not set!");

	auto& pos = b.Position;
	auto& id = b.ID;

	_scene->DrawEnt(
		Rectangle{ pos.x, pos.y, 0.05f, 1 / 15.0f },
		_tileset,
		{
			static_cast<float>((id % _numBlocks.X) * _bsize.X),
			static_cast<float>((id / _numBlocks.X) * _bsize.Y),
			static_cast<float>(_bsize.X),
			static_cast<float>(_bsize.Y)
		},
		WHITE
	);
}

void Tileset::DrawTiles(const std::span<Block>& blocks)
{
	for(auto& b : blocks)
	{
		DrawTile(b);
	}
}

void Tileset::DrawForEditor(Vector2 offset, Vector2 scale)
{
	DrawTexturePro(
		*_tileset,
		{ 0,0, (float)_tileset->width, (float)_tileset->height },
		Game::ScreenRec({
			offset.x,
			offset.y,
			(_numBlocks.X * 0.05f) * (_bsize.X / 32.0f) * scale.x,
			(_numBlocks.Y * 1 / 15.0f) * (_bsize.X / 32.0f) * scale.y,
		}),
		{ 0,0 },
		0.0f,
		WHITE
	);


}

const Point_i32 Tileset::NumBlocks() const noexcept
{
	return _numBlocks;
}
