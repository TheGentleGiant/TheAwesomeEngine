#pragma once
#define MAX_GAME_OBJECTS 250

class GameObject;

class GameWorld {
public:
	GameWorld();
	~GameWorld();

	//create an array of game object.
	//this will allow us to pool our entire game 
	//this will make it easier to keep track of all our objects in the game
	GameObject* Objects[MAX_GAME_OBJECTS];
	
	void Update();
	void Render();

	void SpawnGameObject(GameObject* _gameObject);
	void DestroyGameObject(GameObject* _gameObject);

private:

};