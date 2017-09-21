#include "StateManager.h"
#include "utils.h"


using namespace std;
using namespace utils;

StateManager::StateManager(sf::RenderWindow &wind) : mainWindow(wind)
{
	// get view for the window
	mainView = wind.getView();

	// initialise the states
	InitialiseStates();
}

void StateManager::InitialiseStates()
{
	states[(int)stateType::START] = new StartState(*this, mainView, mainWindow);

	states[(int)stateType::PLAY] = new PlayState(*this, mainView, mainWindow);

	states[(int)stateType::OPTIONS] = new OptionsState(*this, mainView, mainWindow);

	// set initial state to start state
	currentState = (int)stateType::START;
}

void StateManager::Update(const float& dt)
{
	states[currentState]->Update(dt);
}

void StateManager::Render()
{
	states[currentState]->Render(mainWindow);
}

// return 1 if loading failed.
int StateManager::LoadGamefiles()
{
	// load assets for states, if load fails return 1

	// continue game
	return 0;
}

void StateManager::Click(stateType &choice)
{
	// menu click has happened.
	stateType newChoice = choice;

	if (choice == stateType::QUIT)
	{
		mainWindow.close();
		return;
	}

	//switch state
	currentState = (int)newChoice;
}

void StateManager::AddModes(std::vector<VideoMode> vid)
{
	for (auto v : vid)
	{
		if (v.width == 3840 && v.height == 2160) vidModes.push_back(v);
		if (v.width == 1920 && v.height == 1080) vidModes.push_back(v);
        if (v.width == 1366 && v.height == 768) vidModes.push_back(v);
		if (v.width == 1280 && v.height == 720) vidModes.push_back(v);
		if (v.width == 800 && v.height == 600) vidModes.push_back(v);
	}

    auto p = dynamic_cast<OptionsState*>(states[(int)stateType::OPTIONS]);
    p->SetModes(vidModes);

}

void StateManager::Click(int &val)
{

	ChangeWindow(val);
}

void StateManager::ChangeWindow(int &val)
{
    //fullscreen, windowed, borderless window
//if -2 then change window mode
	//otherwise pick from resolutions

	if (currentMode >= 0)
		currentMode = val;

	if (currentMode == -2)
	{
		if (currentStyle == Style::Fullscreen)
			currentStyle = Style::Default;

		if (currentStyle == Style::Default) {
			currentStyle = Style::None;
			currentMode = 0;
		}

		if (currentStyle == Style::None) {
			currentStyle = Style::Fullscreen;
			currentMode = 0;
		}
	}

	if (currentMode != 0)
		currentStyle = Style::Default;

	mainWindow.create(vidModes[currentMode], "Swan Fighter 2000", currentStyle);

	auto state = dynamic_cast<OptionsState*>(states[(int)stateType::OPTIONS]);


	switch(currentStyle)
	{
		case Style::Fullscreen:
			state->windowstyleButton->text->text.setString("Windowed");
			break;
		case Style::Default:
			state->windowstyleButton->text->text.setString("None");
			break;
		case Style::None:
			state->windowstyleButton->text->text.setString("Fullscreen");
			break;
	}

}

//deconstrutor
StateManager::~StateManager()
{
	// clear memory for state pointers
	for (unsigned int i = 0; i < states.size(); ++i)
	{
		if (states[i])
		{
			delete states[i];
		}
	}

	states.empty();
}