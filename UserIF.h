#pragma once

#include "windows.h"
#include "BNT_CreateMachine.h"

typedef enum 
{
	WHITE = 0,
	RED,
	GREEN,
	BLUE,
	YELLOW,
	PINK
}text_color;

class UserIF
{
public:
	void mainMenu();

public:
	UserIF(BNT_CreateMachine* BNTMachine);

private:
	void initMainMenu();
	void printMainTip();

	void setTextColor(text_color color);

	int reactToInputMainMenu(const int& input);
	void answerQ1();
	void answerQ2();
	void answerQ3();
	void answerQ4();
	void answerQ5();
	void answerQ6();
	void answerQ7();
	void answerQ8();

private:

	BNT_CreateMachine* BNTMachine;

	const string BCSystem = "$ The Beal Conjecture System: ";
	const string User = "$ User: ";

	const string Questions1 = "Q1: find the first five distinct, lowest BNTs";
	const string Questions2 = "Q2: find the first five distinct BNTs that are prime numbers";
	const string Questions3 = "Q3: find BNTs where A, B, and C are within the range of 3 to 20, and x, y, and z are within the scope of 3 to 15.";
	const string Questions4 = "Q4: write and read outputs to file.";
	const string Questions5 = "Q5: find the first ten distinct BNTs that are composite numbers.";
	const string Questions6 = "Q6: find the BNTs that are square numbers between 1000 and 100000.";
	const string Questions7 = "Q7: generate an ASCII represented histogram of BNT occurrence";
	const string Questions8 = "Q8: Find the highest BNT";

	const string MainTip = "Tip: Enter a command and press Enter. Input a number from 1 to 8 to display the corresponding answer. Enter 9 to show the main menu again, and 0 to exit the program. ";

};

