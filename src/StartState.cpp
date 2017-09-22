#include "StartState.h"
#include "utils.h"

using namespace std;
SpriteObject* CreateSprite(const Texture &texture);
TextObject* CreateText(String s, Vector2f displacement = Vector2f(0.f, 0.f));


StartState::StartState(StateManager &val, View &view, RenderWindow &win) 
{
	mainWindow = &win;
	mainView = &view;
	parent = &val;
	Init();

}

StartState::~StartState()
{

}

void StartState::Init()
{
    auto ratio = 3840/mainWindow->getSize().x;
    ratio = ratio*2;

	// set size dependent on window
	defaultTextSize = 100 / ratio;



	// load font
	titleFont.loadFromFile("res/fonts/ka1.ttf");
	mainFont = &titleFont;

	texture.loadFromFile("res/img/title.gif");
	Vector2f bkgScale = Vector2f(mainView->getSize().x / texture.getSize().x,
		mainView->getSize().y / texture.getSize().y);
	stateObjects.push_back(CreateSprite(texture, bkgScale));

	// create title buttons
	stateObjects.push_back(CreateText("Swan Fighter 2000", defaultTextSize, Vector2f(0.f, -900.f/ratio )));


	InteractiveObject* buttonPlay = new InteractiveObject(*this, CreateText("Play", defaultTextSize));
	buttonPlay->buttonValue = utils::stateType::PLAY;
	stateObjects.push_back(buttonPlay);
	buttons.push_back(buttonPlay);

	InteractiveObject* buttonOptions = new InteractiveObject(*this, CreateText("Options", defaultTextSize, Vector2f(0.f, 350.f/ratio)));
	buttonOptions->buttonValue = utils::stateType::OPTIONS;
	stateObjects.push_back(buttonOptions);
	buttons.push_back(buttonOptions);

	InteractiveObject* buttonQuit = new InteractiveObject(*this, CreateText("Quit", defaultTextSize, Vector2f(0.f, 900.f/ratio)));
	buttonQuit->buttonValue = utils::stateType::QUIT;
	stateObjects.push_back(buttonQuit);
	buttons.push_back(buttonQuit);
}

void StartState::Update(const float& dt)
{
	
	if (Joystick::isConnected(0))
	{
		if (Joystick::getAxisPosition(0, Joystick::Axis::PovY) < -10 && !lastPos)
		{
			choice++;
			if (choice >= buttons.size())
			{
				choice = 0;
			}
		}


		for (InteractiveObject* bt : buttons)
		{

			bt->HoverGraphics(false);
		}


		buttons[choice]->HoverGraphics(true);

		lastPos = Joystick::getAxisPosition(0, Joystick::Axis::PovY);
	}

	for (GameObject* go : stateObjects)
	{

		go->Update(dt);
	}
}