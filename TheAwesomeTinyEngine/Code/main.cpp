#include <SDL.h>
#include <iostream>
#include "Engine/Engine.h"
#include "GameObject.h"
#include "GameWorld.h"
#include "Player.h"
#include "Enemy.h"

GameObject *_player;
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
		GameWorld _game;
		_game.SpawnGameObject(new Player(Vector(10.f, 10.f), "Res/Ma_Man.png"));

		_game.SpawnGameObject(new Enemy(Vector( 300.f, 300.f), 10.f, "Res/Ma_Man_Enemy.png" ));

		while (IsEngineOpen())
		{
			ClearEngine();
			frameStart = SDL_GetTicks();
			/***GAME LOOP***/
			_game.Update();
			_game.Render();

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

