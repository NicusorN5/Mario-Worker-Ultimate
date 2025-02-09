#include "MouseState.hpp"

MouseState MouseState::GetMouseState()
{
    return
    {
        IsMouseButtonDown(MOUSE_BUTTON_LEFT),
        IsMouseButtonDown(MOUSE_BUTTON_RIGHT),
        static_cast<unsigned>(GetMouseX()),
        static_cast<unsigned>(GetMouseY())
    };
}

MouseState MouseState::GetMouseState(MouseState *ms)
{
    MouseState nms = 
    {
        IsMouseButtonDown(MOUSE_BUTTON_LEFT),
        IsMouseButtonDown(MOUSE_BUTTON_RIGHT),
        static_cast<unsigned>(GetMouseX()),
        static_cast<unsigned>(GetMouseY())
    };
    nms._previousLeftClick = ms->LeftClick;

    return nms;
}

bool MouseState::MouseClickingRectangle(Rectangle r) const noexcept
{
    if(this->LeftClick)
    {
        return (this->X >= r.x && this->X <= r.x + r.width &&
                this->Y >= r.y && this->Y <= r.y + r.height);
    }
    return false;
}

bool MouseState::MouseFinishedClickingRectangle(Rectangle r) const noexcept
{
    if(_previousLeftClick && !LeftClick)
    {
        return (this->X >= r.x && this->X <= r.x + r.width &&
        this->Y >= r.y && this->Y <= r.y + r.height);
    }
    return false;
}

bool MouseState::MouseInsideRectangle(Rectangle r) const noexcept
{
    return (this->X >= r.x && this->X <= r.x + r.width &&
            this->Y >= r.y && this->Y <= r.y + r.height);
}

bool MouseState::MouseFinishedClickingOutsideRectangle(Rectangle r) const noexcept
{
    if(_previousLeftClick && !LeftClick)
    {
        return (this->X <= r.x && this->X >= r.x + r.width &&
                this->Y <= r.y && this->Y >= r.y + r.height);
    }
    return false;
}

bool MouseState::MouseClickingOutsideRectangle(Rectangle r) const noexcept
{
    return LeftClick && !MouseInsideRectangle(r);
}