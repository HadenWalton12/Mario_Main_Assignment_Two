#include "GameScreenManager.h"
#include "GameScreenLevel1.h"
#include "GameScreen.h"

GameScreenManager::GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen)
{
	GameScreen* m_current_screen = nullptr;
	SDL_Renderer* m_renderer = nullptr;
	
	ChangeScreen(startScreen);
}

GameScreenManager::~GameScreenManager()
{
	m_renderer = nullptr;
	delete m_current_screen;
	m_current_screen = nullptr;
}

void GameScreenManager::Render()
{
	m_current_screen->Render();
}

void GameScreenManager::Update(float deltaTime, SDL_Event e)
{
	m_current_screen->Update(deltaTime, e);
}

void GameScreenManager::ChangeScreen(SCREENS new_screen)
{
	//clear up the old screen
	if (m_current_screen != nullptr)
	{
		delete m_current_screen;
	}

}
