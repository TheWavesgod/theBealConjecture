#pragma once

#include <string>

using namespace std;

class Int_large
{
public:
	Int_large& operator = (const Int_large& numCpy);
	Int_large& operator = (const string& numCpy);
	Int_large& operator = (const unsigned long long& numCpy);

private:
	string* Num;
	int length;

};

