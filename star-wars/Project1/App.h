#pragma once

#include "SFML/Graphics.hpp"
#include "Scene.h"
#include "Input.h"

class App
{
public:
	App(const std::string& title, const int& width, const int& height, int choose);
	~App();

	void run();

private:
	sf::RenderWindow* window_;
	int width_;
	int height_;
	std::string title_;
	Scene* scene_;
	Input* input_;
};

