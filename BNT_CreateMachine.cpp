#include "BNT_CreateMachine.h"

void BNT_CreateMachine::AnswerToQuestion1()
{
	int lastBNT = 0;
	int times = 0;
	for (const auto& n : BNTs)
	{
		if (n.BNT != lastBNT)
		{
			printBNT(n);
			++times;
			lastBNT = n.BNT;
		}
		if (times >= 5)
		{
			break;
		}
	}
}

void BNT_CreateMachine::AnswerToQuestion2()
{
	int lastBNT = 0;
	int times = 0;
	for (const auto& n : BNTs)
	{
		if (isPrime(n.BNT))
		{
			if (n.BNT != lastBNT)
			{
				printBNT(n);
				++times;
				lastBNT = n.BNT;
			}
		}
		if (times >= 5)
		{
			break;
		}
	}
}

void BNT_CreateMachine::AnswerToQuestion3()
{
	for (const auto& n : BNTs)
	{
		if (n.A != 2 && n.B != 2 && n.C != 2)
		{
			printBNT(n);
		}
	}
}

void BNT_CreateMachine::AnswerToQuestion4()
{
	ofstream ofs;	
	ofs.open("Answer4.txt", ios::out);

	ofs << "Question 1: " << endl << endl;
	int lastBNT = 0;
	int times = 0;
	for (const auto& n : BNTs)
	{
		if (n.BNT != lastBNT)
		{
			writeBNT(n, ofs);
			++times;
			lastBNT = n.BNT;
		}
		if (times >= 5)
		{
			break;
		}
	}

	ofs << "Question 2: " << endl << endl;
	lastBNT = 0;
	times = 0;
	for (const auto& n : BNTs)
	{
		if (isPrime(n.BNT))
		{
			if (n.BNT != lastBNT)
			{
				writeBNT(n, ofs);
				++times;
				lastBNT = n.BNT;
			}
		}
		if (times >= 5)
		{
			break;
		}
	}

	ofs << "Question 3: " << endl << endl;
	for (const auto& n : BNTs)
	{
		if (n.A != 2 && n.B != 2 && n.C != 2)
		{
			writeBNT(n, ofs);
		}
	}
}

void BNT_CreateMachine::AnswerToQuestion5()
{
	int lastBNT = 0;
	int times = 0;
	for (const auto& n : BNTs)
	{
		if (isPrime(n.BNT) == false)
		{
			if (n.BNT != lastBNT)
			{
				printBNT(n);
				++times;
				lastBNT = n.BNT;
			}
		}
		if (times >= 10)
		{
			break;
		}
	}
}

void BNT_CreateMachine::AnswerToQuestion6()
{

}

void BNT_CreateMachine::AnswerToQuestion7(const int& min, const int& max)
{
	vector<BNT_frqny> data;
	int lastBNT = 0;
	int times = 0;
	for (const auto& n : BNTs)
	{
		if (n.BNT >= min && n.BNT <= max)
		{
			if (n.BNT == lastBNT)
			{
				++times;
			}
			else
			{
				if (lastBNT != 0)
				{
					BNT_frqny tmp(lastBNT, times);
					data.push_back(tmp);
				}
				lastBNT = n.BNT;
				times = 1;
			}
		}
	}
	Tabulator tbltr(data);
	tbltr.drawGram();
}

void BNT_CreateMachine::AnswerToQuestion8()
{

}

void BNT_CreateMachine::createBNT()
{
	int limitLeft = 20;
	int limitRight = 15;
	for (int A = 2; A <= limitLeft; ++A)
	{
		for (int B = A; B <= limitLeft; ++B)
		{
			for (int C = 2; C <= limitLeft; ++C)
			{
				for (int x = 3; x <= limitRight; ++x)
				{
					for (int y = 3; y <= limitRight; ++y)
					{	
						for (int z = 3; z <= limitRight; ++z)
						{
							long long A1, B1, C1;
							A1 = A;
							B1 = B;
							C1 = C;
							if (checkBealConjecture(A1, B1, C1, x, y, z) == true)
							{
								BNT_num tmp(A, B, C, x, y, z);
								insertBNTs(tmp);
							}
						}
					}
				}
			}
		}
	}

	/*limitLeft = 20;
	limitRight = 100;
	for (int A = 1; A <= limitLeft; ++A)
	{
		for (int B = A; B <= limitLeft; ++B)
		{
			for (int C = B; C <= limitLeft; ++C)
			{
				for (int x = 16; x <= limitRight; ++x)
				{
					for (int y = 16; y <= limitRight; ++y)
					{
						for (int z = 16; z <= limitRight; ++z)
						{
							Int_large A1, B1, C1;
							A1 = A;
							B1 = B;
							C1 = C;
							if (checkBealConjecture(A1, B1, C1, x, y, z) == true)
							{
								BNT_num tmp(A, B, C, x, y, z);
								insertBNTs(tmp);
							}
						}
					}
				}
			}
		}
	}*/
}

void BNT_CreateMachine::printBNTs()
{
	for (const auto& num : BNTs)
	{
		printBNT(num);
	}
}

void BNT_CreateMachine::printBNT(const BNT_num& num)
{
	cout << num.BNT << ": " << num.A << ", " << num.x << ", ";
	cout << num.B << ", " << num.y << ", " << num.C << ", " << num.z;
	cout << endl;
}

inline void BNT_CreateMachine::writeBNT(const BNT_num& num, ofstream& ofs)
{
	ofs << num.BNT << ": " << num.A << ", " << num.x << ", ";
	ofs << num.B << ", " << num.y << ", " << num.C << ", " << num.z;
	ofs << endl;
	ofs << endl;
}

void BNT_CreateMachine::insertBNTs(const BNT_num& bnt)
{
	bool flag = false;
	for (auto itr = BNTs.begin(); itr != BNTs.end(); ++itr)
	{
		if (bnt.BNT < itr->BNT)
		{
			BNTs.insert(itr, bnt);
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		BNTs.push_back(bnt);
	}
}

bool BNT_CreateMachine::isPrime(const unsigned& num)
{
	if (num == 2 || num == 3)
	{
		return true;
	}
	if (num % 6 != 1 && num % 6 != 5)
	{
		return false;
	}

	int tmp = sqrt(num);
  
	for (int i = 5; i <= tmp; i += 6)
	{
		if (num % i == 0 || num % (i + 2) == 0)
		{
			return false;
		}
	}
	return true;
}
