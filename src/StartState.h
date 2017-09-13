#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "GameState.h"
#include "GameObject.h"

using namespace sf;

class StartState : public GameState
{
private:
	Texture texture;

	Vector2f viewSize;

	void Init();

	TextObject* CreateText(String s, Vector2f displacement = Vector2f(0.f, 0.f));
	SpriteObject* CreateSprite();

	Font titleFont;

	
public:
	StartState(const Vector2f &view);
	~StartState();


	//void UpdateViewSize(const Vector2f &size);

	
	void Update();
};