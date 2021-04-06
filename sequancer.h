#pragma once
#include"EssentialVars.h"
#include<iostream>
#include"PrintBoard.h"
#include"intParser.h"
#include"Player.h"
#include"randomizer.h"
//This Header file Sets the rank among the players
using namespace std;
bool soundfx = true;
bool Playerseqchck = true;
inline bool checkShipCoordinates(const short& y, const short& x, const short board[BOARD_Y][BOARD_X], const short& ship, const short hideShip = AIHideShip) {
	
	if (board[y][x] == ship || board[y][x] == hideShip) {
		return true;
	}
	else {
		return false;
	}

}

void ScreenPlayerSeq() {
	bool rand = false;
	char incld[3]{};
	short y = 0;
	short x = 0;
	boards();
	while (1) {
		cout << "\nInclude ENEMY FIELD Coordinate \"Y\" (0-" << BOARD_Y - 1 << " Between) OR include R (maybe r) hit RANDOM CORDINATE : ";
		cin >> incld;
		if (incld[0] == 'R' || incld[0] == 'r') {
			rand = true;
			y = randomizerY();
			x = randomizerX();
			break;
		}
		else {
			y = parseInt(incld);
		}

		if (y >= BOARD_Y) {
			system("cls");
			boards();
			cout << "\nPlease Include TRUE Between \"Y\" : (0-" << BOARD_Y - 1 << ") : ";
			cin >> y;
			if (y < BOARD_Y) {
				break;
			}
			system("cls");
			boards();
		}
		else {
			break;
		}

	}
	while (1) {
		if (rand) {
			break;
		}
		cout << "\nInclude ENEMY FIELD Coordinate \"X\" (0-" << BOARD_X - 1 << " Between) : ";
		cin >> x;
		if (x >= BOARD_X) {
			system("cls");
			boards();
			cout << "\nPlease Include TRUE Between \"X\" : (0-" << BOARD_X - 1 << ") : ";
			cin >> x;
			if (x < BOARD_X) {
				break;
			}
			system("cls");
			boards();
		}
		else {
			break;
		}
	}
	if (checkShipCoordinates(y, x, AIboard, AIShip)) {
		AIboard[y][x] = DestroyedShip;
		Playerseqchck = true;
		++Playerscoer;
		if (soundfx) {
			Player("open", "exp.mp3");
			Player("play", "exp.mp3","wait");
			Player("close", "exp.mp3");
		}




	}
	else if (AIboard[y][x] == DestroyedShip) {
		AIboard[y][x] = DestroyedShip;
		Playerseqchck = false;
		if (soundfx) {
			Player("open", "canon.mp3");

			Player("play", "canon.mp3","wait");
			Player("close", "canon.mp3");

		}






	}
	else {

		AIboard[y][x] = PlayerHit;
		Playerseqchck = false;
		if (soundfx) {
			Player("open", "canon.mp3");

			Player("play", "canon.mp3","wait");
			Player("close", "canon.mp3");

		}
		

	}
}
#pragma region Aiseq
short desty = -1;
short destx = -1;
short x = 0;
short y = 0;
bool rig = false;
bool lef = false;
bool up = false;
bool down = false;
short sz = BOARD_Y*BOARD_X+3;
short* hitedY = new short[sz];
short* hitedX = new short[sz];





short cont = 0;
inline void addCoordinates(const short& y, const short& x) {
	hitedY[cont] = y;
	hitedX[cont] = x;
	++cont;
}

