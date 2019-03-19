#pragma once

#include "Maze.h"
#include "Input.h"

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

