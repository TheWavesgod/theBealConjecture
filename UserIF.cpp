#include "UserIF.h"

void UserIF::mainMenu()
{
	string userInput;

	initMainMenu();

	while (1)
	{
		cout << endl;
		setTextColor(RED);
		cout << User;
		setTextColor(WHITE);
		cin >> userInput;
		cout << endl;
		int flag = reactToInputMainMenu(handleInput(userInput));
		if (flag == 0)
		{
			break;
		}
	}

}

UserIF::UserIF(BNT_CreateMachine* BNTMachine)
{
	this->BNTMachine = BNTMachine;
}

void UserIF::initMainMenu()
{
	setTextColor(BLUE);
	cout << BCSystem << endl;
	setTextColor(WHITE);
	cout << "Main Menu" << endl;
	setTextColor(YELLOW);
	cout << Questions1 << endl;
	cout << Questions2 << endl;
	cout << Questions3 << endl;
	cout << Questions4 << endl;
	cout << Questions5 << endl;
	cout << Questions6 << endl;
	cout << Questions7 << endl;
	cout << Questions8 << endl;
	cout << endl;
	printMainTip();
}

void UserIF::printMainTip()
{
	setTextColor(WHITE);
	cout << MainTip<<endl;
}

void UserIF::setTextColor(text_color color)
{
	switch (color)
	{
	case WHITE:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
		break;
	}
	case RED:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		break;
	}
	case GREEN:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		break;
	}
	case BLUE:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		break;
	}
	case YELLOW:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY| FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	}
	}
}

int UserIF::handleInput(string& input)
{
	if (input.compare("0") == 0)
		return 0;
	if (input.compare("1") == 0)
		return 1;
	if (input.compare("2") == 0)
		return 2;
	if (input.compare("3") == 0)
		return 3;
	if (input.compare("4") == 0)
		return 4;
	if (input.compare("5") == 0)
		return 5;
	if (input.compare("6") == 0)
		return 6;
	if (input.compare("7") == 0)
		return 7;
	if (input.compare("8") == 0)
		return 8;
	if (input.compare("9") == 0)
		return 9;
	return 10;
}

int UserIF::reactToInputMainMenu(const int& input)
{
	switch (input)
	{
	case 1:
	{
		answerQ1();
		break;
	}
	case 2:
	{
		answerQ2();
		break;
	}
	case 3:
	{
		answerQ3();
		break;
	}
	case 4:
	{
		answerQ4();
		break;
	}
	case 5:
	{
		answerQ5();
		break;
	}
	case 6:
	{
		answerQ6();
		break;
	}
	case 7:
	{
		answerQ7();
		break;
	}
	case 8:
	{
		answerQ8();
		break;
	}
	case 9:
	{
		initMainMenu();
		break;
	}
	default:
		return input;
	}
}

void UserIF::answerQ1()
{
	setTextColor(BLUE);
	cout << BCSystem << endl;
	setTextColor(YELLOW);
	BNTMachine->AnswerToQuestion1();
}

void UserIF::answerQ2()
{
	setTextColor(BLUE);
	cout << BCSystem << endl;
	setTextColor(YELLOW);
	BNTMachine->AnswerToQuestion2();
}

void UserIF::answerQ3()
{
}

void UserIF::answerQ4()
{
	setTextColor(BLUE);
	cout << BCSystem << endl;
	setTextColor(YELLOW);
	BNTMachine->AnswerToQuestion4();
	cout << "outputs to file completed";
	cout << endl;
}

void UserIF::answerQ5()
{
	setTextColor(BLUE);
	cout << BCSystem << endl;
	setTextColor(YELLOW);
	BNTMachine->AnswerToQuestion5();
}

void UserIF::answerQ6()
{
}

void UserIF::answerQ7()
{
}

void UserIF::answerQ8()
{
}
