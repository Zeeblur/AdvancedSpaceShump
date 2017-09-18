#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameActor;

struct Command
{
	virtual ~Command() {}
	virtual void execute(GameActor& actor) = 0;
};

struct FireCommand : public Command
{
	virtual void execute(GameActor& actor);
};