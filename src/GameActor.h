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
    float coolDown = 20;
    float currTime = 0;
    sf::Clock timer;
    bool canFire = true;
public:
	GameActor(std::string val, GameObject& obj);
	GameActor(std::string val, GameObject& obj, std::vector<GameObject*> bull);
	~GameActor();

	void Update(const float& dt);
	void FireGun();
	void Move(sf::Vector2f& dir);
	void die();
	GameObject* renderObject;
	std::vector<GameObject*> bullets;
};
