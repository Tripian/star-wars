#pragma once

#include "BaseEntity.h"

class Character : public BaseEntity
{
public:
	Character() : location_(Location()) {}
	~Character() {}

	virtual void init(const std::string& resourcePath) = 0;
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
	virtual void destroy() = 0;

	const Location& getLocation() const
	{
		return location_;
	}

	void setLocation(const Location& location)
	{
		location_ = location;
	}

	void setWidth(const float& width)
	{
		width_ = width;
	}

	void setHeight(const float& height)
	{
		height_ = height;
	}

protected:
	std::string entityName;
	Location location_;
	float width_;
	float height_;
private:
};

