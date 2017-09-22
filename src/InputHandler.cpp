#include "InputHandler.h"
#include "Command.h"

InputHandler::InputHandler()
{
	MapButtons();
}

std::vector<Command*> InputHandler::HandleInput()
{
	std::vector<Command*> commands;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) commands.push_back(buttonShoot_);

	if (sf::Joystick::isConnected(0))
	{

		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);


		float episilon = 5;

		if (x < 0 - episilon)
		{
			commands.push_back(buttonLeft_);
		}
		else if (x > 0 + episilon)
		{
			commands.push_back(buttonRight_);
		}

		if (y < 0 - episilon)
		{
			commands.push_back(buttonUp_);
		}
		else if (y > 0 + episilon)
		{
			commands.push_back(buttonDown_);
		}


		if (sf::Joystick::isButtonPressed(0, 0)) commands.push_back(buttonShoot_);

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) commands.push_back(buttonUp_);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) commands.push_back(buttonDown_);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) commands.push_back(buttonLeft_);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) commands.push_back(buttonRight_);

	return commands;
}

void InputHandler::MapButtons()
{

	buttonShoot_ = new FireCommand;
	auto down = sf::Vector2f(0.f, 1.f);
	buttonDown_ = new MoveCommand(down);
    auto left = sf::Vector2f(-1.f, 0.f);
	buttonLeft_ = new MoveCommand(left);
    auto right = sf::Vector2f(1.f, 0.f);
	buttonRight_ = new MoveCommand(right);
    auto up = sf::Vector2f(0.f, -1.f);
	buttonUp_ = new MoveCommand(up);
}
