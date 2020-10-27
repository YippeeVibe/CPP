    最基本的内存单位是bit(位，比特)，一个字节(byte)等于8bit.对于16位操作
    系统。一个字（Word）,等于2个byte，等于16bit,同样的32、64位操作系统分别等于32、64比特。

    另外，以字节位基本单位，也组成了存储量度的单位。
    字节(Byte)=8位(bit) [6] 
    1KB( Kilobyte，千字节)=1024B 
    1MB( Megabyte，兆字节)=1024KB
    1GB( Gigabyte，吉字节，千兆)=1024MB


## $$ C/C++及操作系统基本的类型所占内存的大小？

看一段代码
```cpp
std::cout << sizeof(wchar_t)<<std::endl;//2
     << sizeof(char) << std::endl;//1
     << sizeof(int) << std::endl;//4
     << sizeof(double) << std::endl;//8
     << sizeof(void*) << std::endl;//4
     << sizeof(int*) << std::endl;//4

```
函数`sizeof`输出的是字节的个数，从上面可以看出,C/C++中最基本的单位是字节，一个char占一个字节，一个wchar_t占2个字节...,需要注意的是，指针类型表示的是地址，任何类型的指针都占4个字节，指针的类型信息存储在指针所指向的地址中，而指针本身仅表示堆中的地址。

使用`sizeof`也可以算出不定数组的的字节大小。
```cpp
char str[] = "sss";
int size = sizeof(str); //size == 4 ,最后一个字节是'\0'

int refSize = sizeof(&str);//refSize == 4;

int ptrSize = sizeof(*str);//ptrSize == 1;

char arr[];//错误！不能通过编译。
```

准确来说C/C++在运行时并不存在不定长数组，程序员不指定数组的长度，委托给编译器指定数组的长度。可以看出，C/C++数组左值，它有一下信息，首先是类型信息，然后是数组的长度（byte），然后是数组第一个单位的地址，数据结构中，数组是在内存中的地址连续排序的。

尽管像C++ stl和别的什么库有非常号的封装，像std::string,std::vector等，但是最基本的数组仍然有不可代替的作用，这非常符合C++零开销的原则。

再看一段代码
```cpp
class A
{
public:
	A()
	{

	}
private:
	void f()
	{
		int value = 10;
		static int S_value = 100;
	}

	char v0;// A 占 1byte
	char v1;// A 占 1+1=2 byte
	int v2;// A 占 1+1+2+4 byte;
	int v3;// A 占 1+1+2+4+4=12 byte 
	bool v4;//A 占 16byte
};

A a;
sizeof(A);
sizeof(a);//与类A相同。
```

public和private等封装，完全是编译时的概念。另外也看不到函数在类中占用的内存，这和C++编译器有关系吧。当前还不能理清C++的对象模型，后面深入学习之后，再来补充。
<table><tr><td bgcolor=red>TODO: 学习C++的对象模型！</td></tr></table>

## $$ C/C++中的char和wchar_t?

一个char占用一个字节，一个wchar_t占用两个字节，为了能够表示各种语言及符号，一个字节8bit是不够用的，所有有了wchar_t，它占用两个字节，char和wchar_t的转换是有点麻烦的事情，另外一件此种麻烦的事就是二进制的编码方式了，什么utf-8什么的。

使用char仍然可以表示wchar_t,但是要采用两个字节为一个基本单位的模式，将wchar_t转化为char有时候以两个字节为一个基本单位，有时候会以一个字节为基本单位，这常常导致错误。


<table><tr><td bgcolor=red>TODO: 学习字节的编码方式和wchar_t和char的更准确详细的处理。（easy级别）。</td></tr></table>