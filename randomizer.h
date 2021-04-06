#pragma once
#include"EssentialVars.h"
#include <stdlib.h>
short& randomizerX() {
	short randm = rand()%BOARD_X;
	return randm;
}
short& randomizerY() {
	short randm = rand()%BOARD_Y;
	return randm;
}