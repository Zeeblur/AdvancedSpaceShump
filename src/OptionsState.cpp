#include "OptionsState.h"
#include "StateManager.h"

using namespace std;
SpriteObject* CreateSprite(const Texture &texture);
TextObject* CreateText(String s, Vector2f displacement = Vector2f(0.f, 0.f));

OptionsState::OptionsState(StateManager &sm, View &view, RenderWindow &win)
{
    mainWindow = &win;
    mainView = &view;
    parent = &sm;
}

OptionsState::~OptionsState() {}


void OptionsState::Init()
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
    stateObjects.push_back(CreateText("OPTIONS", defaultTextSize, Vector2f(0.f, -900.f/ratio )));

    windowstyleButton = new InteractiveObject(*this, CreateText("Windowed", defaultTextSize, Vector2f(0.f, -650.f/ratio)));
    windowstyleButton->modeVal = -2;
    stateObjects.push_back(windowstyleButton);

    Vector2f increment = Vector2f(0.f,0.f);

    for (unsigned int i = 0; i< resChoices.size(); ++i)
    {
        auto txt = to_string(resChoices[i].width) + " x " + to_string(resChoices[i].height);
        InteractiveObject* button = new InteractiveObject(*this, CreateText(txt, defaultTextSize, increment));
        button->modeVal = i;
        stateObjects.push_back(button);
        increment.y +=350/ratio;
    }

}

void OptionsState::SetModes(std::vector<sf::VideoMode> mod)
{
    resChoices = mod;
    Init();
}

void OptionsState::Update(const float &dt)
{
    for (GameObject* go : stateObjects)
    {
        go->Update(dt);
    }
}