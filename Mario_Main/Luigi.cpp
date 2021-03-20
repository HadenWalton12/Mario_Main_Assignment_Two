#include "Luigi.h"
#include <iostream>
Luigi::Luigi(SDL_Renderer* renderer, string imagePath, Vector2D start_position , LevelMap* map) : Character(renderer, imagePath, start_position , map)
{




}

Luigi::~Luigi()
{
}

void Luigi::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		//If keyboard event "pressing w " is fulfiled, , movement up
		switch (e.key.keysym.sym)
		{

		case SDLK_l:
			m_moving_right = true;

			break;


		case SDLK_j:
			m_moving_left = true;

			break;

		case SDLK_k:

			Gravity(deltaTime);
			jump();

			break;


		}
		break;
	case SDL_KEYUP://This case event switching the nested switch below will disable movement once the key is up (meaning when we stop pressing down the key.
		switch (e.key.keysym.sym)
		{
		case SDLK_l:
			m_moving_right = false;
			break;

		case SDLK_j:
			m_moving_left = false;
			break;


		}


		break;
	}
	Character::Update(deltaTime, e);
}

void Luigi::MoveLeft(float deltaTime)
{
	Character::MoveLeft(deltaTime);
}

void Luigi::MoveRight(float deltaTime)
{
	Character::MoveRight(deltaTime);
}

void Luigi::Render()
{
	Character::Render();
}



	


