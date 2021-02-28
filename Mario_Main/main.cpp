//SDL Library Functions
#include "GameScreenManager.h"
#include <iostream>//Input/OutPut stream used for inputting and outputting data
#include "Texture2D.h"
#include "constants.h" //Includes screen constants
#include "Commons.h"



#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>




//Globals
SDL_Window* game_window = nullptr; //Creating a global pointer, declaring the a struct pointer (SDL_window struct) to g_window, with the initialised value to null (makes memory address to 0000000)
GameScreenManager* game_screen_manager; 
SDL_Renderer* game_renderer = nullptr;
Uint32 g_old_time;

//Function prototypes
bool InitialiseSDL();
void CLoseSDL();
bool update();
void Render();





int main(int argc, char* args[])
{
	//Checks if we want to quit
	bool quit = false;

	//check if sdl was setup correctly
	if (InitialiseSDL())
	{
		game_screen_manager = new GameScreenManager(game_renderer, SCREEN_LEVEL1);
		//set the time
		g_old_time = SDL_GetTicks();
		//Game loop
		while (!quit)//while !quit = true, creating our game loop
		{
			Render();
			quit = update();

		}


		return true;
	}


	CLoseSDL();//After the INITSDL function has opened the window for 5 seconds, this closes the program and window

	return 0;


}

bool InitialiseSDL()
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
		game_renderer = SDL_CreateRenderer(game_window, -1, SDL_RENDERER_ACCELERATED);
		if (game_renderer != nullptr)
		{
			//init PNG loading
			int imageFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imageFlags) & imageFlags))
			{
				std::cout << "SDL_Image could not initialise. Error: " << IMG_GetError();
				return false;
			}
		}
		else
		{
			std::cout << "Renderer could not initialise. Error: " << SDL_GetError();
			return false;
		}
		//Load the background texture
		//Load the background texture



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

	//clear the texture

	//release the renderer
	SDL_DestroyRenderer(game_renderer);
	game_renderer = nullptr;

	//destroy the game screen manager
	delete game_screen_manager;
	game_screen_manager = nullptr;




}

bool update()
{
	Uint32 new_time = SDL_GetTicks();
	/**/
//Created an event handler, this will handle what happens if an event occurs,
	SDL_Event Event;
	SDL_PollEvent(&Event);




	//We used switch statements since depending on the event , the case with the event can be executed
	switch (Event.type)
	{
		//When 'X' is clicke on the tab, screen is closed
	case SDL_QUIT:
		return true;
		break;

	case SDL_KEYUP:
		//If keyboard event "pressing x " is fulfiled, , window is exitied.
		switch (Event.key.keysym.sym)
		{
		case SDLK_x:
			return true;
			break;

		}

	default:
		break;
	}
	game_screen_manager->Update((float)(new_time - g_old_time) / 1000.0f, Event);
	g_old_time = new_time;
	return false;

}

void Render()
{

	//Clear the screen
	SDL_SetRenderDrawColor(game_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(game_renderer);


	game_screen_manager->Render();//THis calls the gamescreenmanagers Render function

	//update the screen
	SDL_RenderPresent(game_renderer);






}


