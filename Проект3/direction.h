#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Direction {
private:
	bool value;
	Texture directionTexture;
	Sprite directionSprite;
public:
	Direction();
	bool isOpen();
	void setOpennes(bool);
	Sprite getSprite();
	void setPositionSprite(int X, int Y);
};