#include"FunctionPtr.h"

A::A()
{
	a = 0;
}
void A::f1()
{
	cout << a;
}
void A::setA(int A)
{
	a = A;
}
void B::Print(A*a)
{
	for (int i = 0; i < 1900l; ++i)
	{
		cout << 10089 << endl;
	}
	
	(a->*funPtr)();
}