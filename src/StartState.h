#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "GameState.h"

using namespace sf;

class StartState : public GameState
{
private:
	Text titleTxt;
	Text optionsTxt;
	Text playTxt;
	Text exitTxt;

	void Init();
	TextObject* CreateText(String s);
	SpriteObject* CreateSprite();

	Font titleFont;
	
public:
	StartState();// (const View &view);
	~StartState();
	
	void Update();
};