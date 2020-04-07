#include <SDL.h>
#include <iostream>
#include "Engine/Engine.h"

SDL_Renderer* _renderer;

int main(int argc, char* argv[])
{
	_renderer = EngineGetRenderer();
	int FPS = 60;
	int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	int frame = 0;
	InitializeEngine();

	//SDL_Event e;
	while (IsEngineOpen())
	{


		while (IsEngineOpen())
		{
			ClearEngine();
			frameStart = SDL_GetTicks();
			/***GAME LOOP***/

			/*FRAME STABILIZER*/
			frameTime = SDL_GetTicks() - frameStart;
			if (frameDelay > frameTime) {
				SDL_Delay(frameDelay - frameTime);
			}
			/**********/
			UpdateEngine();
		}
	}
	
	DestroyEngine();
	SDL_Quit();
	return 0;
}

