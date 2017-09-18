#include "InputHandler.h"
#include "Command.h"

InputHandler::InputHandler()
{
	MapButtons();
}

Command* InputHandler::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) return buttonShoot_;

	if (sf::Joystick::isConnected(0))
	{
		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) return buttonUp_;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) return buttonDown_;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) return buttonLeft_;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) return buttonRight_;

	return NULL;
}

void InputHandler::MapButtons()
{
	//// joystick controlls
	//if (sf::Joystick::isConnected(0))
	//{

	//	return;
	//}

	buttonShoot_ = new FireCommand;
	buttonDown_ = new MoveCommand(sf::Vector2f(0.f, 1.f));
	buttonLeft_ = new MoveCommand(sf::Vector2f(-1.f, 0.f));
	buttonRight_ = new MoveCommand(sf::Vector2f(1.f, 0.f));
	buttonUp_ = new MoveCommand(sf::Vector2f(0.f, -1.f));
}
