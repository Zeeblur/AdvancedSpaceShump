#include "StartState.h"
#include "utils.h"

using namespace std;
SpriteObject* CreateSprite(const Texture &texture);
TextObject* CreateText(String s, Vector2f displacement = Vector2f(0.f, 0.f));


StartState::StartState(StateManager &val, View &view) 
{
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
	stateObjects.push_back(CreateText("Swan Fighter 2000", Vector2f(0.f, -100.f)));
	stateObjects.push_back(CreateText("Play"));
	stateObjects.push_back(CreateText("Options", Vector2f(0.f, 50.f)));
	stateObjects.push_back(CreateText("Quit", Vector2f(0.f, 100.f)));

	InteractiveObject* buttonPlay = new InteractiveObject(*this, CreateText("Ree"));
	buttonPlay->buttonValue = utils::stateType::PLAY;
	stateObjects.push_back(buttonPlay);
	//AddObject(&CreateText("hello"));
}

void StartState::Update()
{
	for (GameObject* go : stateObjects)
	{
		go->Update();
	}
}