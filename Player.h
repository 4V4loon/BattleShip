#pragma once
#include<string>
#include<iostream>
#include<Windows.h>
using namespace std;
//Music Player
inline void Player(const string& mod, const string& file, string Playmod = " ") {
	string pl;
	if (mod == "open") {

		pl = mod + " " + file + " " + " type mpegvideo alias mp3";
	}
	else {
		pl = mod + " " + file + " " + Playmod;
	}
	wstring plW(pl.begin(), pl.end());
	LPCWSTR finn = plW.c_str();
	mciSendString(finn, NULL, 0, NULL);

}
