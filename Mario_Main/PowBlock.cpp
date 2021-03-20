#include "PowBlock.h"
#include "Texture2D.h"
#include "LevelMap.h"
#include <iostream>

PowBlock::PowBlock(SDL_Renderer* renderer, LevelMap* map)
{
	std::string imagePath = "Images/PowBlock.png"; //local variable that passes the image path into the string
	m_texture = new Texture2D(renderer);//New object on heap , lets us access Texture2D class
	if (!m_texture->LoadFromFile(imagePath.c_str()))//Call load from file from texture2D, pass in the imagepath, if false it will sucessfully load the image , if not we get error message
	{
		std::cout << "Failed to load texture." << std::endl;
		return;
	}

	m_level_map = map;
	m_single_sprite_w = m_texture->GetWidth() / 3; //there are three images in this sprite sheet in a row
	m_single_sprite_h = m_texture->GetHeight();//If we add another row of sprites, we should need to change this
	m_num_hits_left = 3;//Pow is spritesheet with 3 stages, we want to hit it three times
	m_position = Vector2D((SCREEN_WIDTH * 0.5f) - m_single_sprite_w * 0.5f, 260);

}

PowBlock::~PowBlock()
{

	delete m_texture;
	m_texture = nullptr;

	//We dont delete these since other classes are using these variables of the same name, to do would cause a crash.
	m_renderer = nullptr;
	m_level_map = nullptr;
}

void PowBlock::render()
{
	if (m_num_hits_left > 0)
	{
		int sprite_position = m_single_sprite_w*(m_num_hits_left - 1);//Gets us each portion we want to draw
		
		SDL_Rect spritesheet = { sprite_position, 0 , m_single_sprite_w , m_single_sprite_h };//allows us to select one of 3 parts of the sprite sheet
	
		SDL_Rect Rect = {(int) (m_position.x ),(int)(m_position.y)  ,m_single_sprite_w ,m_single_sprite_h };//Sets where we want to draw it using Rect function

		m_texture->Render(spritesheet, Rect, SDL_FLIP_NONE);
	}
}

int PowBlock::TakeHit()
{
	m_num_hits_left - 1;
	if (m_num_hits_left <= 0)
	{
		m_num_hits_left = 0;
		m_level_map->changeTileAt(8, 7, 0);//Comment upholds this regarding the comment, we pass in the row,column then the value we want that tile to change to.
		m_level_map->changeTileAt(8, 8, 0);

		//This statement ensures that if the powblock value turns 0 , we change the tilemap to allow mario or luigi to jump past where the jump block use to be.
		//Done by manipulating the tilemap as seen.
	}
	return 0;
}
