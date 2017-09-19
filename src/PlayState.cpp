#include "PlayState.h"
//#include "SpawnerAI.h"

using namespace std;

PlayState::PlayState(StateManager &val, View &view, RenderWindow &win)
{
	mainView = &view;
	mainWindow = &win;
	parent = &val;
	Init();
	spawnHeight = mainView->getSize().y - 100.f;
}

void PlayState::Update(const float& dt)
{

    // check for collisions
    for(GameActor* ga : enemies)
    {
        if (player->renderObject->CheckCollision(ga->renderObject))
        {
            std::cout << "ouch" << endl;
        }

    }


    // update movements
	player->Update(dt);

	// move and update enemies
	for (GameActor* ga : enemies)
	{
		auto direction = Vector2f(0.f, -1.0f);
		ga->Move(direction);
	}

	// update everysprite
	for (GameObject* go : stateObjects)
	{
		go->Update(dt);
	}


	// timer for spawning enemies
	if (first) timer.restart(); first = false;

	time += timer.getElapsedTime().asSeconds();
	//cout << time << endl;

	// once time elapsed spawn enemy
	if (time >= maxTime)
	{

		Spawn();

		timer.restart();
		time = 0;

	}

}

void PlayState::Init()
{

    ratio = (3860/mainWindow->getSize().x);

	backgroundTexture.loadFromFile("res/img/play.png");
	
	Vector2f bkgScale = Vector2f(mainView->getSize().x / backgroundTexture.getSize().x,
								 mainView->getSize().y / backgroundTexture.getSize().y);

	stateObjects.push_back(CreateSprite(backgroundTexture , bkgScale));

	// create player

	playerSprite.loadFromFile("res/img/swan.png");

	SpriteObject* ps = CreateSprite(playerSprite, Vector2f(5.0f/ratio, 5.0f/ratio), Vector2f(mainView->getSize() / 2.0f));
	player = new GameActor("steve", *ps);
	stateObjects.push_back(ps);

	enSprite.loadFromFile("res/img/swan.png");
	timer.restart();
}

void PlayState::Spawn()
{
	float x = 200.0f;


	SpriteObject* es = CreateSprite(enSprite, Vector2f(5.0f/ratio, 5.0f/ratio), Vector2f(x,spawnHeight));
	GameActor* enemy = new GameActor("bob", *es);
	stateObjects.push_back(es);
	enemies.push_back(enemy);
}
