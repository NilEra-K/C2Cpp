/* 继承最基本的特点 */
// (1) 子类对象的内部包含基类(子)对象
// (2) 子类内部可以直接访问基类的所有非私有成员
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
     void func() {
          // 子类内部可以直接访问基类的所有非私有成员
          m_a = 100;     // [OK]
          Base::foo();   // [OK]
          m_b = 200;     // [OK]
          bar();         // [OK]
          // m_c = 300;  // [ERROR]
          // hum();      // [ERROR]
     }
private:
     // 尽管基类的公有和保护成员在子类中直接可见
     // 但是仍然可以在子类中重新定义这些名字, 子类中的名字会隐藏所有基类中的同名定义
     void foo() { cout << "Derived::foo()" << endl; }
     void bar() { cout << "Derived::bar()" << endl; }
     int m_d;
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Base b;        // | m_a m_b m_c |
     cout << "基类成员 b 的大小 = " << sizeof(b) << endl;

     Derived d;     // | 基类子对象 | m_d | -> | m_a m_b m_c | m_d |
     cout << "子类成员 d 的大小 = " << sizeof(d) << endl;
     d.func();
     return 0;
}
