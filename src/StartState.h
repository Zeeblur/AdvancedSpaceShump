#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "GameState.h"
#include "GameObject.h"


//class InteractiveObject;

using namespace sf;

class StartState : public GameState
{
private:
	Texture texture;

	void Init();

	Font titleFont;

	bool lastPos = false;

public:
	StartState(StateManager &val, View &view, RenderWindow &win);
	~StartState();


	//void UpdateViewSize(const Vector2f &size);

	int choice = 0;
	
	void Update(const float& dt);
};