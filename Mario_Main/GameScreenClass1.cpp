#include "GameScreenClass1.h"
#include "Texture2D.h" //Uphold forward decleration
#include <iostream>
GameScreenClass1::GameScreenClass1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
}

GameScreenClass1::~GameScreenClass1()
{
	m_background_texture = nullptr;

	delete _mario;
	_mario = nullptr;

}

void GameScreenClass1::Render()
{
	//draw the background
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);//m_background calls the render function from Texture2D class
	_mario->Render();
	_luigi-> Render();
}

void GameScreenClass1::Update(float deltaTime, SDL_Event e)
{
	if (Collisions::Instance()->Circle(_mario, _luigi))
	{
		cout << "Circle hit!" << endl;
	}

	//update character
	_mario->Update(deltaTime, e);
	_luigi->Update(deltaTime, e);

}

bool GameScreenClass1::SetUpLevel()
{

	//load texture
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("Images/test.bmp"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
	//set up player character
	_mario = new Mario(m_renderer, "Images/Mario.png", Vector2D(64, 330));
	_luigi = new Luigi(m_renderer, "Images/luigi.png", Vector2D(64, 330));

	return true;
}
