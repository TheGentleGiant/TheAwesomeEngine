#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy(Vector _position, float walkSpeed) :
	GameObject(_position), WalkSpeed(walkSpeed)
{
	WalkSpeed = (rand() % 100);
}

Enemy::Enemy(Vector _position, float walkSpeed, const char* path) :
	GameObject(_position), WalkSpeed(walkSpeed), _path(path) {
	WalkSpeed = (rand() % 100);
}

void Enemy::Update()
{
	_collider.x = _position.x;
	_collider.y = _position.y;
	_collider.w = 64;
	_collider.h = 64;

	_position.x += 5.f;

	if (_position.x > 800)
		_position.x = 0;
}

void Enemy::Render()
{
	if (_path) {
		EngineLoadTexture(_position.x, _position.y, 64, 64, _path);
	}
	else
	{
		EngineSetColor(0, 255, 0, 255);
		RenderSquare(_position.x, _position.y, 64, 64);
	}
}

Vector SetNewTarget() {

	return Vector(0, 0);
}

