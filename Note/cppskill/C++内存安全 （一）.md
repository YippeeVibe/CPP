
    �κι�����Ŀ����������������̣�����ȫ�����η����˵��Ծ��;����ϣ����ǲ��ɿ��ġ�

C++ 11��������չ��3��ָ�룬share_ptr,weak_ptr,unique_ptr,�ټ���ԭ���ġ��㡱ָ��,C++���ڴ���ƿ��Էǳ��İ�ȫ������һ������ĸ�Ч��

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
	void operator delete(void* o) { //Ӧ�õ�������������Ȼ���ͷ��ڴ档
		free(o);

	};

};
class B : public A{

	//�ƶ�this ��ģ�壿
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
�� һ�����new �� delete���غ�������Ϊ˽�У���unque_ptr ָ��ģ���Ƶ�����Ϊ��Ԫ����������Ԫ�࣬�����ں��������� new �� delete,�����Ա����ڴ氲ȫ��