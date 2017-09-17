#include "GameState.h"
#include "GameObject.h"
#include "StateManager.h"

void GameState::Render(RenderWindow &window) const
{
	//std::cout << "render gs.cpp" << std::endl;
	// for each game object. Render
	for(GameObject* go : stateObjects)
	{
		go->Render(window);
	}
}

void GameState::AddObject(const GameObject &go)
{
	//stateObjects.push_back(&go);
}

void GameState::Click(utils::stateType &val) 
{
	parent->Click(val);
}