#include "Maze.h"
#include "LukeSkywalker.h"
#include <iostream>

Maze::Maze(const std::vector<int>& maze, const int& mazeWidth, const int& mazeHeight, const Viewport& viewport)
	:	maze_(maze),
		mazeWidth_(mazeWidth),
		mazeHeight_(mazeHeight),
		viewport_(viewport)
{
	cellWidth_ = (float)viewport_.getWidth() / (float)mazeWidth_;
	cellHeight_ = (float)viewport_.getHeight() / (float)mazeHeight_;

	playerSpawnIndex_ = Location(6, 5);

	gateLocationIndices_[Gates::A] = Location(0, 5);
	gateLocationIndices_[Gates::B] = Location(4, 0);
	gateLocationIndices_[Gates::C] = Location(12, 0);
	gateLocationIndices_[Gates::D] = Location(13, 5);
	gateLocationIndices_[Gates::E] = Location(4, 10);

	for (auto indices : gateLocationIndices_)
	{
		int i = indices.second.getX();
		int j = indices.second.getY();
		maze_.at(mazeWidth * j + i) = 2;
	}

	maze_.at(mazeWidth * playerSpawnIndex_.getY() + playerSpawnIndex_.getX()) = PLAYER_SPAWN;
}


Maze::~Maze()
{
}

void Maze::update()
{

}

void Maze::draw(sf::RenderWindow* window)
{
	int xPos = viewport_.getX();
	int yPos = viewport_.getY();

	for (int i = 0; i < mazeWidth_; i++)
	{
		for (int j = 0; j < mazeHeight_; j++)
		{
			sf::RectangleShape rect(sf::Vector2f(cellWidth_, cellHeight_));
			switch (maze_[mazeWidth_ * j + i])
			{
			case WALL:
				rect.setFillColor(sf::Color::White);
				break;
			case GATE:
				rect.setFillColor(sf::Color::Blue);
				break;
			case PLAYER_SPAWN:
				rect.setFillColor(sf::Color::Yellow);
				break;
			case EMPTY:
			default:
				rect.setFillColor(sf::Color::Black);
				break;
			}

			rect.setPosition((i * cellWidth_) + xPos, (j * cellHeight_) + yPos);
			window->draw(rect);

		}
	}
}

void Maze::destroy()
{

}

const Location& Maze::getGateLocation(Gates gate)
{
	return gateLocationIndices_[gate];
}
