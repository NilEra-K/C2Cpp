/* 静态成员变量 和 静态成员函数 */
#include <iostream>
#include <cstring>

using namespace std;

// 普通(非静态)成员变量: 属于对象, 生命周期为对象的生命周期
// 静态成员变量: 不属于对象, 生命周期为进程级的生命周期

// 普通成员函数: 属于对象(并不意味着其在对象中存储, 而是普通成员函数必须利用对象来调用)
// 静态成员函数: 不属于对象(静态成员函数不需要对象来调用)

class A {
public:
     // 普通成员函数
     // void foo(/*| this |*/) { }

     // 普通成员函数, 带常属性, 告诉编译器补充 this 参数的时候加 const
     void foo(/*| const A* this |*/) const {
          cout << "A::foo()" << endl;
          cout << "m_si = " << m_si << endl; // [OK]
          cout << "m_i = " << m_i << endl;   // [OK]
          bar();                             // [OK]
     }

     // 静态成员函数, 无 this 指针, 因此也无常属性
     // 因此以下注释写法是错误的: 
     // static int bar() const {...}
     static void bar(/*| 无 this 参数 |*/) {
          cout << "A::bar()" << endl;
          // 静态成员函数只能访问静态成员
          cout << "m_si = " << m_si << endl; // [OK]
          // cout << "m_i = " << m_i << endl;// [ERROR] 无法访问非静态成员
          // foo();                          // [ERROR] 无法访问非静态成员
     }
public:
     int m_i;            // 普通成员变量
     static int m_si;    // 静态成员变量
};

int A::m_si = 0;   // 全局域中定义并初始化 -> 进程级生命周期

class Cmp {
public:
     int m_i;
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     A a, b;
     Cmp cmp;
     cout << "a 对象的大小为 : " << sizeof(a) << endl;
     cout << "cmp 对象的大小为 : " << sizeof(cmp) << endl;
     
     A::m_si = 100; // 属于类
                    // 依然受类作用域和访问控制限定符的约束
     
     // 访问静态成员成员变量, 既可以通过类访问, 也可以通过对象访问
     a.m_si = 8888; // 编译器发现访问静态成员变量时, 编译器会更改书写为 A::m_si = 8888;

     // 静态成员变量被该类的所有对象实例所共享
     cout << "b.m_si = " << b.m_si << endl;  // A::m_si

     // 普通成员函数, 隐藏形参 this
     // 调用函数时由编译器传入, 因此调用时必须使用对象
     a.foo(/*this*/);  // foo(&a);
     b.foo(/*this*/);  // foo(&b);

     // 静态成员函数, 不具有形参 this, 调用是不需要使用对象
     A::bar();         // 使用类名调用
     a.bar();          // 也可以通过对象调用
     b.bar();          // 编译器更改书写为 A::bar()

     return 0;
}


