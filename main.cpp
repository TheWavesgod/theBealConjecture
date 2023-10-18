#include "UserIF.h"

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	BNT_CreateMachine* BNTMachine = (BNT_CreateMachine*)lpParameter;
	BNTMachine->createBNT();
	return 1;
}

int main(void)
{
	BNT_CreateMachine BNTMachine;

	UserIF userIF(&BNTMachine);

	DWORD dwThreadID = 0;

	HANDLE hThread = CreateThread(NULL, 0, ThreadProc, &BNTMachine, 0, &dwThreadID);

	userIF.mainMenu();

	return 0;
}