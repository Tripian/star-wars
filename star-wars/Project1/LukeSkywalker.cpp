#include "LukeSkywalker.h"

#include <iostream>

LukeSkywalker::LukeSkywalker()
	: health_(3)
{

	input_ = new Input();

	Viewport viewport(560, 440, 50, 50);
	//maze_ = new Maze(maze, maze_width, maze_height, viewport);
	//std::copy(std::begin(maze_->wallx), std::end(maze_->wallx), std::begin(wallx_));

	//std::cout << maze_->walls[5] << std::endl;
	//int x = 290;
	//int y = 250;
	//std::cout << playerSpawnIndex_.getX() << std::endl;
	//std::cout<< Maze::
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
		/*if (maze_->getWalls(playerSpawnIndex_.getX() , playerSpawnIndex_.getY()) != 10 )
		{
			x = x - 40;
			imageSprite_.move(sf::Vector2f((float)x, (float)y));
			playerSpawnIndex_.setX(playerSpawnIndex_.getX() - 1);
		}*/
		
		x = x - 40;
		imageSprite_.move(sf::Vector2f((float)x, (float)y));
		playerSpawnIndex_.setX(playerSpawnIndex_.getX() - 1);
		
		//std::cout << maze_->wall[playerSpawnIndex_.getX()][playerSpawnIndex_.getY()] << std::endl;
	}

	else if (input_->getKeyDown(sf::Keyboard::Right))
	{
		x = x + 40;
		imageSprite_.move(sf::Vector2f((float)x, (float)y));
		playerSpawnIndex_.setX(playerSpawnIndex_.getX() + 1);
	}

	else if (input_->getKeyDown(sf::Keyboard::Up))
	{
		y = y - 40;
		imageSprite_.move(sf::Vector2f((float)x, (float)y));
		playerSpawnIndex_.setY(playerSpawnIndex_.getY() - 1);
	}

	else if (input_->getKeyDown(sf::Keyboard::Down))
	{
		y = y + 40;
		imageSprite_.move(sf::Vector2f((float)x, (float)y));
		playerSpawnIndex_.setY(playerSpawnIndex_.getY() + 1);
	}
	
	//610 , 410

	if (x == 610 && y == 410) {
		std::cout << "Kazandiniz" << std::endl;
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

	/*sf::Font font;
	font.
	sf::Text text;
	text.setFont(font);
	text.setString("CANLAR");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Blue);
	text.setStyle(sf::Text::Regular);
	text.setPosition(sf::Vector2f(650, 40));	
	window->draw(text);*/

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
