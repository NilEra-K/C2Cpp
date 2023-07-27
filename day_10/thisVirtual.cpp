/* this指针 和 虚函数 */
#include <iostream>
#include <cstring>
using namespace std;

class Base {
public:
     // 调用虚函数的指针也可以是基类中的 this指针 
     // 同样能满足多态的条件, 但在构造和析构函数中除外    
     Base(/*| Base* this |*/) {
          cout << "构造函数中调用" << endl;
          this->vfunction();
     }

     void foo(/*| Base* this |*/) {
          cout << "Base::foo()" << endl;
          this->vfunction();
     }

     virtual void vfunction() {
          cout << "Base::vfunction()" << endl;
     }
};

class Derived : public Base {
public:
     void vfunction() {
          cout << "Derived::vfunction()" << endl;
     }
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void) {
     Derived d;
     d.foo();  // foo(&d)

     return 0;
}