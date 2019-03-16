#pragma once

#include "Maze.h"

/*

	This class is intended to encapsulate game objects on the screen.
	Whatever you put in an instance of this class will be rendered on screen.

*/

class Scene
{
public:
	Scene();
	~Scene();

	bool init(const std::string& resourcePath);
	void update();
	void draw(sf::RenderWindow* window);

private:
	Maze* maze_;
};

