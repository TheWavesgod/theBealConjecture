#include "Int_large.h"

int main(void)
{
	Int_large c, d;

	Int_large a = 923;
	Int_large b = 93465;
	Int_large x = 0;

	c = x + b;
	c.print();

	cout << endl;

	d = b * x;
	d.print();
}