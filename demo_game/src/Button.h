









#pragma once
#include <iostream>
#include "SDL.h"

struct Button
{

	SDL_Rect container;

	Button(int t_x, int t_y, int t_w, int t_h)
	{
		container.x = t_x;
		container.y = t_y;
		container.w = t_w;
		container.h = t_h;
	}

	bool wasClickedOn(int mouseX, int mouseY)
	{
		if (checkIfInBox(mouseX, mouseY, container) && SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(1))
		{
			printf("INSIDE BOXxxxxxxxxxxxxxxxxx\n");
			return true;
		}

		return false;

	}
	bool checkIfInBox(int x, int y, SDL_Rect& container)
	{
		if (x >= container.x && x <= container.x + container.w && y >= container.y && y <= container.y + container.h)
		{
			printf("INSIDE BOX");
			return true;
		}
		return false;
	}
	

};