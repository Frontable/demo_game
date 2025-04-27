






#pragma once
#include "SDL.h"
#include <iostream>

struct Position
{
	float x, y;

	Position()
	{
		x = 0;
		y = 0;
		printf("Position component created.\n");
	}

	Position(float t_x, float t_y)
	{
		x = t_x;
		y = t_y;
		printf("Position component created.\n");
	}
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