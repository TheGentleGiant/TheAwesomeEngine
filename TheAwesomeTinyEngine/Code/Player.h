#pragma once
#include "GameObject.h"

class Player : public GameObject {
public:
	TextureManager* _texture;
	const char* path;
	Player(Vector _position);
	Player(Vector _position, const char* path);
	void Update() override;
	void Render() override;

};