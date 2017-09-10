#include "GameState.h"

void GameState::Render(RenderWindow &window) const
{
	// for each game object. Render
	for(GameObject *go : stateObjects)
	{
		go->Render(window);
	}
}

void GameState::AddObject(GameObject *go)
{
	stateObjects.push_back(go);
}