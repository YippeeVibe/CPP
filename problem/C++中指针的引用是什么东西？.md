## [未解决]

    T*& val,它的类型是T*,它是一个指针的引用。这个问题可以引申到C++中的引用究竟是什么？除了在用法上有所区别之外，它的本质和指针没有任何区别吗？

1. 可以使用T*&,不能使用T&*,不存在一个引用的指针。
2. 存在T**,不存在T&&，不存在一个引用的引用

以下代码使用msvc2019x64编译器，禁用优化。
B.cpp
```cpp
class B 
{
public:
	B(int* pointRef) :b_point_ref(pointRef)
	{

	}

	int*& b_point_ref;
};
```
main.cpp
```cpp
#include <iostream>
#include "B.cpp"
class A 
{
public:
	A(int* pointRef)
		:point_ref(pointRef)
	{


	}
	int*& point_ref;
	int* point_{ nullptr };
	//为什么指针的引用是唯一的？
};
int main()
{
	int stack_value = 10;
	int* heap_value = new int(20);


	
	A a1(&stack_value);
	A a2(heap_value);


	B b1(&stack_value);
	B b2(heap_value);

	stack_value = 11;
	*heap_value = 21;
//在调用std::cout<<"Value:"<<std::endl之前,打印它们的值
	//即使实例化两个A类型，不管是a1还是a2，它们的值都是最后一个实例化赋予的值。
	std::cout << "A:  " << *a1.point_ref << " " << *a2.point_ref << std::endl;
	std::cout << "B:  " << *b1.b_point_ref << " " << *b2.b_point_ref << std::endl;
//打印地址，它们的地址完全相同
	std::cout << "Address:" << std::endl;
	std::cout <<"A:  " << &a1.point_ref << " " << &a2.point_ref<<std::endl;
	std::cout <<"B:  "<< &b1.b_point_ref<<" "<<&b2.b_point_ref<<std::endl;

//打印指向的地址，它们所指向的地址是不同的
	std::cout << "Point Address:" << std::endl;
	std::cout << "A:  " << a1.point_ref << " " << a2.point_ref << std::endl;
	std::cout << "B:  " << b1.b_point_ref << " " << b2.b_point_ref << std::endl;

//打印指向的地址的值,有点奇怪
	std::cout << "value:" << std::endl;

	//因为调用了一系列std::cout函数，所以，A::point_ref的值固定为1970037110，
	//B::b_point_ref的值固定为32，类A和b处在不同的文件
	// 
	std::cout << "A:  " << *a1.point_ref << " " << *a2.point_ref << std::endl;
	std::cout << "B:  " << *b1.b_point_ref << " " << *b2.b_point_ref << std::endl;

	return 0;
}
```

## 去解决的途径
大概要学习内存的布局，和对象模型之后，才能解决疑问了，这个告诉我，要学习汇编语言（看汇编代码，底层是怎么实现的），可能还有编译原理。C++的对象模型（为什么要这样做）