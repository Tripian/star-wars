#include "Yoda.h"

#include <iostream>

Yoda::Yoda()
	:health_(6)
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

	if (!hearthTexture2_.loadFromFile("res/hearth2.png"))
	{
		std::cout << "Could not load hearth texture" << std::endl;
	}
	else
	{
		hearthSprite2_.setTexture(hearthTexture2_);
		hearthSprite2_.setScale(2.0f, 2.0f);
	}

	if (!imageTexture_.loadFromFile("res/yoda.jpg"))
	{
		std::cout << "Could not load hearth texture" << std::endl;
	}
	else
	{
		imageSprite_.setTexture(imageTexture_);
		//imageSprite_.setScale(2.0f, 2.0f);
	}
}


Yoda::~Yoda()
{
}

void Yoda::init(const std::string& resourcePath)
{

}

void Yoda::update()
{

}


void Yoda::draw(sf::RenderWindow* window)
{
	sf::RectangleShape rect(sf::Vector2f(width_, height_));
	/*sf::RectangleShape rect2(sf::Vector2f(40 / 2, 40 / 2));
	rect2.setFillColor(sf::Color::Red);
	rect2.setPosition(6 * 40 + 50 + 40 / 4, 5 * 40 + 50 + 40 / 4);
	window->draw(rect2);*/

	imageSprite_.setPosition(sf::Vector2f(6 * 40 + 50, 5 * 40 + 50));
	window->draw(imageSprite_);

	if (health_ >= 2) {
		hearthSprite_.setPosition(sf::Vector2f(650, 50));
		window->draw(hearthSprite_);
	}

	else if (health_ >= 1) {
		hearthSprite2_.setPosition(sf::Vector2f(650, 50));
		window->draw(hearthSprite2_);
	}

	if (health_ >= 4) {
		hearthSprite_.setPosition(sf::Vector2f(685, 50));
		window->draw(hearthSprite_);
	}

	else if (health_ >= 3) {
		hearthSprite2_.setPosition(sf::Vector2f(685, 50));
		window->draw(hearthSprite2_);
	}

	if (health_ >= 6) {
		hearthSprite_.setPosition(sf::Vector2f(720, 50));
		window->draw(hearthSprite_);
	}

	else if (health_ >= 5) {
		hearthSprite2_.setPosition(sf::Vector2f(720, 50));
		window->draw(hearthSprite2_);
	}



}

void Yoda::destroy()
{

}