#pragma once
#include"EssentialVars.h"
#pragma region level3 
bool checkLevel3ShipLeght(const short board[BOARD_Y][BOARD_X], const short& y, const short& x, const short& ship, bool toUp = false) {
	//check ship placement from coordinate 

	if (!toUp) {
		if (board[y][x] == ship || board[y][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x] == ship || board[y - 1][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x - 1] == ship || board[y - 1][x - 1] == ShipPerimeter || board[y - 1][x + 1] == ship || board[y - 1][x + 1] == ShipPerimeter) {
			return false;
		}


		else if (board[y][x + 1] == ship || board[y][x + 1] == ShipPerimeter || board[y][x - 1] == ship || board[y][x - 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y + 1][x] == ship || board[y + 1][x] == ShipPerimeter) {
			return false;
		}


		else if (board[y + 1][x - 1] == ship || board[y + 1][x - 1] == ShipPerimeter || board[y + 1][x + 1] == ship || board[y + 1][x + 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y + 2][x] == ship || board[y + 2][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y + 2][x - 1] == ship || board[y + 2][x - 1] == ShipPerimeter || board[y + 2][x + 1] == ship || board[y + 2][x + 1] == ShipPerimeter) {
			return false;
		}

		else if (board[y + 3][x] == ship || board[y + 3][x] == ShipPerimeter) {
			return false;
		}

		else if (board[y + 3][x - 1] == ship || board[y + 3][x - 1] == ShipPerimeter || board[y + 3][x + 1] == ship || board[y + 3][x + 1] == ShipPerimeter) {
			return false;
		}
		else if (y + 4 >= BOARD_Y || x +1>= BOARD_X || x-1 < 0||y-1<0) {
			return false;
		}
		return true;
	}
	else {
		if (board[y][x] == ship || board[y][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y + 1][x] == ship || board[y + 1][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y + 1][x - 1] == ship || board[y + 1][x - 1] == ShipPerimeter || board[y + 1][x + 1] == ship || board[y + 1][x + 1] == ShipPerimeter) {
			return false;
		}


		else if (board[y][x + 1] == ship || board[y][x + 1] == ShipPerimeter || board[y][x - 1] == ship || board[y][x - 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x] == ship || board[y - 1][x] == ShipPerimeter) {
			return false;
		}


		else if (board[y - 1][x - 1] == ship || board[y - 1][x - 1] == ShipPerimeter || board[y - 1][x + 1] == ship || board[y - 1][x + 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 2][x] == ship || board[y - 2][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 2][x - 1] == ship || board[y - 2][x - 1] == ShipPerimeter || board[y - 2][x + 1] == ship || board[y - 2][x + 1] == ShipPerimeter) {
			return false;
		}

		else if (board[y - 3][x] == ship || board[y - 3][x] == ShipPerimeter) {
			return false;
		}

		else if (board[y - 3][x - 1] == ship || board[y - 3][x - 1] == ShipPerimeter || board[y - 3][x + 1] == ship || board[y - 3][x + 1] == ShipPerimeter) {
			return false;
		}
		else if (y - 4 < 0 || x+1>= BOARD_X || x-1 < 0||y+1>=BOARD_Y) {
			return false;
		}
		return true;
	}


}
bool checkLevel3ShipWidth(const short board[BOARD_Y][BOARD_X], const short& y, const short& x, const short& ship, bool toLeft = false) {
	//check ship placement from coordinate 

	if (!toLeft) {
		if (board[y][x] == ship || board[y][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y][x - 1] == ship || board[y][x - 1] == ShipPerimeter || board[y][x + 1] == ship || board[y][x + 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x - 1] == ship || board[y - 1][x - 1] == ShipPerimeter || board[y + 1][x - 1] == ship || board[y + 1][x - 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x] == ship || board[y - 1][x] == ShipPerimeter || board[y + 1][x] == ship || board[y + 1][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x + 1] == ship || board[y - 1][x + 1] == ShipPerimeter || board[y + 1][x + 1] == ship || board[y + 1][x + 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y][x + 2] == ship || board[y][x + 2] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x + 2] == ship || board[y - 1][x + 2] == ShipPerimeter || board[y + 1][x + 2] == ship || board[y + 1][x + 2] == ShipPerimeter) {
			return false;
		}
		else if (board[y][x + 3] == ship || board[y][x + 3] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x + 3] == ship || board[y - 1][x + 3] == ShipPerimeter || board[y + 1][x + 3] == ship || board[y + 1][x + 3] == ShipPerimeter) {
			return false;
		}
		else if (x + 4 >= BOARD_X || y +1 >= BOARD_Y || y-1 < 0||x-1<0) {
			return false;
		}
		return true;
	}
	else {
		if (board[y][x] == ship || board[y][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y][x + 1] == ship || board[y][x + 1] == ShipPerimeter || board[y][x - 1] == ship || board[y][x - 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x + 1] == ship || board[y - 1][x + 1] == ShipPerimeter || board[y + 1][x + 1] == ship || board[y + 1][x + 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x] == ship || board[y - 1][x] == ShipPerimeter || board[y + 1][x] == ship || board[y + 1][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x - 1] == ship || board[y - 1][x - 1] == ShipPerimeter || board[y + 1][x - 1] == ship || board[y + 1][x - 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y][x - 2] == ship || board[y][x - 2] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x - 2] == ship || board[y - 1][x - 2] == ShipPerimeter || board[y + 1][x - 2] == ship || board[y + 1][x - 2] == ShipPerimeter) {
			return false;
		}
		else if (board[y][x - 3] == ship || board[y][x - 3] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x - 3] == ship || board[y - 1][x - 3] == ShipPerimeter || board[y + 1][x - 3] == ship || board[y + 1][x - 3] == ShipPerimeter) {
			return false;
		}
		else if (x - 4<0 || y+1 >= BOARD_Y || y-1 < 0||x+1>=BOARD_X) {
			return false;
		}
		return true;
	}
}
#pragma endregion level3

