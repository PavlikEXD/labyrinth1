#include "player.h"

Player::Player() {
	iPlayer.moveField(40, 40);
	Enemy.moveField(550, 40);
	myMove.push_back(0);


	finishTexture.loadFromFile("images/kursova.png");
	finishSprite.setTexture(finishTexture);
	finishSprite.setTextureRect(IntRect(60, 0, 20, 20));

	step.setMySprite();
}

Sprite Player::getfinishSprite() {
	return finishSprite;
}

bool Player::isGarbage(int num) {
	int i = 4;
	switch (i) {
	case 4:
		if (Enemy.isOpen(num, UP) && find(myMove.begin(), myMove.end(), Move(num - 5)) == myMove.end()) return 0;
		else i--;
	case 3:
		if (Enemy.isOpen(num, DOWN) && find(myMove.begin(), myMove.end(), Move(num + 5)) == myMove.end()) return 0;
		else i--;
	case 2:
		if (Enemy.isOpen(num, LEFT) && find(myMove.begin(), myMove.end(), Move(num - 1)) == myMove.end()) return 0;
		else i--;
	case 1:
		if (Enemy.isOpen(num, RIGHT) && find(myMove.begin(), myMove.end(), Move(num + 1)) == myMove.end()) return 0;
		else return 1;
	}
}

int Player::wallMaking(Vector2i position) {
	position.x -= iPlayer.getSprite(0, LEFT).getPosition().x;
	position.y -= iPlayer.getSprite(0, UP).getPosition().y;
	if (position.x > 40 && position.x < 440 && position.y > 40 && position.y < 440) {
		if (((position.x % 80) > 45 && ((position.y % 80)) > 5) && ((position.x % 80) < 55 && ((position.y % 80)) < 15)) {
			if (iPlayer.isOpen((position.x - 40) / 80 + 5 * position.y / 80, UP)) {
				iPlayer.setOpenness(0, (position.x - 40) / 80 + 5 * position.y / 80, UP);
				cout << -1;
				return -1;
			}
			else {
				iPlayer.setOpenness(1, (position.x - 40) / 80 + 5 * position.y / 80, UP);
				return 1;
			}

		}
		else if (((position.x % 80) > 5 && (position.y % 80) > 45) && ((position.x % 80) < 15 && (position.y % 80) < 55)) {
			if (iPlayer.isOpen(position.x / 80 + 5 * (position.y - 40) / 80, LEFT)) {
				iPlayer.setOpenness(0, position.x / 80 + 5 * (position.y - 40) / 80, LEFT);
				return -1;
			}
			else {
				iPlayer.setOpenness(1, position.x / 80 + 5 * (position.y - 40) / 80, LEFT);
				return 1;
			}
		}
	}
	return 0;
}



int Player::setFinish(Vector2i position) {
	position.x -= iPlayer.getSprite(0, LEFT).getPosition().x;
	position.y -= iPlayer.getSprite(0, UP).getPosition().y;

	if (position.x > 40 && position.x < 440 && position.y > 40 && position.y < 440) {
		iPlayer.setFinish(position.x / 80 + 5 * (position.y / 80), 1);
		finishSprite.setPosition(80 + (position.x / 80) * 80, 80 + (position.y / 80) * 80);
		return (position.x / 80 + 5 * (position.y / 80));
	}
	return 0;
}


int Player::going(POSITION go) {
	if (Enemy.isOpen(step.getPlace(), go)) {
		int k = 0;
		switch (go) {
		case UP: {
			step.moving(step.getPlace() - 5);
			return 0;
		}
		case DOWN: {

			step.moving(step.getPlace() + 5);
			return 0;
		}
		case LEFT: {
			step.moving(step.getPlace() - 1);
			return 0;
		}
		case RIGHT: {
			step.moving(step.getPlace() + 1);
			return 0;

		}
		}

	}
	return 0;
}
