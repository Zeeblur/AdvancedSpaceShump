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


	float lastX, lastY;

public:
	std::vector<Command*> HandleInput();
	InputHandler();
	void MapButtons();
};