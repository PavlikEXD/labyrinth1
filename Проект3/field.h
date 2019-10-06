#pragma once
#include <vector>
#include "cell.h"
#include "move.h"

class Field {
private:
	Cell cell[25];
	
public:
	Field();
	Sprite getSprite(int num, POSITION what);
	
	bool isOpen(int num, POSITION where);
	bool isMine(int num);
	bool isFinish(int num);
	void setOpenness(bool newValue, int num, POSITION where);
	void setMine(int num, bool value);
	void setFinish(int num, bool value);
	bool allClosed(int num);
	void moveField(int x, int y);
};