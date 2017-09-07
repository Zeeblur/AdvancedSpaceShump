#include "GameState.h"


GameState::GameState(sf::RenderWindow &wind) : mainWindow(wind)
{
}

void GameState::Update()
{
	// need to change keyboard to inpu/events to check with window focus.
	if (Keyboard::isKeyPressed(Keyboard::B) && !previousKeyState)
	{
		std::cerr << "big window" << std::endl;

	}

	// used to control only 1 key press
	previousKeyState = Keyboard::isKeyPressed(Keyboard::B);
}

void GameState::Render()
{
	// draw ship
	mainWindow.draw(sprite);
}

int GameState::LoadGamefiles()
{
	try {
		if (!texture.loadFromFile("res/img/spaceship1.png")) {
			throw std::invalid_argument("Loading error!");
		}
	}
	catch (const std::exception &) {
		std::cerr << "Load error" << std::endl;
		return 1;

	}

	// set image sprite
	sprite.setTexture(texture);
	sprite.setScale(Vector2f(2.f, 2.f));

	return 0;
}