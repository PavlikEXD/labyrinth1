#include "direction.h"

Direction::Direction() {
	value = true;
	directionTexture.loadFromFile("images/kursova.png");
	directionSprite.setTexture(directionTexture);
	directionSprite.setTextureRect(IntRect(0, 0, 20, 20));
}

bool Direction::isOpen() {
	return value;
}


Sprite Direction::getSprite() {
	return directionSprite;
}

void Direction::setOpennes(bool value) {
	if (value != this->value) {
		this->value = value;
		switch (value) {
		case true:
			directionSprite.setTextureRect(IntRect(0, 0, 20, 20));
			break;
		case false:
			directionSprite.setTextureRect(IntRect(20, 0, 20, 20));
			break;
		}
	}
}

void Direction::setPositionSprite(int X, int Y) {
	directionSprite.move(X, Y);
}