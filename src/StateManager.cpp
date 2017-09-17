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
	states[(int)stateType::START] = new StartState(mainView.getSize());// (const View &view);

	states[(int)stateType::PLAY] = new PlayState();

	// set initial state to start state
	currentState = (int)stateType::START;
}

void StateManager::Update()
{
	states[currentState]->Update();
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

void StateManager::Click(const InteractiveObject &obj)
{
	// menu click has happened.

	////switch state
	//switch (switch_on)
	//{
	//default:
	//	break;
	//}
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