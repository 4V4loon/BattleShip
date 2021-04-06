#pragma once
#include<iostream>
#include<Windows.h>
#include"EssentialVars.h"
using namespace std;


void AIBoardPrint() {
	short s = 0;
	cout << "    ";


	for (size_t i = 0; i < BOARD_X; i++)
	{
		if (s <= 9) {
			cout << s << "  ";
			++s;
		}
		else {
			cout << s << " ";
			if (s == BOARD_X - 1) {
				col.gold();
				cout << "  <- X";
				col.white();
			}
			++s;
		}
	}
	s = 0;
	cout << endl;
	for (size_t i = 0; i < BOARD_Y; i++)
	{
		if (i <= 9) {
			cout << s << "  ";
			++s;
		}
		else {
			cout << s << " ";
			++s;
		}
		for (size_t k = 0; k < BOARD_X; k++)
		{


			if (AIboard[i][k] == PlayerHit) {
				PLhit();

			}
			else if (AIboard[i][k] == AIShip) {
				ship();
			}

			else if (AIboard[i][k] == DestroyedShip) {
				DestroyedShp();

			}
			else {
				aiField();
			}
			if (i == BOARD_Y / 2 - 1 && k == BOARD_X - 1) {
				col.red();
				cout << "\t\t\t\t\t\tENEMY SCORE ==> " << Aiscore;
				col.white();

			}

		}
		cout << endl;
	}
	col.red();
	cout << " \nY\n";
	col.white();
}




void PlayerBoardPrint(bool manual = false) {
	
	if (!manual) {
		for (size_t i = 0; i < BOARD_Y; i++)
		{
			cout << "  ";

			for (size_t k = 0; k < BOARD_X; k++)
			{



				if (Playerboard[i][k] == PlayerShip) {
					ship();
				}

				else if (Playerboard[i][k] == AIhit) {
					Aihit();

				}
				else if (Playerboard[i][k] == DestroyedShip) {
					DestroyedShp();
				}

				else {
					PLfield();
				}

				if (i == BOARD_Y / 2 - 1 && k == BOARD_X - 1) {
					col.green();
					cout << "\t\t\t\t\t\tYOUR SCORE ==> " << Playerscoer;
					col.white();

				}

			}
			cout << endl;
		}
	}
	else {



		short s = 0;
		cout << "    ";

		for (size_t i = 0; i < BOARD_X; i++)
		{
			if (s <= 9) {
				cout << s << "  ";
				++s;
			}
			else {
				cout << s << " ";
				if (s == BOARD_X - 1) {
					col.gold();
					cout << "  <- X";
					col.white();
				}
				++s;
			}
		}
		cout << endl;

		s = 0;
		for (size_t i = 0; i < BOARD_Y; i++)
		{

			if (i <= 9) {
				cout << s << "  ";
				++s;
			}
			else {
				cout << s << " ";
				++s;
			}


			for (size_t k = 0; k < BOARD_X; k++)
			{



				if (Playerboard[i][k] == PlayerShip) {
					ship();
				}

				else if (Playerboard[i][k] == AIhit) {
					Aihit();

				}
				else if (Playerboard[i][k] == DestroyedShip) {
					DestroyedShp();
				}

				else if (Playerboard[i][k] == ShipPerimeter) {
					shipPerm();

				}

				else {
					PLfield();
				}


			}
			cout << endl;
		}
	col.red();
	cout << " \nY\n";
	col.white();
	}
}


inline void boards() {
	colors clos;
	clos.red();
	cout << "ENEMY FIELD \n";
	clos.white();
	AIBoardPrint();
	clos.green();
	cout << "\nYOUR FIELD \n";
	clos.white();
	PlayerBoardPrint(false);
}