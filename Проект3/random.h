#pragma once
#include <iostream>
#include <time.h>

int random(int max) {
	double r = rand() / (RAND_MAX + 1.0);
	return r * max;
}
