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
	Rect2D GetCollisionBox() { return Rect2D(m_position.x, m_position.y, (m_texture->GetWidth() / 3), m_texture->GetHeight()); };//Inline function, passes us x & y positions from which allow us to generate coliision box
	void TakeHit();
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


