#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>
#include "GameState.h"


bool prevkey;

int main()
{
	// get modes for the current gpu/monitor
	std::vector<VideoMode> modes = VideoMode::getFullscreenModes();


	VideoMode desktop = VideoMode::getDesktopMode();
	int i = 0;

	//modes[0].bitsPerPixel = desktop.bitsPerPixel;
	// use best quality first 
	// the first element will always give the best mode (higher width, height and bits-per-pixel).
	RenderWindow window(modes[i], "SFML works!", Style::None);

	// set up gamestate with window load files and check for errors
	GameState newGame = GameState(window);
	if (newGame.LoadGamefiles())
		return 1;

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		// hacky change window need to improve
		if (Keyboard::isKeyPressed(Keyboard::Add) && !prevkey) {
			window.close();
			window.create(modes[15], "SFML works!", Style::Titlebar);

		}
		prevkey = Keyboard::isKeyPressed(Keyboard::Add);

		// update and render window
		window.clear();
		newGame.Update();
		newGame.Render();
		window.display();
	}

	return 0;
}