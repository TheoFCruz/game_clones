#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../include/player.hpp"

// Constants
const int FRAMERATE = 60;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main()
{
	// Create windows
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pong");
	window.setFramerateLimit(FRAMERATE);

	// Create entities
	Player player(window);

	// Main Loop
	while (window.isOpen()) 
	{
		// Handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		// Handle logic
		player.update();

		// Handle drawing
		window.clear(sf::Color::Black);

		player.draw();

		window.display();

	}
	return 0;
}
