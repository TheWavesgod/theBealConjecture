#pragma once

#include <iostream>
#include <string>

using namespace std;

class Int_large
{
	template<typename T>
	friend T power(T left, int right);

public:
	Int_large operator = (const Int_large& numCpy);
	Int_large operator = (int numCpy);

	Int_large operator + (const Int_large& numAdd);

	Int_large operator * (Int_large& numMul);

	bool operator == (const Int_large& numCpy);
	bool operator == (int numCpy);

	int getInt(int pos) const;

	void print();

public:
	Int_large();
	Int_large(const Int_large& numCpy);
	Int_large(int numCpy);

private:
	string Num;
};

template<typename T>
inline T power(T left, int right)
{
	T tmp = left;
	for (int i = 1; i < right; ++i)
	{
		tmp = tmp * left;
	}
	return tmp;
}
