#include "GameScreenManager.h"
#include "GameScreenClass1.h"
#include "GameScreen.h"//Keeps forward decloration true
GameScreenManager::GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen)
{

	m_renderer = renderer;


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
	m_current_screen->Render();//Class the render function from game screen
}

void GameScreenManager::Update(float deltaTime, SDL_Event e)
{
	m_current_screen->Update(deltaTime, e);//Points to the update function from gamescreen, this has nothing into it however , we also needed to pass deletTime and E since they were included in the function in gamescreen
}

void GameScreenManager::ChangeScreen(SCREENS new_screen)
{
	//clear up the old screen
	if (m_current_screen != nullptr)
	{
		delete m_current_screen;
	}
	GameScreenClass1* tempScreen;
	switch (new_screen)
	{
	case SCREEN_LEVEL1:
		tempScreen = new GameScreenClass1(m_renderer);
		m_current_screen = (GameScreen*)tempScreen;
		tempScreen = nullptr;
	default:;
	}

}
