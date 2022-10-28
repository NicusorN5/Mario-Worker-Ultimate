#include "MainMenu.hpp"
#include "Game.hpp"
#include "Dialogs.hpp"
#include "LevelEditor.hpp"
#include "Intro.hpp"
#include <thread>

int main()
{
	//initialization
	ProperlySetWorkingPath();
	InitWindow(800, 600, "Mario Worker Ultimate");
	InitAudioDevice();
	//ToggleFullscreen();

	Game::Resolution::X = 800;
	Game::Resolution::Y = 600;
	Game::CurrentGameSection = 0;

	void* WindowHandle = GetWindowHandle();
	SetGameIcon(WindowHandle);

	IGamePart* gameSections[5]{ nullptr };
	gameSections[0] = new Intro();
	gameSections[0]->LoadContent();

	gameSections[1] = new MainMenu();
	gameSections[2] = new LevelEditor();

	//auto loadF = [=]()
	//{
		try
		{
			Resources::LoadAll();
		}
		catch(GameResourceLoadException& ex)
		{
			std::stringstream str;
			str << "The file: " << ex.what() << " is missing.\r\n Reinstalling the game can fix this issue.";
			ShowMessageBoxError(WindowHandle, str.str().c_str(), "Error loading game content");
			ExitFileNotFound();
		}

		for(int i = 1; i < 5; i++)
		{
			if(gameSections[i] == nullptr) continue;
			try
			{
				gameSections[i]->LoadContent();
			}
			catch(GameResourceLoadException& ex)
			{
				std::stringstream str;
				str << "The file: " << ex.what() << " is missing.\r\n Reinstalling the game can fix this issue.";
				ShowMessageBoxError(WindowHandle, str.str().c_str(), "Error loading game content");
				ExitFileNotFound();
			}
		}
	//};

	//std::thread loadRes(loadF);
	//loadRes.detach();

	Color clearColor = { 0, 0, 0, 255 };

	SetExitKey(0);
	SetTargetFPS(60);
	
	MouseState mouse;

	//game loop
	while(!WindowShouldClose() && Game::GameRunning)
	{
		BeginDrawing();
		BeginBlendMode(BLEND_ALPHA);
		float dt = GetFrameTime();
		ClearBackground(clearColor);
		gameSections[Game::CurrentGameSection]->Draw(dt);
		EndBlendMode();
		EndDrawing();

		mouse = MouseState::GetMouseState(&mouse);
		ControllerState controls = GetControllerState();
		gameSections[Game::CurrentGameSection]->Update(dt,&mouse,&controls);
	}

	CloseAudioDevice();
	CloseWindow();
	//cleanup
	Resources::UnloadAll();
	for(int i = 0; i < 5; i++)
	{
		delete gameSections[i];
	}
	return 0;
}