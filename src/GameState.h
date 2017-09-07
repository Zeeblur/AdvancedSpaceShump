#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

using namespace sf;

// GameState stores the state of the game/menu screens windows etc.

// possible enum for state
enum gameState
{
	START,
	PLAY,
	PAUSE,
	OPTIONS
};

class GameState
{
private:

	// reference to the window
	sf::RenderWindow &mainWindow;

	gameState currentState;
	Texture texture;
	Sprite sprite;
	bool previousKeyState;


	

public:

	GameState(sf::RenderWindow &wind);

	int LoadGamefiles();
	void Update();
	void Render();

};