
    任何工程项目，不仅仅是软件工程，将安全的责任放在人的自觉和警惕上，都是不可靠的。

C++ 11以来，扩展了3种指针，share_ptr,weak_ptr,unique_ptr,再加上原来的“裸”指针,C++的内存控制可以非常的安全，并且一如既往的高效。

```cpp
class A {
	//friend  std::unique_ptr<A> std::make_unique();
	//friend std::unique_ptr<A> std::make_unique(int&&);
	//friend class std::default_delete<A>;
public:
	A(int i) :
		a(i) {

	}
	A() {

	}
	
public:
	int a{0};
protected:
	void* operator new(size_t size) {
		void* o = malloc(size);
		return o;
	};
	void operator delete(void* o) { //应该调用析构函数，然后释放内存。
		free(o);

	};

};
class B : public A{

	//推断this 的模板？
	friend std::unique_ptr<B> std::make_unique<B>();
	friend std::unique_ptr<B> std::make_unique<B>(int&&);
	friend class std::default_delete<B>;
	B() {

	}
	B(int i) :
	  A(i){

	}


};
```
将 一个类的new 和 delete重载函数声明为私有，将unque_ptr 指针模板推导声明为友元函数或者友元类，避免在后续代码中 new 和 delete,将可以避免内存安全。