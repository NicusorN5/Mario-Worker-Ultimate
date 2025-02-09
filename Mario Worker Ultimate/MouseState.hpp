#pragma once
#include "Libs.hpp"

class MouseState
{
	bool _previousLeftClick;
public:
	MouseState() : _previousLeftClick(false), LeftClick(false), RightClick(false), X(0), Y(0) {};
	static MouseState GetMouseState();
	static MouseState GetMouseState(MouseState *ms);
	MouseState(bool l, bool r, unsigned x, unsigned y) : LeftClick(l), RightClick(r), X(x), Y(y), _previousLeftClick(false) {};
	bool LeftClick;
	bool RightClick;
	unsigned X;
	unsigned Y;

	bool MouseClickingRectangle(Rectangle r) const noexcept;
	bool MouseFinishedClickingRectangle(Rectangle r) const noexcept;
	bool MouseInsideRectangle(Rectangle r) const noexcept;
	bool MouseFinishedClickingOutsideRectangle(Rectangle r) const noexcept;
	bool MouseClickingOutsideRectangle(Rectangle r) const noexcept;
};