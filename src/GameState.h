#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "utils.h"


using namespace sf;

// GameState stores the state of the game/menu screens windows etc.

// forward declare game objects
class GameObject;
class TextObject;
class SpriteObject;
class StateManager;

class GameState
{
protected:
	std::vector<GameObject*> stateObjects;
	View* mainView;

	// state manager reference 
	StateManager* parent;

	// current default
	Font* mainFont;
	float defaultTextSize;

	// creating objects
	TextObject* CreateText(String s, float textSize, Vector2f displacement = Vector2f(0.f, 0.f));
	
	// sprites
	SpriteObject* CreateSprite(const Texture &texture, Vector2f scale = Vector2f(1.0f, 1.0f), Vector2f pos = Vector2f(0.0f, 0.0f), IntRect sourceRect = IntRect());



	virtual void Init() = 0;
public:
	// abstract class deconstruction
	GameState() = default;
	virtual ~GameState() {}

	// update changes per implementation
	virtual void Update(const float& dt) = 0;

	// Render function always the same
	void Render(RenderWindow &window) const;

	void AddObject(const GameObject &go);

	void Click(utils::stateType &val);
    void Click(int &val);

	RenderWindow* mainWindow;

	virtual void AddScore(int val);

	int playerScore = 0;

};

