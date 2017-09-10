#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

using namespace sf;

// GameState stores the state of the game/menu screens windows etc.

// possible enum for state
enum gameState
{
	START,
	PLAY,
	PAUSE,
	OPTIONS
};

struct GameObject
{
	Vector2f position;
	std::unique_ptr<FloatRect> boundingBox = nullptr;
	
	virtual void Render(const RenderWindow &window) {}
	virtual ~GameObject() = 0; 

};

struct SpriteObject : public GameObject
{
	std::unique_ptr<Sprite> sprite;

	//using GameObject::GameObject;

	SpriteObject(Sprite *spr);

	~SpriteObject()	{ delete &sprite; }

	void Render(RenderWindow &window) const;
};


struct TextObject : GameObject
{
	std::unique_ptr<Text> text;

	TextObject(Text *text);
	TextObject() { delete &text; }

	void Render(RenderWindow &window) const;
};

class GameState
{
private:
	gameState currentState;

protected:
	std::vector<GameObject*> stateObjects;
	
public:
	// abstract class deconstruction
	GameState() = default;
	virtual ~GameState() {}

	// update changes per implementation
	virtual void Update() = 0;

	// Render function always the same
	void Render(RenderWindow &window) const;

	void AddObject(GameObject *go);

};

