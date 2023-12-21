#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../include/player.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600), "Pong");

	Player player(window);

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
