







#pragma once  
#include <iostream>  
#include "StateManager/State.h"  

struct Button  
{  

   SDL_Rect container;  

   Button(int t_x, int t_y, int t_w, int t_h);

   bool wasClickedOn(int mouseX, int mouseY);  

   bool checkIfInBox(int x, int y, SDL_Rect& container);  

   void clickOnFunction();  
};