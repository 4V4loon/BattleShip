#pragma once
#include<iostream>
#include<string>
#include"colors.h"
#include"StartOverSc.h"
#include"PrintBoard.h"
#include"RandomShipCreator.h"
#include<conio.h>
#include"Player.h"
#include"sequancer.h"
using namespace std;
bool quit = false;
bool mus = true;
bool tot = false;
bool autocreate = true;
bool confCompted = false;
short menuSize = 5;
short colm = 2;
short sel = 0;
bool back = false;
string* menu = new string[menuSize];

void mainMenu();
inline void tabs(const short& value) {
	//Just print tab by value
	for (size_t i = 0; i < value; i++)
	{
		cout << "\t";
	}
}

inline void ConsMiddlePrint(string* text, const short& colmn, const short& menuParams) {
	//Print BattleShip word and menu parametries


	for (size_t i = 0; i < colmn; i++)
	{
		cout << endl;
	}
	tabs(6);

	for (size_t i = 0; i < menuParams; i++)
	{
		SetConsoleTextAttribute(hConsole, i + 1);
		cout << text[i];
		cout << endl;
		tabs(6);
	}
	colors cols;
	cols.white();
}
inline void controlMainMenuParametries() {

	if (tot) {
		++menuSize;
		menu = new string[menuSize];

		menu[4] = "[5] Statisks";
		menu[5] = "[6] Exit";
	}
	else {
		tot = false;
		menu[4] = "[5] Exit";

	}
	menu[0] = "[1] Play GaMe";
	if (mus) {
		menu[1] = "[2] MUSIC OFF";
	}
	else {
		menu[1] = "[2] MUSIC ON";
	}
	if (soundfx) {
		menu[2] = "[3] Sound Effect OFF";
	}
	else {
		menu[2] = "[3] Sound Effect ON";

	}
	menu[3] = "[4] Rules and About";



	/*while (true) {

		if (sel == 2) {
			if (mus) {
				mus = false;
				Player("stop", "und.mp3");
				menu[1] = "[2] MUSIC ON";
				system("cls");
				sel = Select(menu, colm, menuSize);

			}
			else {
				mus = true;
				Player("play", "und.mp3", "repeat");
				menu[1] = "[2] MUSIC OFF";
				system("cls");
				sel = Select(menu, colm, menuSize);
			}
		}
		else if (sel == 4) {
			RulesAbout();

			sel = Select(menu, colm, menuSize);

		}
		else if (sel == 1) {
			ShipCreateMenu();
			system("cls");
			EnemyMode();
			system("cls");
			break;
		}
		else if (sel == 5&&tot) {
			system("cls");
			string* stas = new string[4];
			stas[0] = "Player Total Winned : "+ to_string(totWin);
			stas[1] = "ENEMY Total Winned : " + to_string(totLose);
			stas[2] = "[1] Clear All Statisks";
			stas[3] = "[2] Back";
			short sts = Select(stas, 2, 4);
			if (sts == 1) {
				totWin = 0;
				totLose = 0;
				remove("win.bin");
				remove("los.bin");
				system("cls");

				tot = false;
				break;
			}
			else if (sts == 2) {
				system("cls");
				sel = Select(menu, colm, menuSize);

			}
		}
		else if (sel == 6 && tot) {
			system("cls");
			string bye = "BYE!";
			ConsMiddlePrint(&bye, colm, 1);
			quit = true;
			break;
		}
		else if (sel == 5 && !tot) {
			system("cls");
			string bye = "BYE!";
			ConsMiddlePrint(&bye, colm, 1);
			quit = true;
			break;
		}
		else if (sel == 3) {
			if (soundfx) {
				soundfx = false;
				menu[2] = "[3] Sound Effect ON";
				system("cls");
				sel = Select(menu, colm, menuSize);
			}
			else {
				soundfx = true;
				menu[2] = "[3] Sound Effect OFF";
				system("cls");
				sel = Select(menu, colm, menuSize);

			}
		}

		else {
			system("cls");
			Menu();
			break;
		}

	}*/
}
inline short& Select(string* text, const short& colmn, const short& menParmsValue) {
	//in the menu parametries selected index return
	colors cols;
	cols.red();
	startScreen(false);
	cols.white();
	ConsMiddlePrint(text, colmn, menParmsValue);
	cout << endl;
	tabs(4);
	short selc = 0;
	cout << "Select : ";
	cin >> selc;
	return selc;
}




