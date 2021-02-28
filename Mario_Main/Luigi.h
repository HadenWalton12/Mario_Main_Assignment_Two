#pragma once
#include "Character.h"
#include "SDL.h"
#include "Commons.h"
#include "constants.h"
#include <iostream>
#include <string>

using namespace std;
class Luigi : public Character
{
public:
	Luigi(SDL_Renderer* renderer, string imagePath, Vector2D start_position);
	~Luigi();


	void Update(float deltaTime, SDL_Event e);
	void MoveLeft(float deltaTime);
	void MoveRight(float deltaTime);

	void Render();



};

