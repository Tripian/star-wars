#pragma once

/*

	This class is just a container for variables.
	Viewport can be used to place to place the maze whereever you want on the screen.
	It can also be used to determine the width and height of the maze drawing

	Parameters:
		width_	-	The width of the drawing.
		height_	-	The height of the drawing.
		x_		-	x position on the render window
		y_		-	y position on the render window

*/

class Viewport
{
public:
	Viewport(const int& width, const int& height, const int& x, const int& y)
		: width_(width), height_(height), x_(x), y_(y)
	{}

	const int& getWidth() const
	{
		return width_;
	}

	const int& getHeight() const
	{
		return height_;
	}

	const int& getX() const
	{
		return x_;
	}

	const int& getY() const
	{
		return y_;
	}

private:
	int width_;
	int height_;
	int x_;
	int y_;
};