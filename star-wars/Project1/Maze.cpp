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

	sf::RectangleShape rect2(sf::Vector2f(cellWidth_ / 2 , cellHeight_ / 2));
	rect2.setFillColor(sf::Color::Red);
	rect2.setPosition(6 * cellWidth_ + xPos + cellWidth_ / 4, 5 * cellHeight_ + yPos + cellHeight_ / 4);
	window->draw(rect2);

	sf::ConvexShape convex;
	convex.setPointCount(6);
	convex.setPoint(0, sf::Vector2f(0 + 615, 0 + 40));
	convex.setPoint(1, sf::Vector2f(30 + 615, 30 + 40));
	convex.setPoint(2, sf::Vector2f(60 + 615, 0 + 40));
	convex.setPoint(3, sf::Vector2f(60 + 615, 30 + 40));
	convex.setPoint(4, sf::Vector2f(30 + 615, 60 + 40));
	convex.setPoint(5, sf::Vector2f(0 + 615, 30 + 40));
	convex.setFillColor(sf::Color::Red);
	window->draw(convex);

	sf::ConvexShape convex2;
	convex2.setPointCount(6);
	convex2.setPoint(0, sf::Vector2f(0 + 685, 0 + 40));
	convex2.setPoint(1, sf::Vector2f(30 + 685, 30 + 40));
	convex2.setPoint(2, sf::Vector2f(60 + 685, 0 + 40));
	convex2.setPoint(3, sf::Vector2f(60 + 685, 30 + 40));
	convex2.setPoint(4, sf::Vector2f(30 + 685, 60 + 40));
	convex2.setPoint(5, sf::Vector2f(0 + 685, 30 + 40));
	convex2.setFillColor(sf::Color::Red);
	window->draw(convex2);

	sf::ConvexShape convex3;
	convex3.setPointCount(6);
	convex3.setPoint(0, sf::Vector2f(0 + 755, 0 + 40));
	convex3.setPoint(1, sf::Vector2f(30 + 755, 30 + 40));
	convex3.setPoint(2, sf::Vector2f(60 + 755, 0 + 40));
	convex3.setPoint(3, sf::Vector2f(60 + 755, 30 + 40));
	convex3.setPoint(4, sf::Vector2f(30 + 755, 60 + 40));
	convex3.setPoint(5, sf::Vector2f(0 + 755, 30 + 40));
	convex3.setFillColor(sf::Color::Red);
	window->draw(convex3);

}

void Maze::destroy()
{

}

const Location& Maze::getGateLocation(Gates gate)
{
	return gateLocationIndices_[gate];
}
