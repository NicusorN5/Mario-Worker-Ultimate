#pragma once
#include "IScene.hpp"
#include "../Resources.hpp"
#include "../Game.hpp"
#include "../Libs.hpp"
#include "../Resources.hpp"
#include "../Resolution.hpp"

constexpr float WaterAnimationSpeed = 7.0f;

constexpr float ScreenTilesX = 20.0f;
constexpr float ScreenTilesY = 15.0f;

class GameBase: public IScene
{
protected:
	Vector2 cameraPosition = { 0,0 };

	Rectangle calculateViewTransform(Rectangle normScreen);
	Rectangle calculateTileTransformation(Rectangle normScreen);

	float _liquidAnimTimer = 0;
public:
	void LoadContent() override;
	void Update(float dt, MouseState* ms, ControllerState* cs) override;

	void DrawLiquid();
	void DrawSpikedFloor();

	void Draw(float dt) override;
};