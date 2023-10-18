#include "UserIF.h"

int main(void)
{
	BNT_CreateMachine BNTMachine;

	UserIF userIF(&BNTMachine);

	userIF.mainMenu();

	return 0;
}