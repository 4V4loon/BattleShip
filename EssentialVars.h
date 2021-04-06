#pragma once
#include"colors.h"
#define AIShip 3     //JUST DEBUGING
#define PlayerShip 4 //PlayerShip board number
#define Field 0      //Field board number
#define DestroyedShip 5 //destroyed Ship Number
#define PlayerHit 1   //Player hited Number
#define AIhit 2       //ai hited number
#define AIHideShip 7  //ai hidet ship
#define BOARD_Y 14    
#define BOARD_X 14
#define ShipPerimeter 8 
#define Level3ShipValue 2
#define Level2ShipValue 2
#define Level1ShipValue 2
short AIboard[BOARD_Y][BOARD_X];
short Playerboard[BOARD_Y][BOARD_X] = {};
static short WinScore = (Level3ShipValue * 3) + (Level2ShipValue * 2) + Level1ShipValue;
static short Aiscore = 0;
static short Playerscoer = 0;

short totLose = 0;
short totWin = 0;



colors col;
inline void ship() {
	col.gold();
	cout << "[" << (char)254 << "]";
	col.white();
}
inline void DestroyedShp() {
	col.red();
	cout << "[" << (char)254 << "]";
	col.white();
}
inline void Aihit() {
	col.opBlue();
	cout << "[" << (char)254 << "]";
	col.white();
}
inline void PLhit() {
	col.green();
	cout << "[" << (char)254 << "]";
	col.white();
}
inline void PLfield() {
	col.blue();
	cout << "[" << (char)254 << "]";
	col.white();
}
inline void aiField() {
	col.purple();
	cout << "[" << (char)254 << "]";
	col.white();
}
inline void shipPerm() {
	col.white();
	cout << "[" << (char)254 << "]";
	col.white();
}