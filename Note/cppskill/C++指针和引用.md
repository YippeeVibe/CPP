#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a = 10;

	int b = a;

	int& c = a;
	int* d = &a;

	//int*& f = &c 错误
	int*& f = d;


	int*&& h = std::move(f);
	int*&& g = std::move(d);//一个右值引用的指针。

	int** j = &d;
	int**&& k = &d;//指针的指针的右值引用。

	//任何时候都不应该出现，指向引用的指针。像指针，其实也没有很多。。。。

	//int&* g;  错误  C++运算符是相近结合的。

	

	int&& e = std::move(a);
	std::cout << &d << "," << &a;
	

	//todo 通过汇编了解底层。。

	//这样理解 &和* 与类型和变量结合是不同的意义。
	//首先int& 和int int*是属于不同的类型。它们表示一个 int引用型 的，一个 int型 ，一个 int指针型 。
	//reference &  dereference *   pointer是指指针，它和*经常搭配出现，但和*(derference 解引用运算符)不是一回事。。。
	//一个指针，包含一个地址，和一个类型。 double* d,int* i。d和i都是一个指针,double* 和 int* 为指针的类型，分别为double和int。
	//
	//同样的 一个引用也可以这么理解，int& ir,double& dr, ir和dr都是一个引用，int& 和 double& 是引用的类型。

	//& reference * deference。这些名称的含义都是根据它们和变量结合起来所代表的含意。
	//
	//int* d = &a     *d==a  int (*d) = &a  *d == &a??(error) 
	//int& c = a   c==a   int(&c)=a    &c==a??(err)
	//* &与类型和变量结合起来是完全不同的概念，不能像上述这样理解。下面：
	//int* d = &a  实际上是 d =&a  int& c = a,实际上 是 c=a 。 d 是int* 类型，  c 是int& 类型， 
	//对于实际底层而言，可以这样理解。int& c = a;  这样只是给a 起了个代号，c，程序实际上没有做别的。所以 int&* 毫无意义。。。
	//int* d = &a, 这里分配了一个栈中内存，类型为int*。 所以 int*& =&c（err）&c为a的地址，没有内存取储存它，它是一个左值
	// int*& = &d，这是正确的。
}


还需要记住，函数的返回值是一个右值