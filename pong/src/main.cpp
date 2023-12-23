#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../include/player.hpp"
#include "../include/ball.hpp"

// Constants
const int FRAMERATE = 60;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Main
int main()
{
	// Create windows
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pong");
	window.setFramerateLimit(FRAMERATE);

	// Create entities
	Player player(window);
	Ball ball(5.f, window);

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
		ball.update();

		// Handle drawing
		window.clear(sf::Color::Black);

		player.draw();
		ball.draw();

		window.display();

	}
	return 0;
}
