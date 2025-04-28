








#pragma once
#include "SDL.h"

template<int box>
class Grid
{

private:

	int m_gridBoxWidth;
	int m_gridBoxHeight;

	SDL_Rect r{ 0,0,0,0 };

	SDL_Rect grid[box][box];

public:

	Grid() = default;

	Grid(int t_screenWidth, int t_screenHeight)
		:m_gridBoxWidth(t_screenWidth / box)
		,m_gridBoxHeight(t_screenHeight / box)
		
	{
		for (int i = 0; i < box; i++)
		{
			for (int j = 1; j < box; j++)
			{
				grid[i][j].x = i * m_gridBoxWidth;
				grid[i][j].y = j * m_gridBoxWidth;
				grid[i][j].w = m_gridBoxWidth;
				grid[i][j].h = m_gridBoxWidth;
			}			
		}
	}	

	SDL_Rect getBox(int t_width, int t_height)
	{
		return grid[t_width][t_height];
	}

	int getGridWidth() const
	{
		return m_gridBoxWidth;
	}

	int getGridHeight() const
	{
		return m_gridBoxHeight;
	}

	void print(SDL_Renderer* t_renderer)
	{

		for (int i = 0; i < box; i++)
		{
			for (int j = 0; j < box; j++)
			{
				SDL_SetRenderDrawColor(t_renderer, 255, 0, 0, 255);
				SDL_RenderDrawRect(t_renderer, &grid[i][j]);
			}
			
		}

	}

	void update(int t_mouseX, int t_mouseY)
	{
		for (int i = 0; i < box; i++)
		{
			for (int j = 0; j < box; j++)
			{
				checkIfInBox(t_mouseX, t_mouseY, grid[i][j]);
			}

		}
	}

	bool wasClickedOn(int mouseX, int mouseY)
	{
		if (checkIfInBox(mouseX, mouseY, container) && SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(1))
		{
			printf("INSIDE OF A GRID BOX!!!\n");
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

	void clickOnFunction()
	{

	}	

};