## [δ���]

    T*& val,����������T*,����һ��ָ������á��������������굽C++�е����þ�����ʲô���������÷�����������֮�⣬���ı��ʺ�ָ��û���κ�������

1. ����ʹ��T*&,����ʹ��T&*,������һ�����õ�ָ�롣
2. ����T**,������T&&��������һ�����õ�����

���´���ʹ��msvc2019x64�������������Ż���
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
	//Ϊʲôָ���������Ψһ�ģ�
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
//�ڵ���std::cout<<"Value:"<<std::endl֮ǰ,��ӡ���ǵ�ֵ
	//��ʹʵ��������A���ͣ�������a1����a2�����ǵ�ֵ�������һ��ʵ���������ֵ��
	std::cout << "A:  " << *a1.point_ref << " " << *a2.point_ref << std::endl;
	std::cout << "B:  " << *b1.b_point_ref << " " << *b2.b_point_ref << std::endl;
//��ӡ��ַ�����ǵĵ�ַ��ȫ��ͬ
	std::cout << "Address:" << std::endl;
	std::cout <<"A:  " << &a1.point_ref << " " << &a2.point_ref<<std::endl;
	std::cout <<"B:  "<< &b1.b_point_ref<<" "<<&b2.b_point_ref<<std::endl;

//��ӡָ��ĵ�ַ��������ָ��ĵ�ַ�ǲ�ͬ��
	std::cout << "Point Address:" << std::endl;
	std::cout << "A:  " << a1.point_ref << " " << a2.point_ref << std::endl;
	std::cout << "B:  " << b1.b_point_ref << " " << b2.b_point_ref << std::endl;

//��ӡָ��ĵ�ַ��ֵ,�е����
	std::cout << "value:" << std::endl;

	//��Ϊ������һϵ��std::cout���������ԣ�A::point_ref��ֵ�̶�Ϊ1970037110��
	//B::b_point_ref��ֵ�̶�Ϊ32����A��b���ڲ�ͬ���ļ�
	// 
	std::cout << "A:  " << *a1.point_ref << " " << *a2.point_ref << std::endl;
	std::cout << "B:  " << *b1.b_point_ref << " " << *b2.b_point_ref << std::endl;

	return 0;
}
```

## ȥ�����;��
���Ҫѧϰ�ڴ�Ĳ��֣��Ͷ���ģ��֮�󣬲��ܽ�������ˣ���������ң�Ҫѧϰ������ԣ��������룬�ײ�����ôʵ�ֵģ������ܻ��б���ԭ��C++�Ķ���ģ�ͣ�ΪʲôҪ��������