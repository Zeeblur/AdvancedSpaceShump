#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Command;
class FireCommand;

class InputHandler
{
private:
	Command* buttonUp_;
	Command* buttonDown_;
	Command* buttonLeft_;
	Command* buttonRight_;
	Command* buttonShoot_;

public:
	Command* HandleInput();
	InputHandler();
	void MapButtons();
};