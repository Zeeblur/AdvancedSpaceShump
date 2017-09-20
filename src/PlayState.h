#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
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
	Texture enSprite;
    Texture bulletSp;

	GameActor* player;
	//SpawnerAI spawner;
	std::vector<GameActor*> enemies;

	Clock timer;
	float time = 0.f;
	float maxTime = 400;

    float ratio;
	bool first = true;
    bool paused = false;

	void Spawn();
	float spawnHeight;
public:

	PlayState(StateManager &val, View &view, RenderWindow &win);
	~PlayState() {}
	//int LoadGamefiles();
	void Update(const float& dt);
	void Init();
};