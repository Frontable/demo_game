






#pragma once
#include "SDL.h"

struct Position
{
	float x, y;
};

struct Velocity
{
	float vx, vy;
};

struct BoxComponent
{
	BoxComponent(float x, float y, float w, float h)
	{
		xMid = x - (w / 2);
		yMid = y - (h / 2);

		box.x = static_cast<int>(xMid);
		box.y = static_cast<int>(yMid);
		box.w = static_cast<int>(w);
		box.h = static_cast<int>(h);

	}

	float xMid, yMid;

	SDL_Rect box;
};