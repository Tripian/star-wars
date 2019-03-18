#include "App.h"

#include <iostream>
using namespace std;
#include <string>

App::App(const std::string& title, const int& width, const int& height, int choose)
	: title_(title),
		width_(width),
		height_(height),
		window_(nullptr)
{
	window_ = new sf::RenderWindow(sf::VideoMode(width, height), title);
	window_->setVerticalSyncEnabled(true);
	scene_ = new Scene();
	input_ = new Input();
	if (!scene_->init("res/Harita.txt", choose))
	{
		std::cout << "Cannot initialize scene!" << std::endl;
		exit(-1);
	}
}


App::~App()
{
	if (window_ != nullptr)
	{
		delete window_;
		window_ = nullptr;
	}
}

void App::run()
{
	while (window_->isOpen())
	{
		//Poll all events for this frame
		sf::Event event;
		while (window_->pollEvent(event))
		{
			//Close button pressed
			if (event.type == sf::Event::Closed)
			{
				window_->close();
			}
		}
		
		input_->update(window_);

		/*if (input_->getKeyDown(sf::Keyboard::Left))
		{
			std::cout << "A" << std::endl;
		}

		else if (input_->getKeyDown(sf::Keyboard::Right))
		{
			std::cout << "B" << std::endl;
		}

		else if (input_->getKeyDown(sf::Keyboard::Up))
		{
			std::cout << "C" << std::endl;
		}

		else if (input_->getKeyDown(sf::Keyboard::Down))
		{
			std::cout << "D" << std::endl;
		}*/

		//Clear everything drawn last frame
		window_->clear();
		
		scene_->update(input_);
		scene_->draw(window_);

		//Render everything for this frame
		window_->display();
		
	}
}
