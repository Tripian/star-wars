#pragma once

#include "SFML/Graphics.hpp"

#define KEY_COUNT sf::Keyboard::KeyCount

class Input
{
public:
	Input();
	~Input();
	void update(sf::RenderWindow* window);

	bool getKeyDown(sf::Keyboard::Key key);

	bool getKey(sf::Keyboard::Key key);

	bool getKeyUp(sf::Keyboard::Key key);

private:
	unsigned char keyboard_[KEY_COUNT] = { 0 };
	unsigned char prev_keyboard_[KEY_COUNT] = { 0 };


};

