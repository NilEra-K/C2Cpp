/* 虚函数表 */
#include <iostream>
#include <cstring>
using namespace std;

class A { // 编译器根据 A类的信息, 将制作一张虚函数表:
          // 用于保存 A::foo()的地址, A::bar()的地址
          // 这张表保存在 数据段, 而不是在对象中
public:
     virtual void foo() { cout << "A::foo()" << endl; }
     virtual void bar() { cout << "A::bar()" << endl; }
};

class B : public A { // 编译器根据 B类的信息, 将制作一张虚函数表
                     // 用于保存 B::foo()的地址, A::bar()的地址
                     // 如果没有提供覆盖关系, 将保存 A::bar()与 A::foo()的地址, 对于该表来说, 可以看作是 B::foo() 覆盖了 A::foo()
public:
     void foo() { cout << "B::foo()" << endl; }
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void) {
     A a;
     B b;
     // a 和 b 的大小都是 8, 里面存了一个指针, 可以称之为 "虚表指针"
     // | A 虚表指针 | -> 编译器根据 A 类信息制作的虚函数表
     // | B 虚表指针 | -> 编译器根据 B 类信息制作的虚函数表
     cout << "sizeof(a) = " << sizeof(a) << endl; // 8
     cout << "sizeof(b) = " << sizeof(b) << endl; // 8

     void (**pfunca)() = *((void(***)())&a);  // 从 a 所占内存中取出虚表指针
     pfunca[0]();    // A::foo()
     pfunca[1]();    // A::bar()

     void (**pfuncb)() = *((void(***)())&b);  // 从 b 所占内存中取出虚表指针
     pfuncb[0]();    // B::foo()
     pfuncb[1]();    // A::bar()

     A* pa = &b;
     pa->foo();     // 编译器在编译代码期间, 编译器并不知道到底调用哪个类的 foo() 函数
     // 1. 根据 pa 找到 b 对象所占的内存空间
     // 2. 从 b 对象所占的内存空间获取虚表指针
     // 3. 利用虚表指针找到虚函数表
     // 4. 从虚函数表中获取所调用虚函数的入口地址
     // 5. 根据入口地址, 调用该函数

     return 0;
}


