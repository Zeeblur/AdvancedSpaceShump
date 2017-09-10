#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

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




	Texture texture;
	Sprite sprite;
	bool previousKeyState;

	sf::Font mainFont;

	Text testText;


public:
	StateManager(sf::RenderWindow &wind);


	int LoadGamefiles();
	void Update();
	void Render();

};