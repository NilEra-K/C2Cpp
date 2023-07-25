/* 公有继承独有的特点 */
#include <iostream>
using namespace std;

class Base {
public:
     int m_a;
     void foo() { cout << "Base::foo()" << endl; }
protected:
     int m_b;
     void bar() { cout << "Base::bar()" << endl; }
private:
     int m_c;
     void hum() { cout << "Base::hum()" << endl; }
};

class Derived : public Base {
public:
     void foo() { cout << "Derived::foo()" << endl; }
private:
     int m_d;
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Derived d;     // 只有在公有继承下, 子类对象在类外可以访问基类的公有成员
     d.m_a = 1000;
     d.foo();
     d.Base::foo();
     return 0;
}
