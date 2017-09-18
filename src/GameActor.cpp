#include "GameActor.h"
#include "GameObject.h"
#include "Command.h"

GameActor::GameActor(std::string val, GameObject &obj) : renderObject(&obj)
{
	std::cout << "Hello I am: " << val << std::endl;

	inputHandler = InputHandler();
}

GameActor::~GameActor()
{

}

void GameActor::Update()
{
	// simple movement sim
	//renderObject->addPos(Vector2f(1.f, 1.f));
	Command* command = inputHandler.HandleInput();

	if (command)
	{
		command->execute(*this);
	}
	
}

void GameActor::FireGun()
{
	std::cout << "pew pew" << std::endl;
}