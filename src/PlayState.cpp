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
	player->Update();

	for (GameObject* go : stateObjects)
	{
		go->Update();
	}
}

void PlayState::Init()
{

	backgroundTexture.loadFromFile("res/img/play.png");
	
	Vector2f bkgScale = Vector2f(mainView->getSize().x / backgroundTexture.getSize().x,
								 mainView->getSize().y / backgroundTexture.getSize().y);

	stateObjects.push_back(CreateSprite(backgroundTexture , bkgScale));

	// create player

	playerSprite.loadFromFile("res/img/spaceship1.png");

	SpriteObject* ps = CreateSprite(playerSprite, Vector2f(5.0f, 5.0f));
	player = new GameActor("steve", *ps);
	stateObjects.push_back(ps);
}
