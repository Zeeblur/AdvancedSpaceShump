#include "StartState.h"

using namespace std;

StartState::StartState(const Vector2f &view) : viewSize(view)
{
	Init();
}

StartState::~StartState()
{

}

void StartState::Init()
{
	// load font
	titleFont.loadFromFile("res/fonts/ka1.ttf");

	texture.loadFromFile("res/img/testbkg.jpg");
	stateObjects.push_back(CreateSprite());

	// create title buttons
	stateObjects.push_back(CreateText("Swan Fighter 2000", Vector2f(0.f, -100.f)));
	stateObjects.push_back(CreateText("Play"));
	stateObjects.push_back(CreateText("Options", Vector2f(0.f, 50.f)));
	stateObjects.push_back(CreateText("Quit", Vector2f(0.f, 100.f)));

	stateObjects.push_back(new InteractiveObject(CreateText("Ree")));
	//AddObject(&CreateText("hello"));
}

TextObject* StartState::CreateText(String s, Vector2f displacement)
{
	Text testText;

	testText.setString(s);
	testText.setFont(titleFont);
	testText.setCharacterSize(20);
	testText.setStyle(Text::Bold);
	testText.setColor(Color::White);

	// set origin to middle of object
	testText.setOrigin(Vector2f(testText.getLocalBounds().width / 2.f, testText.getLocalBounds().height / 2.f));

	//// set pos to middle of screen then add displacement 

	testText.setPosition((viewSize/2.0f)+ displacement);

	return new TextObject(testText);
}

SpriteObject* StartState::CreateSprite()
{
	Sprite sprite;
	//boundingBox.left = backshape.getPosition().x;
	//boundingBox.top = backshape.getPosition().y;

	// set image sprite
	sprite.setTexture(texture);
	sprite.setScale(Vector2f(2.f, 2.f));
	sprite.setOrigin(Vector2f(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f));
	sprite.setPosition(viewSize/2.0f);

	return new SpriteObject(sprite);
}

void StartState::Update()
{
	for (GameObject* go : stateObjects)
	{
		go->Update();
	}
}

//
//void StartState::UpdateViewSize(const Vector2f &size)
//{
//	viewSize = size;
//}


//
//void PlayState::Update()
//{
//	// need to change keyboard to inpu/events to check with window focus.
//	if (Keyboard::isKeyPressed(Keyboard::B) && !previousKeyState)
//	{
//		std::cout << "big window" << std::endl;
//		VideoMode dmodes =  VideoMode::getDesktopMode();
//	}
//
//	// used to control only 1 key press
//	previousKeyState = Keyboard::isKeyPressed(Keyboard::B);
//}
//
//void PlayState::Render()
//{
//	// draw ship
//	mainWindow.draw(sprite);
//	mainWindow.draw(testText);
//}
//
//int PlayState::LoadGamefiles()
//{
//	try {
//		if (!texture.loadFromFile("res/img/spaceship1.png")) {
//			throw std::invalid_argument("Loading error!");
//		}
//	}
//	catch (const std::exception &) {
//		std::cerr << "Load error" << std::endl;
//		return 1;
//
//	}
//
//	// load font
//	mainFont.loadFromFile("res/fonts/ka1.ttf");
//
//	testText.setString("Advanced Space Shump");
//	testText.setFont(mainFont);
//	testText.setCharacterSize(50);
//	testText.setStyle(Text::Bold);
//	testText.setColor(Color::White);
//
//	// set origin to middle of object
//	testText.setOrigin(Vector2f(testText.getLocalBounds().width/2, testText.getLocalBounds().height/2));
//
//	// set pos to middle of screen 
//	testText.setPosition(mainView.getSize());
//
//	
//

//	return 0;
//}
