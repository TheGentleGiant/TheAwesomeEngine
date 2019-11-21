#pragma once
#include "GameObject.h"

#define BULLET_WIDTH 20
#define BULLET_HEIGHT 20

class Bullet :public GameObject {
	
public:
	Bullet(Vector _position, Vector _direction) :
		GameObject(_position),direction(_direction){}

	void Update()override;
	void Render()override;
	bool CheckCollision(SDL_Rect a, SDL_Rect b);
private:
	Vector direction;
	float lifetime = 5.f;
};