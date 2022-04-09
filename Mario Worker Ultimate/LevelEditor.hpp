#pragma once
#include "IGamePart.hpp"
#include "Game.hpp"
#include "Libs.hpp"
#include "Resources.hpp"
#include "Resolution.hpp"

class LevelEditor : public IGamePart
{
	Vector2 cameraPosition = { 0,0 };
	Texture _square;

	float levelPx = 0;
	float levelPy = 0;

	Rectangle calculateWorldTransformation(Rectangle normScreen);
	Rectangle calculateTileTransformation(Rectangle normScreen);

	bool _showElements = false;
	bool _previousSpacePress = false;
	// 1 = tiles
	// 2 = enemies
	// 3 = etc
	int categoryId = 0;
	//overwold tiles , desert tiles, et cetera
	int subCategoryId = 0;

	Texture2D W_selectItem;
public:
	void LoadContent() final override;
	void Update(float dt, MouseState* ms, ControllerState* cs) final override;
	void Draw(float dt) final override;
	~LevelEditor();
};