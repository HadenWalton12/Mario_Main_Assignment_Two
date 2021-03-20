#pragma once
class Texture2D;//Forward Declation ,allows Texture 2D class and variables to be accessed and function to be called
#include "SDL.h"

#include "GameScreen.h"
#include "constants.h"
#include "Commons.h"
#include "Collision.h"
//Characters Used
#include "Luigi.h"
#include "Mario.h"
//LevelMap
#include "LevelMap.h"
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
	LevelMap* m_level_map; //Class pointer, this allows m_level_map to access all non privated functions of levelmap

	bool SetUpLevel();
	void SetLevelMap();

protected:


};


