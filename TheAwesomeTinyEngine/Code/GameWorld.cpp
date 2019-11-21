#include "GameWorld.h"
#include "GameObject.h"

GameWorld::GameWorld()
{
	/*inside of the class constructor we also populate the GameObject array
	and set all of the to be a nullptr*/
	for (int i = 0; i < MAX_GAME_OBJECTS; i++)
	{
		Objects[i] = nullptr;
	}
}

GameWorld::~GameWorld()
{
	/*when calling upon the deconstructr we loop again though the list
	and delete the objects created and deallocate the memory previously allocated*/
	for (int i = 0; i < MAX_GAME_OBJECTS; i++)
	{
		if (Objects[i] != nullptr)
		{
			delete Objects[i];
			Objects[i] = nullptr;
		}
	}
}

void GameWorld::Update()
{
	/*loop thorught the object and call their each Update method*/
	for (int i = 0; i < MAX_GAME_OBJECTS; i++)
	{
		if (Objects[i] == nullptr)
		{
			continue;
		}
		Objects[i]->Update();
	}
}



void GameWorld::Render()
{
	/*loop thorught the object and call their each Render method*/
	for (int i = 0; i < MAX_GAME_OBJECTS; i++)
	{
		if (Objects[i] == nullptr)
		{
			continue;
		}
		Objects[i]->Render();
	}
}

void GameWorld::SpawnGameObject(GameObject* _gameObject)
{
	for (int i = 0; i < MAX_GAME_OBJECTS; i++)
	{
		if (Objects[i] == nullptr) {
			Objects[i] = _gameObject;
			break;
		}
	}

	_gameObject->_gameWorld = this;
}

void GameWorld::DestroyGameObject(GameObject* _gameObject)
{
	for (int i = 0; i < MAX_GAME_OBJECTS; i++)
	{
		if (Objects[i] == _gameObject) {
			Objects[i] = nullptr;
			delete _gameObject;
			break;
		}
	}
}