void Statisks() {
	system("cls");
	string* stas = new string[4];
	stas[0] = "Player Total Winned : " + to_string(totWin);
	stas[1] = "ENEMY Total Winned : " + to_string(totLose);
	stas[2] = "[1] Clear All Statisks";
	stas[3] = "[2] Back";
	short sts = Select(stas, 2, 4);
	if (sts == 1) {
		totWin = 0;
		totLose = 0;
		remove("win.bin");
		remove("los.bin");
		system("cls");

		tot = false;
	}
	system("cls");
}





void qtscreen() {
	system("cls");
	string bye = "BYE!";
	ConsMiddlePrint(&bye, colm, 1);
	quit = true;
	confCompted = true;
}


inline void EnemyMode() {
	//Select Enemy mode
	system("cls");
	string* enemymenu = new string[5];
	enemymenu[0] = "Select Artificial Intelligence thinking Mode : ";
	enemymenu[1] = "[1] Stupid";
	enemymenu[2] = "[2] Normal";
	enemymenu[3] = "[3] GENIUS";
	enemymenu[4] = "[4] Back Main Menu";

	Aimode = Select(enemymenu, 2, 5);
	if (Aimode == 4) {
		Aimode = 1;
		back = true;
		system("cls");
		return;

	}
	if (Aimode > 4 || Aimode <= 0) {
		EnemyMode();
		return;
	}

}


void CreateManualSips() {
	//Manual Create Ship Interface menu
	system("cls");
	enum DirectionKey {
		UP = 72, DOWN = 80, RIGHT = 77, LEFT = 75
	};

	short l3 = 0;
	short l2 = 0;
	short l1 = 0;
	short y = -1;
	short x = -1;
	while (true) {
		PlayerBoardPrint(true);
		if (l3 != Level3ShipValue) {
			cout << "Level 3 Ships in STOCK : " << Level3ShipValue - l3;
		}
		else if (l2 != Level2ShipValue) {
			cout << "Level 2 Ships in STOCK : " << Level2ShipValue - l2;

		}
		else if (l1 != Level1ShipValue) {
			cout << "Level 1 Ships in STOCK : " << Level1ShipValue - l1;

		}
		else {
			break;
		}

		while (1) {
			cout << "\nInclude \"Y\" (0-" << BOARD_Y - 1 << " Between) : ";
			cin >> y;
			if (y >= BOARD_Y) {
				system("cls");
				PlayerBoardPrint(true);
				cout << "\nPlease Include TRUE Between \"Y\" : (0-" << BOARD_Y - 1 << ") : ";
				cin >> y;
				if (y < BOARD_Y) {
					break;
				}
				system("cls");
				PlayerBoardPrint(true);

			}
			else {
				break;
			}

		}
		while (1) {

			cout << "\nInclude Coordinate \"X\" (0-" << BOARD_X - 1 << " Between) : ";
			cin >> x;
			if (x >= BOARD_X) {
				system("cls");
				PlayerBoardPrint(true);

				cout << "\nPlease Include TRUE Between \"X\" : (0-" << BOARD_X - 1 << ") : ";
				cin >> x;
				if (x < BOARD_X) {
					break;
				}
				system("cls");
				PlayerBoardPrint(true);

			}
			else {
				break;
			}
		}
		if (l2 != Level2ShipValue || l3 != Level3ShipValue) {

			cout << "Select Ship Direction Using Arrow Keys : ";
			short click = _getch();
			if (click == 224) {
				click = _getch();
				if (click == UP) {
					if (l3 != Level3ShipValue && checkLevel3ShipLeght(Playerboard, y, x, PlayerShip, true)) {
						CreateRandomLevel3ShipLeght(Playerboard, PlayerShip, false, y, x, true);
						++l3;
					}
					else if (l2 != Level2ShipValue && CheckLevel2ShipLeght(Playerboard, y, x, PlayerShip, true)) {
						CreateRandomLevel2ShipLeght(Playerboard, PlayerShip, false, y, x, true);
						++l2;
					}

				}
				else if (click == DOWN) {
					if (l3 != Level3ShipValue && checkLevel3ShipLeght(Playerboard, y, x, PlayerShip, false)) {
						CreateRandomLevel3ShipLeght(Playerboard, PlayerShip, false, y, x, false);
						++l3;
					}
					else if (l2 != Level2ShipValue && CheckLevel2ShipLeght(Playerboard, y, x, PlayerShip, false)) {
						CreateRandomLevel2ShipLeght(Playerboard, PlayerShip, false, y, x, false);
						++l2;
					}
				}
				else if (click == LEFT) {
					if (l3 != Level3ShipValue && checkLevel3ShipWidth(Playerboard, y, x, PlayerShip, true)) {
						CreateRandomLevel3ShipWidth(Playerboard, PlayerShip, false, y, x, true);
						++l3;
					}
					else if (l2 != Level2ShipValue && checkLevel2ShipWidth(Playerboard, y, x, PlayerShip, true)) {
						CreateRandomLevel2ShipWidth(Playerboard, PlayerShip, false, y, x, true);
						++l2;
					}

				}
				else if (click == RIGHT) {
					if (l3 != Level3ShipValue && checkLevel3ShipWidth(Playerboard, y, x, PlayerShip, false)) {
						CreateRandomLevel3ShipWidth(Playerboard, PlayerShip, false, y, x, false);
						++l3;
					}
					else if (l2 != Level2ShipValue && checkLevel2ShipWidth(Playerboard, y, x, PlayerShip, false)) {
						CreateRandomLevel2ShipWidth(Playerboard, PlayerShip, false, y, x, false);
						++l2;
					}
				}
			}

		}
		else {
			if (checkLevelOneShip(Playerboard, y, x, PlayerShip)) {
				CreateRandomLevelOneShip(Playerboard, PlayerShip, false, y, x);
				++l1;
			}
		}
		system("cls");

	}
	system("cls");

}
void RulesAbout() {
	//Rules and about menu
	system("cls");
	tabs(5);
	colors clos;
	clos.red();
	cout << "Welcome BattleShip Game!\n" << endl;
	clos.white();
	cout << "The purpose of this game is to blow up the enemy's ships! Each ship's digit is a point. Earning points is " << WinScore << "." << endl;
	cout << "On both sides " << Level3ShipValue << " value level 3 Ships, " << Level2ShipValue << " value level 2 Ships, " << Level1ShipValue << " value level 1 Ships avalable." << endl;
	cout << "You can arrange your own ships by manual or randomly!" << endl;
	cout << endl << endl << endl;
	tabs(3);
	ship();
	cout << "  <== This Ship Digit" << endl;
	tabs(3);
	PLfield();
	cout << "  <== This Your Field" << endl;
	tabs(3);
	Aihit();
	cout << "  <== This Enemy Hited Your Field Digit" << endl;
	tabs(3);
	shipPerm();
	cout << "  <== This Ship Perimeter" << endl;
	tabs(3);
	DestroyedShp();
	cout << "  <== This Destroyed Ship" << endl << endl;
	tabs(3);
	aiField();
	cout << "  <== This Enemy Field" << endl;
	tabs(3);
	PLhit();
	cout << "  <== This Your Hited Enemy Field\n" << endl;
	cout << "There are 3 enemy difficulty levels : " << endl;
	tabs(2);
	cout << "[1] Stupid : The enemy always randomly chooses where to hit." << endl;
	tabs(2);
	cout << "[2] Normal : If there is a ship where it hit, hit the sides of it." << endl;
	tabs(2);
	cout << "[3] Genius : The enemy will remember where they hit each time and never hit the same place again. \n\t\t\t(Sometimes it slows down game because of thinking too much :D)" << endl << endl << endl;

	system("pause");
	system("cls");

}

