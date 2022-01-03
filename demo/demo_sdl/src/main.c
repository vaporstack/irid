// SDL2 Hello, World!
// This should display a white screen for 2 seconds
// compile with: clang++ main.cpp -o hello_sdl2 -lSDL2
// run with: ./hello_sdl2
#include <SDL2/SDL.h>
#include <irid/irid.h>
#include <stdbool.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

IridRec* irid = NULL;
char*	 dropped_filedir; // Pointer for directory of dropped file

int init_demo(void)
{
	irid = irid_create();

	return 0;
}

void deinit_demo(void)
{
	irid_destroy(irid);
}

int main(int argc, char* args[])
{
	SDL_Window*  window	   = NULL;
	SDL_Surface* screenSurface = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow(
	    "hello_sdl2",
	    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	    SCREEN_WIDTH, SCREEN_HEIGHT,
	    SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		fprintf(stderr, "could not create window: %s\n", SDL_GetError());
		return 1;
	}
	screenSurface = SDL_GetWindowSurface(window);

	init_demo();

	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(window);
	SDL_Event event;
	bool	  quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			/*
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			if (e.type == SDL_KEYDOWN)
			{
				quit = true;
			}
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				quit = true;
			}
			*/

			switch (event.type)
			{
			case (SDL_QUIT):
			{ // In case of exit
				quit = SDL_TRUE;
				break;
			}

			case (SDL_DROPFILE):
			{
				// In case if dropped file
				dropped_filedir = event.drop.file;
				// Shows directory of dropped file
				SDL_ShowSimpleMessageBox(
				    SDL_MESSAGEBOX_INFORMATION,
				    "File dropped on window",
				    dropped_filedir,
				    window);
				SDL_free(dropped_filedir); // Free dropped_filedir memory
				break;
			}
			}
		}
	}
	SDL_Delay(2000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
