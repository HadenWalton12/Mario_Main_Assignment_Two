#include "LevelMap.h"
/*
 * when making a map, remember:
 * 0 = empty space,	1 = blocked/occupied space
 */

LevelMap::LevelMap(int map[MAP_HEIGHT][MAP_WIDTH])//constructor
{
	//Allocate memory for the level map


	m_map = new int* [MAP_HEIGHT];	 //m_map being our pointer to pointer , which creates our dynamic array
	for (unsigned int i = 0; i < MAP_HEIGHT; i++)//For look , running with the iteration of 13
	{
		m_map[i] = new int[MAP_WIDTH];
	}


	//^^above, this simply creates the memory space needed to allocate the holding of all values of the dynamic array , essentially we initialised the two dimensional array on stack
	//The reason we loop this function is that we need to intialise 208 elements on two dimensional array, 
	//two dimensionall arrays allow us to have [x] number of rows and [y] amount of collumns, so this two dimensional array has 13 rows and 16 columns to where we can store data like we do on a typical array, we times the values of x and y to reveal how many elements we have to store objects onto, we will be storing int since this is of integer type
	//populate the array

	
	for (unsigned int i = 0; i < MAP_HEIGHT; i++)//itterates statements 13 times
	{
		for (unsigned int j = 0; j < MAP_WIDTH; j++)	//nested loops allows this loop to run its number of iterations, however will this loop will run 13 times , because the loop nesting it iterates 13 times, the outer loop runs 13 times, making the code within it (nested loop) run its own iterations while looping the outerloop 
		{
			m_map[i][j] = map[i][j]; //This populates the array ,passing in local int map to equal m_map , which passes in from a result our two demisional array values, which are constants Map_height.width
		}
	}

		
		
	
}

LevelMap::~LevelMap()
{
	for (unsigned int i = 0; i < MAP_HEIGHT; i++)//cleares contents of arrays off dynamic memory
	{
		delete[] m_map[i];
	}
	delete[]m_map;

}

int LevelMap::GetTileAt(unsigned int h, unsigned int w)
{
	if (h < MAP_HEIGHT && w < MAP_WIDTH)//If h is less than map_heighct (13) and w  is less than map_width "16" 
	{
		return m_map[h][w];//returns m_map dynamic array passing hx and w into the values of 
	}

	return 0;

}

void LevelMap::changeTileAt(unsigned int row, unsigned int column, unsigned int new_value)
{
	m_map[row][column] = new_value;
}
