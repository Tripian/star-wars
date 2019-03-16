#pragma once
class Location
{
public:
	Location() : x_(0), y_(0) {}
	Location(int x, int y) : x_(x), y_(y) {}
	~Location() {}

	inline void operator=(const Location& location);
	inline bool operator==(const Location& location) const;

	int getX() const
	{
		return x_;
	}

	int getY() const
	{
		return y_;
	}

	void setX(int x)
	{
		x_ = x;
	}

	void setY(int y)
	{
		y_ = y;
	}

private:
	int x_;
	int y_;
};

inline void Location::operator=(const Location& location)
{
	x_ = location.getX();
	y_ = location.getY();
}

inline bool Location::operator==(const Location& location) const
{
	return (location.getX() == x_) && (location.getY() == y_);
}

