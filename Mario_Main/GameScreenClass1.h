#pragma once
class Texture2D;//Forward Declation ,allows Texture 2D class and variables to be accessed and function to be called

#include "GameScreen.h"
#include "Commons.h"
#include "SDL.h"
#include "Collision.h"
#include "Luigi.h"
#include "Mario.h"
class GameScreenClass1 : GameScreen //GanescreenClass1 is a child class to gamescreen , gamescreen is parent class
{
public:
	GameScreenClass1(SDL_Renderer* renderer);
	~GameScreenClass1();

	void Render() override;
	void Update(float deltaTime, SDL_Event event) override;



private:

	Texture2D* m_background_texture;
	Mario* _mario;
	Luigi* _luigi;

	bool SetUpLevel();

protected:


};


