#pragma once
#include "Viewport.h"
#include "Maze.h"
#include "Scene.h"
#include "Character.h"
#include "Input.h"

class LukeSkywalker : public Character
{
public:
	LukeSkywalker();
	~LukeSkywalker();

	virtual void init(const std::string& resourcePath) override;
	virtual void update(Input * input)  override;
	virtual void draw(sf::RenderWindow* window) override;
	virtual void destroy() override;
	

private:
	int health_;
	Input* input_;
	Maze* maze_;
	int walls_;
	sf::RenderWindow* window_;
	sf::Texture hearthTexture_;
	sf::Sprite hearthSprite_;
	sf::Texture imageTexture_;
	sf::Sprite imageSprite_;
	Location playerSpawnIndex_ = Location(6, 5);
	int x = playerSpawnIndex_.getX() * 40 + 50;
	int y = playerSpawnIndex_.getY() * 40 + 50;
};

