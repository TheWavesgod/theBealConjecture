#include "Tabulator.h"

Tabulator::Tabulator(const vector<BNT_frqny>& data)
{
	processDate(data);
}

void Tabulator::drawGram()
{
	for (auto itr = gram.rbegin(); itr != gram.rend(); ++itr)
	{
		for (const auto& n : *itr)
		{
			cout << setw(3) << n;
		}
		cout << endl;
	}
}

void Tabulator::processDate(const vector<BNT_frqny>& data)
{
	int maxtime = 0;
	for (const auto& n : data)
	{
		if (n.times > maxtime)
		{
			maxtime = n.times;
		}
	}
	initGram(maxtime + 2, data.size() + 2);
	int i = 2;
	for (const auto& n : data)
	{
		string BNT = to_string(n.BNT);
		gram[0][i] = BNT;
		for (int j = 0; j < n.times; ++j)
		{
			gram[j + 1][i] = "*";
		}
		++i;
	}
}

void Tabulator::initGram(const int& row, const int& col)
{
	for (int i = 0; i < row; ++i)
	{
		vector<string> tmp(col, " ");
		string num = to_string(i);
		tmp[0] = num;
		tmp[1] = "|";
		gram.push_back(tmp);
	}
}
