
# C++风格规范

## 0.总则

---

1. 定期删掉无用的注释和冗(rong)余的代码，不管是无用的注释和冗余的代码都带来强大的迷惑性，它们在一开始是有用的，但会逐渐没用。完全没用时应该删除它们，或者做一个备注：暂时无用。

### 0.1 命名

1. 所有的命名都要体现完整的功能或目的

2. 任何情况下不使用汉语拼音

3. 所有缩写均使用大写字母

4. 一维容器的命名后面后缀"S"

### 0.2 项目结构

不要以.h文件和.cpp文件划分结构，除非做不到（QT 一把泪。。。）

每个项目中添加ReadMe.md,介绍项目和详细的结构。

Note.md 记录一写杂乱的学习笔记，和注意事项，交接时应去掉。

ToDoList.txt 记录总的待做事项及计划。

## 1.头文件

使用全小写的方式,若想要分开不同单词，可以使用下划线。
例如：

```cpp
#include<helloworld.h>

```

1. 若头文件中不包含类，而是一些信息的集合，头文件的命名是这些信息集合的名称。

2. 一个头文件中最好只包含一个类（必要时，可以有对这个类作补充的功能类），这个类的名称与头文件的名称保持一致。

另外，尽量将声明和定义分开，采用  .h  +  .cpp组合的方式，如果要在头文件中实现定义，那么应该使用 .hpp 后缀。

## 2. 不属于任何类的变量和函数

这些变量和函数通常是为了满足供给全局可访问的信息和全局可使用的方法这样的需求。**必须让它们在一个命名空间内。**

例如：

```cpp
namespace hellowordspace
{
    int thisCount;
    void thisFun();
}
```

Note:

1.不要使用static变量或者函数,不要使用extern变量或者函数（除非为了导出）  C++中对于类外静态成员，每一个obj中的静态成员只被这个obj中的函数完全控制，另外一个obj中使用它实际上发生了Copy，这是另外一个变量了，它会导致难以控制的错误。

## 3. 类

类的命名遵循驼峰式命名方法，第一个字母大写,不要出现下划线和数字，要与头文件的名称保持一致。

例如:

```cpp
class HelloWorld
```

### 3.1 类的成员变量

类的成员变量命名附加前缀“m”,与m紧邻的字母大写,若存在缩写，应该在缩写之后加下划线“_”,静态成员要在"m"前加组合"S_"

例如：

```cpp
int mCount;
bool mIsReady;
std::string mIO_Addr;
static double S_mThisValue;
```

### 3.2 类的成员函数

类的成员函数命名，第一个字母小写，采用驼峰式命名法,非静态成员函数，不出现下划线。静态成员函数需要加前缀“S_”

例如：

```cpp
void oneFun();

static bool S_isReady();

```

使用QT时，对于信号函数和槽函数，需要加前缀。

例如：

```cpp
signals:
    void siganlToDoSomething();
slots:
    void slotSomethingAchieve();

```

### 3.3类的成员函数指针

类的成员函数指针应该使用前缀“mpf_”,不需要额外声明它指向那个类的函数，因为在使用时，这些要显式的表示出来。

例如：

```cpp
class A
{
    void (*mpf_fun);//指向一个非类的成员函数
    void (A::*mpf_fun2)//指向一个类A的成员函数
    void (B::*mpf_fun3)//指向一个类B的成员函数

}
```

使用这些函数指针时，语法规则较为复杂，可以参考：

```cpp
#include <functional>
#include <iostream>

class A;
class B
{
public:
    void print_B()
    {
        std::cout << "B";
    }

};
class A
{
public:
    B* b;
    void print_A()
    {
        std::cout << "A";
    }
	void(*mpf_fun)();//指向一个非类的成员函数
    void(A::*mpf_fun2)();//指向一个类A的成员函数
    void(B::*mpf_fun3)();//指向一个类B的成员函数

    void TestPrint()
    {
        mpf_fun();
        (this->*mpf_fun2)();
        (b->*(this->mpf_fun3))();
       
    }
};


int main()
{
    A a;
    B b;
	(a.*(a.mpf_fun2))();
	// (a.*a.mpf_fun2)();
	(b.*(a.mpf_fun3))();
	// store a free function
	


	
}
```

//注意使用std::function
```cpp
 Foo f;
    std::function<void(Foo*)> ff = &Foo::p;
    f.p();
```

### 3.4 类声明布局和封装关键字

1. 类中，构造函数、析构函数、拷贝构造函数、移动构造函数、重载=等生成类函数相同封装共享一个关键字

2. 所有相同封装的函数共享一个关键字

3. 所有相同封装的成员变量共享一个关键字

