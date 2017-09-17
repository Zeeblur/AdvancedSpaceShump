#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "utils.h"

using namespace sf;

// GameObjects Base class and concrete versions.

// fwd declare
class GameState;

struct GameObject
{

	FloatRect boundingBox;

	virtual void Render(RenderWindow &window) {}
	virtual void Update() {}
	virtual ~GameObject() = 0; 

	bool dirty = true;  // flag for updates

	void setPosition(const Vector2f &newPoss);

protected:
	Vector2f position;
	const GameState* _parentState;
};

struct SpriteObject : public GameObject
{
	Sprite sprite;

	//using GameObject::GameObject;

	SpriteObject(const Sprite &spr, const GameState& parent);

	void Render(RenderWindow &window) override;
};


struct TextObject : GameObject
{
	Text text;

	TextObject(const Text &text, const GameState& parent);

	void Render(RenderWindow &window) override;
	void Update() override;
};

struct InteractiveObject : GameObject
{
	utils::stateType buttonValue;
	SpriteObject* sprite;
	TextObject* text;
	TextObject* textShadow = nullptr;

	RectangleShape backshape;
	bool previousMouseState;
	
	InteractiveObject(const GameState& parent, TextObject* textObj = nullptr, SpriteObject* spriteObj = nullptr);

	void Render(RenderWindow &window) override;
	void Update();//(Event& e, RenderWindow& window);
	void HoverGraphics(const bool &val);
	void Click();
};