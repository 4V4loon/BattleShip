#pragma comment(lib, "winmm.lib")


#include<iostream>
#include<Windows.h>
#include<ctime>
#include<conio.h>
#include <vector>
#include"intParser.h"
#include"colors.h"
#include<mmsystem.h>
#include"StartOverSc.h"
#include"PrintBoard.h"
#include"EssentialVars.h"
#include"randomizer.h"
#include"sequancer.h"
#include"RandomShipCreator.h"
#include"ShipCoordChecker.h"
#include <string>
#include"menuAndParams.h"
#include"Player.h"



using namespace std;

inline bool fileFoundTest(const string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

inline void cleanBoard(short board[BOARD_Y][BOARD_X]) {
	for (size_t i = 0; i < BOARD_Y; i++)
	{
		for (size_t k = 0; k < BOARD_X; k++)
		{
			board[i][k] = NULL;
		}
	}
}

short enc = 9;

void main(bool first = true) {

	if (fileFoundTest("los.bin") || fileFoundTest("win.bin")) {
		tot = true;
		if (first) {
			if (fileFoundTest("win.bin")) {
				FILE* file;
				fopen_s(&file, "win.bin", "rb");
				fread_s(&totWin, 1 * sizeof(short), sizeof(short), 1, file);
				fclose(file);
				totWin ^= enc;
			}
			if (fileFoundTest("los.bin")) {
				FILE* file;
				fopen_s(&file, "los.bin", "rb");
				fread_s(&totLose, 1 * sizeof(short), sizeof(short), 1, file);
				fclose(file);
				totLose ^= enc;

			}

		}
	}
	SetConsoleTitle(L"BATTLESHIP!");
	srand(time(0));
	if (first) {
		startScreen();

	}
	if (mus) {
		Player("open", "und.mp3");
		Player("play", "und.mp3", "repeat");
	}

	while (!confCompted) {
		mainMenu();
	}
	if (quit) {
		return;
	}
	confCompted = false;
	system("cls");
	if (autocreate) {
		CrateRandomShipSAnyValue(Level3ShipValue, Level2ShipValue, Level1ShipValue, Playerboard, PlayerShip);
	}
	CrateRandomShipSAnyValue(Level3ShipValue, Level2ShipValue, Level1ShipValue, AIboard, AIHideShip);
#pragma region BATTLE

	while (1) {
		if (Playerseqchck) {
			ScreenPlayerSeq();

		}
		else if (!Playerseqchck) {
			AIsequence(Aimode);
		}
		if (Playerscoer >= WinScore || Aiscore >= WinScore) {
			system("cls");
			break;
		}

		else {
			system("cls");

		}

	}
	if (Playerscoer >= WinScore) {
		win();
		++totWin;
		short a = totWin ^ enc;
		if (fileFoundTest("win.bin")) {
			remove("win.bin");
		}
		FILE* file;
		fopen_s(&file, "win.bin", "wb");
		fwrite(&a, sizeof(short), 1, file);
		fclose(file);
		//system("attrib +h win.bin");
		SetFileAttributes(L"win.bin", FILE_ATTRIBUTE_HIDDEN);

	}
	else if (Aiscore >= WinScore) {
		lose();
		++totLose;
		short b = totLose ^ enc;
		if (fileFoundTest("los.bin")) {
			remove("los.bin");
		}
		FILE* file1;
		fopen_s(&file1, "los.bin", "wb");
		fwrite(&b, sizeof(short), 1, file1);
		fclose(file1);
		//system("attrib +h los.bin");
		SetFileAttributes(L"los.bin", FILE_ATTRIBUTE_HIDDEN);

	}

#pragma endregion BATTLE

	Playerscoer = 0;
	Aiscore = 0;
	cleanBoard(AIboard);
	cleanBoard(Playerboard);
	Player("close", "*mp3");
	main(false);









}


