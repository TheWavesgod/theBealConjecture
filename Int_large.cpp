#include "Int_large.h"

Int_large& Int_large::operator=(const Int_large& numCpy)
{

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
