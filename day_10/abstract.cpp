/* 纯虚函数 和 抽象类 */
#include <iostream>
#include <cstring>
using namespace std;

class A { // 抽象类
public:
     // 纯虚函数
     virtual void foo() = 0;
};

class B : public A {
public:
     void foo() { cout << "B::foo()" << endl; }
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void) {
     // A a;
     // new A;
     B b;
     return 0;
}


