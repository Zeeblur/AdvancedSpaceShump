#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

using namespace sf;

// GameState stores the state of the game/menu screens windows etc.

struct GameObject
{
	Vector2f position;
	FloatRect boundingBox;
	
	virtual void Render(RenderWindow &window) {}
	virtual ~GameObject() = 0; 

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

	TextObject(const TextObject& other);

	void Render(RenderWindow &window) override;
};

class GameState
{
private:
	//stateType currentState;


protected:
	std::vector<GameObject*> stateObjects;
	View* view;
public:
	// abstract class deconstruction
	GameState() = default;
	virtual ~GameState() {}

	// update changes per implementation
	virtual void Update() = 0;

	// Render function always the same
	void Render(RenderWindow &window) const;

	void AddObject(const GameObject &go);

};

