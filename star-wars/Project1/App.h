#pragma once

#include "SFML/Graphics.hpp"
#include "Scene.h"

class App
{
public:
	App(const std::string& title, const int& width, const int& height);
	~App();

	void run( int choose );

private:
	sf::RenderWindow* window_;
	int width_;
	int height_;
	std::string title_;
	Scene* scene_;
};

