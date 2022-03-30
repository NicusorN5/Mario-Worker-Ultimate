#include "Libs.h"

int main()
{
	InitWindow(800, 600, "Mario Worker Ultimate");
	
	Color clearColor = { 128, 128, 255, 255 };

	SetExitKey(0);
	SetTargetFPS(60);
	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(clearColor);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}