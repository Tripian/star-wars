#pragma once

#include "BaseEntity.h"
#include "Viewport.h"
#include "Character.h"

#include <vector>
#include <map>

#define RECT_WIDTH 20
#define RECT_HEIGHT 20

enum Gates
{
	A,
	B,
	C,
	D,
	E
};

enum BlockTypes
{
	WALL = 0,
	EMPTY = 1,
	GATE = 2,
	PLAYER_SPAWN = 3
};

class Maze
{
public:
	Maze(const std::vector<int>& maze, const int& mazeWidth, const int& mazeHeight, const Viewport& viewport);
	~Maze();

	void update();
	void draw(sf::RenderWindow* window);
	void destroy();

	const Location& getGateLocation(Gates gate);

	const float& getCellWidth() const
	{
		return cellWidth_;
	}

	const float& getCellHeight() const
	{
		return cellHeight_;
	}


private:
	std::vector<int> maze_;
	int mazeWidth_;
	int mazeHeight_;
	float cellWidth_;
	float cellHeight_;
	Viewport viewport_;

	std::vector<Character*> badGuys_;
	Character* player_;

	std::map<Gates, Location> gateLocationIndices_;
	Location playerSpawnIndex_;
};

