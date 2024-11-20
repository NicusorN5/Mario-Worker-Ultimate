#include "GameBase.hpp"
#include "LevelEditor.hpp"

Rectangle GameBase::calculateViewTransform(Rectangle normScreen)
{
	return { normScreen.x - cameraPosition.x,
		normScreen.y - cameraPosition.y,
		normScreen.width, normScreen.height };
}

Rectangle GameBase::calculateTileTransformation(Rectangle normScreen)
{
	return { normScreen.x - ((int)cameraPosition.x % (Game::Resolution::X)),
		normScreen.y - ((int)cameraPosition.y % (Game::Resolution::Y)),
		normScreen.width + normScreen.x / 20 , normScreen.height + normScreen.x / 15 };
}

void GameBase::LoadContent()
{

}

void GameBase::Update(float dt, MouseState* ms, ControllerState* cs)
{
}

void GameBase::DrawWater()
{
	Texture2D liquid;

	switch(Game::CurrentLevel.Liquid)
	{
		case LiquidType::Water:
			liquid = Resources::Water;
			break;
		case LiquidType::Lava:
			liquid = Resources::Water;
			break;
		case LiquidType::Poison:
			liquid = Resources::Water;
			break;
		default:
			return;
	}

	auto height = Game::CurrentLevel.LiquidLevel / Game::Resolution::Y;
	Rectangle currentWaterWorldTile;

	for(int i = 0; i < 20; i++)
	{
		auto waterAnimRectangle = Rectangle{
			0,
			static_cast<float>((static_cast<int>(_waterAnimTimer) % 5) * 16),
			64,
			16
		};
		currentWaterWorldTile = calculateViewTransform(Game::ScreenRec({0, height, 0.05f, 1 / 30.0f }));
		currentWaterWorldTile.x = Game::Resolution::X * 0.05F * i;

		DrawTexturePro(
			liquid,
			waterAnimRectangle,
			currentWaterWorldTile,
			{ 0,0 },
			0.0f,
			Color(255,255,255, 220)
		);
	}

	DrawRectangle(
		0,
		currentWaterWorldTile.y + 16,
		Game::Resolution::X,
		Game::Resolution::Y * (1),
		Resources::WaterColor
	);
}

void GameBase::DrawSpikedFloor()
{

}

void GameBase::Draw(float dt)
{
	//draw background
	Game::CurrentLevel.LvlBackground->Draw(cameraPosition, Game::CurrentLevel.Size);

	//update fluid animation
	_waterAnimTimer += dt * WaterAnimationSpeed;
}
