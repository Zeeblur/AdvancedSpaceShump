#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>
#include "GameState.h"

int main() {
  RenderWindow window(VideoMode(400, 400), "SFML works!");

  // set up gamestate with window load files and check for errors
  GameState newGame = GameState(window);
  if (newGame.LoadGamefiles())
	  return 1;

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed){
        window.close();
      }
    }
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
      window.close();
    }

	// update and render window
    window.clear();
	newGame.Update();
    newGame.Render();
    window.display();
  }

  return 0;
}