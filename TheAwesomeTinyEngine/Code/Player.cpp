#include "Player.h"
#include "GameWorld.h"
#include "Bullet.h"

#include <iostream>

Player::Player(Vector _position) : GameObject(_position) {}

Player::Player(Vector _position, const char* path) :
	GameObject(_position), path(path){}

void Player::Update()
{
	float _directionX = 0.0f;
	float _directionY = 0.0f;

	if (EngineGetKey(Key::W))
	{
		_position.y -= 5.f;
		_directionY--;
	}
	if (EngineGetKey(Key::S)) {
		
		_position.y += 5.f;
		_directionY++;
	}
	if (EngineGetKey(Key::A)) {

		_position.x -= 5.f;
		_directionX--;
	}
	if (EngineGetKey(Key::D)) {

		_position.x+= 5.f;
		_directionX++;
	}
	if (_directionX == 0 && _directionY == 0) {
		_directionX = 1;
	}
	if (EngineGetKeyDown(Key::Space))
	{
		_gameWorld->SpawnGameObject(new Bullet(Vector(
			_position.x + 64.f * _directionX , _position.y + 32.f * _directionY), Vector(_directionX,_directionY)));
	}
	//printf("direnction X: %f , direnction Y: %f \n", _directionX, _directionY);
}



void Player::Render()
{
	if(path){
		EngineLoadTexture(_position.x, _position.y, 64, 64, path);
	}
	else
	{
		EngineSetColor(150, 12, 12, 255);
		RenderSquare(_position.x, _position.y, 64, 64);
	}
}


