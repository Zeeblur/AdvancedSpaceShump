#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameState.h"
#include "GameObject.h"

class OptionsState : public GameState
{
    Texture texture;

    void Init();

    Font titleFont;


    std::vector<VideoMode> resChoices;


public:
    OptionsState(StateManager &sm, View &view, RenderWindow &win);
    ~OptionsState();

    void SetModes(std::vector<sf::VideoMode> mod);

    void Update(const float& dt);
    InteractiveObject* windowstyleButton;
};
