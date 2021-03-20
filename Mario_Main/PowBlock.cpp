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
}

void PowBlock::render()
{
}
