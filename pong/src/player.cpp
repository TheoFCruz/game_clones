#include "../include/player.hpp"

Player::Player(sf::RenderWindow& window):
	_window(window)
{
	_player_shape.setFillColor(sf::Color::White);
	_player_shape.setSize(sf::Vector2f(5.f, 40.f));
	_player_shape.setPosition(sf::Vector2f(50.f, 300.f));
}

void Player::draw()
{
	_window.draw(_player_shape);
}

void Player::update()
{
	// Check inputs
	int up = sf::Keyboard::isKeyPressed(sf::Keyboard::W) ? 1 : 0;
	int down = sf::Keyboard::isKeyPressed(sf::Keyboard::S) ? 1 : 0;

	float max_y = _window.getSize().y - _player_shape.getSize().y;

	// Move
	_player_shape.move(0, (down - up) * _speed);

	// Check collisions
	if (_player_shape.getPosition().y < 0)
	{
		_player_shape.setPosition(_player_shape.getPosition().x, 0);
	}
	else if (_player_shape.getPosition().y > max_y)
	{
		_player_shape.setPosition(_player_shape.getPosition().x, max_y);
	}
}

