





/*
#include "State.h"
#include "../Game.h"
#include "../Button.h"


//MAIN MENU STATE//
MainMenuState::MainMenuState(Game* t_game)
{
	m_playButton = new Button(100, 100, 100, 100);
	m_exitButton = new Button(100, 300, 100, 100);
	m_buttons.emplace_back(m_playButton);
	m_buttons.emplace_back(m_exitButton);
	m_game= t_game;
	m_id = StateID::MainMenuID;
	//printf("%d STATE ID\n", m_id);
	
}

MainMenuState::~MainMenuState()
{

	for (auto button : m_buttons)
	{
		delete button;
	}

}


void MainMenuState::ProcessInput(const uint8_t* t_state) 
{

	if (t_state[SDL_SCANCODE_ESCAPE])
	{
		m_game->getStateManager()->changeState(PausedID);
	}

}
void MainMenuState::Update(float t_deltaTime) 
{
	
	SDL_GetMouseState(&mouseX, &mouseY);

	//printf("mouse x: %d y: %d\n", mouseX, mouseY);

	
	if (!m_buttons.empty())
	{
		if (m_playButton->wasClickedOn(mouseX, mouseY))
		{
			m_game->getStateManager()->changeState(PausedID);
		}
		if (m_exitButton->wasClickedOn(mouseX, mouseY))
		{
			m_game->getStateManager()->changeState(PausedID);
		}
	}

}
void MainMenuState::Render(SDL_Renderer* t_renderer) 
{	
	if (!m_buttons.empty())
	{
		
		for (auto button : m_buttons)
		{
			SDL_SetRenderDrawColor(t_renderer, 255, 255, 255, 255);
			SDL_RenderDrawRect(t_renderer, &button->container);
		}
		
		
	}
	
	
}

bool MainMenuState::checkIfInBox(int x, int y, SDL_Rect& box)
{
	if (x >= box.x && x <= box.x + box.w && y >= box.y && y <= box.y + box.h)
	{
		//printf("INSIDE BOX");
		return true;
	}
	return false;
}



//PAUSED STATE//
PausedState::PausedState(Game* t_game)
{
	m_game = t_game;
	m_id = StateID::PausedID;
	//printf("%d STATE ID\n", m_id);
}

void PausedState::ProcessInput(const uint8_t* t_state) 
{
	if (t_state[SDL_SCANCODE_ESCAPE])
	{
		m_game->getStateManager()->changeState(MainMenuID);
	}
}
void PausedState::Update(float t_deltaTime) 
{
	//printf("%d\n", num);
	num--;
}
void PausedState::Render(SDL_Renderer* t_renderer)
{

}
*/