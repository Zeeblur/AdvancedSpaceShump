#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "utils.h"

using namespace sf;

// GameObjects Base class and concrete versions.
class GameState;

struct GameObject
{

	FloatRect boundingBox;

	virtual void Render(RenderWindow &window) {}
	virtual void Update(const float &dt) {}
	virtual ~GameObject() = 0; 

	bool dirty = true;  // flag for updates

	void setPosition(const Vector2f &newPoss);
	void addImpulse(const Vector2f &direction);

protected:
	Vector2f position;
	GameState* _parentState;

	float moveScale = 60.0f;
	bool moveReq = false;

	float maxSpeed = 20.0f * moveScale;

	// player movement
	Vector2f acceleration = Vector2f(0.2f * moveScale, 0.2f * moveScale);
	Vector2f deceleration = Vector2f(0.4f * moveScale, 0.3f * moveScale);
	Vector2f moveSpeed = Vector2f(0.0f, 0.0f);
};

struct SpriteObject : public GameObject
{
	Sprite sprite;

	//using GameObject::GameObject;

	SpriteObject(Sprite &spr, GameState& parent);

	void Render(RenderWindow &window) override;
	void Update(const float& dt);
};


struct TextObject : GameObject
{
	Text text;

	TextObject(const Text &text, GameState& parent);

	void Render(RenderWindow &window) override;
	void Update(const float& dt) override;
};

struct InteractiveObject : GameObject
{
	utils::stateType buttonValue;
	SpriteObject* sprite;
	TextObject* text;
	TextObject* textShadow = nullptr;

	RectangleShape backshape;
	bool previousMouseState;
	
	InteractiveObject(GameState& parent, TextObject* textObj = nullptr, SpriteObject* spriteObj = nullptr);

	void Render(RenderWindow &window) override;
	void Update(const float& dt);
	void HoverGraphics(const bool &val);
	void Click();
};