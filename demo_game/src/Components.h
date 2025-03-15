






#pragma once
#include "SDL.h"

struct Position
{
	float x, y;
};

struct Velocity
{

};

struct BoxComponent
{
	BoxComponent(int x, int y, int w, int h)
	{
		box.x = x;
		box.y = y;
		box.w = w;
		box.h = h;
	}

	SDL_Rect box;
};