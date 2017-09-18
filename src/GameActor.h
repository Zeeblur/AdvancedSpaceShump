#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "InputHandler.h"

// game actor
class GameObject;
class Command;

class GameActor
{
private:
	GameObject* renderObject;
	InputHandler inputHandler;


public:
	GameActor(std::string val, GameObject& obj);
	~GameActor();

	void Update();
	void FireGun();
};
