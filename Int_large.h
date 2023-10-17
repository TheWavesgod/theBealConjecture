#pragma once

#include <iostream>
#include <string>

using namespace std;

class Int_large
{
public:
	Int_large();

	Int_large& operator = (const Int_large& numCpy);
	Int_large& operator = (const string& numCpy);
	Int_large& operator = (unsigned long long numCpy);
	Int_large& operator = (int numCpy);

	Int_large& operator + (const Int_large& numCpy);

	void print();

private:
	string* Num;
	int length;
};

