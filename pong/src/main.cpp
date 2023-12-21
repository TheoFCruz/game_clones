#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600), "Pong");

	while (window.isOpen()) 
	{
		// Handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		// Handle drawing
		window.clear(sf::Color::Black);

		window.display();

		// Handle logic
	}
	return 0;
}
