#pragma once
#include "player.h"

class Bot : public Player {
public:
	Bot();
	void mazemake();
	bool deadend(int x, bool clear[]);
	bool going(Field field);
};


