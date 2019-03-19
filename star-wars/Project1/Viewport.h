#pragma once

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