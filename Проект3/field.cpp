
#include "field.h"

Field::Field() {
	for (int i = 0; i < 25;i++) { //объедин€ю в один адрес соседние границы клеток
		if (i < 20) cell[i].connection(cell[i + 5].getPosition(UP), DOWN);
		if (i == 4 || i == 9 || i == 14 || i == 19 || i == 24) continue;
		cell[i].connection(cell[i + 1].getPosition(LEFT), RIGHT);
	}
	for (int i = 0; i < 5; i++) {  // закрашиваю границы пол€ 
		cell[i].setOpenness(0, UP);
		cell[i * 5].setOpenness(0, LEFT);
		cell[i * 5 + 4].setOpenness(0, RIGHT);
		cell[20 + i].setOpenness(0, DOWN);
		cell[i * 5 + 4].setPositionSprite(RIGHT, 400, 40 + i * 80);
		cell[20 + i].setPositionSprite(DOWN, 40 + i * 80, 400);

	}
	int X = 0;
	int Y = 0;
	for (int i = 0; i < 25; i++,X++) {
		if (i % 5 == 0 && i != 0) X = 0,Y++;
		cell[i].setPositionSprite(UP, 40 + X * 80, Y * 80);
		cell[i].setPositionSprite(LEFT,X * 80, 40 + Y * 80);
	}
		
}

Sprite Field::getSprite(int num, POSITION what) {
	return cell[num].getSprite(what);
}


bool Field::isOpen(int num, POSITION where) {
	return cell[num].isOpen(where);
}

bool Field::isMine(int num){
	return cell[num].isMine();
}

bool Field::isFinish(int num) {
	return cell[num].isfinish();
}

void Field::setOpenness(bool newValue,int num, POSITION where) {
	cell[num].setOpenness(newValue, where);
}

void Field::setMine(int num, bool value) {
	cell[num].setMine(value);
}

void Field::setFinish(int num, bool value) {
	cell[num].setFinish(value);
}

bool Field::allClosed(int num) {
	return !(cell[num].isOpen(UP) || cell[num].isOpen(DOWN) || cell[num].isOpen(LEFT) || cell[num].isOpen(RIGHT));
}

void Field::moveField(int x, int y) {
	for (int i = 0; i < 25; i++) {
		cell[i].setPositionSprite(UP, x, y);
		cell[i].setPositionSprite(LEFT, x,y);
	}
	for (int i = 0; i < 5; i++) {
		cell[i * 5 + 4].setPositionSprite(RIGHT,x,y);
		cell[20 + i].setPositionSprite(DOWN, x,y);

	}
}