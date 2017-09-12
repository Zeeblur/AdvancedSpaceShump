#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>
#include "StateManager.h"


bool prevkey;
bool prevkey2;



int main()
{
	// get modes for the current gpu/monitor
	std::vector<VideoMode> modes = VideoMode::getFullscreenModes();

	VideoMode desktop = VideoMode::getDesktopMode();

	// modes[0].bitsPerPixel = desktop.bitsPerPixel;
	// use best quality first 
	// the first element will always give the best mode (higher width, height and bits-per-pixel).
	RenderWindow window(modes[15], "Advanced Space Shump", Style::None);

	//int newH = (1920*modes[i].width)/modes[i].height;
	//int displace = (newH - 1080)/(-2);

	//window.setView(sf::View(sf::FloatRect(0, displace, 1920, newH)));

	// set up gamestate with window load files and check for errors
	StateManager newGame = StateManager(window);
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

		// update and render window
		window.clear(Color::Red);
		newGame.Update();
		newGame.Render();
		window.display();
	}

	return 0;
}