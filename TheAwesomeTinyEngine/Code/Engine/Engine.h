#pragma once
#include <SDL.h>
#include "Key.h"

/*CORE ENGINE*/
void InitializeEngine();

void UpdateEngine();

void ClearEngine();

void CloseEngine();

void DestroyEngine();

bool IsEngineOpen();

/*RENDERING HELPER METHODS*/

void RenderSquare(float posX, float posY, int width, int height);

/*HELPER METHODS*/

bool EngineGetKey(Key key);

bool EngineGetKeyDown(Key key);

float EngineDeltaTime();

SDL_Renderer* EngineGetRenderer();

/*COLOUR*/
void EngineSetColor(int r, int g, int b, int a);

void EngineLoadTexture(float posX, float posY, int height, int width, const char* _path);