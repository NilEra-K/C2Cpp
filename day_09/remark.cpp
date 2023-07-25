/* 三种继承方式的差别 */
// 基类中的公有、保护和私有成员
// 在子类中将对这些基类成员的访问控制限定进行重新标记
#include <iostream>
using namespace std;

class Base {
public:   // 原始标记
     int m_a;
     void foo() { cout << "Base::foo()" << endl; }
protected:// 原始标记
     int m_b;
     void bar() { cout << "Base::bar()" << endl; }
private:  // 原始标记
     int m_c;
     void hum() { cout << "Base::hum()" << endl; }
};

// 子类中将对基类成员的访问控制限定进行重新标记
// m_a/foo() [public] -> [public]
// m_b/foo() [protected] -> [protected]
// m_c/foo() [private] -> [private]
class PublicDerived : public Base {
public:
     // 在子类内部能否访问基类的某个成员
     // 编译器需要查看这个成员在直接基类中的访问控制标记
     void func() {
          m_a = 100;     // [OK]
          Base::foo();   // [OK]
          m_b = 200;     // [OK]
          bar();         // [OK]
          // m_c = 300;  // [ERROR]
          // hum();      // [ERROR]
     }
private:
     int m_d;
};

// 子类中将对基类成员的访问控制限定进行重新标记
// m_a/foo() [public] -> [protected]
// m_b/foo() [protected] -> [protected]
// m_c/foo() [private] -> [private]
class ProtectedDerived : protected Base {
public:
     // 在子类内部能否访问基类的某个成员
     // 编译器需要查看这个成员在直接基类中的访问控制标记
     void func() {
          m_a = 100;     // [OK]
          Base::foo();   // [OK]
          m_b = 200;     // [OK]
          bar();         // [OK]
          // m_c = 300;  // [ERROR]
          // hum();      // [ERROR]
     }
private:
     int m_d;
};

// 子类中将对基类成员的访问控制限定进行重新标记
// m_a/foo() [public] -> [private]
// m_b/foo() [protected] -> [private]
// m_c/foo() [private] -> [private]
class PrivateDerived : private Base {
public:
     // 在子类内部能否访问基类的某个成员
     // 编译器需要查看这个成员在直接基类中的访问控制标记
     void func() {
          m_a = 100;     // [OK]
          Base::foo();   // [OK]
          m_b = 200;     // [OK]
          bar();         // [OK]
          // m_c = 300;  // [ERROR]
          // hum();      // [ERROR]
     }
private:
     int m_d;
};

class Grandson : public ProtectedDerived {
public:
     // 在子类内部能否访问基类的某个成员
     // 编译器需要查看这个成员在直接基类中的访问控制标记
     // 孙子类能否访问爷爷类的成员, 编译器需要查看这个成员在 PublicDerived 类中的标记
     void boo(){ 
          m_a = 100;     // Public[OK] Protected[OK] Private[ERROR]
          foo();         // Public[OK] Protected[OK] Private[ERROR]
          m_b = 100;     // Public[OK] Protected[OK] Private[ERROR]
          bar();         // Public[OK] Protected[OK] Private[ERROR]
          // m_c = 100;  // [ERROR]
          // m_d = 100;  // [ERROR]
     }
private:

};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     PublicDerived pbd;     // 当利用子类对象, 在类外访问基类成员时, 编译器需要查看相应子类的重新标记
     pbd.m_a = 1000;        // [OK]
     pbd.foo();             // [OK]
     // pbd.m_b = 1000;     // [ERROR]
     // pbd.bar();          // [ERROR]
     // pbd.m_c = 1000;     // [ERROR]
     // pbd.hum();          // [ERROR]

     ProtectedDerived ptd;
     // ptd.m_a = 1000;     // [ERROR]
     // ptd.foo();          // [ERROR]
     // ptd.m_b = 1000;     // [ERROR]
     // ptd.bar();          // [ERROR]
     // ptd.m_c = 1000;     // [ERROR]
     // ptd.hum();          // [ERROR]

     PrivateDerived pvd;
     // pvd.m_a = 1000;     // [ERROR]
     // pvd.foo();          // [ERROR]
     // pvd.m_b = 1000;     // [ERROR]
     // pvd.bar();          // [ERROR]
     // pvd.m_c = 1000;     // [ERROR]
     // pvd.hum();          // [ERROR]
     return 0;
}
