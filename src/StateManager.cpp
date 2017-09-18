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
		return;

	//switch state
	currentState = (int)newChoice;
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