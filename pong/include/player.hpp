#pragma once

#include <SFML/Graphics.hpp>

class Player{
private:
	sf::RectangleShape _player_shape;
	sf::RenderWindow& _window;

	float _speed = 0.5f;

public:
	Player(sf::RenderWindow& window);

	void draw();
	void update();
};
	
