    最基本的内存单位是bit(位，比特)，一个字节(byte)等于8bit.对于16位操作
    系统,一个字（Word）,等于2个byte，等于16bit,32、64位操作系统分别对应32、64比特。

    另外，以字节位基本单位，也组成了存储量度的单位。
    字节(Byte)=8位(bit) [6] 
    1KB( Kilobyte，千字节)=1024B 
    1MB( Megabyte，兆字节)=1024KB
    1GB( Gigabyte，吉字节，千兆)=1024MB


## $$ C/C++基本的类型所占内存的大小

看一段代码
```cpp
std::cout << sizeof(wchar_t)<<std::endl;//2
     << sizeof(char) << std::endl;//1
     << sizeof(int) << std::endl;//4
     << sizeof(double) << std::endl;//8
     << sizeof(void*) << std::endl;//4
     << sizeof(int*) << std::endl;//4

```
函数`sizeof`输出的是字节的个数，从上面可以看出,C/C++中最基本的单位是字节，一个char占一个字节，一个wchar_t占2个字节...

指针类型代表的是地址，任何类型的指针都占4个字节，指针的类型信息存储在指针所指向的地址中，而指针本身仅表示堆中的地址。

使用`sizeof`也可以算出不定数组的的字节大小。
```cpp
int intArr[] = {1,2,4}; 

int ISize = sizeof(intArr);//ISize == 3

char str[] = "sss";

int size = sizeof(str); //size == 4 ,最后一个字节是'\0'

int refSize = sizeof(&str);//refSize == 4;

int ptrSize = sizeof(*str);//ptrSize == 1;

char arr[];//错误！不能通过编译。
```

准确来说C/C++在运行时并不存在不定长数组，程序员不指定数组的长度，委托给编译器指定数组的长度。，C/C++数组左值，它包含这些信息：首先是类型信息，然后是数组的长度（byte），最后是数组第一个单位的地址。数据结构中，数组是在内存中的地址连续排序的。

尽管像C++ stl和别的什么库有非常好的封装，像std::string,std::vector等，但是最基本的数组仍然有不可代替的作用，这非常符合C++零开销的原则。

另外，在进程间通信时，为了尽可能减少开销，常常使用最基本的数组,在共享内存中写入数据，或者将数据copy到共享内存中，从共享内存中读数据，或者copy数据。
```cpp

char str[] ="ss";//定长为3的数组，传递时，需要额外传递3字节长度。

char(*a)[3]=&str;//它的类型信息

void* b = &str;//转换成void*

char(*c)[3]=(char(*)[3])(b);//这是强制转换

std::cout<<*c;//输出 ss

char d [10] = "dddd";
char c [12];
memcpy(c,d,10);// 最基本的数组直接指向了内存占用，它属于左值，不能直接赋值,使用内存复制函数memcpy。
std::wstring wstr = "ss";
wchat_t wCh[20];
memcpt(wCh,wstr.c_str(),wstr.size()*2);//memcpy的第三个行参，它的基本单位是一个字节，如果使用某个类型的size()，记得应该乘以该类型的基本单位
std::cout<<c;//输出 dddd





```

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

虽然大多数情况下，C/C++中最基本的内存单元是byte,但是在C/C++中也存在二进制的操作符，"<<"、">>"、"&"、"|"等，如下：
```cpp
 int v = 13;//二进制格式为：1101;
 v<<3;//左移，结果是 11010 10进制26
 v>>1;//右移，结果是 110 10进制6;

 int v1 = 4;//100
 v1&v;//真值表，离散数学，1101 & 0100 结果是100，十进制 4 
```
使用位运算符会快一些吗？还是编译器翻译成汇编，优化后是这样？

## $$ C/C++中的char和wchar_t?

一个char占用一个字节，一个wchar_t占用两个字节，为了能够表示各种语言及符号，一个字节8bit是不够用的，所有有了wchar_t，它占用两个字节，char和wchar_t的转换是有点麻烦的事情，另外一件此种麻烦的事就是二进制的编码方式了，什么utf-8什么的。

使用char仍然可以表示wchar_t,但是要采用两个字节为一个基本单位的模式，将wchar_t转化为char有时候以两个字节为一个基本单位，有时候会以一个字节为基本单位，这常常导致错误。


<table><tr><td bgcolor=red>TODO: 学习字节的编码方式和wchar_t和char的更准确详细的处理。（easy级别）。</td></tr></table>