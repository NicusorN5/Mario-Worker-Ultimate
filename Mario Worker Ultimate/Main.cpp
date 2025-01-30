#include "Scenes/MainMenu.hpp"
#include "Game.hpp"
#include "UI/Dialogs.hpp"
#include "Native.hpp"
#include "Scenes/LevelEditor.hpp"
#include "Scenes/Intro.hpp"
#include "Scenes/LevelPlayer.hpp"
#include "Scenes/BlankScene.hpp"
#include <thread>
#include <chrono>

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
	gameSections[1].reset(new MainMenu());
	gameSections[2].reset(new LevelEditor());
	gameSections[3].reset(new LevelPlayer());

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

	for(int i = 0; i < 5; i++)
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

	SetExitKey(0);
	SetTargetFPS(60);

	MouseState mouse;

	/*
	std::jthread update_thread = std::jthread([&]()
	{
		float udt = 0;
		while(!WindowShouldClose() && Game::GameRunning)
		{
			auto t1 = std::chrono::high_resolution_clock::now();
			mouse = MouseState::GetMouseState(&mouse);
			ControllerState controls = GetControllerState();
			gameSections[Game::CurrentGameSection]->Update(udt, &mouse, &controls);

			auto t2 = std::chrono::high_resolution_clock::now();
			udt = std::chrono::duration<float>(t2 - t1).count();
		}
	}
	);
	update_thread.detach();
	*/

	float udt = 0;
	//game loop
	while(!WindowShouldClose() && Game::GameRunning)
	{
		BeginDrawing();
		BeginBlendMode(BLEND_ALPHA);
		float dt = GetFrameTime();
		ClearBackground(BLACK);
		gameSections[Game::CurrentGameSection]->Draw(dt);
		EndBlendMode();
		EndDrawing();

		auto t1 = std::chrono::high_resolution_clock::now();
		mouse = MouseState::GetMouseState(&mouse);
		ControllerState controls = GetControllerState();
		gameSections[Game::CurrentGameSection]->Update(dt, &mouse, &controls);

		auto t2 = std::chrono::high_resolution_clock::now();
		udt = std::chrono::duration<float>(t2 - t1).count();
	}

	CloseAudioDevice();
	CloseWindow();
	//cleanup
	Resources::UnloadAll();
	return 0;
}