#pragma once
#include "direction.h"
enum POSITION { LEFT, RIGHT, UP, DOWN };

class Cell {
private:
	Direction *left;
	Direction *right;
	Direction *up;
	Direction *down;
	bool mine;
	bool finish;
public:
	Cell();

	bool isOpen(POSITION where);
	bool isMine();
	bool isfinish();
	Sprite getSprite(POSITION);
	Direction* getPosition(POSITION where);
	void setMine(bool value);
	void setFinish(bool value);
	void setOpenness(bool newValue, POSITION where);
	void setPositionSprite(POSITION WHAT, int X, int Y);
	void connection(Direction* newAddres, POSITION WHAT);
};