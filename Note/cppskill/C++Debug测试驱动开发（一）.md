编写GUI程序的时候，一般是面向需求先写功能，调试时，直接在release代码上更改，GUI功能运行时间较短，而且运行的影响较小，这样做是最有效率的。

写在服务器上，或者耗时非常严重的程序，应该遵循先写测试，再写功能需求的模式，与写GUI程序时，不写测试的方式是极大不同的。运行时间较长，影响较大的程序，不能直接从运行效果上debug。

C++使用宏支持编译选项，可以直接在一份源代码中，对于关键部分，根据是测试还是正式发布版本编写不同的代码。
```cpp
#define _DEBUG
#ifdef _DEBUG
//somethinhg
#elif _RELEASE
//something
#else
 //something
#endif
```
既可以在源代码中指定预编译选项，也可以在IDE或者CMAKE中指定预编译选项。

```cmake
add_defininations(-D _DEBUG)
```
