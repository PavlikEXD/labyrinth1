#include "player.h"
#include "bot.h"
#include "random.h"


Bot::Bot() {
	mazemake();
	int Mine = 3;
	for (int i = 1; i < 25 && Mine>0; i++) {
		if (random(5) == 3 && !iPlayer.isMine(i)) {
			iPlayer.setMine(i, 1);
			Mine--;
		}
		if (i > 24 && Mine > 0) i = 6;
	}
	int c = 12 + random(12);
	if (!iPlayer.isMine(c)) iPlayer.setFinish(c,1);

}




void Bot::mazemake() {
	//В итоге поставит 16 стенок
	int x, c, a, n;
	n = 25;
	bool clear[25];

	for (int i = 0; i < 25; i++) { // заставляем стенками
		iPlayer.setOpenness(0, i, UP);
		iPlayer.setOpenness(0, i, DOWN);
		iPlayer.setOpenness(0, i, LEFT);
		iPlayer.setOpenness(0, i, RIGHT);
		clear[i] = 0;
	}

	x = 0; a = 0; // Точка приземления 

	while (a < 10000) { 
		clear[x] = 1;
		a += 1;
		while (1) { // Бесконечный цикл, который прерывается только тупиком
			c = rand() % 4; 
			switch (c) {  
			case 0: if (x > 4)
				if (clear[x - 5] == 0) { // Вверх
					iPlayer.setOpenness(1, x, UP);
					clear[x - 5] = 1;
					n--; if (n == 0) return;
					x -= 5;
				}
			case 1: if (x < 20)
				if (clear[x + 5] == 0) { // Вниз
					clear[x + 5] = 1;
					iPlayer.setOpenness(1, x, DOWN);
					n--; if (n == 0) return;
					x += 5;
				}
			case 2: if ((x % 5) != 0)
				if (clear[x - 1] == 0) { // Налево
					iPlayer.setOpenness(1, x, LEFT);
					clear[x - 1] = 1;
					n--; if (n == 0) return;
					x-=1;
				}
			case 3: if ((x % 5) != 4)
				if (clear[x + 1] == 0) { // Направо
					iPlayer.setOpenness(1, x, RIGHT);
					clear[x + 1] = 1;
					n--; if (n == 0) return;
					x+=1;
				}
			}

			if (deadend(x,clear))
				break;
		}

		if (deadend(x,clear)) // Вытаскиваем  из тупика
			do {
				x = (rand() % 25);
			} while (clear[x] == 0);
	} // На этом и все.
}

bool Bot::deadend(int x,bool clear[]) {
	int a = 0;

	if ((x % 5) != 0) {
		if (clear[x-1]==1)
			a += 1;
	}
	else a += 1;


	if (x > 4) {
		if (clear[x-5]==1)
			a += 1;
	}
	else a += 1;

	if ((x % 5) != 4) {
		if (clear[x+1]==1)
			a += 1;
	}
	else a += 1;

	if (x < 20) {
		if (clear[x+5]==1)
			a += 1;
	}
	else a += 1;

	if (a == 4)
		return 1;
	else
		return 0;

}

bool Bot::going(Field field) {
	int k = 0;
	while(1){
		k = (myMove.at(random(myMove.size()))).getPlace();
		cout << endl<<"    " << k<<endl;
		for_each(myMove.begin(), myMove.end(), [](Move a) { cout<<a.getPlace()<<"  "; });
		cout << endl;
		if (garbageMove.size())
			for_each(garbageMove.begin(), garbageMove.end(), [](Move a) { cout << a.getPlace() << "  "; });
		
		if (Enemy.isOpen(k, UP) && find(garbageMove.begin(), garbageMove.end(), (k - 5)) == garbageMove.end()) {
			if (field.isOpen(k, UP)) {
				if (field.isFinish(k - 5)) return 1;
				if (!isGarbage(k - 5) && find(myMove.begin(), myMove.end(), Move(k - 5)) == myMove.end()) {
					myMove.push_back(Move(k - 5));
				}
				else if (isGarbage(k - 5)) garbageMove.push_back(k - 5);
				if (isGarbage(k) && find(myMove.begin(), myMove.end(), Move(k)) != myMove.end()) {
					myMove.erase(find(myMove.begin(), myMove.end(), Move(k)));
					garbageMove.push_back(k);
				}
			}
			else {
				Enemy.setOpenness(0, k, UP);
				return 0;
			}
		}
		if (Enemy.isOpen(k, DOWN) && find(garbageMove.begin(), garbageMove.end(), (k + 5)) == garbageMove.end()) {
			if (field.isOpen(k, DOWN)) {
				if (field.isFinish(k + 5)) return 1;
				if (!isGarbage(k + 5) && find(myMove.begin(), myMove.end(), Move(k + 5)) == myMove.end()) {
					myMove.push_back(Move(k + 5));
				}
				else if (isGarbage(k + 5)) garbageMove.push_back(k + 5);
				if (isGarbage(k) && find(myMove.begin(), myMove.end(), Move(k)) != myMove.end()) {
					myMove.erase(find(myMove.begin(), myMove.end(), Move(k)));
					garbageMove.push_back(k);
				}
			}
			else {
				Enemy.setOpenness(0, k, DOWN);
				return 0;
			}
		}
		if (Enemy.isOpen(k, LEFT) && find(garbageMove.begin(), garbageMove.end(), (k - 1)) == garbageMove.end()) {
			if (field.isOpen(k, LEFT)) {
				if (field.isFinish(k - 1)) return 1;
				if (!isGarbage(k - 1) && find(myMove.begin(), myMove.end(), Move(k - 1)) == myMove.end()) {
					myMove.push_back(Move(k - 1));
				}
				else if (isGarbage(k - 1)) garbageMove.push_back(k - 1);
				if (isGarbage(k) && find(myMove.begin(), myMove.end(), Move(k)) != myMove.end()) {
					myMove.erase(find(myMove.begin(), myMove.end(), Move(k)));
					garbageMove.push_back(k);
				}
			}
			else {
				Enemy.setOpenness(0, k, LEFT);
				return 0;
			}
		}
		if (Enemy.isOpen(k, RIGHT) && find(garbageMove.begin(), garbageMove.end(), (k + 1)) == garbageMove.end()) {
			if (field.isOpen(k, RIGHT)) {
				if (field.isFinish(k + 1)) return 1;
				if (!isGarbage(k + 1) && find(myMove.begin(), myMove.end(), Move(k + 1)) == myMove.end()) {
					myMove.push_back(Move(k + 1));
				}
				else if (isGarbage(k + 1)) garbageMove.push_back(k + 1);
				if (isGarbage(k) && find(myMove.begin(), myMove.end(), Move(k)) != myMove.end()) {
					myMove.erase(find(myMove.begin(), myMove.end(), Move(k)));
					garbageMove.push_back(k);
				}
			}
			else {
				Enemy.setOpenness(0, k, RIGHT);
				return 0;
			}
		}
	}
}