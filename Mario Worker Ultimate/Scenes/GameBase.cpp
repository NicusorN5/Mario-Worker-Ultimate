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

void GameBase::DrawLiquid()
{
	Texture2D liquid;
	Rectangle currentWaterWorldTile;
	Rectangle liquidAnimRectangle;
	Color liquidColor;

	switch(Game::CurrentLevel.Liquid)
	{
		case LiquidType::Water:
			liquid = Resources::Water;
			liquidAnimRectangle = Rectangle{
				0,
				static_cast<float>((static_cast<int>(_liquidAnimTimer) % 5) * 16),
				64 * ScreenTilesX / 2,
				16
			};
			liquidColor = Resources::WaterColor;
			break;
		case LiquidType::Lava:
			liquid = Resources::Lava;
			liquidAnimRectangle = Rectangle{
				0,
				static_cast<float>((static_cast<int>(_liquidAnimTimer) % 7) * 34),
				64 * ScreenTilesX / 2,
				34
			};
			liquidColor = Resources::LavaColor;
			break;
		case LiquidType::Poison:
			liquidAnimRectangle = Rectangle{
				ScreenTilesX * Resources::Water.width,
				static_cast<float>((static_cast<int>(_liquidAnimTimer) % 5) * 16),
				64 * ScreenTilesX,
				16
			};
			liquid = Resources::Water;
			liquidColor = Resources::WaterColor;
			break;
		default:
			return;
	}

 	auto height = Game::CurrentLevel.LiquidLevel / ScreenTilesY;
	
	currentWaterWorldTile = calculateViewTransform(Game::ScreenRec({0, height, 1.0f, 1.0f / (ScreenTilesY * (32.f / liquidAnimRectangle.height))}));
	currentWaterWorldTile.x = 0;

	DrawTexturePro(
		liquid,
		liquidAnimRectangle,
		currentWaterWorldTile,
		{ 0,0 },
		0.0f,
		Color(255,255,255, 255)
	);



	DrawRectangle(
		0,
		currentWaterWorldTile.y + liquidAnimRectangle.height,
		Game::Resolution::X,
		Game::Resolution::Y * (1),
		liquidColor
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
	_liquidAnimTimer += dt * WaterAnimationSpeed;
}
