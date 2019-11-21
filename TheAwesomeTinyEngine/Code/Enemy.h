#pragma once
#include "GameObject.h"

class Enemy : public GameObject {
public:
	Enemy(Vector _position, float walkSpeed);
	Enemy(Vector _position, float walkSpeed, const char* path);

	const char* _path;

	void Update() override;
	void Render() override;
	float WalkSpeed;

};