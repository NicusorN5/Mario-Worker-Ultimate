#include "Animable.hpp"

Animable::Animable(float speed, short numFrames, short startFrame) :
	AnimSpeed(speed),
	NumFrames(numFrames),
	currentFrame(startFrame),
	_animTimer(0)
{
}

void Animable::UpdateAnim(float dt)
{
	_animTimer += dt;

	//Assume the game runs at 60 frames per second.
	if(_animTimer >= (1.0f / 60.0f) * AnimSpeed)
	{
		_animTimer = 0;
		currentFrame++;
	}

	if(currentFrame >= NumFrames)
	{
		currentFrame = 0;
	}
}

Rectangle Animable::GetFrame(Rectangle animOffsetAndSize, SpriteSheetOrientation orientation)
{
	return
	{
		animOffsetAndSize.x + (orientation == SpriteSheetOrientation::Horizontal ? animOffsetAndSize.width * currentFrame : 0),
		animOffsetAndSize.y + (orientation == SpriteSheetOrientation::Vertical ? animOffsetAndSize.height * currentFrame : 0),
		animOffsetAndSize.width,
		animOffsetAndSize.height
	};
}

void Animable::SwitchAnim(float speed, short numFrames, short startFrame)
{
	AnimSpeed = speed;
	NumFrames = numFrames;
	currentFrame = startFrame;
	_animTimer = 0;
}

void Animable::SwitchAnim(short numFrames, short startFrame)
{
	NumFrames = numFrames;
	currentFrame = startFrame;
	_animTimer = 0;
}