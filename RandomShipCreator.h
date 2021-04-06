#pragma once
#include"EssentialVars.h"
#include"randomizer.h"
#include "ShipCoordChecker.h"
short Aimode = 1; 

#pragma region level3Create
void CreateRandomLevel3ShipLeght(short board[BOARD_Y][BOARD_X], const short& shipNum, bool random = true, short y = -1, short x = -1, bool toUp=false) {
	//create random or manual coordinate create level3 ship by board just y coordinate
	if (random) {
		while (true) {
			y = randomizerY();
			x = randomizerX();
			if (checkLevel3ShipLeght(board, y, x, shipNum)) {
				break;
			}
		}
	}

	if (!toUp) {
		for (size_t i = 0; i < 3; i++)
		{
			board[y + i][x] = shipNum;

		}

		board[y + 3][x] = ShipPerimeter;
		board[y + 3][x + 1] = ShipPerimeter;
		board[y + 3][x - 1] = ShipPerimeter;
		board[y - 1][x] = ShipPerimeter;
		board[y - 1][x + 1] = ShipPerimeter;
		board[y - 1][x - 1] = ShipPerimeter;
		board[y][x - 1] = ShipPerimeter;
		board[y][x + 1] = ShipPerimeter;
		board[y + 1][x - 1] = ShipPerimeter;
		board[y + 2][x - 1] = ShipPerimeter;
		board[y + 1][x + 1] = ShipPerimeter;
		board[y + 2][x + 1] = ShipPerimeter;
	}
	else {
		for (size_t i = 0; i < 3; i++)
		{
			board[y - i][x] = shipNum;

		}

		board[y - 3][x] = ShipPerimeter;
		board[y - 3][x + 1] = ShipPerimeter;
		board[y - 3][x - 1] = ShipPerimeter;
		board[y + 1][x] = ShipPerimeter;
		board[y + 1][x + 1] = ShipPerimeter;
		board[y + 1][x - 1] = ShipPerimeter;
		board[y][x - 1] = ShipPerimeter;
		board[y][x + 1] = ShipPerimeter;
		board[y - 1][x - 1] = ShipPerimeter;
		board[y - 2][x - 1] = ShipPerimeter;
		board[y - 1][x + 1] = ShipPerimeter;
		board[y - 2][x + 1] = ShipPerimeter;
	}
}
void CreateRandomLevel3ShipWidth(short board[BOARD_Y][BOARD_X], const short& shipNum, bool random = true, short y = -1, short x = -1, bool toLeft = false) {
	//create random or manual coordinate create level3 ship by board just x coordinate
	if (random) {
		while (true) {
			y = randomizerY();
			x = randomizerX();
			if (checkLevel3ShipWidth(board, y, x, shipNum)) {
				break;
			}
		}
	}
	if (!toLeft) {
		for (size_t i = 0; i < 3; i++)
		{
			board[y][x + i] = shipNum;

		}
		board[y][x + 3] = ShipPerimeter;
		board[y + 1][x + 3] = ShipPerimeter;
		board[y - 1][x + 3] = ShipPerimeter;
		board[y][x - 1] = ShipPerimeter;
		board[y + 1][x - 1] = ShipPerimeter;
		board[y - 1][x - 1] = ShipPerimeter;
		board[y - 1][x] = ShipPerimeter;
		board[y + 1][x] = ShipPerimeter;
		board[y - 1][x + 1] = ShipPerimeter;
		board[y - 1][x + 2] = ShipPerimeter;
		board[y + 1][x + 1] = ShipPerimeter;
		board[y + 1][x + 2] = ShipPerimeter;
	}
	else {
		for (size_t i = 0; i < 3; i++)
		{
			board[y][x - i] = shipNum;

		}
		board[y][x - 3] = ShipPerimeter;
		board[y + 1][x - 3] = ShipPerimeter;
		board[y - 1][x - 3] = ShipPerimeter;
		board[y][x + 1] = ShipPerimeter;
		board[y + 1][x + 1] = ShipPerimeter;
		board[y - 1][x + 1] = ShipPerimeter;
		board[y - 1][x] = ShipPerimeter;
		board[y + 1][x] = ShipPerimeter;
		board[y - 1][x - 1] = ShipPerimeter;
		board[y - 1][x - 2] = ShipPerimeter;
		board[y + 1][x - 1] = ShipPerimeter;
		board[y + 1][x - 2] = ShipPerimeter;


	}
}


