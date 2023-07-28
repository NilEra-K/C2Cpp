/* 关于捕获异常的几点建议 */
#include <iostream>
#include <cstdio>
using namespace std;
class A { 
public:
     A() { }
     A(const A& that){ cout << "A 类拷贝构造函数被调用" << endl; }
     ~A() { }
private:
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者
void foo(void) {
     // A a;
     throw A();   // 以匿名对象抛出异常, 编译器会直接优化代码, 延迟销毁匿名对象, 不会进行克隆
}

int main(void) {
     try {
          foo();
     }
     catch(A& e){ // 如果 catch 不使用引用, A 类对象会克隆两次
                  // (1) 一次是 抛出异常时, 克隆一份 A类对象 a 给 C++ 标准库
                  // (2) 一次是 捕获异常时, 克隆一份 A类对象 a 给 catch 形参 e
     }
     return 0;
}

