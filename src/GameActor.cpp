#include "GameActor.h"
#include "GameObject.h"

GameActor::GameActor(std::string val, GameObject &obj) : renderObject(&obj)
{
	std::cout << "Hello I am: " << val << std::endl;
}

GameActor::~GameActor()
{

}

void GameActor::Update()
{
	// simple movement sim
	renderObject->addPos(Vector2f(1.f, 1.f));
}