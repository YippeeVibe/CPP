#pragma once
#include<iostream>
using namespace std;
class A
{
public:
	A();
public:
	void f1();
	void setA(int);
private:
	int a;
};

class B
{
public:
	void (A::*funPtr)();
	void Print(A*);
};