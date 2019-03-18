#pragma once

#include "Maze.h"
#include "Input.h"

/*

	This class is intended to encapsulate game objects on the screen.
	Whatever you put in an instance of this class will be rendered on screen.

*/

class Scene
{
public:
	Scene();
	~Scene();

	bool init(const std::string& resourcePath, int choose);
	void update(Input * input);
	void draw(sf::RenderWindow* window);

private:
	Maze* maze_;
	BaseEntity* lukeSkywalker_;
	BaseEntity* yoda_;
	BaseEntity* player_;
};

