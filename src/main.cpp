#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>
#include "StateManager.h"


sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight) {

	// Compares the aspect ratio of the window to the aspect ratio of the view,
	// and sets the view's viewport accordingly in order to archieve a letterbox effect.
	// A new view (with a new viewport set) is returned.

	float windowRatio = windowWidth / (float)windowHeight;
	float viewRatio = view.getSize().x / (float)view.getSize().y;
	float sizeX = 1;
	float sizeY = 1;
	float posX = 0;
	float posY = 0;

	bool horizontalSpacing = true;
	if (windowRatio < viewRatio)
		horizontalSpacing = false;

	// If horizontalSpacing is true, the black bars will appear on the left and right side.
	// Otherwise, the black bars will appear on the top and bottom.

	if (horizontalSpacing) {
		sizeX = viewRatio / windowRatio;
		posX = (1 - sizeX) / 2.f;
	}

	else {
		sizeY = windowRatio / viewRatio;
		posY = (1 - sizeY) / 2.f;
	}

	view.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));

	return view;
}

int main()
{
	// get modes for the current gpu/monitor
	std::vector<VideoMode> modes = VideoMode::getFullscreenModes();

	VideoMode desktop = VideoMode::getDesktopMode();

	// modes[0].bitsPerPixel = desktop.bitsPerPixel;
	// use best quality first 
	// the first element will always give the best mode (higher width, height and bits-per-pixel).
	RenderWindow window(modes[0], "Advanced Space Shump", Style::Resize);

	// cap frames
	window.setVerticalSyncEnabled(true);

	float resX = modes[0].width;
	float resY = modes[0].height;

	sf::View view;
	view.setSize(resX, resY);
	view.setCenter(view.getSize().x / 2, view.getSize().y / 2);
	view = getLetterboxView(view, resX, resY);


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


			if (event.type == sf::Event::Resized)
				view = getLetterboxView(view, event.size.width, event.size.height);


		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::P))
		{
			Vector2u size = Vector2u(modes[15].width, modes[15].height);
			window.setSize(size);

			Vector2i pos = Vector2i((modes[0].width / 2)-(size.x /2), (modes[0].height / 2)-(size.y/2));
			window.setPosition(pos);
		}

		// update and render window
		window.clear();

		window.setView(view);
		newGame.Update();
		newGame.Render();
		window.display();
	}

	return 0;
}
