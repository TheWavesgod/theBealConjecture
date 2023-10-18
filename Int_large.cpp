#include "Int_large.h"

Int_large Int_large::operator=(const Int_large& numCpy)
{
	this->Num = numCpy.Num;
	return *this;
}

Int_large Int_large::operator=(int numCpy)
{
	if (Num.empty() != true)
	{
		Num.clear();
	}
	if (numCpy == 0)
	{
		Num.push_back(48);
	}
	while (numCpy > 0)
	{
		int temp = numCpy % 10;
		char num_tmp = temp + 48;
		Num.push_back(num_tmp);
		numCpy /= 10;
	}
	return *this;
}

Int_large Int_large::operator+(const Int_large& numAdd)
{
	Int_large tmp;

	int step = this->Num.size() > numAdd.Num.size() ? this->Num.size() : numAdd.Num.size();
	int flag = 0;

	for (int i = 0; i < step; ++i)
	{
		int x = this->getInt(i) + numAdd.getInt(i) + flag;
		if (x < 10)
		{
			tmp.Num.push_back(x + 48);
			flag = 0;
		}
		else
		{
			tmp.Num.push_back(x - 10 + 48);
			flag = 1;
		}
	}

	if (flag == 1)
	{
		tmp.Num.push_back(1 + 48);
	}

	return tmp;
}

Int_large Int_large::operator*(Int_large& numMul)
{
	Int_large outcome;
	outcome = 0;
	if ((*this) == 0 || numMul == 0)
	{
		return outcome;
	}
	for (int i = 0; i < this->Num.size(); ++i)
	{
		int mltplr = this->getInt(i);
		int flag = 0;
		Int_large tmp;
		for (int j = 0; j < numMul.Num.size(); ++j)
		{
			int x = mltplr * numMul.getInt(j) + flag;
			tmp.Num.push_back(x % 10 + 48);
			flag = x / 10;
		}
		if (flag != 0)
		{
			tmp.Num.push_back(flag + 48);
		}
		for (int j = 0; j < i; ++j)
		{
			tmp.Num.insert(0, 1, '0');
		}
		outcome = outcome + tmp;
	}
	return outcome;
}

bool Int_large::operator==(const Int_large& numCpy)
{
	if (this->Num.compare(numCpy.Num) == 0)
	{
		return true;
	}
	return false;
}

bool Int_large::operator==(int numCpy)
{
	Int_large tmp = numCpy;
	if (this->Num.compare(tmp.Num) == 0)
	{
		return true;
	}
	return false;
}

int Int_large::getInt(int pos) const
{
	if (pos >= Num.size())
	{
		return 0;
	}
	return Num[pos] - 48;
}

void Int_large::print()
{
	for (auto iter = Num.crbegin(); iter < Num.crend(); ++iter)
	{
		cout << *iter;
	}
	cout << endl;
}

Int_large::Int_large()
{
}

Int_large::Int_large(const Int_large& numCpy)
{
	this->Num = numCpy.Num;
}

Int_large::Int_large(int numCpy)
{
	if (numCpy == 0)
	{
		Num.push_back(48);
	}
	while (numCpy > 0)
	{
		int temp = numCpy % 10;
		char num_tmp = temp + 48;
		Num.push_back(num_tmp);
		numCpy /= 10;
	}
}
