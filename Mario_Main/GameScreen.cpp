	#include "GameScreen.h"

GameScreen::GameScreen(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}

GameScreen::~GameScreen()
{
	m_renderer = nullptr; //This is to prevent 
}

void GameScreen::Render(){}

void GameScreen::Update(float deltaTime, SDL_Event e){}
