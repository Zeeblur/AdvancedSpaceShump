#include "PauseState.h"
#include "utils.h"
#include "StateManager.h"

using namespace std;
SpriteObject* CreateSprite(const Texture &texture);
TextObject* CreateText(String s, Vector2f displacement = Vector2f(0.f, 0.f));


PauseState::PauseState(StateManager &val, View &view, RenderWindow &win, bool highscore) : highscores(highscore)
{
	mainWindow = &win;
	mainView = &view;
	parent = &val;
	Init();
}

PauseState::~PauseState()
{

}

void PauseState::Init()
{
    auto ratio = 3840/mainWindow->getSize().x;
    ratio = ratio*2;

	// set size dependent on window
	defaultTextSize = 100 / ratio;

	// load font
	titleFont.loadFromFile("res/fonts/ka1.ttf");
	mainFont = &titleFont;

	texture.loadFromFile("res/img/pause.gif");
	Vector2f bkgScale = Vector2f(mainView->getSize().x / texture.getSize().x,
		mainView->getSize().y / texture.getSize().y);
	stateObjects.push_back(CreateSprite(texture, bkgScale));

    string titleText = "PAUSED";

    if (highscores)
        titleText = "HIGH SCORES";

	// create title buttons
    auto pTxt = (CreateText(titleText, defaultTextSize*2, Vector2f(0.f, -900.f/ratio )));
    pTxt->text.setColor(Color::Black);
    stateObjects.push_back(pTxt);

    if (!highscores)
    {
        currentScore = CreateText("Current Score:", defaultTextSize, Vector2f(0.0f, -650.f / ratio));
        currentScore->text.setColor(Color::Black);
        stateObjects.push_back(currentScore);
    }


    Vector2f increment = Vector2f(0.f,0.f);

   // auto scores = parent.

    // get highscores
    for (auto score : parent->scoreValues)
    {
        auto highscore = CreateText(to_string(score), defaultTextSize, -increment);
		highscore->text.setColor(Color::Black);
        stateObjects.push_back(highscore);

        increment.y +=350/ratio;
    }


}

void PauseState::Update(const float& dt)
{
	currentScore->text.setString("Current Score: " + to_string(parent->currentScore));

	for (GameObject* go : stateObjects)
	{
		go->Update(dt);
	}
}