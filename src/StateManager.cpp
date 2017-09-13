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
	states[stateType::START] = new StartState(mainView.getSize());// (const View &view);

	states[stateType::PLAY] = new PlayState();

	// set initial state to start state
	currentState = START;
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