编程 = 数据结构+算法。（预计在学习完成更底层的知识时更新。）


为什么指针如此重要？编程所做的无非就是数据和控制数据的方法，但无论是方法还是数据，都必须以二进制的形式存储，所以，编程所做的事情再抽象一下，就是编程所做的事情就是数据。指针表示的是数据的存储位置，指针就是一切.


函数是指针是指针就是一切的子集。
刚开始学习编程的时候，以为指针固有的指向数据，后来实践中发现，有存储、传递方法的需求，然后发现，这些需求能用C++函数指针轻而易举的实现。

对于函数的第一印象：函数是方法。后来，理解到方法也是一种数据，所以函数也是一种数据。
C++中，函数，它的数据有且仅有以下要素。
1. 返回类型。
   如果程序员不需要调用的函数返回值，可以声明返回类型位void（void*表示可以指向任何类型的指针，声明返回类型为void*的函数需要返回一个指针）
   不能把void看作NULL。

   特殊一点的是,C++的构造函数和析构函数，它们的返回值可以看作固定，程序员不该有权限指定他们的返回值，所以也不能指定他们的返回类型。

   Note:使用std::tuple可以更加灵活的指定函数的返回值。
   ```cpp
   void f();//显式表示程序员不需要这个函数有返回值，但实际上，这个函数有返回值，调用这个函数之后返回的是调用地址。void!=空

   void* f1();//返回任意类型的指针。

   class A{
      A();//构造函数和析构函数，均不可指定返回值。
      ~A();
   }
   ```
2. 形参列表，接受什么样的参数。
   函数接受什么类型的输入。
   ```cpp
   //函数接受一个任意类型的指针
   void f(void*);

   //函数接受不定参数，count指调用时不定参数的数目，在调用时指定。C风格。
   void f1(int count,...)
   {
      //实现
      va_list args;
      va_start(args,count)
      while(count--)
      {
         //doSomething
      }
      va_end(args);
   }
   template<typename T>
   void f2(T);//一个模板函数，编译器自动推断类型。

   //toDO可变参数模板。
   ```

3. 函数被谁所拥有。
   
   面向对象编程范式中，一个函数被一个类拥有，作为一个类的成员函数；在面向过程范式中，一个函数是个“裸”函数。

理解了函数的基本要素，就可以理解函数是可以被存储，复制和移动的。
```cpp
void f(int);//声明一个函数 不被任何类拥有，返回类型void 接受形参 int 

void (*pf)(int);//声明一个函数指针，

pf = f;//要素相同的函数可以被赋值

pf(3);//与调用 f(3)效果相同。
```

如果在类中使用函数指针，语法还是有些复杂的。
```cpp
class A;
class B
{
public:
    void (A::* pf)();//在类B中存储一个类A中的函数 没有初始化

    void (B::*pf1)() { nullptr };//在类B中存储一个类B中的函数 初始化为nullptr
    A* a{ nullptr };

    void f()
    {
        (a->*(this->pf))();//调用

    }
};

class A
{
public:
    void f()
    {

    }


};

int main()
{
	A a;
	B b;
	b.a = &a;

	b.pf1 = &B::f; //赋值！
	b.pf = &A::f;//赋值！

	(b.*(b.pf1))();//调用
	(a.*(b.pf))();//调用。 
}
```
理解函数指针十分简单，1.函数指针属于谁？2.函数被谁所拥有？3.指针只有解引用才能取出值，否者只表示一段地址。

在大部分编译器中，这些语法也是可以的
```cpp
void f();
void (*pf)();

pf = f;//OK
pf = &f;//OK

pf();//OK

(*pf)();//OK

```
C中并没有类的概念，这样做是在没有二义性的原则下保持与C的兼容？

指针是构成一切的基础！有时候，我们可能需要其它的更适合场景的实现方式，C++标准库对函数式编程有非常好的支持，使用它们可以完全代替函数指针，并且不会带来额外的开销，相比于使用指针能够更好的理解底层，使用标准库能够更好的理解抽象，更方便的处理业务！
```cpp
#include<functional>

```




Note: 
对于非类成员，一个函数指针可以视为一个普通的指针，它可以强制转换。也可以理解，一个函数是一个指针，一切皆是指针。
```cpp
void f(int);

void* any_ptr = &f;//取函数f的地址。

void* v = any_ptr;

((void(*)(int))(v))(10);//相当于调用f(10);

// void(*)(int)  一个函数指针，和它的类型。
//(void(*)(int)) 强制转换
//((void(*)(int))(v)) 优先运算规则，获得一个函数

```

