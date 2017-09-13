#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

using namespace sf;

// GameState stores the state of the game/menu screens windows etc.

// forward declare game objects
class GameObject;

class GameState
{
private:
	//stateType currentState;


protected:
	std::vector<GameObject*> stateObjects;
	View* view;
public:
	// abstract class deconstruction
	GameState() = default;
	virtual ~GameState() {}

	// update changes per implementation
	virtual void Update() = 0;

	// Render function always the same
	void Render(RenderWindow &window) const;

	void AddObject(const GameObject &go);

};

