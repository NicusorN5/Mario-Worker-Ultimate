#include "Scenes/MainMenu.hpp"
#include "Game.hpp"
#include "UI/Dialogs.hpp"
#include "Scenes/LevelEditor.hpp"
#include "Scenes/Intro.hpp"

int main(int argv, char **argc)
{
	bool isFullscreen = false;
	//parse arguments
	for(int i = 1; i < argv; ++i)
	{
		//-fullscreen command line argument
		if(strcmp(argc[i], "-fullscreen") == 0)
		{
			isFullscreen = true;
		}

		//-res X Y command line argument, sets the size of the window and backbuffer.
		if(strcmp(argc[i], "-res") == 0 && argv > i+2)
		{
			Game::Resolution::X = std::stoi(argc[i + 1]);
			Game::Resolution::Y = std::stoi(argc[i + 2]);
		}
	}
	//640x480
	Game::Resolution::X = 640;
	Game::Resolution::Y = 480;
	Game::CurrentGameSection = 0;

	//initialization
	ProperlySetWorkingPath();
	InitWindow(Game::Resolution::X, Game::Resolution::Y, "Mario Worker Ultimate");
	InitAudioDevice();

	if(isFullscreen)
	{
		ToggleFullscreen();
	}

	void* WindowHandle = GetWindowHandle();
	SetGameIcon(WindowHandle);

	std::array<std::unique_ptr<IScene>, 5> gameSections;
	gameSections[0].reset(new Intro());

	try
	{
		gameSections[0]->LoadContent();
	}
	catch(GameResourceLoadException& ex)
	{
		std::stringstream str;
		str << "The file: " << ex.what() << " is missing.\r\n Reinstalling the game can fix this issue.";
		ShowMessageBoxError(WindowHandle, str.str().c_str(), "Error loading game content");
		ExitFileNotFound();
	}

	gameSections[1].reset(new MainMenu());
	gameSections[2].reset(new LevelEditor());

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
		gameSections[Game::CurrentGameSection]->Update(dt, &mouse, &controls);
	}

	CloseAudioDevice();
	CloseWindow();
	//cleanup
	Resources::UnloadAll();
	return 0;
}