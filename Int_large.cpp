#include "Int_large.h"

Int_large::Int_large()
{
    this->Num = new string;

    this->length = Num->size();
}

Int_large& Int_large::operator=(const Int_large& numCpy)
{
    if (Num->empty() != true)
    {
        Num->clear();
    }
    if (numCpy.Num->empty() != true)
    {
        *Num = *(numCpy.Num);
    }
    return *this;
}

Int_large& Int_large::operator=(const string& numCpy)
{
    if (Num->empty() != true)
    {
        Num->clear();
    }
    if (numCpy.empty() != true)
    {
        *Num = numCpy;
    }
    return *this;
}

Int_large& Int_large::operator=(unsigned long long numCpy)
{
    if (Num->empty() != true)
    {
        Num->clear();
    }
    while (numCpy > 0)
    {
        int temp = numCpy % 10;
        char num_tmp = temp + 48;
        Num->push_back(num_tmp);
        numCpy /= 10;
    }
    return *this;
}

Int_large& Int_large::operator=(int numCpy)
{
    if (Num->empty() != true)
    {
        Num->clear();
    }
    while (numCpy > 0)
    {
        int temp = numCpy % 10; 
        char num_tmp = temp + 48;
        Num->push_back(num_tmp);
        numCpy /= 10;
    }
    return *this;
}

Int_large& Int_large::operator+(const Int_large& numCpy)
{
    Int_large tmp;

    return *this;
}

void Int_large::print()
{
    for (auto iter = Num->crbegin(); iter < Num->crend(); ++iter)
    {
        cout << *iter;
    }
}

