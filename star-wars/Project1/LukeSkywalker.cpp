#include "LukeSkywalker.h"

#include <iostream>

LukeSkywalker::LukeSkywalker()
	: health_(3)
{

	input_ = new Input();
	int control_ = 0;
	int x = 6 * 40 + 50;
	int y = 5 * 40 + 50;

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

void LukeSkywalker::update(Input * input) 
{
	
	input_->update(window_);

	if (input_->getKeyDown(sf::Keyboard::Left))
	{
		//x = x - 40;
		//imageSprite_.move(sf::Vector2f(x, y));
		control_ = 1;
	}

	else if (input_->getKeyDown(sf::Keyboard::Right))
	{
		control_ = 2;
	}

	else if (input_->getKeyDown(sf::Keyboard::Up))
	{
		control_ = 3;
	}

	else if (input_->getKeyDown(sf::Keyboard::Down))
	{
		control_ = 4;
	}
}

void LukeSkywalker::draw(sf::RenderWindow* window)
{
	int count=0;
	sf::RectangleShape rect(sf::Vector2f(width_, height_));
	/*sf::RectangleShape rect2(sf::Vector2f(40 / 2, 40 / 2));
	rect2.setFillColor(sf::Color::Red);
	rect2.setPosition(6 * 40 + 50 + 40 / 4, 5 * 40 + 50 + 40 / 4);
	window->draw(rect2);*/

	if(count==0) {
		imageSprite_.setPosition(sf::Vector2f(6 * 40 + 50, 5 * 40 + 50));
		window->draw(imageSprite_);
		count++;
	}

	std::cout << count << std::endl;

	if (control_ == 1) {
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
	}

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
