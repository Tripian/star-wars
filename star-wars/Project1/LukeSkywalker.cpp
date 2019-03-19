#include "LukeSkywalker.h"

#include <iostream>

LukeSkywalker::LukeSkywalker()
	: health_(3)
{

	input_ = new Input();
	//int x = 290;
	//int y = 250;

	if (!hearthTexture_.loadFromFile("res/hearth.png"))
	{
		std::cout << "Could not load hearth texture" << std::endl;
	}
	else
	{
		hearthSprite_.setTexture(hearthTexture_);
		hearthSprite_.setScale(2.0f, 2.0f);
	}

	if (!imageTexture_.loadFromFile("res/luke3.png"))
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

void LukeSkywalker::update(Input * input) 
{
	//x = 290;
	//y = 250;
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
}

void LukeSkywalker::draw(sf::RenderWindow* window)
{
	
	sf::RectangleShape rect(sf::Vector2f(width_, height_));
	/*sf::RectangleShape rect2(sf::Vector2f(40 / 2, 40 / 2));
	rect2.setFillColor(sf::Color::Red);
	rect2.setPosition(6 * 40 + 50 + 40 / 4, 5 * 40 + 50 + 40 / 4);
	window->draw(rect2);*/

	imageSprite_.setPosition(sf::Vector2f((float)x, (float)y));
	window->draw(imageSprite_);
		

	/*if (control_ == 1) {
		x = x - 40;
		imageSprite_.move(sf::Vector2f((float)x, (float)y));
		//imageSprite_.setPosition(sf::Vector2f((float)x, (float)y));
		window->draw(imageSprite_);
		control_ = 0;
	}

	if (control_ == 2) {
		x = x + 40;
		imageSprite_.move(sf::Vector2f((float)x, (float)y));
		//imageSprite_.setPosition(sf::Vector2f((float)x, (float)y));
		window->draw(imageSprite_);
		control_ = 0;
	}

	if (control_ == 3) {
		y = y - 40;
		imageSprite_.move(sf::Vector2f((float)x, (float)y));
		//imageSprite_.setPosition(sf::Vector2f((float)x, (float)y));
		window->draw(imageSprite_);
		control_ = 0;
	}

	if (control_ == 4) {
		y = y + 40;
		imageSprite_.move(sf::Vector2f((float)x, (float)y));
		//imageSprite_.setPosition(sf::Vector2f((float)x, (float)y));
		window->draw(imageSprite_);
		control_ = 0;
	}*/

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
