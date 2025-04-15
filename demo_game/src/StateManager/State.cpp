





#include "State.h"
#include "../Game.h"


//MAIN MENU STATE//
MainMenuState::MainMenuState(Context* t_context)
{
	m_playButton = new Button(0, 0, 100, 100);
	m_buttons.emplace_back(m_playButton);
	m_context = t_context;
	m_id = StateID::MainMenuID;
	printf("%d STATE ID\n", m_id);
	
}
void MainMenuState::ProcessInput(const uint8_t* t_state) 
{

	if (t_state[SDL_SCANCODE_ESCAPE])
	{
		m_context->mStateManager->changeState(PausedID);
	}

}
void MainMenuState::Update(float t_deltaTime) 
{
	
	SDL_GetMouseState(&mouseX, &mouseY);

	printf("mouse x: %d y: %d\n", mouseX, mouseY);

	if (!m_buttons.empty())
	{
		if (m_playButton->wasClickedOn(mouseX, mouseY))
		{
			delete m_playButton;
		}

		m_playButton->container.x += 100 * t_deltaTime;
		m_playButton->container.y += 100 * t_deltaTime;
		printf("%d\n", num);
		num++;
	}
	
}
void MainMenuState::Render(SDL_Renderer* t_renderer) 
{	
	if (!m_buttons.empty())
	{		
		SDL_SetRenderDrawColor(t_renderer, 255, 255, 255, 255);
		SDL_RenderDrawRect(t_renderer, &m_playButton->container);
		
	}
	
	
}

bool MainMenuState::checkIfInBox(int x, int y, SDL_Rect& box)
{
	if (x >= box.x && x <= box.x + box.w && y >= box.y && y <= box.y + box.h)
	{
		printf("INSIDE BOX");
		return true;
	}
	return false;
}



//PAUSED STATE//
PausedState::PausedState(Context* t_context)
{
	m_context = t_context;
	m_id = StateID::PausedID;
	printf("%d STATE ID\n", m_id);
}

void PausedState::ProcessInput(const uint8_t* t_state) 
{
	if (t_state[SDL_SCANCODE_ESCAPE])
	{
		m_context->mStateManager->changeState(MainMenuID);
	}
}
void PausedState::Update(float t_deltaTime) 
{
	printf("%d\n", num);
	num--;
}
void PausedState::Render(SDL_Renderer* t_renderer)
{

}