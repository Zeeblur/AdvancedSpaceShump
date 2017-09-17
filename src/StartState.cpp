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
	// load font
	titleFont.loadFromFile("res/fonts/ka1.ttf");
	mainFont = &titleFont;

	texture.loadFromFile("res/img/testbkg.jpg");
	stateObjects.push_back(CreateSprite(texture));

	// create title buttons
	stateObjects.push_back(CreateText("Swan Fighter 2000", Vector2f(0.f, -900.f)));


	InteractiveObject* buttonPlay = new InteractiveObject(*this, CreateText("Play"));
	buttonPlay->buttonValue = utils::stateType::PLAY;
	stateObjects.push_back(buttonPlay);

	InteractiveObject* buttonOptions = new InteractiveObject(*this, CreateText("Options", Vector2f(0.f, 350.f)));
	buttonOptions->buttonValue = utils::stateType::OPTIONS;
	stateObjects.push_back(buttonOptions);

	InteractiveObject* buttonQuit = new InteractiveObject(*this, CreateText("Quit", Vector2f(0.f, 900.f)));
	buttonQuit->buttonValue = utils::stateType::QUIT;
	stateObjects.push_back(buttonQuit);
}

void StartState::Update()
{
	for (GameObject* go : stateObjects)
	{
		go->Update();
	}
}