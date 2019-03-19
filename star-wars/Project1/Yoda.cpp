#include "Yoda.h"

#include <iostream>

Yoda::Yoda()
	:health_(6)
{

	input_ = new Input();

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

	if (!imageTexture_.loadFromFile("res/yoda2.jpg"))
	{
		std::cout << "Could not load hearth texture" << std::endl;
	}
	else
	{
		imageSprite_.setTexture(imageTexture_);
	}
}


Yoda::~Yoda()
{
}

void Yoda::init(const std::string& resourcePath)
{

}

void Yoda::update(Input * input, Maze * maze)
{
	input_->update(window_);

	if (input_->getKeyDown(sf::Keyboard::Left))
	{
		x = x - 40;
		imageSprite_.move(sf::Vector2f((float)x, (float)y));
	}

	else if (input_->getKeyDown(sf::Keyboard::Right))
	{
		x = x + 40;
		imageSprite_.move(sf::Vector2f((float)x, (float)y));
	}

	else if (input_->getKeyDown(sf::Keyboard::Up))
	{
		y = y - 40;
		imageSprite_.move(sf::Vector2f((float)x, (float)y));
	}

	else if (input_->getKeyDown(sf::Keyboard::Down))
	{
		y = y + 40;
		imageSprite_.move(sf::Vector2f((float)x, (float)y));
	}

	if (x == 610 && y == 410) {
		std::cout << "Kazandiniz" << std::endl;
	}

}


void Yoda::draw(sf::RenderWindow* window)
{
	sf::RectangleShape rect(sf::Vector2f(width_, height_));

	imageSprite_.setPosition(sf::Vector2f((float)x, (float)y));
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