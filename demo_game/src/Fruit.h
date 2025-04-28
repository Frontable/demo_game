










#pragma once
#include "Game.h"
#include <cstdlib>



class Fruit
{

private:

	SDL_Rect fruit;



public:

	Fruit(SDL_Rect t_owner)
	{
		fruit.x = t_owner.x + 5;
		fruit.y = t_owner.y + 5;
		fruit.w = t_owner.w - 10;
		fruit.h = t_owner.h - 10;		

	}

	void printFruit(SDL_Renderer* t_renderer)
	{
		SDL_SetRenderDrawColor(t_renderer, 0, 255, 0, 255);

		SDL_RenderDrawRect(t_renderer, &fruit);
	}



};