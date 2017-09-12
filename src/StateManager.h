#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <memory>
#include "GameState.h"
#include "StartState.h"
#include "PlayState.h"


using namespace sf;

// GameState stores the state of the game/menu screens windows etc.

// possible enum for state
enum stateType
{
	START,
	PLAY,
	PAUSE,
	OPTIONS
};

class StateManager
{
private:

	// reference to the window
	sf::RenderWindow &mainWindow;
	View mainView;

	stateType currentState;

	// list of states.
	std::array<GameState*, 4> states = {};

	Texture texture;
	Sprite sprite;
	bool previousKeyState;

	sf::Font mainFont;

	Text testText;

	void InitialiseStates();
public:
	StateManager(sf::RenderWindow &wind);
	~StateManager();

	int LoadGamefiles();
	void Update();
	void Render();

};