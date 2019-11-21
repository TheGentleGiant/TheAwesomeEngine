#include "Bullet.h"
#include "GameWorld.h"
#include <iostream>
#include "Engine/Type.h"
#include "Enemy.h"

void Bullet::Update()
{
	_position.x += 20.f * direction.x;
	_position.y += 20.f * direction.y;
	
	_collider.x = _position.x;
	_collider.y = _position.y;
	_collider.w = BULLET_WIDTH;
	_collider.h = BULLET_HEIGHT;

	lifetime -= EngineDeltaTime();
	if (lifetime <= 0)
	{
		_gameWorld->DestroyGameObject(this);
		return;
	}

	
	for (int i = 0; i < MAX_GAME_OBJECTS; i++)
	{
		GameObject* GOPtr = _gameWorld->Objects[i];

		if (GOPtr == nullptr || GOPtr == this)
		{
			continue;
		}
		if (IsA<Enemy>(GOPtr)) {
			if (CheckCollision(_collider, GOPtr->_collider)) {
				_gameWorld->DestroyGameObject(GOPtr);
				_gameWorld->DestroyGameObject(this);
				return;
			}
		}
	}

	printf("collider xpos: %d \n", _collider.x);
}

void Bullet::Render()
{
	EngineSetColor(0, 255, 0, 255);
	RenderSquare(_position.x, _position.y, BULLET_WIDTH, BULLET_HEIGHT);
}

bool Bullet::CheckCollision(SDL_Rect a, SDL_Rect b)
{
	int leftA, leftB;
	int rightA, rightB;
	int bottomA, bottomB;
	int topA, topB;

	//calculate a
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;
	//calculate b
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if (bottomA <= topB)
	{
		return false;
	}
	if (topA >= bottomB)
	{
		return false;
	}
	if (rightA <= leftB)
	{
		return false;
	}
	if (leftA >= rightB)
	{
		return false;
	}
	return true;
}

