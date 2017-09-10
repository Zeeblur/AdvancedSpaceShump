#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "GameState.h"

using namespace sf;

class StartState : public GameState
{
private:
	Text hudText;
	
public:
	StartState();
	~StartState();
	
	void Update();
};