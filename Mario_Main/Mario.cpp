#include "Mario.h"
#include <iostream>

Mario::Mario(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map) : Character(renderer, imagePath, start_position, map)
{




}

Mario::~Mario()
{
}

void Mario::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		//If keyboard event "pressing w " is fulfiled, , movement up
		switch (e.key.keysym.sym)
		{

		case SDLK_d:
			m_moving_right = true;

			break;


		case SDLK_a:
			m_moving_left = true;

			break;

		case SDLK_SPACE:

			Gravity(deltaTime);
			jump();

			break;


		}
		break;
	case SDL_KEYUP://This case event switching the nested switch below will disable movement once the key is up (meaning when we stop pressing down the key.
		switch (e.key.keysym.sym)
		{
		case SDLK_d:
			m_moving_right = false;
			break;

		case SDLK_a:
			m_moving_left = false;
			break;


		}


		break;
	}
	Character::Update(deltaTime, e);
}

void Mario::MoveLeft(float deltaTime)
{
	Character::MoveLeft(deltaTime);
}

void Mario::MoveRight(float deltaTime)
{
	Character::MoveRight(deltaTime);
}

void Mario::Render()
{
	Character::Render();
}
