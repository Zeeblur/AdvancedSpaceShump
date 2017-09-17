#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "GameState.h"
#include "GameObject.h"

using namespace sf;

class StartState : public GameState
{
private:
	Texture texture;

	void Init();

	Font titleFont;

public:
	StartState(StateManager &val, View &view);
	~StartState();


	//void UpdateViewSize(const Vector2f &size);

	
	void Update();
};