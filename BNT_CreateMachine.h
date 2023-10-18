#pragma once

#include "Int_large.h"

#include <cmath>
#include <list>

struct BNT_num
{
	unsigned BNT;
	unsigned A;
	unsigned B;
	unsigned C;
	unsigned x;
	unsigned y;
	unsigned z;

	BNT_num(unsigned A, unsigned B, unsigned C, unsigned x, unsigned y, unsigned z)
	{
		this->A = A;
		this->B = B;
		this->C = C;
		this->x = x;
		this->y = y;
		this->z = z;
		this->BNT = A + B + C + x + y + z;
	}
};

class BNT_CreateMachine
{
public:
	void AnswerToQuestion1();
	void AnswerToQuestion2();
	void AnswerToQuestion3();
	void AnswerToQuestion4();
	void AnswerToQuestion5();
	void AnswerToQuestion6();
	void AnswerToQuestion7();
	void AnswerToQuestion8();
	
public:
	void createBNT();
	
	void printBNTs();

	template<typename T>
	friend bool checkBealConjecture(T A, T B, T C, int x, int y, int z);

private:
	list<BNT_num> BNTs;

private:
	inline void printBNT(const BNT_num& num);

	inline void insertBNTs(const BNT_num& bnt);

	bool isPrime(const unsigned& num);

};

template<typename T>
inline bool checkBealConjecture(T A, T B, T C, int x, int y, int z)
{
	return power<T>(A, x) + power<T>(B, y) == power<T>(C, z);
}
