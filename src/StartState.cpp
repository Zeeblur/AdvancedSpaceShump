#include "StartState.h"

using namespace std;

StartState::StartState()//(const View &viw) : view(viw)
{
	Init();
}

StartState::~StartState()
{

}

void StartState::Init()
{
	titleFont.loadFromFile("res/fonts/ka1.ttf");
	auto a = CreateText("yo suck suck my mem leaks pidgeon");

	stateObjects.push_back(a);

	//stateObjects.push_back(CreateSprite());
	//AddObject(&CreateText("hello"));
}

TextObject* StartState::CreateText(String s)
{
	Text testText;

	testText.setString(s);
	testText.setFont(titleFont);
	testText.setCharacterSize(20);
	testText.setStyle(Text::Bold);
	testText.setColor(Color::Black);

	// set origin to middle of object
	testText.setOrigin(Vector2f(testText.getLocalBounds().width / 2.f, testText.getLocalBounds().height / 2.f));

	//// set pos to middle of screen 

	testText.setPosition(Vector2f(50.f, 50.f));//view->getSize());

	return new TextObject(testText);
}

SpriteObject* StartState::CreateSprite()
{
	Sprite sprite;

	Texture texture;
	texture.loadFromFile("res/img/spaceship1.png");
	// set image sprite
	sprite.setTexture(texture);
	sprite.setScale(Vector2f(20.f, 20.f));
	sprite.setPosition(Vector2f(0.f, 0.f));

	return new SpriteObject(sprite);
}

void StartState::Update()
{
	cout << "update start" << endl;
}



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