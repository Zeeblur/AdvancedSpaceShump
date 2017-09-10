#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "GameState.h"

using namespace sf;

class PlayState : public GameState
{
private:
	Text hudText;
	
public:

	PlayState();
	~PlayState() {}
	//int LoadGamefiles();
	void Update();
};