#include "GameScreenClass1.h"
#include "PowBlock.h" //Uphold forward decleration			
#include "Texture2D.h" //Uphold forward decleration
#include <iostream>
GameScreenClass1::GameScreenClass1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetLevelMap();
	SetUpLevel();
	
	m_level_map = nullptr;
}

GameScreenClass1::~GameScreenClass1()
{
	m_background_texture = nullptr;

	delete _mario;
	_mario = nullptr;

	m_pow_block = nullptr;
}

void GameScreenClass1::Render()
{
	//draw the background
	m_background_texture->Render(Vector2D(0, m_background_yPos), SDL_FLIP_NONE);//m_background calls the render function from Texture2D class
	_mario->Render();
	_luigi-> Render();
	m_pow_block->render();
}

void GameScreenClass1::Update(float deltaTime, SDL_Event e)
{
	/*
* do the screen shake if required
*/
	if (m_screenshake)
	{
		m_shake_time -= deltaTime;
		m_wobble++;
		m_background_yPos = sin(m_wobble);//Use sin function to create each wobble
		m_background_yPos *= 3.0f;//Used to move screen y position up and down 

		//end shake after duration from above 
		if (m_shake_time <= 0.0f)
		{
			m_shake_time = false;
			m_background_yPos = 0.0f;//Sets y position to default
		}
	}

	if (Collisions::Instance()->Circle(_mario, _luigi))
	{
		cout << "Circle hit!" << endl;
	}

	//update character
	_mario->Update(deltaTime, e);
	_luigi->Update(deltaTime, e);
	updatePowBlock();


}

void GameScreenClass1::updatePowBlock()
{
	if (Collisions::Instance()->Box(m_pow_block->GetCollisionBox(), _mario->GetCollisionBox()) )//call instance function , then load collision box then pass in pow block and mario
	{
		if (m_pow_block->IsAvailable())
		{
			//collided while jumping
			if (_mario->isJumping())
			{
				DoShakeScreen();
				m_pow_block->TakeHit();
				_mario->CancelJump();
			}

			
		}
	}

}

bool GameScreenClass1::SetUpLevel()
{

	//load texture
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("Images/BackgroundMB.png"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
	//set up player character
	_mario = new Mario(m_renderer, "Images/Mario.png", Vector2D(64, 330), m_level_map);
	_luigi = new Luigi(m_renderer, "Images/luigi.png", Vector2D(64, 330), m_level_map);
	m_pow_block = new PowBlock(m_renderer, m_level_map);//Creates powblock,pass in values it needs
	m_screenshake = false;
	m_background_yPos = 0.0f;
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
	//This works and nothing needs changing here
}

void GameScreenClass1::DoShakeScreen()
{
	m_screenshake = true;
	m_shake_time = SHAKE_DURATION;
	m_wobble = 0.0f;

}
