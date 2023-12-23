#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../include/player.hpp"
#include "../include/ball.hpp"

// Constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Other functions

void check_ball_collision(Ball& ball, Player& player)
{
	sf::FloatRect ball_bounds = ball.get_shape().getGlobalBounds();
	sf::FloatRect player_bounds = player.get_shape().getGlobalBounds();

	if (ball_bounds.intersects(player_bounds))
	{
		ball.paddle_bounce();
	}
}

// Main
int main()
{
	// Create windows
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pong");
	window.setVerticalSyncEnabled(true);

	// Delta time clock
	sf::Clock delta_clock;

	// Create entities
	Player player(window);
	Ball ball(10.f, window);

	// Main Loop
	while (window.isOpen()) 
	{
		sf::Time delta_time = delta_clock.restart();

		// Handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		// Handle logic
		player.update(delta_time);
		ball.update(delta_time);

		check_ball_collision(ball, player);

		// Handle drawing
		window.clear(sf::Color::Black);

		player.draw();
		ball.draw();

		window.display();

	}
	return 0;
}
