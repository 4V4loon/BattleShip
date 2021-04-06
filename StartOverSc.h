#pragma once
#include<iostream>
#include<vector>
#include<Windows.h>
#include"colors.h"
#include"Player.h"
#include"sequancer.h"
using namespace std;
inline void centerify_output(const string& str, const int& num_cols) {
	int padding_left = (num_cols / 2) - (str.size() / 2);

	for (int i = 0; i < padding_left; ++i) cout << ' ';

	cout << str;
}
inline void point(const int& count) {
	for (size_t i = 0; i < count; i++)
	{
		cout << " .";
	}
}
void startScreen(bool first = true) {
	vector<string> lines = {
		 "                                                                                                                    ",
		 "                          ()()()()()       ()()   ()()()()() ()()()()() ()           ()()()()()()                   ",
		 "                          ()       ()     ()  ()      ()         ()     ()           ()                             ",
		 "                          ()       ()    ()    ()     ()         ()     ()           ()                             ",
		 "                          ()()()()()    ()()()()()    ()         ()     ()           ()()()()()                     ",
		 "                          ()       ()  ()        ()   ()         ()     ()           ()                             ",
		 "                          ()       () ()          ()  ()         ()     ()           ()                             ",
		 "                          ()()()()() ()            () ()         ()     ()()()()()() ()()()()()()                   ",
		 "                                                                                                                    ",
		 "                                       ()()()()  ()      () () ()()()()     (*)                                     ",
		 "                                      ()      () ()      ()    ()     ()    (*)                                     ",
		 "                                      ()         ()      () () ()     ()    (*)                                     ",
		 "                                        ()()()   ()()()()() () ()()()()     (*)                                     ",
		 "                                             ()  ()      () () ()           (*)                                     ",
		 "                                     ()      ()  ()      () () ()                                                   ",
		 "                                      ()()()()   ()      () () ()           (*)                                     ",
		 "                                                                                                                    ",
	};
	if(first){
		
	colors colrs;
	for (size_t i = 1; i <= 5; i++)
	{


		SetConsoleTextAttribute(hConsole, i + 2);

		
		int num_cols = 100;

		cout << endl;
		for (int i = 0; i < num_cols; ++i)cout << " ";
		cout << endl;

		for (int i = 0; i < lines.size(); ++i) {
			centerify_output(lines[i], num_cols);
			cout << endl;
		}

		cout << endl;
		for (int i = 0; i < num_cols; ++i)cout << ' ';
		cout << endl;
		cout << endl;
		cout << endl;

		cout << "\t\t\tLOADING .";
		point(i);
		Sleep(700);
		system("cls");
	}
	}
	else {
		
		int num_cols = 100;

		

		for (int i = 0; i < lines.size(); ++i) {
			centerify_output(lines[i], num_cols);
			cout << endl;
		}

	}

	
}

void win() {
	Player("stop", "und.mp3");

	colors colrs;
	colrs.green();
	


		vector<string> lines = {
		 "+------------------------------------------------------------------------------------------+",
		 "                                                                                            ",
		 "                                                                                            ",
		 "                                                                                            ",
		 "                                                                                            ",
		 "                   ()            () ()() ()()      ()        ()()                           ",
		 "                   ()     ()     ()  ()  () ()     ()         ()                            ",
		 "                   ()    ()()    ()      ()  ()    ()        ()()                           ",
		 "                   ()   ()  ()   ()  ()  ()   ()   ()         ()                            ",
		 "                   ()  ()    ()  ()  ()  ()    ()  ()        ()()                           ",
		 "                   () ()      () ()  ()  ()     () ()                                       ",
		 "                   ()()        ()()  ()  ()      ()()         ()                            ",
		 "                                                                                            ",
		 "                                                                                            ",
		 "                                                                                            ",
		 "                                                                                            ",
		 "+------------------------------------------------------------------------------------------+",

		};
		int num_cols = 100;
		cout << endl;
		for (int i = 0; i < num_cols; ++i)cout << " ";
		cout << endl;
		for (int i = 0; i < lines.size(); ++i) {
			centerify_output(lines[i], num_cols);
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < num_cols; ++i)cout << ' ';
		cout << endl;
		if (soundfx) {
			Player("open", "win.mp3");
			Player("play", "win.mp3");

		}
		system("pause");
		system("cls");
}

void lose() {
	Player("stop", "und.mp3");
	colors colrs;
	colrs.red();
	vector<string> lines = {
	 "+--------------------------------------------------------------------------------------------------------------------+",
	 "                                                                                                                     ",
	 "                                                                                                                     ",
	 "                                                                                                                     ",
	 "                                                                                                                     ",
	 "                                    ()             (()()()()()))         ()()()()    ()()()()()()                    ",
	 "                                    ()            ()           ()       ()      ()   ()                              ",
	 "                                    ()           ()             ()      ()           ()                              ",
	 "                                    ()          ()               ()       ()()()     ()()()()                        ",
	 "                                    ()           ()             ()             ()    ()                              ",
	 "                                    ()            ()           ()      ()      ()    ()                              ",
	 "                                    ()()()()()     ()()()()()())        ()()()()     ()()()()()()                    ",
	 "                                                                                                                     ",
	 "                                                                                                                     ",
	 "                                                                                                                     ",
	 "                                                                                                                     ",
	 "+-------------------------------------------------------------------------------------------------------------------+",

	};
	int num_cols = 100;
	cout << endl;
	for (int i = 0; i < num_cols; ++i)cout << " ";
	cout << endl;
	for (int i = 0; i < lines.size(); ++i) {
		centerify_output(lines[i], num_cols);
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < num_cols; ++i)cout << ' ';
	cout << endl;
	if (soundfx) {
		Player("open", "lose.mp3");

		Player("play", "lose.mp3");
	}

	system("pause");
	system("cls");
}