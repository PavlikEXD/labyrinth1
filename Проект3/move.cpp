#include <iostream>
#include "move.h"
using namespace std;

Move::Move() {
	place = 0;
	placeTexture.loadFromFile("images/kursova.png");
	placeSprite.setTexture(placeTexture);
	placeSprite.setTextureRect(IntRect(40, 0, 20, 20));
}

Move::Move(int newPlace) {
	place = newPlace;
	placeTexture.loadFromFile("images/kursova.png");
	placeSprite.setTexture(placeTexture);
	placeSprite.setTextureRect(IntRect(40, 0, 20, 20));
	placeSprite.move(80 + 80*(newPlace%5),80 + 80*(newPlace/5));
}

void Move::setMySprite() {
	placeSprite.setTextureRect(IntRect(80, 0, 20, 20));
	placeSprite.setPosition(590, 80);
}

bool operator==(Move a, Move b) {
	return a.getPlace() == b.getPlace();
}


int Move::getPlace() {
	return place;
}

Sprite Move::getSprite() {
	return placeSprite;
}

void Move::moving(int newPlace) {
	place = newPlace;
	placeSprite.setPosition(80 + 80 * (newPlace % 5) + 510, 80 + 80 * (newPlace / 5));
}



