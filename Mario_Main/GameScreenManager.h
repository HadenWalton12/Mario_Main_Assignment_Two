#pragma once
#include "SDL.h"
#include "Commons.h"


class GameScreen;//Forward declare gamescreen too allow its elements to be accessed
class GameScreenManager
{
public:
	GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen); //SDL_renderder struct and screen enum from commons
	~GameScreenManager();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	void ChangeScreen(SCREENS new_screen);


private:
	SDL_Renderer* m_renderer;
	GameScreen* m_current_screen;



};

