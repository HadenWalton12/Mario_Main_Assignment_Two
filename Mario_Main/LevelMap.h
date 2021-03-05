#pragma once
#ifndef _LEVELMAP_H
#define _LEVELMAP_H

#include "constants.h"
class LevelMap
{




public:
	LevelMap(int map[MAP_HEIGHT][MAP_WIDTH]);//map has a two dimensional array , one being map_height the other width
	~LevelMap();

	int GetTileAt(unsigned int h, unsigned int w);
	void changeTileAt(unsigned int row, unsigned int column, unsigned int new_value);
private:
	int** m_map;//This is a pointer to a pointer, allows us to create dynamic arrays


};

#endif