#include "GameScreenClass1.h"
#include "Texture2D.h" //Uphold forward decleration
#include <iostream>
GameScreenClass1::GameScreenClass1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
	SetLevelMap();
	m_level_map = nullptr;
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
	_mario = new Mario(m_renderer, "Images/Mario.png", Vector2D(64, 330), m_level_map);
	_luigi = new Luigi(m_renderer, "Images/luigi.png", Vector2D(64, 330), m_level_map);

	return true;
}

void GameScreenClass1::SetLevelMap()
{
	int map[MAP_HEIGHT][MAP_WIDTH] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									   { 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1 },
									   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									   { 0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0 },
									   { 1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
									   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									   { 0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0 },
									   { 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1 },
									   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };//We have populated each individual element of the two dimensional array with either 0/1

	//clear any old maps
	if (m_level_map != nullptr)
	{
		delete m_level_map;
	}

	//set the new one
	m_level_map = new LevelMap(map);

}