inline bool checkHited(const short& y, const short& x) {
	for (size_t i = 0; i < sz; i++)
	{
		if (hitedY[i] == y && hitedX[i] == x) {
			return false;
		}
	}
	return true;
}
inline void easy() {
	y = randomizerY();
	x = randomizerX();
	if (checkShipCoordinates(y, x, Playerboard, PlayerShip)) {
		Playerboard[y][x] = DestroyedShip;
		Playerseqchck = false;
		++Aiscore;

	}
	else if (Playerboard[y][x] == DestroyedShip) {
		Playerboard[y][x] = DestroyedShip;
		Playerseqchck = true;

	}
	else {
		Playerboard[y][x] = AIhit;
		Playerseqchck = true;

	}
}
void normal() {
	if (!rig && !lef && !up && !down) {
		y = randomizerY();
		x = randomizerX();

		if (checkShipCoordinates(y, x, Playerboard, PlayerShip)) {
			Playerboard[y][x] = DestroyedShip;
			Playerseqchck = false;
			desty = y;
			destx = x;

			++Aiscore;
			if (y - 1 < 0) {
				down = true;
				if (x - 1 >= 0 && x + 1 < BOARD_X) {
					lef = true;
					rig = true;
				}
				else if (x - 1 >= 0 && x + 1 >= BOARD_X) {
					lef = true;
				}
				else if (x - 1 < 0 && x + 1 < BOARD_X) {
					rig = true;
				}

			}
			else if (y + 1 >= BOARD_Y) {
				up = true;
				if (x - 1 >= 0 && x + 1 < BOARD_X) {
					lef = true;
					rig = true;
				}
				else if (x - 1 >= 0 && x + 1 >= BOARD_X) {
					lef = true;
				}
				else if (x - 1 < 0 && x + 1 < BOARD_X) {
					rig = true;
				}
			}
			else {
				if (x - 1 >= 0 && x + 1 < BOARD_X) {
					lef = true;
					rig = true;
				}
				else if (x - 1 >= 0 && x + 1 >= BOARD_X) {
					lef = true;
				}
				else if (x - 1 < 0 && x + 1 < BOARD_X) {
					rig = true;
				}
				up = true;
				down = true;
			}

		}
		else if (Playerboard[y][x] == DestroyedShip) {
			Playerboard[y][x] = DestroyedShip;
			Playerseqchck = true;

		}
		else {
			Playerboard[y][x] = AIhit;
			Playerseqchck = true;

		}
	}
	else if (rig) {

		if (checkShipCoordinates(desty, destx + 1, Playerboard, PlayerShip)) {
			Playerboard[desty][destx + 1] = DestroyedShip;
			destx += 1;
			++Aiscore;

		}
		else {
			if (Playerboard[desty][destx + 1] == DestroyedShip) {
				Playerboard[desty][destx + 1] = DestroyedShip;

			}
			else {
				Playerboard[desty][destx + 1] = AIhit;


			}
			rig = false;
			Playerseqchck = true;
			desty = y;
			destx = x;
		}



	}
	else if (lef) {
		if (checkShipCoordinates(desty, destx - 1, Playerboard, PlayerShip)) {
			Playerboard[desty][destx - 1] = DestroyedShip;
			Playerseqchck = false;
			destx -= 1;
			++Aiscore;
		}
		else {
			if (Playerboard[desty][destx - 1] == DestroyedShip) {
				Playerboard[desty - 1][destx - 1] = DestroyedShip;
			}
			else {
				Playerboard[desty][destx - 1] = AIhit;

			}
			lef = false;
			Playerseqchck = true;
			desty = y;
			destx = x;
		}
	}
	else if (up) {
		if (checkShipCoordinates(desty - 1, destx, Playerboard, PlayerShip)) {
			Playerboard[desty - 1][destx] = DestroyedShip;
			Playerseqchck = false;
			desty -= 1;
			++Aiscore;
		}
		else {
			if (Playerboard[desty - 1][destx] == DestroyedShip) {
				Playerboard[desty - 1][destx] = DestroyedShip;
			}
			else {
				Playerboard[desty - 1][destx] = AIhit;

			}
			up = false;
			Playerseqchck = true;
			desty = y;
			destx = x;
		}
	}
	else if (down) {
		if (checkShipCoordinates(desty + 1, destx, Playerboard, PlayerShip)) {
			Playerboard[desty + 1][destx] = DestroyedShip;
			Playerseqchck = false;
			desty += 1;
			++Aiscore;
		}
		else {
			if (Playerboard[desty + 1][destx] == DestroyedShip) {
				Playerboard[desty + 1][destx] = DestroyedShip;
			}
			else {
				Playerboard[desty + 1][destx] = AIhit;

			}
			down = false;
			Playerseqchck = true;
			desty = y;
			destx = x;
		}
	}
}

