#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

// game actor
class GameObject;

class GameActor
{
private:
	GameObject* renderObject;

public:
	GameActor(std::string val, GameObject& obj);
	~GameActor();

	void Update();
};
