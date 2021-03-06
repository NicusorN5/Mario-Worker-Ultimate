#include "ControllerState.hpp"

ControllerState GetControllerState()
{
    return
    {
        IsKeyDown(KEY_UP),
        IsKeyDown(KEY_DOWN),
        IsKeyDown(KEY_LEFT),
        IsKeyDown(KEY_RIGHT),
        IsKeyDown(KEY_X),
        IsKeyDown(KEY_Z),
        IsKeyDown(KEY_C),
        IsKeyDown(KEY_P),
        IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT),
        IsKeyDown(KEY_SPACE)
    };
}
