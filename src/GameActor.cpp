#include "GameActor.h"
#include "GameObject.h"
#include "Command.h"

GameActor::GameActor(GameObject &obj) : renderObject(&obj)
{
    //std::cout << "Hello I am: " << val << std::endl;

    renderObject->enemy = true;
    endGame = false;

    inputHandler = InputHandler();

}

GameActor::GameActor(std::string val, GameObject &obj, std::vector<GameObject*> bull) : renderObject(&obj), bullets(bull)
{
	std::cout << "Hello I am: " << val << std::endl;

    renderObject->enemy = false;
    endGame = true;

	inputHandler = InputHandler();

    for(auto b : bullets)
    {
        b->visible = false;
    }

	// player sound

	auto a = soundBuffer.loadFromFile("res/sound/thunder.wav");

	fire.setBuffer(soundBuffer);
}

GameActor::~GameActor()
{

}

void GameActor::die()
{	
	if (updoot == 0)
	{
		renderObject->death(endGame);
		return;
	}


	updoot++;

	if (updoot == 4)
	{
		this->Updoot(false);
	}

}

void GameActor::Update(const float& dt)
{

	// command pattern
	std::vector<Command*> commands = inputHandler.HandleInput();

	for (Command* com : commands)
		com->execute(*this);


    if (!canFire) {
        currTime += timer.getElapsedTime().asSeconds();
        //cout << time << endl;
        // once time elapsed spawn enemy
        if (currTime >= coolDown) {
            std::cout << "can fire" << std::endl;
            canFire = true;
        }
    }
}

void GameActor::FireGun()
{
	std::cout << "pew pew" << std::endl;

    if(!canFire)
        return;

    canFire = false;
    timer.restart();
    currTime = 0;

    for(GameObject* bullet : bullets)
    {
        //check if avalible to use then fire.
        if(!bullet->visible)
        {
            auto pos = this->renderObject->getPosition();
            bullet->setPosition(pos);
            bullet->Fire();
			fire.play();
            bullet->visible = true;
            return;
        }
    }

}

void GameActor::Move(sf::Vector2f& dir)
{
	renderObject->addImpulse(dir);
}

void GameActor::Updoot(bool val)
{
	auto ro = dynamic_cast<SpriteObject*>(renderObject);

	if (val)
	{
		ro->sprite.setTexture(pow);
		updoot = 1;
	}
	else
	{
		ro->sprite.setTexture(play);
		updoot = 0;
	}
}