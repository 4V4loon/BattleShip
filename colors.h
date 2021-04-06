#pragma once
#include<iostream>
#include<Windows.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
struct colors
{
	auto gold() {
		SetConsoleTextAttribute(hConsole, 14);
	}
	auto green() {
		SetConsoleTextAttribute(hConsole, 10);
	}
	auto red() {
		SetConsoleTextAttribute(hConsole, 12);

	}
	auto white() {
		SetConsoleTextAttribute(hConsole, 7);

	}
	auto blue() {
		SetConsoleTextAttribute(hConsole, 1);
	}
	auto purple() {
		SetConsoleTextAttribute(hConsole, 5);

	}
	auto opBlue() {
		SetConsoleTextAttribute(hConsole, 11);
	}

};