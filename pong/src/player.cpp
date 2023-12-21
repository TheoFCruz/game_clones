#include "../include/player.hpp"
#include <SFML/Window/Keyboard.hpp>

Player::Player()
{
	_player_shape.setFillColor(sf::Color::White);
	_player_shape.setSize(sf::Vector2f(5.f, 20.f));
	_player_shape.setPosition(sf::Vector2f(50.f, 300.f));
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(_player_shape);
}

void Player::update()
{
	// Check inputs
	int up = sf::Keyboard::isKeyPressed(sf::Keyboard::W) ? 1 : 0;
	int down = sf::Keyboard::isKeyPressed(sf::Keyboard::S) ? 1 : 0;

	// Move
	_player_shape.move(0, (down - up) * _speed);
}

