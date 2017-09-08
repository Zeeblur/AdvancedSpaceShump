#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>
#include "GameState.h"


bool prevkey;
bool prevkey2;

int main()
{
	// get modes for the current gpu/monitor
	std::vector<VideoMode> modes = VideoMode::getFullscreenModes();


	VideoMode desktop = VideoMode::getDesktopMode();
	int i = 15;

	// modes[0].bitsPerPixel = desktop.bitsPerPixel;
	// use best quality first 
	// the first element will always give the best mode (higher width, height and bits-per-pixel).
	RenderWindow window(modes[i], "SFML works!", Style::None);

	int newH = (1920*modes[i].width)/modes[i].height;
	int displace = (newH - 1080)/(-2);

	window.setView(sf::View(sf::FloatRect(0, displace, 1920, newH)));
	window.clear(Color(255, 0, 0, 255));
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

			// preserve aspect ratio
			int originalHeight = window.getViewport(window.getView()).height;
			int originalWidth = window.getViewport(window.getView()).width;

			std::cout << originalHeight << std::endl;
			window.close();
			window.create(modes[15], "SFML works!", Style::Titlebar);
			int newH = (originalHeight / originalWidth) * modes[15].width;
			int displace = (newH - 1080) / (-2);

			originalHeight = window.getViewport(window.getView()).width;
			std::cout << originalHeight << std::endl;
			window.setView(sf::View(sf::FloatRect(0, 0, modes[15].width, newH)));
			window.clear(Color(255, 0, 0, 255));
			std::cout << window.getViewport(window.getView()).width << " + he " << window.getViewport(window.getView()).height << std::endl;
		}

		if (Keyboard::isKeyPressed(Keyboard::Subtract) && !prevkey2) {
			window.close();
			window.create(modes[1], "SFML works!", Style::Titlebar);
			int newH = (1920 * modes[1].width) / modes[1].height;
			int displace = (newH - 1080) / (-2);

			window.setView(sf::View(sf::FloatRect(0, displace, 1920, newH)));
			window.clear(Color(255, 0, 0, 255));

		}
		prevkey = Keyboard::isKeyPressed(Keyboard::Add);
		prevkey2 = Keyboard::isKeyPressed(Keyboard::Subtract);

		// update and render window
		window.clear(Color(255,0,0,255));
		newGame.Update();
		newGame.Render();
		window.display();
	}

	return 0;
}