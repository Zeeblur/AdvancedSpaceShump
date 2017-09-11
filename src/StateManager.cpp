#include "StateManager.h"


using namespace std;

StateManager::StateManager(sf::RenderWindow &wind) : mainWindow(wind)
{
	// get view for the window
	mainView = wind.getView();

	// initialise the states
	InitialiseStates();
}

void StateManager::InitialiseStates()
{
	StartState* start = new StartState();
	states[stateType::START] = start;

	PlayState* play = new PlayState();
	states[stateType::PLAY] = play;

	// set initial state to start state
	currentState = start;
}

void StateManager::Update()
{
}

void StateManager::Render()
{
	currentState->Render(mainWindow);
}

// return 1 if loading failed.
int StateManager::LoadGamefiles()
{
	// load assets for states, if load fails return 1

	// continue game
	return 0;
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