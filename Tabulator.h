#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct BNT_frqny
{
	unsigned BNT;
	unsigned times;

	BNT_frqny(unsigned BNT, unsigned times)
	{
		this->BNT = BNT;
		this->times = times;
	}
};

class Tabulator
{
public:
	Tabulator(const vector<BNT_frqny>& data);

	void drawGram();
private:
	vector<vector<string>> gram;

private:
	void processDate(const vector<BNT_frqny>& data);
	void initGram(const int& row, const int& col);
};
