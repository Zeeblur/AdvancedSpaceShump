#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "GameState.h"
#include "GameObject.h"
#include "GameActor.h"
#include "SpawnerAI.h"


using namespace sf;

class PlayState : public GameState
{
private:
	Text hudText;
	Texture backgroundTexture;

	Texture playerSprite;
	Texture enSprite;

	GameActor* player;
	//SpawnerAI spawner;
	std::vector<GameActor*> enemies;

	Clock timer;
	float time = 0.f;
	float maxTime = 400;

	bool first = true;

	void Spawn();
	float spawnHeight;
public:

	PlayState(StateManager &val, View &view, RenderWindow &win);
	~PlayState() {}
	//int LoadGamefiles();
	void Update(const float& dt);
	void Init();
};