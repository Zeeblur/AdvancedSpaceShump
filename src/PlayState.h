#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "GameState.h"
#include "GameObject.h"
#include "GameActor.h"


using namespace sf;

class PlayState : public GameState
{
private:
	Text hudText;
	Texture backgroundTexture;

	Texture playerSprite;
	GameActor* player;
public:

	PlayState(StateManager &val, View &view, RenderWindow &win);
	~PlayState() {}
	//int LoadGamefiles();
	void Update(const float& dt);
	void Init();
};