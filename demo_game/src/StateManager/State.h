







/*
#pragma once
#include <iostream>
#include <vector>
#include "SDL.h"


enum StateID
{
	MainMenuID,
	PausedID,
	InGameID
};

class Game;
struct Button;

class State
{

protected:
	int mouseX, mouseY; //TO DO: will be Vec2 in future
	Game* m_game;
	StateID m_id;


public:

	~State() = default;

	StateID getID() const { return m_id; }

	virtual void ProcessInput(const uint8_t* t_state) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(SDL_Renderer* t_renderer) = 0;

};

class MainMenuState : public State
{
private:
	int num = 1;
	Button* m_playButton;
	Button* m_exitButton;
	bool active = true;
	std::vector<Button*> m_buttons;
public:
	MainMenuState(Game* t_game);
	~MainMenuState();
	void ProcessInput(const uint8_t* t_state) override;
	void Update(float t_deltaTime) override;
	void Render(SDL_Renderer* t_renderer) override;

	bool checkIfInBox(int x, int y, SDL_Rect& box);

};

class PausedState : public State
{

private:
	int num = 1000;

public:

	PausedState(Game* t_game);

	void ProcessInput(const uint8_t* t_state) override;
	void Update(float t_deltaTime) override;
	void Render(SDL_Renderer* t_renderer) override;

};

class InGameState : public State
{

private:

	int num = 1000;

public:
	InGameState()
	{
		m_id = StateID::InGameID;
	}
	void Update(float t_deltaTime) override
	{
		printf("%d\n", num);
		num--;
	}

};


struct Context;

class State {
public:
    virtual ~State() = default;

    
    virtual void OnEnter() {}       
    virtual void OnExit() {}        
    virtual void OnPause() {}       
    virtual void OnResume() {}      

    
    virtual void ProcessInput() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render() = 0;

protected:
    std::shared_ptr<Context> m_context;
};
*/