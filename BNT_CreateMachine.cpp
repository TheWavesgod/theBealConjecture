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
	cout << "The following formula satisfies the Beal's Conjecture: " << endl;
	cout << "2^n + 2^n = 2^(n+1)" << endl;
	cout << "After rearranging it as: (Here I use ABCxyz to represent the formula)" << endl;
	cout << "A = 2^i, B = 2^j, C = 2^k, x = n/i, y = n/j, z = (n+1)/k" << endl;
	cout << "So, we can express BNT as: 2^i + 2^j +2^k + n/i + n/j + (n+1)/k" << endl;
	cout << "Since n must be divisible by both i and j, we take n as i * j * n, then, take n as zn+z+d, and BNT can be represented as: " << endl;
	cout << "2^i + 2^j + 2^k + ij + ik + jk + (i + j)d + (ijd + 1)/k + (ij + ik + jk)n, n is a positive integer, d is a integer that can make (ijd + 1)/z a integer" << endl;
	cout << "When i and j take values from 1 to 15, k must be odd, all square numbers can be represented by the formula above, which means they are all BNT" << endl;
	cout << "I have stored square numbers from 1000 to 100000 in a vector, removed those that meet the formula, and below is the count of square numbers before and after removal:" << endl;

	vector<int> squareNums;
	for (int i = 32; power(i, 2) <= 100000; ++i)
	{
		squareNums.push_back(power(i, 2));
	}
	cout << squareNums.size() << " ";
	cout << "calculating......   ";

	for (int k = 1; k < 6; k = k + 2)
	{
		for (int i = 1; i < 15; ++i)
		{
			for (int j = 1; j < 15; ++j)
			{
				int d = 1;
				while ((i * j * d + 1) % k != 0)
				{
					++d;
				}
				unsigned int frt = power(2, i) + power(2, j) + power(2, k) + i * j + i * k + j * k + (i + j) * d + (i * j * d + 1) / k;
				unsigned int bk = i * j + i * k + j * k;
				if (squareNums.empty() != true)
				{
					auto itr = squareNums.begin();
					while (itr != squareNums.end())
					{
						if (*itr - frt > 0 && (*itr - frt) % bk == 0)
						{
							squareNums.erase(itr);
							itr = squareNums.begin();
							continue;
						}
						++itr;
					}
				}
			}
		}
	}

	cout << squareNums.size() << endl;

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
	cout << "When A, B, C are all greater than 2, the following formula can satisfy Beal's Conjecture: " << endl;
	cout << "4^(3n+1) + 4^(3n+1) = 8^(2n+1)" << endl;
	cout << "where BNT can be represented as 8n+19, n is a positive integer" << endl;
	cout << "Therefore, in theory, as long as the value of n is sufficiently large, BNT can be arbitrarily large, making BNT equal to infinity.";
	cout << "For example, take n = 10000000, BNT = 80000019 , A = 4, B = 4, C = 4, x = 30000001, y = 30000001, z = 20000001" << endl;
	cout << endl;
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

	limitLeft = 20;
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
	}
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
