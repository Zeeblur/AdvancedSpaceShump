#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <memory>

#include "GameState.h"
#include "StartState.h"
#include "PlayState.h"
#include "OptionsState.h"
#include "PauseState.h"
#include "utils.h"

using namespace sf;


class StateManager
{
private:

	// reference to the window
	sf::RenderWindow &mainWindow;
	View mainView;

	unsigned int currentState;

	// list of states.
	std::array<GameState*, 5> states = {};

	Texture texture;
	Sprite sprite;
	bool previousKeyState;

	void ChangeWindow(int &val);

	sf::Font mainFont;

	Text testText;

    int currentMode =0;
    int currentStyle = Style::Fullscreen;

	void InitialiseStates();

    void ChangeWindow();


	sf::SoundBuffer soundBuffer;
	sf::Sound hey;

	sf::SoundBuffer soundDeath;
	sf::Sound ded;



public:
	StateManager(sf::RenderWindow &wind);
	~StateManager();

	int LoadGamefiles();
	void Update(const float& dt);
	void Render();

	void Click(utils::stateType &choice);
	void Click(int &i);

	std::vector<VideoMode> vidModes;

	void AddModes(std::vector<VideoMode> vid);

	std::vector<int> scoreValues;
	int currentScore = 0;

	void EndGame();

};