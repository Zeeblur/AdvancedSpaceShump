#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

using namespace sf;

// GameObjects Base class and concrete versions.

struct GameObject
{
	FloatRect boundingBox;

	virtual void Render(RenderWindow &window) {}
	virtual void Update() {}
	virtual ~GameObject() = 0; 

	bool dirty = true;  // flag for updates

	void setPosition(const Vector2f &newPos);

protected:
	Vector2f position;
};

struct SpriteObject : public GameObject
{
	Sprite sprite;

	//using GameObject::GameObject;

	SpriteObject(const Sprite &spr);

	void Render(RenderWindow &window) override;
};


struct TextObject : GameObject
{
	Text text;

	TextObject(const Text &text);

	void Render(RenderWindow &window) override;
	void Update() override;
};

struct InteractiveObject : GameObject
{
	SpriteObject* sprite;
	TextObject* text;
	TextObject* textShadow = nullptr;

	RectangleShape backshape;
	bool previousMouseState;
	
	InteractiveObject(TextObject* textObj = nullptr, SpriteObject* spriteObj = nullptr);

	void Render(RenderWindow &window) override;
	void Update();//(Event& e, RenderWindow& window);
	void HoverGraphics(const bool &val);
	void Click();
};