void hard() {
	if (!rig && !lef && !up && !down) {
		while (true) {
			y = randomizerY();
			x = randomizerX();
			if (checkHited(y, x)) {
				break;
			}
		}
		if (checkShipCoordinates(y, x, Playerboard, PlayerShip)) {
			Playerboard[y][x] = DestroyedShip;
			Playerseqchck = false;
			desty = y;
			destx = x;
			addCoordinates(y, x);
			++Aiscore;
			if (y - 1 < 0) {
				down = true;
				if (x - 1 >= 0 && x + 1 < BOARD_X) {
					lef = true;
					rig = true;
				}
				else if (x - 1 >= 0 && x + 1 >= BOARD_X) {
					lef = true;
				}
				else if (x - 1 < 0 && x + 1 < BOARD_X) {
					rig = true;
				}

			}
			else if (y + 1 >= BOARD_Y) {
				up = true;
				if (x - 1 >= 0 && x + 1 < BOARD_X) {
					lef = true;
					rig = true;
				}
				else if (x - 1 >= 0 && x + 1 >= BOARD_X) {
					lef = true;
				}
				else if (x - 1 < 0 && x + 1 < BOARD_X) {
					rig = true;
				}
			}
			else {
				if (x - 1 >= 0 && x + 1 < BOARD_X) {
					lef = true;
					rig = true;
				}
				else if (x - 1 >= 0 && x + 1 >= BOARD_X) {
					lef = true;
				}
				else if (x - 1 < 0 && x + 1 < BOARD_X) {
					rig = true;
				}
				up = true;
				down = true;
			}

		}
		else if (Playerboard[y][x] == DestroyedShip) {
			Playerboard[y][x] = DestroyedShip;
			Playerseqchck = true;

		}
		else {
			Playerboard[y][x] = AIhit;
			Playerseqchck = true;
			addCoordinates(y, x);

		}
	}
	else if (rig) {

		if (checkShipCoordinates(desty, destx + 1, Playerboard, PlayerShip)) {
			Playerboard[desty][destx + 1] = DestroyedShip;
			destx += 1;
			++Aiscore;
			addCoordinates(desty, destx + 1);

		}
		else {
			
			
				Playerboard[desty][destx + 1] = AIhit;
				addCoordinates(desty, destx + 1);


			
			rig = false;
			Playerseqchck = true;
			desty = y;
			destx = x;
		}



	}
	else if (lef) {
		if (checkShipCoordinates(desty, destx - 1, Playerboard, PlayerShip)) {
			Playerboard[desty][destx - 1] = DestroyedShip;
			Playerseqchck = false;
			destx -= 1;
			++Aiscore;
			addCoordinates(desty, destx - 1);

		}
		else {


			Playerboard[desty][destx - 1] = AIhit;
			addCoordinates(desty, destx - 1);


			lef = false;
			Playerseqchck = true;
			desty = y;
			destx = x;
		}
	}
	else if (up) {
		if (checkShipCoordinates(desty - 1, destx, Playerboard, PlayerShip)) {
			Playerboard[desty - 1][destx] = DestroyedShip;
			Playerseqchck = false;
			desty -= 1;
			++Aiscore;
			addCoordinates(desty - 1, destx);

		}
		else {


			Playerboard[desty - 1][destx] = AIhit;
			addCoordinates(desty - 1, destx);


			up = false;
			Playerseqchck = true;
			desty = y;
			destx = x;
		}
	}
	else if (down) {
		if (checkShipCoordinates(desty + 1, destx, Playerboard, PlayerShip)) {
			Playerboard[desty + 1][destx] = DestroyedShip;
			Playerseqchck = false;
			desty += 1;
			++Aiscore;
			addCoordinates(desty + 1, destx);

		}
		else {


			Playerboard[desty + 1][destx] = AIhit;
			addCoordinates(desty + 1, destx);


			down = false;
			Playerseqchck = true;
			desty = y;
			destx = x;
		}
	}
	
}




inline void AIsequence(short mod = 3) {
	if (mod == 1) {
		easy();
	}
	else if (mod == 2) {
		normal();
	}
	else if (mod == 3) {
		hard();
	}
}
#pragma endregion Aiseq

