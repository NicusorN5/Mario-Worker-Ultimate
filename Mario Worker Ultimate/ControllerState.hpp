#pragma once
#include "raylib.h"

struct ControllerState
{
	bool Up; //up arrow
	bool Down; //down arrow
	bool Left; //left arrow
	bool Right; //right arrow
	bool X; //x button 
	bool Z; // z button 
	bool C; // c button (may not be used)
	bool P; // p button (for pausing the game).
	bool Shift; // shift (for speeeing up movement in the editor)
	bool Space; // space button (showing the elements)
};

ControllerState GetControllerState();