#pragma region level2
bool CheckLevel2ShipLeght(const short board[BOARD_Y][BOARD_X], const short& y, const short& x, const short& ship,bool toUp=false) {
	//check ship placement from coordinate 
	if (!toUp) {
		if (board[y][x] == ship || board[y][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x] == ship || board[y - 1][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x - 1] == ship || board[y - 1][x - 1] == ShipPerimeter || board[y - 1][x + 1] == ship || board[y - 1][x + 1] == ShipPerimeter) {
			return false;
		}


		else if (board[y][x + 1] == ship || board[y][x + 1] == ShipPerimeter || board[y][x - 1] == ship || board[y][x - 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y + 1][x] == ship || board[y + 1][x] == ShipPerimeter) {
			return false;
		}


		else if (board[y + 1][x - 1] == ship || board[y + 1][x - 1] == ShipPerimeter || board[y + 1][x + 1] == ship || board[y + 1][x + 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y + 2][x] == ship || board[y + 2][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y + 2][x - 1] == ship || board[y + 2][x - 1] == ShipPerimeter || board[y + 2][x + 1] == ship || board[y + 2][x + 1] == ShipPerimeter) {
			return false;
		}


		else if (y + 3 >= BOARD_Y || x+1 >= BOARD_X || x -1 < 0||y-1<0) {
			return false;
		}
		return true;
	}
	else {
		if (board[y][x] == ship || board[y][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y + 1][x] == ship || board[y + 1][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y + 1][x - 1] == ship || board[y + 1][x - 1] == ShipPerimeter || board[y + 1][x + 1] == ship || board[y + 1][x + 1] == ShipPerimeter) {
			return false;
		}


		else if (board[y][x + 1] == ship || board[y][x + 1] == ShipPerimeter || board[y][x - 1] == ship || board[y][x - 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x] == ship || board[y - 1][x] == ShipPerimeter) {
			return false;
		}


		else if (board[y - 1][x - 1] == ship || board[y - 1][x - 1] == ShipPerimeter || board[y - 1][x + 1] == ship || board[y - 1][x + 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 2][x] == ship || board[y - 2][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 2][x - 1] == ship || board[y - 2][x - 1] == ShipPerimeter || board[y - 2][x + 1] == ship || board[y - 2][x + 1] == ShipPerimeter) {
			return false;
		}


		else if (y - 3 <0 || x +1 >= BOARD_X || x-1  < 0||y+1>=BOARD_Y) {
			return false;
		}
		return true;
	}


}
bool checkLevel2ShipWidth(const short board[BOARD_Y][BOARD_X], const short& y, const short& x, const short& ship,bool toLeft=false) {
	//check ship placement from coordinate 

	if (!toLeft) {
		if (board[y][x] == ship || board[y][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y][x - 1] == ship || board[y][x - 1] == ShipPerimeter || board[y][x + 1] == ship || board[y][x + 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x - 1] == ship || board[y - 1][x - 1] == ShipPerimeter || board[y + 1][x - 1] == ship || board[y + 1][x - 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x] == ship || board[y - 1][x] == ShipPerimeter || board[y + 1][x] == ship || board[y + 1][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x + 1] == ship || board[y - 1][x + 1] == ShipPerimeter || board[y + 1][x + 1] == ship || board[y + 1][x + 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y][x + 2] == ship || board[y][x + 2] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x + 2] == ship || board[y - 1][x + 2] == ShipPerimeter || board[y + 1][x + 2] == ship || board[y + 1][x + 2] == ShipPerimeter) {
			return false;
		}

		else if (x + 3 >= BOARD_X || y+1 >= BOARD_X || y-1 < 0||x-1<0) {
			return false;
		}
		return true;
	}
	else {
		if (board[y][x] == ship || board[y][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y][x + 1] == ship || board[y][x + 1] == ShipPerimeter || board[y][x - 1] == ship || board[y][x - 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x + 1] == ship || board[y - 1][x + 1] == ShipPerimeter || board[y + 1][x + 1] == ship || board[y + 1][x + 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x] == ship || board[y - 1][x] == ShipPerimeter || board[y + 1][x] == ship || board[y + 1][x] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x - 1] == ship || board[y - 1][x - 1] == ShipPerimeter || board[y + 1][x - 1] == ship || board[y + 1][x - 1] == ShipPerimeter) {
			return false;
		}
		else if (board[y][x - 2] == ship || board[y][x - 2] == ShipPerimeter) {
			return false;
		}
		else if (board[y - 1][x - 2] == ship || board[y - 1][x - 2] == ShipPerimeter || board[y + 1][x - 2] == ship || board[y + 1][x - 2] == ShipPerimeter) {
			return false;
		}

		else if (x - 3 <0 || y+1>= BOARD_X || y-1 < 0||x+1>=BOARD_X) {
			return false;
		}
		return true;
	}
}
#pragma endregion level2



