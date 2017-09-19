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

void GameActor::Update(const float& dt)
{

	// command pattern
	std::vector<Command*> commands = inputHandler.HandleInput();

	for (Command* com : commands)
		com->execute(*this);
	
}

void GameActor::FireGun()
{
	std::cout << "pew pew" << std::endl;
}

void GameActor::Move(sf::Vector2f& dir)
{
	renderObject->addImpulse(dir);
}