void ShipCreateMenu() {
	//Ship create auto or manual mode select menu
	system("cls");
	string* ShipCreateMenuWord = new string[4];
	ShipCreateMenuWord[0] = "Select Create Your Ships Mode : ";
	ShipCreateMenuWord[1] = "[1] Manual";
	ShipCreateMenuWord[2] = "[2] Auto";
	ShipCreateMenuWord[3] = "[3] Back To Main Menu";
	short Selected = Select(ShipCreateMenuWord, 4, 4);
	if (Selected == 1) {
		autocreate = false;
		CreateManualSips();
		system("cls");
		return;
	}
	else if (Selected == 2) {
		autocreate = true;
		system("cls");

		return;
	}
	else if (Selected == 3) {
		back = true;
		system("cls");
		return;

	}
	else {
		ShipCreateMenu();
		return;
	}

}


void mainMenu() {
	system("cls");
	controlMainMenuParametries();
	sel = Select(menu, colm, menuSize);
	if (sel == 1) {
		ShipCreateMenu();
		if (back) {
			back = false;
			return;
		}
		EnemyMode();
		if (back) {
			back = false;
			return;
		}
		confCompted = true;
	}
	else if (sel == 2) {
		if (mus) {
			mus = false;
			Player("stop", "und.mp3");
		}
		else {
			mus = true;
			Player("play", "und.mp3");

		}
	}
	else if (sel == 3) {
		if (soundfx) {
			soundfx = false;
		}
		else {
			soundfx = true;

		}
	}
	else if (sel == 4) {
		RulesAbout();
	}
	else if (sel == 5) {
		if (tot) {
			Statisks();
		}
		else {
			qtscreen();
			return;
		}

	}
	else if (sel == 6 && tot) {
		qtscreen();
		return;
	}
	system("cls");
}