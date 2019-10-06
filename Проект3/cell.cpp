#include "cell.h"

Cell::Cell() {
	left = new Direction();
	right = new Direction();
	up = new Direction();
	down = new Direction();
	finish = 0;
	mine = 0;
}

bool Cell::isOpen(POSITION where) {
	switch (where) {
	case LEFT:
		return left->isOpen();
	case RIGHT:
		return right->isOpen();
	case UP:
		return up->isOpen();
	case DOWN:
		return down->isOpen();
	}
}

bool Cell::isMine() {
	return mine;
}

bool Cell::isfinish() {
	return finish;
}

Sprite Cell::getSprite(POSITION where) {
	switch (where) {
	case LEFT:
		return left->getSprite();
	case RIGHT: {
		return right->getSprite();
	}
	case UP: {
		return up->getSprite();
	}
	case DOWN: {
		return down->getSprite();
	}
	}
}

Direction* Cell::getPosition(POSITION where) {
	switch (where) {
	case LEFT:
		return left;
	case RIGHT: {
		return right;
	}
	case UP: {
		return up;
	}
	case DOWN: {
		return down;
	}
	}
}

void Cell::setMine(bool value) {
	mine = value;
}

void Cell::setFinish(bool value) {
	finish = value;
}

void Cell::setOpenness(bool newValue, POSITION where) {
	switch (where) {
	case LEFT: {
		if (left->isOpen() != newValue) left->setOpennes(newValue);
		break;
	}
	case RIGHT: {
		if (right->isOpen() != newValue) right->setOpennes(newValue);
		break;
	}
	case UP: {
		if (up->isOpen() != newValue) up->setOpennes(newValue);
		break;
	}
	case DOWN: {
		if (down->isOpen() != newValue) down->setOpennes(newValue);
		break;
	}
	}
}


void Cell::setPositionSprite(POSITION WHAT, int X, int Y) {
	switch (WHAT) {
	case LEFT: {
		left->setPositionSprite(X, Y);
		break;
	}
	case RIGHT: {
		right->setPositionSprite(X, Y);
		break;
	}
	case UP: {
		up->setPositionSprite(X, Y);
		break;
	}
	case DOWN: {
		down->setPositionSprite(X, Y);
		break;
	}
	}
}

void Cell::connection(Direction* newAddres, POSITION WHAT) {
	switch (WHAT) {
	case LEFT: {
		delete left;
		left = newAddres;
		break;
	}
	case RIGHT: {
		delete right;
		right = newAddres;
		break;
	}
	case UP: {
		delete up;
		up = newAddres;
		break;
	}
	case DOWN: {
		delete down;
		down = newAddres;
		break;
	}
	}
}