bool checkLevelOneShip(const short board[BOARD_Y][BOARD_X], const short& y, const short& x, const short& ship) {
	//check ship placement from coordinate 

	if (board[y][x] == ship || board[y][x] == ShipPerimeter) {
		return false;
	}
	else if (board[y - 1][x] == ship || board[y - 1][x] == ShipPerimeter) {
		return false;
	}
	else if (board[y - 1][x - 1] == ship || board[y - 1][x - 1] == ShipPerimeter) {
		return false;
	}
	else if (board[y - 1][x + 1] == ship || board[y - 1][x + 1] == ShipPerimeter) {
		return false;
	}
	else if (board[y][x - 1] == ship || board[y][x - 1] == ShipPerimeter) {
		return false;
	}
	else if (board[y][x+1] == ship || board[y][x+1] == ShipPerimeter) {
		return false;
	}
	else if (board[y+1][x] == ship || board[y+1][x] == ShipPerimeter) {
		return false;
	}
	else if (board[y+1][x + 1] == ship || board[y+1][x + 1] == ShipPerimeter) {
		return false;
	}
	else if (board[y+1][x - 1] == ship || board[y+1][x - 1] == ShipPerimeter) {
		return false;
	}
	else if (y >= BOARD_X || y < 0 || x >= BOARD_X || x < 0) {
		return false;
	}
	return true;
}
