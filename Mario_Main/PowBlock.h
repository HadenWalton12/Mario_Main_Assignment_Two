#pragma once

#include <SDL.h>

#include "commons.h"
#include "Collision.h"

#include <string>

class PowBlock
{
public:
	PowBlock(SDL_Renderer* renderer, LevelMap* map);
	~PowBlock();


	void render();
	int GetCollisionBox() { return m_texture->GetWidth(), m_texture->GetHeight(); };
	int TakeHit() { return 0; };
	bool IsAvailable() { return m_num_hits_left > 0; }//This will return true making powblock avaliable.



private:

	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	LevelMap* m_level_map;

	float m_single_sprite_w;
	float m_single_sprite_h;
	int m_num_hits_left;



};


