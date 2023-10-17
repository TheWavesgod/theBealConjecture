#pragma once

#include <iostream>
#include <string>

using namespace std;

class Int_large
{
public:
	Int_large();
	Int_large(const Int_large& numCpy);
	Int_large(unsigned long long numCpy);
	Int_large(int numCpy);

	Int_large& operator = (const Int_large& numCpy);
	Int_large& operator = (const string& numCpy);
	Int_large& operator = (unsigned long long numCpy);
	Int_large& operator = (int numCpy);

	Int_large& operator + (const Int_large& numAdd);

	Int_large& operator * (Int_large& numMul);

	bool operator == (int numCpy);

	int getInt(int pos) const;

	void print();
	void updateLength();

private:
	string* Num;
	int length;

private:
};

