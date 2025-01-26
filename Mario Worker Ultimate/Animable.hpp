#pragma once
#include "Libs.hpp"

class Animable
{
	float _animTimer;
	
	short currentFrame;

protected:
	Animable(float speed = 0, short numFrames = 1, short startFrame = 0);
public:
	void UpdateAnim(float dt);

	/// <summary>
	/// A value of 1.00f represents 60 frames per second (just like in Clickteam Fusion 2.5).
	/// </summary>
	float AnimSpeed;
	short NumFrames;

	enum class SpriteSheetOrientation
	{
		Horizontal,
		Vertical,
	};

	Rectangle GetFrame(Rectangle animOffsetAndSize, SpriteSheetOrientation orientation = SpriteSheetOrientation::Horizontal);
	
	void SwitchAnim(short numFrames, short startFrame);
	void SwitchAnim(float speed, short numFrames, short startFrame);
};