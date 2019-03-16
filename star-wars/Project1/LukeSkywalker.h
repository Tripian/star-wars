#pragma once
#include "Viewport.h"
#include "Maze.h"
#include "Scene.h"
#include "Character.h"

class LukeSkywalker : public Character
{
public:
	LukeSkywalker();
	~LukeSkywalker();

	virtual void init(const std::string& resourcePath) override;
	virtual void update() override;
	virtual void draw(sf::RenderWindow* window) override;
	virtual void destroy() override;
};

