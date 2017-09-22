#include "PlayState.h"
#include "StateManager.h"

using namespace std;



PlayState::PlayState(StateManager &val, View &view, RenderWindow &win)
{
	mainView = &view;
	mainWindow = &win;
	parent = &val;
	Init();
	spawnHeight = mainView->getSize().y - (100.f/ratio);
}

void PlayState::AddScore(int val)
{
	playerScore += val;
}

void PlayState::Update(const float& dt)
{
    if(paused)
    {
        auto p = this->GameState::playerScore;
        return;
    }

	parent->currentScore = playerScore;

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

			if (player->updoot > 0)
			{
				ga->die();
			}
			else
			{
				parent->EndGame();
			}

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

	if (powerUp->renderObject->visible)
	{
		if (player->renderObject->CheckCollision(powerUp->renderObject))
		{
			player->Updoot(true);
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
	if (first)
	{
		timer.restart();
		totalTime.restart();
		first = false;
	}

	time += timer.getElapsedTime().asSeconds();
	//cout << time << endl;

	// once time elapsed spawn enemy
	if (time >= maxTime)
	{
		Spawn();

		timer.restart();
		time = 0;
	}

	int t = totalTime.getElapsedTime().asSeconds();
	
	if (t % 10 == 0)
	{
		SpawnPower();
	}

	if (powerUp->renderObject->visible)
	{
		auto direction = Vector2f(0.f, -1.0f);
		powerUp->Move(direction);
	}

	// increase diff
	if (playerScore > difficulty)
	{
		cout << "difficulty increase" << endl;
		percentageOfBadness += 1.0f;
		maxTime *= percentageOfBadness;
		difficulty += 5;
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

	playerSprite.loadFromFile("res/img/hero.png");
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

	enemy2.loadFromFile("res/img/bigSwan.png");

	powerUpSprite.loadFromFile("res/img/Powerup.png");
	// create powerup
	auto powup = CreateSprite(powerUpSprite, Vector2f(5.0f / ratio, 5.0f / ratio), Vector2f(0.f, 0.f));
	powerUp = new GameActor(*powup);
	powup->visible = false;
	stateObjects.push_back(powup);


	player->play = playerSprite;
	player->pow = powerUpSprite;

}

void PlayState::Spawn()
{
	float x = 200.0f/ratio;
    x *= rand() % 12;

	auto choice = rand() % 11;

	if (choice > percentageOfBadness)
	{
		SpriteObject* es = CreateSprite(enemy2, Vector2f(5.0f / ratio, 5.0f / ratio), Vector2f(x, spawnHeight));
		GameActor* enemy = new GameActor(*es);
		stateObjects.push_back(es);
		enemies.push_back(enemy);
	}
	
	x *= rand() % 12;

	SpriteObject* es = CreateSprite(enSprite, Vector2f(5.0f/ratio, 5.0f/ratio), Vector2f(x,spawnHeight));
	GameActor* enemy = new GameActor(*es);
	stateObjects.push_back(es);
	enemies.push_back(enemy);


}

void PlayState::SpawnPower()
{
	if (powerUp->renderObject->visible)
		return;

	float x = 200.0f / ratio;
	x *= rand() % 12;

	powerUp->renderObject->visible = true;
	powerUp->renderObject->setPosition(Vector2f(x, spawnHeight));
}
