#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Move {
private:
	int place;
	Texture placeTexture;
	Sprite placeSprite;
public:
	Move();
	Move(int newPlace);
	int getPlace();
	Sprite getSprite();
	void setMySprite();
	void moving(int newPlace);
	//Move(int newPlace);
};

bool operator==(Move a, Move b);


