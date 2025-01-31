#pragma once

struct Point
{
	float X;
	float Y;

	Point() = default;
	Point(float x, float y) : X(x), Y(y) { }
};

struct Point_i32
{
	int X;
	int Y;
	Point_i32() = default;
	Point_i32(int x, int y) : X(x), Y(y) { }
};