再看一端代码一个函数的调用,既可以通过函数指针调用，也可以通过函数本身调用

```cpp
void f(int i) {
	std::cout << i << std::endl;
}
int main()
{
	
	void* tf = &f;

	void* c = tf;


	void(*pf)(int) = (void(*)(int))(c);

	std::cout << typeid(f).name() << std::endl;

	std::cout << typeid(&f).name()<<std::endl;

	std::cout << typeid(pf).name()<<std::endl;

	std::cout << typeid(*pf).name() << std::endl;


	(*pf)(10);
	pf(10);
	f(10);
	(&f)(10);
}

输出：
void __cdecl(int)
void (__cdecl*)(int)
void (__cdecl*)(int)
void __cdecl(int)
10
10
10
10
```


那么类的成员函数是不是这样呢？
```cpp
void f(int i) {
	std::cout << i << std::endl;
}
class A {
public:
	void f(int i) {
		std::cout << i << std::endl;
	}
};
int main()
{
	
	void* tf = &f;

	void* tf1 = f;

	//void* tf2 = A::f;  错误

	//void* tf2 = &A::f; 错误


	//void(A:: * tf2)(int) = A::f;//错误

	void(A:: * tf2)(int) = &A::f;
	A a;
	std::cout << typeid(tf2).name() << std::endl;
	//std::cout << typeid(*tf2).name() << std::endl;  错误

	//std::cout << typeid(A::f).name() << std::endl;  错误
	std::cout << typeid(&A::f).name() << std::endl;

	a.f(10);
	//a.(&f)(10);//错误
	//(&(a.f))(10);//错误
	(a.*tf2)(10);
	//(a.tf2)(10);//错误


}

输出：
void (__thiscall A::*)(int)
void (__thiscall A::*)(int)
10
10
```
C++语法比C语法更加严谨。首先，应该明白的的是，一个非类成员若已经声明、定义，就一定会实例化，而类则是新定义一个类型，它对应与int char 等基本类型。它比基本类型可以有更多的扩展，它的声明和定义，并不意味着实例化。  一个类函数指针，若想被正常使用，必须要有两个信息，一个是该函数，一个是这个函数属于哪一个实例。所以，对于“万能指针void*”,并不能体现，这个类的成员函数属于哪一个实例的类，所以，编译器定制规则，不能赋值。还是叫“无类型指针吧”。  另外，在类中，使用一个成员函数，必须解引用。也就是说，类中函数的调用，只有解引用指针后才是一个完整的具体的函数，否则，只是一个指针，它仅仅表示一段地址和它的类型。如果想要一个具体的功能呢？那么绑定它们一个实例的指针可以轻易做到。


需要函数指针，意味着我们需要，运行时确定改变调用方向，这个有别于设定状态值，使用if else 判断。

绑定一个类内函数没有什么实际的意义，增加了复杂性。这种需求可以通过存储一个类的指针,然后再调用它的函数轻松实现。


把任意类型的指针转化为void* 必须要从其它地方知道它的信息。这种情况下，常用于系统间进程通信，系统间进程通信，传递一个函数。

typeid 真的是个好东西。。。

注意，打印它们的信息出现了 __thiscall 和__cdecl 这两种前缀，它们应该代表函数的调用方式，记得还有其它的调用方式，它们的区别和其它意义呢？

更正：万能指针实质名归，下面这段代码可以帮助理解C++内存模型，以及内存布局。

```cpp
class B
{
public:
void f() {
    static int j = 0;
    std::cout<<"class B:"<<j++<<std::endl;
}

};
class A
{
public:
void f()
{
    static int i = 0;
    std::cout<<"class A:"<<i++<<std::endl;
}
void (A::*f_p)();
void (B::*f_p1)();

};

int main() { 
    A a;
    B b;

    a.f_p= &A::f;
    a.f_p1 = &B::f;

    (a.*(a.f_p))();
    (b.*(a.f_p1))();

    void* a_void = &(a.f_p);
    void* b_void = &(a.f_p1);
    //auto dd = a.f_p1;
    //auto c = (void(A::**)())(a_void);
    //auto d = (void(B::**)())(b_void);
    (a.**((void(A::**)())(a_void)))();
    (b.**((void(B::**)())(b_void)))();
}
```
