// Mario_Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>//Used for input/output data to console
#include "constants.h"
//SDL Libary Inclusions
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>


//Globals
SDL_Window* game_window = nullptr;//SDL_Window function pointed to variable called game_window with the value of null

//Function prototypes
bool InitSDL();//Initliases  SDL
void CLoseSDL();//Closes SDL


int main(int argc, char* args[])
{
	//check if sdl was setup correctly
	if (InitSDL())
	{
		SDL_Delay(5000);//This opens the window for 5 seconds
	}

	CLoseSDL();//After the INITSDL function has opened the window for 5 seconds, this closes the program and window

	return 0;

}

bool InitSDL()
{
	//Setup SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)//the SDL_INIT_VIDEO Flag is passed into SDL_INIT function to specify we are using a video subsystem (its a sub-system since this is contextualised from the SDL System0
	{
		std::cout << "SDL did not initialise. Error: " << SDL_GetError();
		return false;
		/*The flag SDL*/
	}
	else
	{
		//setup passed so create window
		game_window = SDL_CreateWindow//game_window is pointed to the SDL_Window Function
		("Mario Project By Hayden Walton",//Credited Title of the game_window
			
			SDL_WINDOWPOS_UNDEFINED,//x
			SDL_WINDOWPOS_UNDEFINED,//y    //These statements intialise  the x and y axis of the newly created window, in order to generate the window, both an Width(x) & Height(Y) will need to be coordinated
			
			SCREEN_WIDTH,//width 
			SCREEN_HEIGHT,//Height // Constants from the "constants.h" file

			SDL_WINDOW_SHOWN); //Flag - a flag can be considered as a specfic parameter which gives in this instance, a window , specific properties
	
	
		//This conditional checks whether the game_window was created, since when created a new value that isnt its intial value "null" would replace this
		if (game_window == nullptr) 
		{
			//window failed
			std::cout << "Window was not created. Error: " << SDL_GetError();
			return false;
		}
	}

	return true;
	
}

void CLoseSDL()//Free's up memory by closing down the SDL functions we generated
{
	//release the window
	SDL_DestroyWindow(game_window);//Destroys The game window we created by using the pointer
	game_window = nullptr;//Since the game_window would of be fiven value from generating the gamewindow, this returns this pointer back to its null value

	//quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

}
