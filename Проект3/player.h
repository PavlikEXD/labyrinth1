#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "field.h"
#include "move.h"
using namespace std;

class Player {
public:
	Player();
	Field iPlayer;
	Field Enemy;
	Texture	finishTexture;
	Sprite finishSprite;
	Move step;

	vector<Move> myMove;
	vector<int> garbageMove;

	Sprite getfinishSprite();



	bool isGarbage(int num);
	int wallMaking(Vector2i position);
	int setFinish(Vector2i position);
	int going(POSITION);
//

};