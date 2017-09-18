#include "InputHandler.h"
#include "Command.h"

InputHandler::InputHandler()
{
	MapButtons();
}

Command* InputHandler::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) return buttonShoot_;
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
}
