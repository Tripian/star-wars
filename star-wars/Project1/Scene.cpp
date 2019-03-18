#include "Scene.h"

#include <fstream>
#include <iostream>
#include "LukeSkywalker.h"
#include "Yoda.h"
#include "Input.h"

Scene::Scene()
{
}


Scene::~Scene()
{
}

bool Scene::init(const std::string& resourcePath, int choose)
{
	std::ifstream infile(resourcePath);
	if (infile.is_open())
	{
		std::cout << "Reading from file " << resourcePath << std::endl;
	}
	else
	{
		std::cout << "CANNOT READ FILE AT " << resourcePath << std::endl;
		return false;
	}

	std::string temp;
	std::string characterName1;
	std::string gate1;
	std::string characterName2;
	std::string gate2;

	std::getline(infile, temp, ':');
	std::getline(infile, characterName1, ',');
	std::getline(infile, temp, ':');
	std::getline(infile, gate1, '\n');

	std::getline(infile, temp, ':');
	std::getline(infile, characterName2, ',');
	std::getline(infile, temp, ':');
	std::getline(infile, gate2, '\n');

	std::cout << "Spawning " + characterName1 + " at gate " + gate1 << std::endl;
	std::cout << "Spawning " + characterName2 + " at gate " + gate2 << std::endl;

	std::vector<int> maze;
	int maze_width = 0;
	int temp_width = 0;
	int maze_height = 0;

	char c;
	while (infile.get(c))
	{
		if (c != '\t')
		{
			if (c != '\n')
			{
				maze.push_back((int)c - 48);
				temp_width++;
			}
			else
			{
				maze_height++;
				if (maze_width == 0)
				{
					maze_width = temp_width;
				}
				temp_width = 0;
			}
		}
	}

	std::cout << "Creating maze with width: " << maze_width << " height: " << maze_height << std::endl;

	Viewport viewport(560, 440, 50, 50);
	maze_ = new Maze(maze, maze_width, maze_height, viewport);
	lukeSkywalker_ = new LukeSkywalker();
	yoda_ = new Yoda();

	if (choose == 1) {
		player_ = new LukeSkywalker();
	}

	if (choose == 2) {
		player_ = new Yoda();
	}

	return true;
}

void Scene::update(Input * input)
{
	
	player_->update(input);
}

void Scene::draw(sf::RenderWindow* window)
{
	maze_->draw(window);
	player_->draw(window);

}
