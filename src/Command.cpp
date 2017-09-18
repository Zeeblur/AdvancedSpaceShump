#include "Command.h"
#include "GameActor.h"

void FireCommand::execute(GameActor & actor)
{
	actor.FireGun();
}
