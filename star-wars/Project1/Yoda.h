#pragma once
#include "Viewport.h"
#include "Maze.h"
#include "Scene.h"
#include "Character.h"
#include "Input.h"

class Yoda : public Character
{
public:
	Yoda();
	~Yoda();

	virtual void init(const std::string& resourcePath) override;
	virtual void update(Input * input)  override;
	virtual void draw(sf::RenderWindow* window) override;
	virtual void destroy() override;

private:
	int health_;
	int x = 290;
	int y = 250;
	Input* input_;
	sf::RenderWindow* window_;
	sf::Texture hearthTexture_;
	sf::Sprite hearthSprite_;
	sf::Texture hearthTexture2_;
	sf::Sprite hearthSprite2_;
	sf::Texture imageTexture_;
	sf::Sprite imageSprite_;

};

