#include "LukeSkywalker.h"

#include <iostream>

LukeSkywalker::LukeSkywalker()
	: health_(3)
{
	if (!hearthTexture_.loadFromFile("res/hearth.png"))
	{
		std::cout << "Could not load hearth texture" << std::endl;
	}
	else
	{
		hearthSprite_.setTexture(hearthTexture_);
		hearthSprite_.setScale(2.0f, 2.0f);
	}

	if (!imageTexture_.loadFromFile("res/luke2.png"))
	{
		std::cout << "Could not load hearth texture" << std::endl;
	}
	else
	{
		imageSprite_.setTexture(imageTexture_);
		//imageSprite_.setScale(2.0f, 2.0f);
	}

}


LukeSkywalker::~LukeSkywalker()
{
}

void LukeSkywalker::init(const std::string& resourcePath)
{

}

void LukeSkywalker::update()
{

}

void LukeSkywalker::draw(sf::RenderWindow* window)
{
	sf::RectangleShape rect(sf::Vector2f(width_, height_));
	/*sf::RectangleShape rect2(sf::Vector2f(40 / 2, 40 / 2));
	rect2.setFillColor(sf::Color::Red);
	rect2.setPosition(6 * 40 + 50 + 40 / 4, 5 * 40 + 50 + 40 / 4);
	window->draw(rect2);*/

	imageSprite_.setPosition(sf::Vector2f(6 * 40 + 50 , 5 * 40 + 50 ));
	window->draw(imageSprite_);

	if (health_ >= 1) {
		hearthSprite_.setPosition(sf::Vector2f(650, 50));
		window->draw(hearthSprite_);
	}

	if (health_ >= 2) {
		hearthSprite_.setPosition(sf::Vector2f(685, 50));
		window->draw(hearthSprite_);
	}

	if (health_ >= 3) {
		hearthSprite_.setPosition(sf::Vector2f(720, 50));
		window->draw(hearthSprite_);
	}
}

void LukeSkywalker::destroy()
{

}