#include "PlayState.h"

using namespace std;

PlayState::PlayState(StateManager &val, View &view, RenderWindow &win)
{
	mainView = &view;
	mainWindow = &win;
	parent = &val;
	Init();
}

void PlayState::Update()
{

}


void PlayState::Init()
{

	backgroundTexture.loadFromFile("res/img/play.png");
	stateObjects.push_back(CreateSprite(backgroundTexture));
}
