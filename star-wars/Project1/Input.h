#pragma once

#include "SFML/Graphics.hpp"

#define KEY_COUNT sf::Keyboard::KeyCount

class Input
{
public:
	Input();
	~Input();
	void update(sf::RenderWindow* window);

	// Tu�a bast�ktan sonra true d�nd�r�r
	bool getKeyDown(sf::Keyboard::Key key);

	// Tu�a bas�l�ysa true d�nd�r�r
	bool getKey(sf::Keyboard::Key key);

	// Tu�u b�rakt�ktan sonra true d�nd�r�r
	bool getKeyUp(sf::Keyboard::Key key);

private:
	unsigned char keyboard_[KEY_COUNT] = { 0 };
	unsigned char prev_keyboard_[KEY_COUNT] = { 0 };


};

