#include "PlayState.h"
//#include "SpawnerAI.h"

using namespace std;

PlayState::PlayState(StateManager &val, View &view, RenderWindow &win)
{
	mainView = &view;
	mainWindow = &win;
	parent = &val;
	Init();
	spawnHeight = mainView->getSize().y - (100.f/ratio);
}

void PlayState::Update(const float& dt)
{
    if(paused)
    {
        auto p = this->GameState::playerScore;
        return;
    }

    // check for collisions
    for(GameActor* ga : enemies)
    {
        // if not visible- don't check for objects.
        if (!ga->renderObject->visible)
            continue;

        if (player->renderObject->CheckCollision(ga->renderObject))
        {
            std::cout << "ouch" << endl;
            player->die();

            paused = true;
            return;
        }

        for(auto b : player->bullets)
        {
           if (b->visible && ga->renderObject->CheckCollision(b))
           {
               std::cout << "i am ded" << std::endl;
               ga->die();

           }
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
	if (time >= 4)// maxTime)
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
    bulletSp.loadFromFile("res/img/bread.png");

    std::vector<GameObject*> bulletList;
    for(unsigned int i =0; i < 5; ++i)
    {
        auto s = CreateSprite(bulletSp, Vector2f(5.0f/ratio, 5.0f/ratio), Vector2f(mainView->getSize() / 2.0f));
        bulletList.push_back(s);
        stateObjects.push_back(s);

    }

	SpriteObject* ps = CreateSprite(playerSprite, Vector2f(5.0f/ratio, 5.0f/ratio), Vector2f(mainView->getSize() / 2.0f));
	player = new GameActor("steve", *ps, bulletList);
	stateObjects.push_back(ps);

	enSprite.loadFromFile("res/img/swan.png");
	timer.restart();


	powerUpSprite.loadFromFile("res/img/Powerup.png");
	// create powerup
	auto powup = CreateSprite(powerUpSprite, Vector2f(5.0f / ratio, 5.0f / ratio), Vector2f(mainView->getSize() / 2.0f));
	powerUp = new GameActor(*powup);
	stateObjects.push_back(powup);

}

void PlayState::Spawn()
{
	float x = 200.0f/ratio;
    x *= rand() % 12;


	SpriteObject* es = CreateSprite(enSprite, Vector2f(5.0f/ratio, 5.0f/ratio), Vector2f(x,spawnHeight));
	GameActor* enemy = new GameActor(*es);
	stateObjects.push_back(es);
	enemies.push_back(enemy);
}
