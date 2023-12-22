#pragma once

#include <SFML/Graphics.hpp>

// Constants
const float BASE_SPEED = 5.f;

class Player{
private:
	sf::RectangleShape _player_shape;
	sf::RenderWindow& _window;

	float _speed = BASE_SPEED;

public:
	Player(sf::RenderWindow& window);

	void draw();
	void update();
};
	
