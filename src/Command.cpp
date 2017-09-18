#include "Command.h"
#include "GameActor.h"

void FireCommand::execute(GameActor & actor)
{
	actor.FireGun();
}

MoveCommand::MoveCommand(sf::Vector2f& direction) : dir(direction)
{

}


void MoveCommand::execute(GameActor& actor)
{
	actor.Move(dir);
}
