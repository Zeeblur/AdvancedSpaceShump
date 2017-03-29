#include <iostream>
#include <stdexcept>
#include <SFML/Graphics.hpp>

sf::Texture texture;

void Load() {
  if (!texture.loadFromFile("res/img/spaceship1.png")) {
    throw std::invalid_argument("Loading error!");
  }
}

int main(){
  sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

  try {
    Load();
  }
  catch (const std::exception&) {
    std::cerr << "Load error" << std::endl;
    return 1;
  }

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();

    window.display();
  }

  return 0;
}