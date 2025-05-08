






#pragma once
#ifdef _WIN32
#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
#else
#define ENGINE_API
#endif

class ENGINE_API State
{
public:
	virtual void onEnter() = 0;
	virtual void onExit() = 0;

	virtual void processInput() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

};

class ENGINE_API MainMenuState : public State
{
public:
	void onEnter() override;
	void onExit() override;

	void processInput() override;
	void update() override;
	void render() override;
};