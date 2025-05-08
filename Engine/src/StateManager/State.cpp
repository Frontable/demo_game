







#include "StateManager/State.h"
#include <iostream>


void MainMenuState::onEnter()
{
	printf("Entering Main Menu;\n");
}

void MainMenuState::onExit()
{
	printf("Exiting Main Menu;\n");
}

void MainMenuState::processInput()
{
	printf("Processing Input Main Menu;\n");
}

void MainMenuState::update()
{
	printf("UpdatingMain Menu;\n");
}

void MainMenuState::render()
{
	printf("Rendering Main Menu;\n");
}


