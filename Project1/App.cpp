#include "App.h"

#include <iostream>

App::App(const std::string& title, const int& width, const int& height)
	: title_(title),
		width_(width),
		height_(height),
		window_(nullptr)
{
	window_ = new sf::RenderWindow(sf::VideoMode(width, height), title);
	window_->setVerticalSyncEnabled(true);
	scene_ = new Scene();
	if (!scene_->init("res/Harita.txt"))
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

		//Clear everything drawn last frame
		window_->clear();

		scene_->draw(window_);

		//Render everything for this frame
		window_->display();
	}
}