4. 运算符重载共享一个关键字

5. 静态成员变量共享一个关键字

6. 静态成员函数共享一个关键字

7. 函数指针共享一个关键字

若,一个类中的元素实在过多，使用 #pragma region regionName,#pragma endregion regionName 隔离开来。在这样一个域中共享一个关键字。

## 4. 区域内的临时变量及函数形参

采用驼峰式命名方式，第一个字母小写，若使用缩写，后面是一个“_”,static变量加前缀“S_”

```cpp
void fun(bool isMe);

void fun(bool isMe)
{
    static int S_count;

    double value;
}

```

## 5.资源管理

与其说C++有智能指针，倒不如说C++有4种指针 unique_ptr,shared_ptr,weak_ptr和裸指针。uniuqe_ptr更多搭配裸指针，
shared_ptr和weak_ptr搭配场景更多。当需要使用C++指针时，首先是需要在堆中分配内存，和跨作用域传递值。C++指针真正解决的是资源所有权的问题。

1. 使用QT,继承QObject的类使用裸指针new创建，在主动释放时使用 deleteLater()函数（qt对象系统根据父子关系管理内存）。

2. 除Qt外不要使用new/delete 创建销毁对象，使用智能指针自动创建和销毁对象。

3. 智能指针只应该解决资源管理的问题。资源管理的本意是，当创建资源时就应该指定销毁资源的对象，不管如何，最终一定要销毁支援，使用智能指针避免手动释放资源。但一些对象不负责资源的销毁时，他应该使用裸指针俩寻找对象。所以，不应该传递智能指针对象，在函数中应传递裸指针。

4. 函数形参中传递裸指针。

```cpp
class A:public QObject
{
    Q_OBJECT
}

A *a = new A();
a->deleteLater();

class B
{

}

std::unique_ptr<B> b = std::make_unique<B>();
```

## 6. 设计原则

### 6.1 设计模式的使用

尽量不要使用单例模式，特别是操作频繁的部分。首先，单例模式在使用了可能不安全的static 变量,再则单例模式可能被滥用（带来需求更改的许多问题）。使用可以代替单例模式的依赖注入模式。

### 6.2 模块化技巧

qt编程中，尽量避免将GUI和业务代码写到一切，当程序规模稍微大一点时，这是非常麻烦的。

### 6.3 资源分配

如果一块资源在整个程序期间都存在，并且，依赖这块资源的模块很多，尤其时整个程序围绕着这块资源转，应该把它设为全局的，通过依赖注入模式授权给其它模块使用。

## 7. QT

### 7.1 Qt UI文件

需要在代码中使用的界面，或者需要使用qss设置样式的界面，应该使用所属类+下划线+功能的命名方式,所属类使用大写缩写。

例如：

```cpp
QPushButton BTN_Quit;

QLineEdit LE_Password;

```

### 7.2 信号槽函数的使用

connect连接函数中，不推荐使用SIGNAL和SLOT宏，这样，当信号槽函数发生变化时，无法在编译器检查错误，不利于Debug

```cpp
class A;
class B;
A a;
B b;
connect(&a,SINGAL(singlefun()),&b,SLOT(slotfun()));//不推荐

connect(&a,&A::singlefun,&b,&B::slotfun);//推荐

```

## 8. 缩进风格

一个大括号占一行，使用tab缩进，lamda表达式特殊缩进。

例如：

```cpp
void fun()
{
   int a;
}

auto f = []()
{
    return 0;

};

server.set_http_handler<GET, POST>("/", [](request& req,response& res){
    res.set_status_and_content(status_type::ok, "hello world");
});

```

## 9. 注释

提供导出接口注释。

```cpp
/** \brief 函数功能
 *
 * \param count - parameter bla bla
 * \param value - parameter bla bla
 * \param str - parameter bla bla
 */
 void extern "C" __stdcall fun(int count,double value,char *str);

```

非导出接口,尽量使用接口名称代替注释，除非这个接口可能造成明显的歧义。

注释应该在实现功能的那一部分以解释功能。

## 10.枚举

枚举结构的命名与类的命名一致。枚举值的命名也保持一致

例如：

```cpp
enum class Request
    {
        ServiceLog,
        GetServiceUserList,
        GetUserInfo,
        NewUserGroup,
        Find,
        DelGroup,
        ModifyUserLableInfo,
        ModifyUserGroup,
        ModefyUserInfo,
        ModifyGroupName,
        ModifyChattingUseInfo
    };
```

$$
f(x)=\int_{-\infty}^{\infty}
\hat f(\xi)\,e^{2 \pi i \pi i \xi x}\,d\xi
$$


