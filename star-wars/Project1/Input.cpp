#include "Input.h"



Input::Input()
{
}


Input::~Input()
{
}

void::Input::update(sf::RenderWindow* window)
{
	memcpy(prev_keyboard_, keyboard_, KEY_COUNT);

	for (unsigned int i = sf::Keyboard::A; i < KEY_COUNT; i++)
	{
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i))) {
			keyboard_[i] = 1;
		}
		else
		{
			keyboard_[i] = 0;
		}
	}

}

bool::Input::getKeyDown(sf::Keyboard::Key key)
{
	return keyboard_[key] && !prev_keyboard_[key];
}

bool::Input::getKey(sf::Keyboard::Key key)
{
	return keyboard_[key];
}

bool::Input::getKeyUp(sf::Keyboard::Key key)
{
	return !keyboard_[key] && prev_keyboard_[key];
}