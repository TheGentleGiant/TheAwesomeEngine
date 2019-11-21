#include "GameObject.h"

GameObject::GameObject(Vector position) : _position(position)
{
}

void GameObject::Render()
{
	RenderSquare(_position.x,_position.y, 64, 64);
}

/*bool GameObject::CheckCollision(SDL_Rect a, SDL_Rect b)
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
}*/

