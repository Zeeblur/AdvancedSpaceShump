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
	Texture powerUpSprite;
	Texture enSprite;
	Texture enemy2;
    Texture bulletSp;

	GameActor* player;
	GameActor* powerUp;
	//SpawnerAI spawner;
	std::vector<GameActor*> enemies;

	Clock timer;
	float time = 0.f;
	float maxTime = 10;

	Clock totalTime;

    float ratio;
	bool first = true;
    bool paused = false;

	void Spawn();
	void SpawnPower();
	float spawnHeight;

	int difficulty = 5;
	float percentageOfBadness = 1.0f;

	sf::SoundBuffer quackBuf;
	sf::Sound quack;

public:
    int playerScore = 0;

	PlayState(StateManager &val, View &view, RenderWindow &win);
	~PlayState() {}
	//int LoadGamefiles();
	void Update(const float& dt);
	void Init();

	void AddScore(int val);
};