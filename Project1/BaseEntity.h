#pragma once

#include <string>

#include "SFML/Graphics.hpp"
#include "Location.h"

class BaseEntity
{
public:
	BaseEntity() : resourcePath("") {}
	virtual ~BaseEntity() {}

	virtual void init(const std::string& resourcePath) = 0;
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
	virtual void destroy() = 0;

protected:
	std::string resourcePath;
};

