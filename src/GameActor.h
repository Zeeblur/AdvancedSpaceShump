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

	InputHandler inputHandler;


public:
	GameActor(std::string val, GameObject& obj);
	~GameActor();

	void Update(const float& dt);
	void FireGun();
	void Move(sf::Vector2f& dir);
	GameObject* renderObject;
};