#pragma endregion level3Create
#pragma region level2Create
void CreateRandomLevel2ShipLeght(short board[BOARD_Y][BOARD_X], const short& shipNum, bool random = true, short y = -1, short x = -1,bool toUp=false) {
	//create random or manual coordinate create level2 ship by board just y coordinate
	if (random) {
		while (true) {
			y = randomizerY();
			x = randomizerX();
			if (CheckLevel2ShipLeght(board, y, x, shipNum)) {
				break;
			}
		}
	}
	if (!toUp) {
		for (size_t i = 0; i < 2; i++)
		{
			board[y + i][x] = shipNum;

		}

		board[y + 2][x] = ShipPerimeter;
		board[y + 2][x + 1] = ShipPerimeter;
		board[y + 2][x - 1] = ShipPerimeter;
		board[y - 1][x] = ShipPerimeter;
		board[y - 1][x + 1] = ShipPerimeter;
		board[y - 1][x - 1] = ShipPerimeter;
		board[y][x - 1] = ShipPerimeter;
		board[y][x + 1] = ShipPerimeter;
		board[y + 1][x - 1] = ShipPerimeter;
		board[y + 1][x + 1] = ShipPerimeter;
	}
	else {
		for (size_t i = 0; i < 2; i++)
		{
			board[y - i][x] = shipNum;

		}

		board[y - 2][x] = ShipPerimeter;
		board[y - 2][x + 1] = ShipPerimeter;
		board[y - 2][x - 1] = ShipPerimeter;
		board[y + 1][x] = ShipPerimeter;
		board[y + 1][x + 1] = ShipPerimeter;
		board[y + 1][x - 1] = ShipPerimeter;
		board[y][x - 1] = ShipPerimeter;
		board[y][x + 1] = ShipPerimeter;
		board[y - 1][x - 1] = ShipPerimeter;
		board[y - 1][x + 1] = ShipPerimeter;
	}
}
void CreateRandomLevel2ShipWidth(short board[BOARD_Y][BOARD_X], const short& shipNum, bool random = true, short y = -1, short x = -1, bool toLeft = false) {
	//create random or manual coordinate create level2 ship by board just x coordinate
	if (random) {
		while (true) {
			y = randomizerY();
			x = randomizerX();
			if (checkLevel2ShipWidth(board, y, x, shipNum)) {
				break;
			}
		}
	}
	if (!left) {
		for (size_t i = 0; i < 2; i++)
		{
			board[y][x + i] = shipNum;

		}
		board[y][x + 2] = ShipPerimeter;
		board[y + 1][x + 2] = ShipPerimeter;
		board[y - 1][x + 2] = ShipPerimeter;
		board[y][x - 1] = ShipPerimeter;
		board[y + 1][x - 1] = ShipPerimeter;
		board[y - 1][x - 1] = ShipPerimeter;
		board[y - 1][x] = ShipPerimeter;
		board[y + 1][x] = ShipPerimeter;
		board[y - 1][x + 1] = ShipPerimeter;
		board[y + 1][x + 1] = ShipPerimeter;
	}
	else {
		for (size_t i = 0; i < 2; i++)
		{
			board[y][x - i] = shipNum;

		}
		board[y][x - 2] = ShipPerimeter;
		board[y + 1][x - 2] = ShipPerimeter;
		board[y - 1][x - 2] = ShipPerimeter;
		board[y][x + 1] = ShipPerimeter;
		board[y + 1][x + 1] = ShipPerimeter;
		board[y - 1][x + 1] = ShipPerimeter;
		board[y - 1][x] = ShipPerimeter;
		board[y + 1][x] = ShipPerimeter;
		board[y - 1][x - 1] = ShipPerimeter;
		board[y + 1][x - 1] = ShipPerimeter;



	}



}
#pragma endregion level2Create

void CreateRandomLevelOneShip(short board[BOARD_Y][BOARD_X], const short& shipNum, bool random = true, short y = -1, short x = -1) {
	//create random or manual coordinate create level1 ship by board
	if (random) {
		while (true) {
			y = randomizerY();
			x = randomizerX();
			if (checkLevelOneShip(board, y, x, shipNum)) {
				break;
			}
		}
	}
	board[y][x] = shipNum;
	board[y - 1][x + 1] = ShipPerimeter;
	board[y - 1][x - 1] = ShipPerimeter;
	board[y - 1][x] = ShipPerimeter;
	board[y][x + 1] = ShipPerimeter;
	board[y][x - 1] = ShipPerimeter;
	board[y + 1][x] = ShipPerimeter;
	board[y + 1][x - 1] = ShipPerimeter;
	board[y + 1][x + 1] = ShipPerimeter;


}

inline void CrateRandomShipSAnyValue(const short& lv3, const short& lv2, const short& lv1, short board[BOARD_Y][BOARD_X], const short& shipNum) {
	//sented value random coordinate create level1 level2 level3 by board
	short i = 0;
	if (lv3 % 2 != 0 && lv3 > 0) {
		while (i <= lv3)
		{
			++i;
			CreateRandomLevel3ShipLeght(board, shipNum);
			if (i == lv3) {
				break;
			}
			++i;
			CreateRandomLevel3ShipWidth(board, shipNum);
		}
	}
	else if (lv3 % 2 == 0 && lv3 > 0) {
		while (i < lv3)
		{
			++i;
			CreateRandomLevel3ShipLeght(board, shipNum);
			if (i == lv3) {
				break;
			}
			++i;
			CreateRandomLevel3ShipWidth(board, shipNum);
		}
	}

	i = 0;
	if (lv2 % 2 != 0 && lv2 > 0) {
		while (i <= lv2) {
			++i;
			CreateRandomLevel2ShipLeght(board, shipNum);
			if (i == lv2) {
				break;
			}
			++i;
			CreateRandomLevel2ShipWidth(board, shipNum);
		}
	}
	else if (lv2 % 2 == 0 && lv2 > 0) {
		while (i < lv2)
		{
			++i;
			CreateRandomLevel2ShipLeght(board, shipNum);
			if (i == lv2) {
				break;
			}
			++i;
			CreateRandomLevel2ShipWidth(board, shipNum);
		}
	}
	i = 0;

	while (i < lv1)
	{
		CreateRandomLevelOneShip(board, shipNum);
		++i;
	}

}