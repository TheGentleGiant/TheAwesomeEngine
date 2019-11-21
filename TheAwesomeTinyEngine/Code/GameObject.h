#pragma once
#include "Engine/Engine.h"
#include "MathHelpers/Vector.h"

class GameWorld;
class TextureManager;

class GameObject {
public:
	SDL_Rect _collider;
	Vector _position;
	GameObject(Vector position);

	virtual void Update()= 0;
	virtual void Render();
	//virtual bool CheckCollision(SDL_Rect a, SDL_Rect b);

	GameWorld* _gameWorld;

};