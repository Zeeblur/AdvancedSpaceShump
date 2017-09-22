#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "GameState.h"
#include "GameObject.h"

using namespace sf;

class PauseState : public GameState
{
private:
	Texture texture;

	void Init();

	Font titleFont;


    bool highscores;


public:
	PauseState(StateManager &val, View &view, RenderWindow &win, bool highscore = false);
	~PauseState();

	TextObject* currentScore;
	//void UpdateViewSize(const Vector2f &size);
	
	void Update(const float& dt);
	void Recall();

	bool notEnd = true;
};